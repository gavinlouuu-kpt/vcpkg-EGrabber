/* Copyright Euresys 2021*/

#ifndef EURESYS_EGRABBER_DISCOVERY_GENERATED_HEADER_FILE
#define EURESYS_EGRABBER_DISCOVERY_GENERATED_HEADER_FILE

#include "../libutil.h"

namespace EURESYS_NAMESPACE {

inline EGrabberDiscovery::EGrabberDiscovery(EGenTL & gentl)
: gentl(gentl), box(0) {
    int status = getGenTL().egrabberDll.euEurEGDiscovery_createFEur_EGenTL(gentl.getBox(), &box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
inline EGrabberDiscovery::~EGrabberDiscovery() {
    int status = getGenTL().egrabberDll.euEurEGDiscovery_destroy(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
inline void EGrabberDiscovery::discover(bool findCameras) {
    int status = getGenTL().egrabberDll.euEurEGDiscovery_discoverFb8(box, static_cast<bool8_t>(findCameras));
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
inline int EGrabberDiscovery::egrabberCount() const {
    int returnValue;
    int status = getGenTL().egrabberDll.euEurEGDiscovery_egrabberCount(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
inline EGrabberInfo EGrabberDiscovery::egrabbers(int index) const {
    Internal::Box<EGrabberInfo, ce::Eur_EGrabberInfo> returnBoxed(getGenTL());
    int status = getGenTL().egrabberDll.euEurEGDiscovery_egrabbersFi(box, index, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
inline int EGrabberDiscovery::cameraCount() const {
    int returnValue;
    int status = getGenTL().egrabberDll.euEurEGDiscovery_cameraCount(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
inline EGrabberCameraInfo EGrabberDiscovery::cameras(int index, int streamIndex) const {
    Internal::Box<EGrabberCameraInfo, ce::Eur_EGrabberCameraInfo> returnBoxed(getGenTL());
    int status = getGenTL().egrabberDll.euEurEGDiscovery_camerasFii(box, index, streamIndex, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
inline EGrabberCameraInfo EGrabberDiscovery::cameras(const std::string & deviceUserID, int streamIndex) const {
    Internal::Box<EGrabberCameraInfo, ce::Eur_EGrabberCameraInfo> returnBoxed(getGenTL());
    int status = getGenTL().egrabberDll.euEurEGDiscovery_camerasFccpi(box, deviceUserID.c_str(), streamIndex, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
inline int EGrabberDiscovery::interfaceCount() const {
    int returnValue;
    int status = getGenTL().egrabberDll.euEurEGDiscovery_interfaceCount(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
inline EGrabberInfo EGrabberDiscovery::interfaceInfo(int interfaceIndex) const {
    Internal::Box<EGrabberInfo, ce::Eur_EGrabberInfo> returnBoxed(getGenTL());
    int status = getGenTL().egrabberDll.euEurEGDiscovery_interfaceInfoFi(box, interfaceIndex, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
inline int EGrabberDiscovery::deviceCount(int interfaceIndex) const {
    int returnValue;
    int status = getGenTL().egrabberDll.euEurEGDiscovery_deviceCountFi(box, interfaceIndex, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
inline EGrabberInfo EGrabberDiscovery::deviceInfo(int interfaceIndex, int deviceIndex) const {
    Internal::Box<EGrabberInfo, ce::Eur_EGrabberInfo> returnBoxed(getGenTL());
    int status = getGenTL().egrabberDll.euEurEGDiscovery_deviceInfoFii(box, interfaceIndex, deviceIndex, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
inline int EGrabberDiscovery::streamCount(int interfaceIndex, int deviceIndex) const {
    int returnValue;
    int status = getGenTL().egrabberDll.euEurEGDiscovery_streamCountFii(box, interfaceIndex, deviceIndex, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
inline EGrabberInfo EGrabberDiscovery::streamInfo(int interfaceIndex, int deviceIndex, int streamIndex) const {
    Internal::Box<EGrabberInfo, ce::Eur_EGrabberInfo> returnBoxed(getGenTL());
    int status = getGenTL().egrabberDll.euEurEGDiscovery_streamInfoFiii(box, interfaceIndex, deviceIndex, streamIndex, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
} // namespace EURESYS_NAMESPACE

#endif // EURESYS_EGRABBER_DISCOVERY_GENERATED_HEADER_FILE
