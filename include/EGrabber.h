/* Copyright Euresys 2014 */

#ifndef EGRABBER_HEADER_FILE
#define EGRABBER_HEADER_FILE

#include <string>
#include <vector>
#include "EGenTL.h"
#include "EGrabberTypes.h"
#include "EGrabberGenICam.h"
#include "internal/EGrabberImpl.h"
#include "EGrabberDiscovery.h"

/** @file

    Main EGrabber header file (defines EGrabber, Buffer, and ScopedBuffer)
 **/

namespace EURESYS_NAMESPACE {

/** @defgroup EGrabber EGrabber
    Euresys EGrabber C++ classes (abstracting lower-level GenTL concepts)
    @{
 **/

/** An <a href=../egrabber.html#egrabber>EGrabber</a> object
    encapsulates a set of related <a href=../egrabber.html#gentl>GenTL</a>
    modules (an interface, a device, a data stream, a remote device, and a
    number of buffers).

    -   An InterfaceModule: the module that represents global (shared) frame
        grabber settings and features. This includes digital I/O control, PCIe
        and firmware status...
    -   A DeviceModule (or local device, as opposed to remote device): the
        module that contains the frame grabber settings and features relating
        to the camera. This consists mainly of camera and illumination control
        features: strobes, triggers...
    -   A StreamModule: the module that handles image buffers.
    -   A RemoteModule: the CoaXPress camera.
    -   A number of buffers.
 **/
template <typename CallbackModel = CallbackOnDemand>
class EGrabber: public Internal::EGrabberBase,
                private Internal::EGrabberEventCallbacks,
                private Internal::EGrabberScriptCallbacks {
    public:
        ///@{ @name Constructor
        /** Create an EGrabber object
            @tparam CallbackModel   the EGrabber callback configuration to use (@ref EGrabberCallbackModel)
            @param gentl            EGenTL object
            @param interfaceIndex   index of the InterfaceModule to use
            @param deviceIndex      index of the DeviceModule to use
            @param dataStreamIndex  index of the StreamModule to use
            @param deviceOpenFlags  how the device is to be opened
            @param remoteRequired   whether the remote device is required to create the grabber
            @throw gentl_error @ref GenTL::GC_ERR_INVALID_ADDRESS if remoteRequired is true
                   and there is no available remote device when the grabber is created

            @note Partial EGrabber objects (e.g., a grabber with only the interface module, or a grabber
            with the interface and device modules but without the datastream) can be created by passing -1
            as interfaceIndex, deviceIndex, or dataStreamIndex
         **/
        EGrabber(EGenTL &gentl, int interfaceIndex = 0, int deviceIndex = 0, int dataStreamIndex = 0,
                 gc::DEVICE_ACCESS_FLAGS deviceOpenFlags = defaultDeviceOpenFlags,
                 bool remoteRequired = true);
        /// Create an EGrabber object for a discovered grabber (@ref EGrabberDiscovery)
        EGrabber(const EGrabberInfo &grabber,
                 gc::DEVICE_ACCESS_FLAGS deviceOpenFlags = defaultDeviceOpenFlags,
                 bool remoteRequired = true);
        /// Create an EGrabber object for a discovered camera (@ref EGrabberDiscovery)
        EGrabber(const EGrabberCameraInfo &camera,
                 gc::DEVICE_ACCESS_FLAGS deviceOpenFlags = defaultDeviceOpenFlags);
        ///@}
        virtual ~EGrabber();

        ///@{ @name Buffer manipulation

        /** Reallocates the buffers

            reallocBuffers performs the following operations:
            - revoke current buffers (if any)
            - allocate bufferCount buffers (if bufferSize is zero, the size is
              determined automatically)
            - announce the new buffers to the data stream
            - queue the new buffers to the data stream input fifo

            @note reallocBuffers invalidates all buffer indexes
         **/
        BufferIndexRange reallocBuffers(size_t bufferCount, size_t bufferSize = 0);
        /// Allocate, announce and queue a memory buffer.
        BufferIndexRange announceAndQueue(const GenTLMemory &memory, size_t bufferCount = 1);
        /// Announce and queue a user-allocated memory buffer.
        BufferIndexRange announceAndQueue(const UserMemory &memory);
        /// Announce and queue an array of contiguous buffers using a user-allocated memory buffer.
        BufferIndexRange announceAndQueue(const UserMemoryArray &memory);
        /// Announce and queue optionally in a reverse order an array of contiguous buffers using a user-allocated memory buffer.
        BufferIndexRange announceAndQueue(const UserMemoryArray &memory, bool reverse);
        /// Announce and queue a user-allocated bus-memory buffer.
        BufferIndexRange announceAndQueue(const BusMemory &memory);
        /// Announce and queue a user-allocated device-memory buffer.
        BufferIndexRange announceAndQueue(const NvidiaRdmaMemory &memory);
        /// Move buffers from/to specific data stream buffer queues (see ACQ_QUEUE_TYPE_LIST)
        void flushBuffers(gc::ACQ_QUEUE_TYPE operation = gc::ACQ_QUEUE_ALL_TO_INPUT);
        /** Reset the buffers queues

            resetBufferQueue performs the following operations:
            - discard pending buffers (if any)
            - queue all buffers to the data stream input fifo, in the initial
              order (i.e., the order in which they were announced with
              reallocBuffers or announceBuffer)
            
            @note the data stream must be idle when calling this function
         **/
        void resetBufferQueue();
        /** Reset and queue a range of announced buffers

            resetBufferQueue performs the following operations:
            - discard pending buffers (if any)
            - queue the buffers of the given range to the data stream input fifo
            @param range range of announced buffers (returned by reallocBuffers
            or announceAndQueue)
            
            @note the data stream must be idle when calling this function
         **/
        void resetBufferQueue(const BufferIndexRange &range);
        /** Queue a range of announced buffers
        
            queue a range of announced buffers
            @param range range of announced buffers (returned by reallocBuffers
            or announceAndQueue)
         **/
        void queue(const BufferIndexRange &range);
        /** Revoke a range of announced buffers
            @note revoke does not invalidate other buffer indexes
         **/
        void revoke(const BufferIndexRange &range);
        /** Get an indication about the need to reconfigure internal resources such as the DMA

            In this case the already announced buffers need to be revoked and announced again
            otherwise some changes in the stream configuration like `StripeArrangement` would
            not be taken into account
         **/
        bool shouldReannounceBuffers();
        /** Get an indication about the need to reallocate buffers because the payload size or
            the alignment changed

            In this case the already announced buffers need to be revoked and reallocated
         **/
        bool shouldReallocBuffers();

        ///@}

        ///@{ @name Acquisitions

        /** Start acquisitions
            @param frameCount the number of buffers to fill
            @param controlRemoteDevice defines whether or not to start and stop
            the remote device by automatically executing AcquisitionStart and
            AcquisitionStop commands
        
            start performs the following operations:
            - start the data stream for frameCount buffers
            - if controlRemoteDevice is true, start the remote device by
              executing AcquisitionStart
            - for Coaxlink and Grablink Duo, start the Camera and Illumination
              Controller by executing ActivateCic
            
            @note the data stream must be idle when calling this function
            @note when frameCount buffers have been filled, the data stream
            automatically goes idle, but the remote device is not stopped
            @note if controlRemoteDevice is true, AcquisitionStop will be
            exectuted in a subsequent call to @ref stop (or in the EGrabber
            destructor)
            @note by default NewBufferData event will be enabled, unless
            explicitly disabled beforehand
         **/
        void start(uint64_t frameCount = GENTL_INFINITE, bool controlRemoteDevice = true);
        /** Stop acquisitions
        
            stop performs the following operations:
            - for Coaxlink and Grablink Duo, stop the Camera and Illumination
              Controller by executing DeactivateCic
            - stop the remote device (unless start was called with
              controlRemoteDevice = false)
            - stop the data stream
            
            @note this function will block until the data stream is idle
         **/
        void stop();

        ///@}

        ///@{ @name Image format

        /// Get the width (in pixels) of images produced by the grabber
        size_t getWidth();
        /** Get the height (in lines) of images produced by the grabber
            @note for line-scan cameras, the height is determined by the data
            stream feature "BufferHeight"
         **/
        size_t getHeight();
        /// Get the payload size of images produced by the grabber
        size_t getPayloadSize();
        /** Get the pixel format of images produced by the grabber
            @note both the camera and the data stream influence this
         **/
        std::string getPixelFormat();

        ///@}

        /**@{ @name GenTL get info
              Working with <a href=../egrabber.html#gentl>GenTL</a> Module info commands
         **/

        /** Getting Module information
            @tparam M Module to query (@ref GenTLModulesAndPorts)
            @tparam T The C++ type corresponding to the type
            (@ref GenTL::INFO_DATATYPE_LIST) of data to get
            @param cmd the info command to get, available values depend on the module M
            @parblock
            - if M is SystemModule: cmd values belong to @ref GenTL::TL_INFO_CMD_LIST
            - if M is InterfaceModule: cmd values belong to @ref GenTL::INTERFACE_INFO_CMD_LIST
            - if M is DeviceModule: cmd values belong to @ref GenTL::DEVICE_INFO_CMD_LIST
            - if M is StreamModule: cmd values belong to @ref GenTL::STREAM_INFO_CMD_LIST
            @endparblock
            @note the template parameter M cannot be set to RemoteModule because the GenTL
            standard does not expose module information about the remote device
         **/
        template <typename M, typename T> T getInfo(int32_t cmd);

        /** Get information of buffer at index bufferIndex
            @tparam T The C++ type corresponding to the type
            (@ref GenTL::INFO_DATATYPE_LIST) of data to get
            @param bufferIndex the index of the buffer to query (see @ref BufferIndexRange)
            @param cmd cmd values belong to either
            @ref GenTL::BUFFER_INFO_CMD_LIST or
            @ref GenTL::EuresysCustomGenTL::BUFFER_INFO_CUSTOM_CMD_LIST
         **/
        template <typename T> T getBufferInfo(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd);

        /** Get handle details of buffer at index bufferIndex
            @param bufferIndex the index of the buffer to query (see @ref BufferIndexRange)
         **/
        NewBufferData getBufferData(size_t bufferIndex);

        ///@}

        ///@{ @name GenTL port access

        /** Check if a port has been opened
         *  @tparam P Port Module to check (@ref GenTLModulesAndPorts)
         */
        template <typename P> bool isOpen();
        /** Read data from port
            @tparam P Port Module to use (@ref GenTLModulesAndPorts)
            @param address byte address to read from
            @param data output buffer
            @param size number of bytes to read
         */
        template <typename P> void gcReadPortData(uint64_t address, void *data, size_t size);
        /** Write data to port
            @tparam P Port Module to use (@ref GenTLModulesAndPorts)
            @param address byte address to write to
            @param data input buffer containing the data to write
            @param size number of bytes to write
         */
        template <typename P> void gcWritePortData(uint64_t address, const void *data, size_t size);
        /** Read size bytes from specified port at given address
            @tparam P Port Module to use (@ref GenTLModulesAndPorts)
            @param address byte address to read from
            @param size number of bytes to read
         **/
        template <typename P> std::vector<char> gcReadPort(uint64_t address, size_t size);
        /** Write data.size() bytes to specified port at given address
            @tparam P Port Module to use (@ref GenTLModulesAndPorts)
            @param address byte address to write to
            @param data input buffer containing the data to write
         **/
        template <typename P> void gcWritePort(uint64_t address, const std::vector<char> &data);

        /** Read a single value from specified port at given address
            @tparam P Port Module to use (@ref GenTLModulesAndPorts)
            @tparam V The C++ type corresponding to the value to read
            @param address byte address to read from
         **/
        template <typename P, typename V> V gcReadPortValue(uint64_t address);
        /** Write a single value to specified port at given address
            @tparam P Port Module to use (@ref GenTLModulesAndPorts)
            @tparam V The C++ type corresponding to the value to write
            @param address byte address to write to
            @param value value to write as a sequence of bytes
         **/
        template <typename P, typename V> void gcWritePortValue(uint64_t address, V value);

        /** Read size bytes as null-terminated string from specified port at given address
            @tparam P Port Module to use (@ref GenTLModulesAndPorts)
            @param address byte address to read from
            @param size number of bytes to read
            @note any trailing null character will be trimmed
         **/
        template <typename P> std::string gcReadPortString(uint64_t address, size_t size);

        ///@}

        /**@{ @name GenApi functions
              Working with <a href=../egrabber.html#genapi>GenApi</a> Port Module features
         **/
        
        /** Get Integer (INT64) value of specified GenApi Port Module feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to read (@ref EGenTL::genapiGetInteger)
         **/
        template <typename P> int64_t getInteger(const std::string &feature);
        /** Get Float (DOUBLE) value of specified GenApi Port Module feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to read (@ref EGenTL::genapiGetFloat)
         **/
        template <typename P> double getFloat(const std::string &feature);
        /** Get String value of specified GenApi Port Module feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to read (@ref EGenTL::genapiGetString)
         **/
        template <typename P> std::string getString(const std::string &feature);
        /** Get String data of specified GenApi Port Module feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to read (@ref EGenTL::genapiGetString)
            @param data an optionally resized vector
         **/
        template <typename P> void getStringData(const std::string &feature, std::vector<char> &data);
        /** Get list of String values returned by some query on GenApi Port Module
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param what Euresys specific query to perform, such queries are
            built using the helpers from @ref Euresys::query
         **/
        template <typename P> std::vector<std::string> getStringList(const std::string &what);
        /** Read data of specified GenApi Port Module register feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to read (@ref EGenTL::genapiGetRegister)
            @param data output buffer
            @param size number of bytes to read
         */
        template <typename P> void getRegister(const std::string &feature, void *data, size_t size);
        /**
            Set Integer (INT64) value of specified GenApi Port Module feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to modify (@ref EGenTL::genapiSetInteger)
            @param value value to write
         **/
        template <typename P> void setInteger(const std::string &feature, int64_t value);
        /** Set Float (DOUBLE) value of specified GenApi Port Module feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to modify (@ref EGenTL::genapiSetFloat)
            @param value value to write
         **/
        template <typename P> void setFloat(const std::string &feature, double value);
        /** Set String value of specified GenApi Port Module feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to modify (@ref EGenTL::genapiSetString)
            or Euresys specific action to perform, such actions are built using
            the helpers from @ref Euresys::action
            @param value value to write (or parameter of the action to perform)
         **/
        template <typename P> void setString(const std::string &feature, const std::string &value);
        /** Write data to specified GenApi Port Module register feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to modify (@ref EGenTL::genapiSetRegister)
            @param data input buffer containing the data to write
            @param size number of bytes to write
         */
        template <typename P> void setRegister(const std::string &feature, const void *data, size_t size);
        /** Execute specified GenApi Port Module command feature
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param command name of feature to execute (@ref EGenTL::genapiExecuteCommand)
         **/
        template <typename P> void execute(const std::string &command);
        /** Attach GenApi event to specified GenApi Port Module
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param eventId GenApi event identifier
            @param buffer optional event data associated to the event
            @param size size of the optional event data in bytes
         **/
        template <typename P> void attachEvent(uint64_t eventId, const void *buffer, size_t size);
        /** Invalidate cache of specified GenApi Port Module feature (and its dependencies)
            @tparam P GenApi Port Module to use (@ref GenTLModulesAndPorts)
            @param feature name of feature to invalidate (@ref EGenTL::genapiInvalidate)
            @note this only invalidates the cache (the feature itself will not be changed)
         **/
        template <typename P> void invalidate(const std::string &feature);

        /** Run a <a href=../egrabber.html#euresys-genapi-scripts>Euresys GenApi script</a>.
            @param script Euresys GenApi script to run, this can be either a location (path)
                          or some actual script statements (@ref EGenTL::genapiRunScript)
            @param context an optional context that is passed to the callback @ref onScriptUiCallback
         **/
        void runScript(const std::string &script, void *context = 0);

        /** Interrupt the execution of a running Euresys GenApi script
            @param scriptId Identifier of the script to interrupt. It is returned by the user
            interface callback with operation "scriptid" and parameter name "id" (@ref EGenTL::genapiInterruptScript)
            @pre interruptScript cannot be called from @ref onScriptUiCallback
         **/
        void interruptScript(const std::string &scriptId);

        virtual ge::GENAPI_UI_CALLBACK_RET_CODE onScriptUiCallback(const std::string &operation,
            void *context, const std::map<std::string, std::string> &args, std::string &value);

        ///@}

        ///@{ @name Memento
        
        /** Output text to Memento
            @note text is inserted into the stream of Memento traces under the Kind "User0"
            with the verbosity MEMENTO_VERBOSITY_INFO
         **/
        void memento(const std::string &text);
        /** Output text to Memento with specified verbosity and user kind
            @param verbosity
            @parblock
            - MEMENTO_VERBOSITY_CRITICAL
            - MEMENTO_VERBOSITY_ERROR
            - MEMENTO_VERBOSITY_WARNING
            - MEMENTO_VERBOSITY_NOTICE
            - MEMENTO_VERBOSITY_INFO
            - MEMENTO_VERBOSITY_DEBUG
            - MEMENTO_VERBOSITY_VERBOSE
            @endparblock
            @param kind user kind identifier, from 0 to 15
            @parblock
            - 0 to output trace under the Kind "User0"
            - 1 to output trace under the Kind "User1"
            - ...
            - 10 (0xA) to output trace under the Kind "UserA"
            - 11 (0xB) to output trace under the Kind "UserB"
            - 12 (0xC) to output trace under the Kind "UserC"
            - 13 (0xD) to output trace under the Kind "UserD"
            - 14 (0xE) to output trace under the Kind "UserE"
            - 15 (0xF) to output trace under the Kind "UserF"
            @endparblock
            @param text string to output
         **/
        void memento(unsigned char verbosity, unsigned char kind, const std::string &text);
        /** Inject a user analyzer event UP into the memento logging system
            with a "+1" semantic on the user wave form of the analyzer event specified by id.
            @note The id values from 0 to 15 are mapped onto "UserWave0" to "UserWaveF"
            @note The display name of these 15 user analyzer events can be changed in the Analyzer Configurator
            panel of the Memento application using the Alias property found in the Advanced tab of
            the Analyzer Configurator panel
            @param kind user kind identifier, from 0 to 15, mapped onto "User0" to "UserF"
            @param id user analyzer event identifier, from 0 to 15, mapped onto "UserWave0" to "UserWaveF"
        **/
        void mementoWaveUp(unsigned char kind, unsigned char id);
        /** Inject a user analyzer event DOWN into the memento logging system
            with a "-1" semantic on the user wave form of the analyzer event specified by id.
            @note The id values from 0 to 15 are mapped onto "UserWave0" to "UserWaveF"
            @note The display name of these 15 user analyzer events can be changed in the Analyzer Configurator
            panel of the Memento application using the Alias property found in the Advanced tab of
            the Analyzer Configurator panel
            @param kind user kind identifier, from 0 to 15, mapped onto "User0" to "UserF"
            @param id user analyzer event identifier, from 0 to 15, mapped onto "UserWave0" to "UserWaveF"
        **/
        void mementoWaveDown(unsigned char kind, unsigned char id);
        /** Inject a user analyzer event RESET into the memento logging system
            with a "reset to 0" semantic on the user wave form of the analyzer event specified by id.
            @note The id values from 0 to 15 are mapped onto "UserWave0" to "UserWaveF"
            @note The display name of these 15 user analyzer events can be changed in the Analyzer Configurator
            panel of the Memento application using the Alias property found in the Advanced tab of
            the Analyzer Configurator panel
            @param kind user kind identifier, from 0 to 15, mapped onto "User0" to "UserF"
            @param id user analyzer event identifier, from 0 to 15, mapped onto "UserWave0" to "UserWaveF"
        **/
        void mementoWaveReset(unsigned char kind, unsigned char id);
        /** Inject a user analyzer event VALUE into the memento logging system
            with a "set to value" semantic on the user wave form of the analyzer event specified by id.
            @note The id values from 0 to 15 are mapped onto "UserWaveValue0" to "UserWaveValueF"
            @note The display name of these 15 user analyzer events can be changed in the Analyzer Configurator
            panel of the Memento application using the Alias property found in the Advanced tab of
            the Analyzer Configurator panel
            @param kind user kind identifier, from 0 to 15, mapped onto "User0" to "UserF"
            @param id user analyzer event identifier, from 0 to 15, mapped onto "UserWaveValue0" to "UserWaveValueF"
            @param value value of the analyzer event
        **/
        void mementoWaveValue(unsigned char kind, unsigned char id, uint64_t value);
        /** Inject a user analyzer event NOVALUE into the memento logging system
            with a "disable value" semantic on the user wave form of the analyzer event specified by id.
            @note The id values from 0 to 15 are mapped onto "UserWaveValue0" to "UserWaveValueF"
            @note The display name of these 15 user analyzer events can be changed in the Analyzer Configurator
            panel of the Memento application using the Alias property found in the Advanced tab of
            the Analyzer Configurator panel
            @param kind user kind identifier, from 0 to 15, mapped onto "User0" to "UserF"
            @param id user analyzer event identifier, from 0 to 15, mapped onto "UserWaveValue0" to "UserWaveValueF"
        **/
        void mementoWaveNoValue(unsigned char kind, unsigned char id);
        ///@}

        ///@{ @name Events

        /** Enable event handling for the specified event
            @tparam DATA the event(s) to enable (@ref EGrabberEventDataOrAll)
            @note by default NewBufferData is enabled in method start, unless explicitly disabled beforehand
            @note under the hood, this method registers the corresponding GenTL event(s) to the system.
         **/
        template <typename DATA> void enableEvent();
        /** Disable event handling for the specified event
            @tparam DATA the event(s) to disable (@ref EGrabberEventDataOrAll)
            @note under the hood, this method unregisters the corresponding GenTL event(s) from the system.
         **/
        template <typename DATA> void disableEvent();
        /** Flush the event queue(s)
            @tparam DATA the event(s) to flush (@ref EGrabberEventDataOrAll)
         **/
        template <typename DATA> void flushEvent();

        /** Return a NewBufferData structure (to be given to ScopedBuffer or Buffer)
            @param timeout timeout in milliseconds
            @pre only available for EGrabber configuration CallbackOnDemand
            @pre NewBufferData event is enabled
            @pre EGrabber is not already waiting for NewBufferData event in another thread
            @note only the most important exceptions are listed below
            @throw gentl_error @ref GenTL::GC_ERR_ABORT when @ref cancelPop
            @throw gentl_error @ref GenTL::GC_ERR_INVALID_HANDLE when NewBufferData event is disabled
            @throw gentl_error @ref GenTL::GC_ERR_TIMEOUT when pop times out before an event occurs
            @throw client_error with message "EGrabber is busy in another thread"
                   if EGrabber is already waiting for NewBufferData event in another thread
                   with either pop or processEvent
            @throw client_error with message "EGrabber has no registered event for this filter"
                   if NewBufferData event is not enabled
         **/
        NewBufferData pop(uint64_t timeout = GENTL_INFINITE);
        /** Get the oldest event from a series of requested events described in @ref OneOf
            @param oneOf description of events to wait for
            @param position 1-based position of the popped event data in the @ref OneOf structure
            @param timeout timeout in milliseconds
            @return the number of pending events
            @pre only available for EGrabber configuration CallbackOnDemand
            @pre Request event types are enabled
            @pre EGrabber is not already waiting for one of the requested event in another thread
            @note only the most important exceptions are listed below
            @throw gentl_error @ref GenTL::GC_ERR_ABORT when @ref cancelPop or @ref cancelEvent
            @throw gentl_error @ref GenTL::GC_ERR_INVALID_HANDLE when a requested event is disabled
            @throw gentl_error @ref GenTL::GC_ERR_TIMEOUT when pop times out before an event occurs
            @throw client_error with message "EGrabber is busy in another thread"
                   if EGrabber is already waiting for a requested event in another thread
                   with either pop or processEvent
            @throw client_error with message "EGrabber has no registered event for this filter"
                   if no requested event is enabled
         **/
        template <typename DATA1, typename DATA2, typename DATA3,
                  typename DATA4, typename DATA5, typename DATA6,
                  typename DATA7, typename DATA8>
        size_t pop(OneOf<DATA1, DATA2, DATA3, DATA4, DATA5, DATA6, DATA7, DATA8> &oneOf, int &position, uint64_t timeout = GENTL_INFINITE);
        /** Cancel a waiting pop
            @pre only available for EGrabber configuration CallbackOnDemand
            @note any waiting pop will be aborted by throwing a gentl_error (@ref GenTL::GC_ERR_ABORT) exception
            @note cancelPop is equivalent to cancelEvent<NewBufferData>
         **/
        void cancelPop();
        /** Invoke the corresponding Event Callback(s)
            @pre events are enabled (enableEvent<DATA>)
            @pre events are available
            @tparam ANYDATA the set of events to process (@ref EGrabberEventAnyData)
            @return the number of pending events when the callback returned
            @pre only available for EGrabber configuration CallbackOnDemand
            @pre EGrabber is not already waiting for one of ANYDATA event in another thread
            @note only the most important exceptions are listed below
            @throw gentl_error @ref GenTL::GC_ERR_ABORT when @ref cancelEvent
            @throw gentl_error @ref GenTL::GC_ERR_INVALID_HANDLE when corresponding event is disabled
            @throw gentl_error @ref GenTL::GC_ERR_TIMEOUT when processEvent times out before an event occurs
            @throw client_error with message "EGrabber is busy in another thread"
                   if EGrabber is already waiting for one of ANYDATA event in another thread
                   with pop or processEvent
            @throw client_error with message "EGrabber has no registered event for this filter"
                   if none of ANYDATA event is enabled
         **/
        template <typename ANYDATA> size_t processEvent(uint64_t timeout = GENTL_INFINITE);
        /** Cancel a waiting processEvent<ANYDATA>
            the current processEvent<ANYDATA> will abort by throwing a gentl_error
            (@ref GenTL::GC_ERR_ABORT) exception
            @tparam ANYDATA the set of events to cancel (@ref EGrabberEventAnyData)
            @pre only available for EGrabber configuration CallbackOnDemand
         **/
        template <typename ANYDATA> void cancelEvent();
        /** Get the number of pending events in the different DATA queues
            @tparam ANYDATA the set of event queues to query (@ref EGrabberEventAnyData)
            @pre only available for EGrabber configuration CallbackOnDemand
         **/
        template <typename ANYDATA> size_t getPendingEventCount();
        
        ///@}

        /**@{ @name Event Callbacks
              The following methods are overridable callbacks.
              They are invoked if
              - their corresponding events are enabled with enableEvent<DATA>
              - events do occur
              @note depending on the EGrabber callback configuration (@ref EGrabberCallbackModel),
              the callbacks are invoked at different timings and from different contexts
         **/
        
        /// @pre @ref enableEvent<NewBufferData>
        virtual void onNewBufferEvent(const NewBufferData &data);
        /// @pre @ref enableEvent<IoToolboxData>
        virtual void onIoToolboxEvent(const IoToolboxData &data);
        /// @pre @ref enableEvent<CicData>
        virtual void onCicEvent(const CicData &data);
        /// @pre @ref enableEvent<DataStreamData>
        virtual void onDataStreamEvent(const DataStreamData &data);
        /// @pre @ref enableEvent<CxpInterfaceData>
        virtual void onCxpInterfaceEvent(const CxpInterfaceData &data);
        /// @pre @ref enableEvent<DeviceErrorData>
        virtual void onDeviceErrorEvent(const DeviceErrorData &data);
        /// @pre @ref enableEvent<CxpDeviceData>
        virtual void onCxpDeviceEvent(const CxpDeviceData &data);
        /// @pre @ref enableEvent<RemoteDeviceData>
        virtual void onRemoteDeviceEvent(const RemoteDeviceData &data);

        ///@}

        /**@{ @name Thread start/stop callbacks
              The following methods are overridable callbacks.
              They are invoked when a callback thread starts or stops:
              - onThreadStart is executed from the thread as soon as it started
              - onThreadStop is executed from the thread when it is about to exit
              These callbacks are reserved for advanced users who need to perform very specific
              operations on a callback thread before its event processing loop starts (e.g. changing thread priority).
              @param type the event type(s) the thread processes
              @pre only available for EGrabber configurations CallbackSingleThread and CallbackMultiThread
         **/
        virtual void onThreadStart(EventType type);
        virtual void onThreadStop(EventType type);
        ///@}

        /// Get the grabber index of the last event received on the current thread
        int getLastEventGrabberIndex();

        /** Access the GenICam interface of a specific underlying grabber
            @param ix the index of the grabber to access
            @note this is useful when the EGrabber instance is managing a camera
                  composed by several remote devices and a remote device needs
                  to be queried or configured independently
         **/
        EGrabberGenICam grabbers(int ix);

        ///@{ @name Cleanup
        /** Explicitly shutdown an EGrabber object
            @note this is useful to completely shutdown an EGrabber (including
                  any pending or executing callback) from the destructor of a
                  derived class when callbacks use derived class resources; this
                  is required if callbacks are still executing when destroying
                  grabbers using CallbackMultiThread or CallbackSingleThread
                  models
         **/
        virtual void shutdown();
        ///@}

        ///@cond
    private:
        #include "internal/class.EGrabber.h"
        #include "deprecated/common/class.EGrabber.h"
        ///@endcond
};

/// EGrabber using the configuration CallbackOnDemand
typedef EGrabber<CallbackOnDemand>     EGrabberCallbackOnDemand;
/// EGrabber using the configuration CallbackSingleThread
typedef EGrabber<CallbackSingleThread> EGrabberCallbackSingleThread;
/// EGrabber using the configuration CallbackMultiThread
typedef EGrabber<CallbackMultiThread>  EGrabberCallbackMultiThread;

/** Represents a GenTL buffer
 *
    @sa EGrabber<CallbackOnDemand>::pop()
 **/
class Buffer {
    public:
        /** Create a Buffer object encapsulating a GenTL buffer
            @param data data from the callback @ref EGrabber::onNewBufferEvent
         **/
        Buffer(const NewBufferData &data);
        /** Push the GenTL buffer back to the data stream input fifo
            @param grabber the grabber managing the underlying GenTL buffer to push back
         */
        void push(Internal::EGrabberBase &grabber);
        /** Get buffer information
            @tparam T The C++ type corresponding to the type (@ref GenTL::INFO_DATATYPE_LIST) of data to get
            @param grabber the grabber managing the underlying GenTL buffer to query
            @param cmd cmd values belong to either
            @ref GenTL::BUFFER_INFO_CMD_LIST or
            @ref GenTL::EuresysCustomGenTL::BUFFER_INFO_CUSTOM_CMD_LIST
         **/
        template <typename T> T getInfo(Internal::EGrabberBase &grabber, gc::BUFFER_INFO_CMD cmd);
        /// Get the user pointer provided when the GenTL buffer was announced (if any)
        void *getUserPointer();
        /** Save the buffer content to disk
            @param grabber the grabber managing the underlying GenTL buffer to save to disk
            @param filepath path or path pattern
            @parblock
            - path of the new image file, the file extension determines the file format
            - path pattern where a group characters 'N' is replaced by the value of index:
              - if index is 5, N becomes 5
              - if index is 9, NN becomes 09
              - if index is 10, NN becomes 10
            @code{.cpp}
            for (size_t i = 0; i < 20; ++i) {
                buffer[i]->saveToDisk(grabber, "images/buffer.NNN.jpeg", i);
            }
            @endcode
            @endparblock
            @param index
            @parblock
            - if index >= 0, enable pattern substitution with given index value
            - if index < 0, disable pattern substitution
            @endparblock
            @param params optional parameters (see @ref GenTL::EuresysCustomGenTL::ImageSaveToDiskParams)
            @pre the parent directory must exist
            @note buffer information (address, width, height, format) are automatically
            queried
            @note no buffer conversion will be applied before writing the image file,
            please use the RGBConverter if needed
            @sa EuresysImage.h
         **/
        void saveToDisk(Internal::EGrabberBase &grabber,
                        const std::string &filepath,
                        int64_t index = -1,
                        const ge::ImageSaveToDiskParams *params = 0);
        /// Get useful buffer information
        BufferInfo getInfo(Internal::EGrabberBase &grabber);

        ///@cond
    private:
        NewBufferData data;
        #include "deprecated/common/class.Buffer.h"
        ///@endcond
};

/** Buffer wrapper that queues its buffer when going out of scope.

    When the ScopedBuffer is destroyed, the buffer it contains is pushed to the
    back of the data stream input fifo).

    ScopedBuffer has two use cases:

    -   ScopedBuffer(grabber, timeout) with EGrabberCallbackOnDemand
        In this case, EGrabberCallbackOnDemand::pop(timeout) is called

    -   ScopedBuffer(grabber, bufferData) from the callback onNewBufferEvent
    
    @warning ScopedBuffer objects are designed to be used as short-lived variables.
    They hold a reference to a grabber therefore they *cannot* outlive their grabbers.
 **/
class ScopedBuffer {
    public:
        /** Pop a buffer and return it as a ScopedBuffer
            @param grabber the grabber managing the underlying GenTL buffer
            @param timeout timeout in milliseconds
            @sa EGrabber<CallbackOnDemand>::pop
         **/
        ScopedBuffer(EGrabber<CallbackOnDemand> &grabber, uint64_t timeout = GENTL_INFINITE);
        /** Create a ScopedBuffer encapsulating a GenTL buffer
            @param grabber the grabber managing the underlying GenTL buffer
            @param data data from the callback @ref EGrabber::onNewBufferEvent
         **/
        ScopedBuffer(Internal::EGrabberBase &grabber, const NewBufferData &data);
        /** Push the underlying GenTL buffer back to the grabber data stream
            input fifo automatically
         **/
        ~ScopedBuffer();
        /** Get buffer information
            @tparam T The C++ type corresponding to the type
            (@ref GenTL::INFO_DATATYPE_LIST) of data to get
            @param cmd cmd values belong to either
            @ref GenTL::BUFFER_INFO_CMD_LIST or
            @ref GenTL::EuresysCustomGenTL::BUFFER_INFO_CUSTOM_CMD_LIST
         **/
        template <typename T> T getInfo(gc::BUFFER_INFO_CMD cmd);
        /// Get the user pointer provided when the GenTL buffer was announced (if any)
        void *getUserPointer();
        /** Save the buffer content to disk
            @param filepath path or path pattern
            @parblock
            - path of the new image file, the file extension determines the file format
            - path pattern where a group characters 'N' is replaced by the value of index:
              - if index is 5, N becomes 5
              - if index is 9, NN becomes 09
              - if index is 10, NN becomes 10
            @code{.cpp}
            for (size_t i = 0; i < 20; ++i) {
                ScopedBuffer buffer(grabber);
                buffer.saveToDisk("images/buffer.NNN.jpeg", i);
            }
            @endcode
            @endparblock
            @param index
            @parblock
            - if index >= 0, enable pattern substitution with given index value
            - if index < 0, disable pattern substitution
            @endparblock
            @param params optional parameters (see @ref GenTL::EuresysCustomGenTL::ImageSaveToDiskParams)
            @pre the parent directory must exist
            @note buffer information (address, width, height, format) are automatically
            queried
            @note no buffer conversion will be applied before writing the image file,
            please use the RGBConverter if needed
            @sa EuresysImage.h
         **/
        void saveToDisk(const std::string &filepath, // path or file pattern
                        int64_t index = -1,  // if >= 0, value to use in file pattern
                        const ge::ImageSaveToDiskParams *params = 0);
        /// Get useful buffer information
        BufferInfo getInfo();

        ///@cond
    protected:
        static void *operator new(size_t); // no new ScopedBuffer
        static void *operator new[](size_t);  // no new ScopedBuffer[]
    private:
        ScopedBuffer(const ScopedBuffer &); // no copy
        ScopedBuffer &operator=(const ScopedBuffer &); // no assignment
        Internal::EGrabberBase &grabber;
        Buffer buffer;
        #include "deprecated/common/class.ScopedBuffer.h"
        ///@endcond
};

/** @} */

/** @defgroup Events Events
    Euresys Event/Notification definitions
    @{
 **/

/** Get a textual description of an event
    @param numid identifier of the event to describe
 **/
std::string getEventDescription(ge::EVENT_DATA_NUMID_CUSTOM numid);

/** @} */

} // EURESYS_NAMESPACE

#include "internal/EGrabberIImpl.h"

#endif
