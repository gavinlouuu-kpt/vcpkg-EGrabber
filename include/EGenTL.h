/* Copyright Euresys 2014, 2017 */

#ifndef EURESYS_EGENTL_HEADER_FILE
#define EURESYS_EGENTL_HEADER_FILE

#include <stdio.h>
#include <stdarg.h>
#include "internal/EGenTLImpl.h"

/** @file
    Defines GenTL
 **/

namespace EURESYS_NAMESPACE {

/** @namespace Euresys::gc
    Shortcut to GenTL Client namespace
 **/
namespace gc = GenTL;
/** @namespace Euresys::ge
    Shortcut to GenTL Euresys custom namespace
 **/
namespace ge = GenTL::EuresysCustomGenTL;

/** @defgroup GenTL GenTL
    Euresys C++ wrapper around <a href=../egrabber.html#gentl>GenTL</a>
    low-level C API
    @{
 **/

const gc::DEVICE_ACCESS_FLAGS defaultDeviceOpenFlags = gc::DEVICE_ACCESS_CONTROL;

/** auto-select the CTI path to access system-installed Coaxlink producer
 */
std::string Coaxlink();
/** auto-select the CTI path to access system-installed Grablink producer
 */
std::string Grablink();
/** auto-select the CTI path to access system-installed GigE Vision producer
 */
std::string Gigelink();
/** auto-select the CTI path to access system-installed Playlink producer
 */
std::string Playlink();

/** <a href=../egrabber.html#gentl>GenTL library functions</a>
 *  @throw gentl_error on return codes other than GenTL::GC_ERR_SUCCESS.
 *  The error code can then be found in \c gentl_error.gc_err .
 **/
class EGenTL {
    public:
        /** Initializes the EGenTL library.
         *  @arg path: filesystem path to the EGenTL library.
         *      The default value relies on the `EURESYS_DEFAULT_GENTL_PRODUCER`
         *      environment variable to select one of the GenTL producers:
         *      - `coaxlink.cti` if `EURESYS_DEFAULT_GENTL_PRODUCER=coaxlink`
         *      - `grablink.cti` if `EURESYS_DEFAULT_GENTL_PRODUCER=grablink`
         *      - `gigelink.cti` if `EURESYS_DEFAULT_GENTL_PRODUCER=gigelink`
         *      - `playlink.cti` if `EURESYS_DEFAULT_GENTL_PRODUCER=playlink`
         *  @arg shared: shared mode allows multiple opens of TL/IF/DEV/DS handles.
         *      When shared is false, EGenTL behaves as specified in the GenTL
         *      standard, i.e. opening an already opened TL, interface, or
         *      device will throw a gentl_error (GenTL::GC_ERR_RESOURCE_IN_USE).
         */
        EGenTL(const std::string &path = Internal::getEuresysCtiPath(), bool shared = true);
        EGenTL(const char *path, bool shared = true);
        EGenTL(bool shared, const std::string &path = Internal::getEuresysCtiPath());
        
        virtual ~EGenTL();

        /** Retrieves numerical information for the system module. 
         *  See GenTL::TL_INFO_CMD_LIST for allowed \c cmd values.
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T gcGetInfo(gc::TL_INFO_CMD cmd);

        ///@{ @name Low-level GenTL Port functions

        /** Fills \c data with \c data.size bytes from \c ph 's registers space.
         *    values at [address .. address+data.size[ will be read.
         *  @throw unexpected_data_size if the vector couldn't be filled.
         */
        void gcReadPort(gc::PORT_HANDLE ph, uint64_t address, std::vector<char> &data);
        /** Reads up to \c size bytes from \c ph 's registers space as a string.
         */
        std::string gcReadPortString(gc::PORT_HANDLE ph, uint64_t address, size_t size);

        /** Reads a single 32-bit value from \c ph 's registers space.
         */
        uint32_t gcReadPort(gc::PORT_HANDLE ph, uint64_t address);
        /** Writes \c data.size bytes into \c ph 's registers space.
         *  @throw unexpected_data_size if some bytes couldn't be sent.
         */
        void gcWritePort(gc::PORT_HANDLE ph, uint64_t address, const std::vector<char> &data);
        /** Read data from port
         *  @throw unexpected_data_size if all requested bytes could not be read.
         */
        void gcReadPortData(gc::PORT_HANDLE ph, uint64_t address, void *data, size_t size);
        /** Write data to port
         *  @throw unexpected_data_size if all given bytes could not be written.
         */
        void gcWritePortData(gc::PORT_HANDLE ph, uint64_t address, const void *data, size_t size);

        /** Returns the list of XML description URL for the given port.
         */
        std::vector<std::string> gcGetPortURL(gc::PORT_HANDLE ph);

        /** retrieve numerical information for a port module.
         *  See GenTL::PORT_INFO_CMD_LIST for allowed \c cmd values.
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T gcGetPortInfo(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd);
        ///@}

        ///@{ @name GenTL Event functions

        /** Returns the handle to a newly registered event
         *  @arg h: the source module handle (e.g. a GenTL::DS_HANDLE)
         */
        gc::EVENT_HANDLE gcRegisterEvent(gc::EVENTSRC_HANDLE h, gc::EVENT_TYPE event);
        void gcUnregisterEvent(gc::EVENTSRC_HANDLE h, gc::EVENT_TYPE event);
        /** Waits for event to happen for at most \c timeout ms and returns filled data size
         *  @throw gentl_error on timeout or termination through @ref eventKill.
         */
        size_t eventGetData(gc::EVENT_HANDLE eh, void *buffer, size_t size, uint64_t timeout);
        /** Waits for multiple events to happen for at most \c timeout ms
         *  @throw gentl_error on timeout (unless timeout is NULL) or termination through @ref eventKill.
         *  @warning see documentation of underlying function GenTL::EuresysCustomGenTL::EuresysEventsGetData
         */
        void eventsGetData(std::vector<ge::EURESYS_EVENT_GET_DATA_ENTRY> &entries, uint64_t *timeout);

        /** Retrieves numerical information for an event data given in buffer.
         *  See GenTL::EVENT_DATA_INFO_CMD_LIST for allowed \c cmd values.
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T eventGetDataInfo(gc::EVENT_HANDLE eh,
                                                 const void *buffer, size_t size,
                                                 gc::EVENT_DATA_INFO_CMD cmd);
        /** Retrieves numerical information for an event.
         *  See GenTL::EVENT_INFO_CMD_LIST for allowed \c cmd values.
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T eventGetInfo(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd);
        /** Discards all the past occurrences.
         */
        void eventFlush(gc::EVENT_HANDLE eh);
        /** Terminates a pending operation.
         */
        void eventKill(gc::EVENT_HANDLE eh);
        ///@}

        ///@{ @name GenTL TL functions
        gc::TL_HANDLE tlOpen();
        void tlClose(gc::TL_HANDLE tlh);
        /** Retrieves numerical information for the TL module. 
         *  See GenTL::TL_INFO_CMD_LIST for allowed \c cmd values
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T tlGetInfo(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd);
        uint32_t tlGetNumInterfaces(gc::TL_HANDLE tlh);
        std::string tlGetInterfaceID(gc::TL_HANDLE tlh, uint32_t index);
        /** Retrieves numerical information for the Interface module identified by its ID. 
         *  See GenTL::INTERFACE_INFO_CMD_LIST for allowed \c cmd values
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T tlGetInterfaceInfo(gc::TL_HANDLE tlh, const std::string &ifID, gc::TL_INFO_CMD cmd);
        gc::IF_HANDLE tlOpenInterface(gc::TL_HANDLE tlh, const std::string &ifID);
        /** Checks whether the list of interface modules has changed.
         */
        bool tlUpdateInterfaceList(gc::TL_HANDLE tlh, uint64_t timeout = GENTL_INFINITE);
        ///@}

        ///@{ @name GenTL Interface functions
        void ifClose(gc::IF_HANDLE ifh);
        /** Retrieves numerical information for the Interface module. 
         *  See GenTL::INTERFACE_INFO_CMD_LIST for allowed \c cmd values
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T ifGetInfo(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd);
        uint32_t ifGetNumDevices(gc::IF_HANDLE ifh);
        std::string ifGetDeviceID(gc::IF_HANDLE ifh, uint32_t index);
        /** Checks whether the list of devices has changed.
         */
        bool ifUpdateDeviceList(gc::IF_HANDLE ifh, uint64_t timeout = GENTL_INFINITE);
        /** Retrieves numerical information for the Device module identified by its ID. 
         *  See GenTL::DEVICE_INFO_CMD_LIST for allowed \c cmd values
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T ifGetDeviceInfo(gc::IF_HANDLE ifh, const std::string &devID, gc::INTERFACE_INFO_CMD cmd);
        gc::DEV_HANDLE ifOpenDevice(gc::IF_HANDLE ifh, const std::string &devID,
                                    gc::DEVICE_ACCESS_FLAGS flags = defaultDeviceOpenFlags);
        ///@}

        ///@{ @name GenTL Device functions
        gc::PORT_HANDLE devGetPort(gc::DEV_HANDLE devh);
        uint32_t devGetNumDataStreams(gc::DEV_HANDLE devh);
        std::string devGetDataStreamID(gc::DEV_HANDLE devh, uint32_t index);
        gc::DS_HANDLE devOpenDataStream(gc::DEV_HANDLE devh, const std::string &dsID);
        void devClose(gc::DEV_HANDLE devh);
        /** Retrieves numerical information for the Device module. 
         *  See GenTL::DEVICE_INFO_CMD_LIST for allowed \c cmd values
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T devGetInfo(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd);
        ///@}

        ///@{ @name GenTL DataStream functions
        /** Gets the handle of a new DataStream buffer allocated by the user.
         *  @arg buffer: user buffer address
         *  @arg size: user buffer size
         *  @arg userPointer: pointer to private data (passed to new buffer events)
         */
        gc::BUFFER_HANDLE dsAnnounceBuffer(gc::DS_HANDLE dsh, void *buffer,
                                           size_t size, void *userPointer = 0);
        /** Gets the handle of a new DataStream buffer allocated automatically.
         *  @arg size: desired buffer size
         *  @arg userPointer: pointer to private data (passed to new buffer events)
         */
        gc::BUFFER_HANDLE dsAllocAndAnnounceBuffer(gc::DS_HANDLE dsh, size_t size,
                                                   void *userPointer = 0);
        /** Gets the handle of a new DataStream buffer allocated by the user
         *  and addressable on the PCIe bus.
         *  @arg buffer: bus buffer address
         *  @arg size: buffer size
         *  @arg userPointer: pointer to private data (passed to new buffer events)
         */
        gc::BUFFER_HANDLE dsAnnounceBusBuffer(gc::DS_HANDLE dsh, uint64_t busAddress,
                                              size_t size, void *userPointer = 0);
        /** Gets the handle of a new DataStream buffer allocated by the user
         *  on a device and addressable by dma
         *  @arg buffer: device buffer address
         *  @arg size: buffer size
         *  @arg memoryType: memory type, see @ref GenTL::EuresysCustomGenTL::MEMORY_TYPE_LIST
         *  @arg userPointer: pointer to private data (passed to new buffer events)
         */
        gc::BUFFER_HANDLE dsAnnounceDeviceBuffer(gc::DS_HANDLE dsh, void *deviceAddress,
                                                 size_t size, ge::MEMORY_TYPE memoryType,
                                                 void *userPointer = 0);
        /** Fills \c buffers vector with \c buffers.size handles to newly allocated buffers.
         *  @arg size: desired size for the buffers.
         */
        void dsAllocAndAnnounceBuffers(gc::DS_HANDLE dsh, size_t size,
                                       std::vector<gc::BUFFER_HANDLE> &buffers);
        /** Flushes a buffers pool/queue.
         */
        void dsFlushQueue(gc::DS_HANDLE dsh, gc::ACQ_QUEUE_TYPE operation);
        /** Declares the DataStream ready for acquisition.
         *  does not execute a GenApi StartAcquisition command.
         */
        void dsStartAcquisition(gc::DS_HANDLE dsh,
                                gc::ACQ_START_FLAGS flags = gc::ACQ_START_FLAGS_DEFAULT,
                                uint64_t count = GENTL_INFINITE);

        /** Declares the DataStream as done with acquisition.
         *  does not execute a GenApi StopAcquisition command.
         */
        void dsStopAcquisition(gc::DS_HANDLE dsh,
                               gc::ACQ_STOP_FLAGS flags = gc::ACQ_STOP_FLAGS_DEFAULT);
        void dsClose(gc::DS_HANDLE dsh);
        /** Retrieves numerical information for the DataStream module. 
         *  See GenTL::STREAM_INFO_CMD_LIST for allowed \c cmd values
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T dsGetInfo(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd);
        gc::BUFFER_HANDLE dsGetBufferID(gc::DS_HANDLE dsh, uint32_t index);
        void dsRevokeBuffer(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh,
                            void **buffer = 0, void **userPointer = 0);
        /** Revokes the buffers contained in the \c buffers vector.
         */
        void dsRevokeBuffers(gc::DS_HANDLE dsh, std::vector<gc::BUFFER_HANDLE> &buffers);
        /** Adds a buffer to the input buffer queue.
         */
        void dsQueueBuffer(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh);
        /** Adds the buffers contained in the \c buffers vector to the input
         *  buffer queue.
         */
        void dsQueueBuffers(gc::DS_HANDLE dsh,
                            const std::vector<gc::BUFFER_HANDLE> &buffers);
        /** Retrieves numerical information for a buffer.
         *  See GenTL::BUFFER_INFO_CMD_LIST for allowed \c cmd values.
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T dsGetBufferInfo(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh,
                                                gc::BUFFER_INFO_CMD cmd);
        /** Retrieves useful buffer information in one operation.
         */
        BufferInfo dsGetBufferInfo(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh);
        uint32_t dsGetNumBufferParts(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh);
        /** Retrieves numerical information for a buffer part.
         *  See GenTL::BUFFER_PART_INFO_CMD_LIST for allowed \c cmd values.
         *  @throw unexpected_data_type if the size of the argument type T
         *      does not match the actual size.
         */
        template <typename T> T dsGetBufferPartInfo(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh,
                                                    uint32_t index,
                                                    gc::BUFFER_PART_INFO_CMD cmd);
        uint32_t gcGetNumPortURLs(gc::PORT_HANDLE h);
        template <typename T> T gcGetPortURLInfo(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd);
        /** Reads a number of bytes from the given address on the specified port for
         *  every element in the entries vector
         *  @note If an exception occurs, entries is resized according to the number of
         *  successful operations.
         */
        void gcReadPortStacked(gc::PORT_HANDLE h, std::vector<gc::PORT_REGISTER_STACK_ENTRY> &entries);
        /** Writes a number of bytes to the given address on the specified port for
         *  every element in the entries vector
         *  @note If an exception occurs, entries is resized according to the number of
         *  successful operations.
         */
        void gcWritePortStacked(gc::PORT_HANDLE h, std::vector<gc::PORT_REGISTER_STACK_ENTRY> &entries);
        gc::TL_HANDLE ifGetParent(gc::IF_HANDLE ifh);
        gc::IF_HANDLE devGetParent(gc::DEV_HANDLE devh);
        gc::DEV_HANDLE dsGetParent(gc::DS_HANDLE dsh);
        ///@}
        ///@{ @name Euresys Memento functions
        /** Reports a string to the memento logging system.
         */
        void memento(const std::string &text);
        void memento(unsigned char verbosity, unsigned char kind, const std::string &text);
        /** Injects a user analyzer event UP into the memento logging system
         *  with a "+1" semantic on the user wave form of the analyzer event specified by id.
         */
        void mementoWaveUp(unsigned char kind, unsigned char id);
        /** Injects a user analyzer event DOWN into the memento logging system
         *  with a "-1" semantic on the user wave form of the analyzer event specified by id.
         */
        void mementoWaveDown(unsigned char kind, unsigned char id);
        /** Injects a user analyzer event RESET into the memento logging system
         *  with a "reset to 0" semantic on the user wave form of the analyzer event specified by id.
         */
        void mementoWaveReset(unsigned char kind, unsigned char id);
        /** Injects a user analyzer event VALUE into the memento logging system
         *  with a "set to value" semantic on the user wave form of the analyzer event specified by id.
         */
        void mementoWaveValue(unsigned char kind, unsigned char id, uint64_t value);
        /** Injects a user analyzer event NOVALUE into the memento logging system
         *  with a "disable value" semantic on the user wave form of the analyzer event specified by id.
         */
        void mementoWaveNoValue(unsigned char kind, unsigned char id);
        uint64_t getTimestampUs();
        ///@}

        ///@{ @name Euresys Genapi functions
        /** Updates a feature with string contents.
         *  @sa Euresys::action
         *  @throw gentl_error if feature is missing or read-only.
         */
        void genapiSetString(gc::PORT_HANDLE h, const std::string &feature,
                             const std::string &value);
        /** Reads a feature as string.
         *  @throw gentl_error if feature is missing.
         *  @note when an integer or a float feature is accessed, optional
         *  suffixes (as documented in @ref genapiGetInteger and @ref genapiGetFloat)
         *  can be used
         *  @sa Euresys::query
         */
        std::string genapiGetString(gc::PORT_HANDLE h, const std::string &feature);
        /** Reads a feature into a vector, the size of the vector is updated
         *  @throw gentl_error if feature is missing.
         *  @note if the vector is not empty, the read operation is tried on
         *  the available vector buffer; if the buffer is too small, the data
         *  size is queried and the vector size is updated accordingly before
         *  retrying the read operation
         *  @note when an integer or a float feature is accessed, optional
         *  suffixes (as documented in @ref genapiGetInteger and @ref genapiGetFloat)
         *  can be used
         *  @sa Euresys::query
         */
        void genapiGetStringData(gc::PORT_HANDLE h, const std::string &feature, std::vector<char> &data);
        /** Reads a list of strings.
         *  @throw gentl_error if an error occurs.
         *  @sa Euresys::query
         */
        std::vector<std::string> genapiGetStringList(gc::PORT_HANDLE h, const std::string &what);
        /** Updates a feature with integer value
         *  @throw gentl_error if feature is missing or read-only.
         */
        void genapiSetInteger(gc::PORT_HANDLE h, const std::string &feature,
                              int64_t value);
        /** Reads a feature as an integer.
         *  @param h port handle
         *  @param feature name of feature to read with or without one of the following suffixes:
         *  @parblock
         *  - .Min: to read the minimum of the feature
         *  - .Max: to read the maximum of the feature
         *  - .Inc: to read the increment of the feature
         *  - .Value: to read the value of the feature (same as without .Value suffix)
         *  @endparblock
         *  @throw gentl_error if feature is missing.
         *
         *  Examples:
         *  - genapiGetInteger(cameraHandle, "Width");
         *  - genapiGetInteger(deviceHandle, "CxpTriggerMaxResendCount.Max");
         */
        int64_t genapiGetInteger(gc::PORT_HANDLE h, const std::string &feature);
        /** Reads a feature as an integer.
         *  @return feature value or defaultValue if feature is missing.
         */
        int64_t genapiGetIntegerWithDefault(gc::PORT_HANDLE h,
                                            const std::string &feature,
                                            int64_t defaultValue);
        /** Updates a feature with float value
         *  @throw gentl_error if feature is missing or read-only.
         */
        void genapiSetFloat(gc::PORT_HANDLE h, const std::string &feature,
                            double value);
        /** Reads a feature as a float.
         *  @param h port handle
         *  @param feature name of feature to read with or without one of the following suffixes:
         *  @parblock
         *  - .Min: to read the minimum of the feature
         *  - .Max: to read the maximum of the feature
         *  - .Inc: to read the increment of the feature (when defined)
         *  - .Value: to read the value of the feature (same as without .Value suffix)
         *  @endparblock
         *  @throw gentl_error if feature is missing.
         *
         *  Examples:
         *  - genapiGetFloat(interfaceHandle, "Temperature");
         *  - genapiGetFloat(deviceHandle, "CycleMinimumPeriod.Min");
         */
        double genapiGetFloat(gc::PORT_HANDLE h, const std::string &feature);
        /** Reads a feature as a float.
         *  @return feature value or default_value if feature is missing.
         */
        double genapiGetFloatWithDefault(gc::PORT_HANDLE h,
                                         const std::string &feature,
                                         double defaultValue);
        /** Update data of a register feature.
         */
        void genapiSetRegister(gc::PORT_HANDLE h, const std::string &feature, const void *data, size_t size);
        /** Read data of a register feature.
         */
        void genapiGetRegister(gc::PORT_HANDLE h, const std::string &feature, void *data, size_t size);
        /** Executes a GenApi command.
         */
        void genapiExecuteCommand(gc::PORT_HANDLE h, const std::string &feature);
        /** Attach a GenApi event.
         */
        void genapiAttachEvent(gc::PORT_HANDLE h, uint64_t eventId, const void *buffer, size_t size);
        /** Invalidate a GenApi feature.
         */
        void genapiInvalidate(gc::PORT_HANDLE h, const std::string &feature);
        /** Run a Euresys GenApi script.
         */
        void genapiRunScript(gc::PORT_HANDLE h, const std::string &script, ge::GENAPI_UI_SCRIPT_CONTEXT *context = 0);
        /** Run a Euresys GenApi script.
         */
        void genapiRunScript(const std::vector<gc::PORT_HANDLE> &handles, const std::string &script, ge::GENAPI_UI_SCRIPT_CONTEXT *context = 0);
        /** Interrupt a running Euresys GenApi script.
            @pre genapiInterruptScript cannot be called from the @ref GenTL::EuresysCustomGenTL::GENAPI_UI_SCRIPT_CONTEXT callback
         */
        void genapiInterruptScript(const std::string &scriptId);
        ///@}

        ///@{ @name Euresys Image functions
        /** Get PFNC value from name.
         */
        unsigned int imageGetPixelFormatValue(const std::string &format, unsigned int ns);
        std::string imageGetPixelFormat(uint64_t format);
        /** Get Bytes per pixel.
         */
        unsigned int imageGetBytesPerPixel(const std::string &format);
        /** Get Bits per pixel.
         */
        unsigned int imageGetBitsPerPixel(const std::string &format);
        /** Convert an image.
         */
        void imageConvert(const ge::ImageConvertInput &input, const ge::ImageConvertOutput &output, const ge::ImageConvertROI *roi = 0);
        /** Save an image to disk.
         */
        void imageSaveToDisk(const ge::ImageConvertInput &input, const std::string &filepath,
                             int64_t index = -1, const ge::ImageSaveToDiskParams *params = 0);
        /** Get information of an image.
         */
        void *imageGet(ge::ImageId id, size_t *outSize = 0);
        /** Release an image.
         */
        void imageRelease(ge::ImageId id);
        /** Preallocate buffers in the pool to improve conversion performance.
            @param bufferSize size of the buffers to preallocate in the converter pool
            @param count the number of buffers to preallocate
            @note this function improves the performance of subsequent image conversions
                  that need one or more buffers of size bufferSize
            @warning a conversion requiring a buffer of a different size (for which
                     there is no preallocated or unused buffer in the pool) will
                     automatically allocate a new buffer prior to applying the conversion
         **/
        void imagePrepareBuffers(size_t bufferSize, size_t count);
        /** Reclaim unused buffers managed by the converter to free memory.
         */
        void imageTrimBuffers();

        ///@}

    private:
        #include "internal/class.EGenTL.h"
        #include "deprecated/class.EGenTL.h"
};

/** @} */

/** @addtogroup GenApi GenApi
    Helper functions to build Euresys GenApi queries or actions

    The functions below create queries (Euresys::query) or actions
    (Euresys::action) to GenApi module

    @note these functions do not return actual information nor perform action
    but do return queries for EGrabber::getStringList and EGrabber::getString
    or actions for EGrabber::setString
    @note query or action strings are Euresys custom extensions only supported
    by the Euresys GenApi module

    Most queries return a string list with EGrabber::getStringList. It is
    possible to filter the list using either a regular expression or a glob
    expression as in the following examples.

    Example: get names of all available features exposed by the camera
    @code{.cpp}
    vector<string> cameraFeatures(grabber.getStringList<RemoteModule>(query::features()));
    @endcode

    Example: get names of all features starting with "Cxp"
    @code{.cpp}
    vector<string> cameraFeatures(grabber.getStringList<RemoteModule>(query::features().regex("^Cxp")));
    @endcode

    Example: get names of all features with name ending with "Max"
    @code{.cpp}
    vector<string> maxFeatures(grabber.getStringList<RemoteModule>(query::features().glob("*Max")));
    @endcode

    Example: get all enumeration entries of PixelFormat, including those which
    are not available at "query" time
    @code{.cpp}
    vector<string> allFormats(grabber.getStringList<RemoteModule>(query::enumEntries("PixelFormat", false)));
    @endcode

    Example: get all available enumeration entries of PixelFormat starting with
    "Mono"
    @code{.cpp}
    vector<string> monoFormats(grabber.getStringList<RemoteModule>(query::enumEntries("PixelFormat").regex("^Mono")));
    @endcode

    Example: get all available enumeration entries of PixelFormat containing
    with "BGR"
    @code{.cpp}
    vector<string> bgrFormats(grabber.getStringList<RemoteModule>(query::enumEntries("PixelFormat").glob("*BGR*")));
    @endcode

    @note Available glob pattern wildcards:
      - @b * matches 0, 1 or several characters
        e.g. "Mono*" could match "Mono8", "Mono16"
      - @b ? matches exactly 1 character
        e.g. "Mono1?" could match "Mono10", "Mono12", "Mono14", "Mono16"

    @{
 **/

namespace query {
    /** Create a query to get the list of attributes exposed by a GenApi Module
     **/
    GenApiQueryBuilder attributes();
    /** Create a query to get the list of features exposed by a GenApi Module
        @param availableOnly if true: the query will be configured to only
        include features available at "query" time; if false: the query will be
        configured to include all the exposed features
     **/
    GenApiQueryBuilder features(bool availableOnly = true);
    /** Create a query to get the list of features of a category exposed by a
        GenApi Module
        @param category name of the category
        @param availableOnly if true: the query will be configured to only
        include features of the category available at "query" time; if false:
        the query will be configured to include all the exposed features of the
        category
     **/
    GenApiQueryBuilder featuresOf(const std::string &category, bool availableOnly = true);
    /** Create a query to get the list of categories exposed by a GenApi Module
        @param availableOnly if true: the query will be configured to only
        include categories available at "query" time; if false: the query will
        be configured to include all the exposed categories
     **/
    GenApiQueryBuilder categories(bool availableOnly = true);
    /** Create a query to get the list of categories of a category exposed by a
        GenApi Module
        @param category name of the category
        @param availableOnly if true: the query will be configured to only
        include categories of the category available at "query" time;
        if false: the query will be configured to include all the exposed
        categories of the category
     **/
    GenApiQueryBuilder categoriesOf(const std::string &category, bool availableOnly = true);
    /** Create a query to get the list of entries of a GenApi enumeration
        @param feature name of enumeration feature to query
        @param availableOnly if true: the query will be configured to only
        include enumeration entries available at "query" time; if false: the
        query will be configured to include all enumeration entries of the given
        feature
     **/
    GenApiQueryBuilder enumEntries(const std::string &feature, bool availableOnly = true);
    /** Create a query to check if a feature is available
        @param feature name of the feature to query
     **/
    GenApiQueryBuilder available(const std::string &feature);
    /** Create a query to check if a feature is readable
        @param feature name of the feature to query
     **/
    GenApiQueryBuilder readable(const std::string &feature);
    /** Create a query to check if a feature is writeable
        @param feature name of the feature to query
     **/
    GenApiQueryBuilder writeable(const std::string &feature);
    /** Create a query to check if a feature is implemented
        @param feature name of the feature to query
     **/
    GenApiQueryBuilder implemented(const std::string &feature);
    /** Create a query to check if a feature is a command
        @param feature name of the feature to query
     **/
    GenApiQueryBuilder command(const std::string &feature);
    /** Create a query to check if execution of a command is done
        @param feature name of the command to query
     **/
    GenApiQueryBuilder done(const std::string &feature);
    /** Create a query to get the list of interfaces of a feature
        @param feature name of the feature to query
     **/
    GenApiQueryBuilder interfaces(const std::string &feature);
    /** Create a query to get the XML source of a feature
        @param feature name of the feature to query
     **/
    GenApiQueryBuilder source(const std::string &feature);
    /** Create a query to get the register description document of a GenApi Module
     **/
    GenApiQueryBuilder xml();
    /** Create a query to get XML information of a feature node
        @param feature name of the feature to query
        @param what name of the XML child to query

        Example: get Tooltip of feature Width
        @code{.cpp}
        string tooltip(grabber.getString<RemoteModule>(query::info("Width", "Tooltip")));
        @endcode
     **/
    GenApiQueryBuilder info(const std::string &feature, const std::string &what);
    /** Create a query to get the list of declared virtual user features
        @sa Euresys::action::declareInteger
        @sa Euresys::action::declareFloat
        @sa Euresys::action::declareString
     **/
    GenApiQueryBuilder declared();
}

namespace action {
    /** Create an action to declare a virtual user feature of type Integer on a
        GenApi Module
        @note a declared virtual user feature is used as a GenApi feature by
        prefixing its name with a dollar sign ($)

        Example: create a virtual user feature "size" of type Integer on the
        Device module
        @code{.cpp}
        grabber.setString<DeviceModule>(action::declareInteger(), "size");
        grabber.setInteger<DeviceModule>("$size", 1024);
        grabber.runScript(pathToScriptUsingTheUserFeature$size);
        int64_t size = grabber.getInteger<DeviceModule>("$size");
        @endcode
     **/
    GenApiActionBuilder declareInteger();
    /** Create an action to declare a virtual user feature of type Float on a
        GenApi Module
     **/
    GenApiActionBuilder declareFloat();
    /** Create an action to declare a virtual user feature of type String on a
        GenApi Module
     **/
    GenApiActionBuilder declareString();
    /** Create an action to undeclare (delete) a virtual user feature on a
        GenApi Module

        Example: delete a virtual user feature "size" on the Device module
        @code{.cpp}
        grabber.setString<DeviceModule>(action::undeclare(), "size");
        @endcode
     **/
    GenApiActionBuilder undeclare();
}

/** @} */

#include "deprecated/common/namespace.Euresys.h"

} // namespace EURESYS_NAMESPACE

#include "internal/class.EGenTL.impl.h"

#endif
