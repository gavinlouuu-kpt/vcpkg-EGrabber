/* Copyright Euresys 2021 */

#ifndef EGRABBER_DISCOVERY_HEADER_FILE
#define EGRABBER_DISCOVERY_HEADER_FILE

#include "internal/EGrabberDiscoveryImpl.h"

/** @file

    EGrabberDiscovery header file
 **/

namespace EURESYS_NAMESPACE {

/** @defgroup EGrabberDiscovery EGrabberDiscovery
    Euresys EGrabber and camera <a href=../egrabber.html#discovering-grabbers-and-cameras>discovery</a>
    @{
 **/

/** An EGrabberDiscovery object <a href=../egrabber.html#discovering-grabbers-and-cameras>discovers</a>
    available grabbers and cameras in the system and simplifies the creation of EGrabber objects
 **/
class EGrabberDiscovery
{
    public:
        ///@{ @name Constructor
        /** Create an EGrabberDiscovery object
            @param gentl EGenTL object
            @note it's not recommended to create more than one EGrabberDiscovery
            object for the same system (EGenTL object)
            @note the EGrabberDiscovery object takes exclusive control of the
            interface and device lists of the system (i.e. EGenTL) to prevent
            inconsistencies between objects discovered by EGrabberDiscovery
            and actual modules reported by EGenTL; the exclusive control is
            released as soon as the EGrabberDiscovery is deleted;
            As long as EGrabberDiscovery exists, any attempt to update interface
            or device lists will trigger a not_allowed exception, this could
            happen if an EGrabber is created using the index-based constructor
            instead of the EGrabberInfo or EGrabberCameraInfo variants because
            the index-based constructor updates the interface and device lists
            before opening the requested GenTL modules
         **/
        EGrabberDiscovery(EGenTL &gentl);
        virtual ~EGrabberDiscovery();
        /** Perform the discovery
            @param findCameras enable or disable the camera-oriented discovery
                               in addition to the grabber-oriented discovery
            @note the camera-oriented discovery (i.e. the default behavior of
            @ref discover) takes more time to complete because it inspects all
            the grabbers of the system to present a list of available cameras;
            A multi-bank camera that exposes several CoaXPress devices (each
            device providing a part of the acquired images) can be detected by
            the camera-oriented discovery as a **single** camera; indeed the
            discovery is able to identify which devices go together and how to
            reorder them so the master device is always in the first position
         **/
        void discover(bool findCameras = true);
        /// How many grabbers were discovered (by the last run of @ref discover)
        int egrabberCount() const;
        /** Return information to create an EGrabber object for a discovered grabber
            @param index index of the grabber (must be smaller than @ref egrabberCount)
            @return input for the @ref EGrabber constructor
         **/
        EGrabberInfo egrabbers(int index) const;
        /** How many cameras were discovered (by the last run of @ref discover)
            @note if the last run of @ref discover was performed without the camera
            discovery, @ref cameraCount returns 0
         **/
        int cameraCount() const;
        /** Return information to create an EGrabber object for a discovered camera
            @param index index of the camera (must be smaller than @ref cameraCount)
            @param streamIndex optional index of the data stream to select (0 by default)
            @return input for the @ref EGrabber constructor
         **/
        EGrabberCameraInfo cameras(int index, int streamIndex = 0) const;
        /** Return information to create an EGrabber object for a discovered camera
            @param deviceUserID user-defined name of the camera
            @param streamIndex optional index of the data stream to select (0 by default)
            @return input for the @ref EGrabber constructor
         **/
        EGrabberCameraInfo cameras(const std::string &deviceUserID, int streamIndex = 0) const;
        /// How many interfaces were found in the system (by the last run of @ref discover)
        int interfaceCount() const;
        /// Return information about an interface (found by the last run of @ref discover)
        EGrabberInfo interfaceInfo(int interfaceIndex) const;
        /// How many devices were found in an interface (by the last run of @ref discover)
        int deviceCount(int interfaceIndex) const;
        /// Return information about a device (found by the last run of @ref discover)
        EGrabberInfo deviceInfo(int interfaceIndex, int deviceIndex) const;
        /// How many streams were found in a device (by the last run of @ref discover)
        int streamCount(int interfaceIndex, int deviceIndex) const;
        /// Return information about a stream (found by the last run of @ref discover)
        EGrabberInfo streamInfo(int interfaceIndex, int deviceIndex, int streamIndex) const;
    private:
        #include "internal/class.EGrabberDiscovery.h"
};

/** @} */

} // EURESYS_NAMESPACE

#include "internal/EGrabberDiscoveryIImpl.h"

#endif
