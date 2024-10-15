/* Copyright Euresys 2021*/

#ifndef EURESYS_EGRABBER_GENERATED_HEADER_FILE
#define EURESYS_EGRABBER_GENERATED_HEADER_FILE

#include "../libutil.h"

namespace EURESYS_NAMESPACE {

template <> inline EGrabber<CallbackOnDemand>::EGrabber(EGenTL & gentl, int interfaceIndex, int deviceIndex, int dataStreamIndex, gc::DEVICE_ACCESS_FLAGS deviceOpenFlags, bool remoteRequired)
: gentl(gentl), box(0) {
    int status = getGenTL().egrabberDll.euEGCOD_createFEur_EGenTLiiiDAFb8(gentl.getBox(), interfaceIndex, deviceIndex, dataStreamIndex, deviceOpenFlags, static_cast<bool8_t>(remoteRequired), &box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    setCallbacks();
}
template <> inline EGrabber<CallbackOnDemand>::EGrabber(const EGrabberInfo & grabber, gc::DEVICE_ACCESS_FLAGS deviceOpenFlags, bool remoteRequired)
: gentl(*grabber.gentl), box(0) {
    Internal::Box<EGrabberInfo, ce::Eur_EGrabberInfo> grabberBoxed(getGenTL(), grabber);
    int status = getGenTL().egrabberDll.euEGCOD_createFEurEGInfoDAFb8(grabberBoxed.getBox(), deviceOpenFlags, static_cast<bool8_t>(remoteRequired), &box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    setCallbacks();
}
template <> inline EGrabber<CallbackOnDemand>::EGrabber(const EGrabberCameraInfo & camera, gc::DEVICE_ACCESS_FLAGS deviceOpenFlags)
: gentl(*camera.grabbers.at(0).gentl), box(0) {
    Internal::Box<EGrabberCameraInfo, ce::Eur_EGrabberCameraInfo> cameraBoxed(getGenTL(), camera);
    int status = getGenTL().egrabberDll.euEGCOD_createFEurEGCameraInfoDAF(cameraBoxed.getBox(), deviceOpenFlags, &box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    setCallbacks();
}
template <> inline EGrabber<CallbackOnDemand>::~EGrabber() {
    int status = getGenTL().egrabberDll.euEGCOD_destroy(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline BufferIndexRange EGrabber<CallbackOnDemand>::reallocBuffers(size_t bufferCount, size_t bufferSize) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_reallocBuffersFss(box, bufferCount, bufferSize, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackOnDemand>::announceAndQueue(const GenTLMemory & memory, size_t bufferCount) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<GenTLMemory, ce::Eur_GenTLMemory> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGCOD_announceAndQueueFEur_GenTLMemorys(box, memoryBoxed.getBox(), bufferCount, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackOnDemand>::announceAndQueue(const UserMemory & memory) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<UserMemory, ce::Eur_UserMemory> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGCOD_announceAndQueueFEur_UserMemory(box, memoryBoxed.getBox(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackOnDemand>::announceAndQueue(const UserMemoryArray & memory) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<UserMemoryArray, ce::Eur_UserMemoryArray> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGCOD_announceAndQueueFEur_UserMemoryArray(box, memoryBoxed.getBox(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackOnDemand>::announceAndQueue(const UserMemoryArray & memory, bool reverse) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<UserMemoryArray, ce::Eur_UserMemoryArray> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGCOD_announceAndQueueFEur_UserMemoryArrayb8(box, memoryBoxed.getBox(), static_cast<bool8_t>(reverse), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackOnDemand>::announceAndQueue(const BusMemory & memory) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<BusMemory, ce::Eur_BusMemory> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGCOD_announceAndQueueFEur_BusMemory(box, memoryBoxed.getBox(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackOnDemand>::announceAndQueue(const NvidiaRdmaMemory & memory) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<NvidiaRdmaMemory, ce::Eur_NvidiaRdmaMemory> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGCOD_announceAndQueueFEur_NvidiaRdmaMemory(box, memoryBoxed.getBox(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void EGrabber<CallbackOnDemand>::flushBuffers(gc::ACQ_QUEUE_TYPE operation) {
    int status = getGenTL().egrabberDll.euEGCOD_flushBuffersFAQT(box, operation);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::resetBufferQueue() {
    int status = getGenTL().egrabberDll.euEGCOD_resetBufferQueue(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::resetBufferQueue(const BufferIndexRange & range) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> rangeBoxed(getGenTL().egrabberDll, range);
    int status = getGenTL().egrabberDll.euEGCOD_resetBufferQueueFEur_BufferIndexRange(box, rangeBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::queue(const BufferIndexRange & range) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> rangeBoxed(getGenTL().egrabberDll, range);
    int status = getGenTL().egrabberDll.euEGCOD_queueFEur_BufferIndexRange(box, rangeBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::revoke(const BufferIndexRange & range) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> rangeBoxed(getGenTL().egrabberDll, range);
    int status = getGenTL().egrabberDll.euEGCOD_revokeFEur_BufferIndexRange(box, rangeBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline bool EGrabber<CallbackOnDemand>::shouldReannounceBuffers() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_shouldReannounceBuffers(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> inline bool EGrabber<CallbackOnDemand>::shouldReallocBuffers() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_shouldReallocBuffers(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> inline void EGrabber<CallbackOnDemand>::start(uint64_t frameCount, bool controlRemoteDevice) {
    int status = getGenTL().egrabberDll.euEGCOD_startFu64b8(box, frameCount, static_cast<bool8_t>(controlRemoteDevice));
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::stop() {
    int status = getGenTL().egrabberDll.euEGCOD_stop(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline size_t EGrabber<CallbackOnDemand>::getWidth() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getWidth(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline size_t EGrabber<CallbackOnDemand>::getHeight() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getHeight(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline size_t EGrabber<CallbackOnDemand>::getPayloadSize() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getPayloadSize(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGrabber<CallbackOnDemand>::getPixelFormat() {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getPixelFormat(box, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAsOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi8OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi16OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi32OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi64OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu8OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu16OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu32OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu64OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAdOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAfOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t * EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    uint8_t * returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu8pOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoASsOSystemModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void * EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    void * returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAvptrOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::vector<char> EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoASvcOSystemModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoASv_std_stringOSystemModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAb8OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline char * EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    char * returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAcptrOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline InfoCommandInfo EGrabber<CallbackOnDemand>::getInfo<SystemModule>(int32_t cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoA_CINFOOSystemModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAsOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi8OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi16OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi32OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi64OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu8OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu16OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu32OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu64OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAdOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAfOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t * EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    uint8_t * returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu8pOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoASsOInterfaceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void * EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    void * returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAvptrOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::vector<char> EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoASvcOInterfaceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoASv_std_stringOInterfaceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAb8OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline char * EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    char * returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAcptrOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline InfoCommandInfo EGrabber<CallbackOnDemand>::getInfo<InterfaceModule>(int32_t cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoA_CINFOOInterfaceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAsODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi8ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi16ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi32ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi64ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu8ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu16ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu32ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu64ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAdODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAfODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t * EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    uint8_t * returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu8pODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoASsODeviceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void * EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    void * returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAvptrODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::vector<char> EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoASvcODeviceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoASv_std_stringODeviceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAb8ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline char * EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    char * returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAcptrODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline InfoCommandInfo EGrabber<CallbackOnDemand>::getInfo<DeviceModule>(int32_t cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoA_CINFOODeviceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAsOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi8OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi16OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi32OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAi64OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu8OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu16OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu32OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu64OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAdOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAfOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t * EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    uint8_t * returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAu8pOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoASsOStreamModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void * EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    void * returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAvptrOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::vector<char> EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoASvcOStreamModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoASv_std_stringOStreamModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAb8OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline char * EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    char * returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInfoAcptrOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline InfoCommandInfo EGrabber<CallbackOnDemand>::getInfo<StreamModule>(int32_t cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getInfoA_CINFOOStreamModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoAsFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoAi8FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoAi16FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoAi32FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoAi64FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoAu8FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoAu16FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoAu32FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoAu64FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoAdFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoAfFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t * EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoAu8pFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoASsFsBIC(box, bufferIndex, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void * EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    void * returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoAvptrFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::vector<char> EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoASvcFsBIC(box, bufferIndex, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoASv_std_stringFsBIC(box, bufferIndex, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoAb8FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline char * EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    char * returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoAcptrFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline InfoCommandInfo EGrabber<CallbackOnDemand>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getBufferInfoA_CINFOFsBIC(box, bufferIndex, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline NewBufferData EGrabber<CallbackOnDemand>::getBufferData(size_t bufferIndex) {
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getBufferDataFs(box, bufferIndex, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackOnDemand>::isOpen<SystemModule>() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_isOpenOSystemModule(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline bool EGrabber<CallbackOnDemand>::isOpen<InterfaceModule>() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_isOpenOInterfaceModule(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline bool EGrabber<CallbackOnDemand>::isOpen<DeviceModule>() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_isOpenODeviceModule(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline bool EGrabber<CallbackOnDemand>::isOpen<StreamModule>() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_isOpenOStreamModule(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline bool EGrabber<CallbackOnDemand>::isOpen<RemoteModule>() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_isOpenORemoteModule(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcReadPortData<SystemModule>(uint64_t address, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortDataOSystemModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcReadPortData<InterfaceModule>(uint64_t address, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortDataOInterfaceModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcReadPortData<DeviceModule>(uint64_t address, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortDataODeviceModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcReadPortData<StreamModule>(uint64_t address, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortDataOStreamModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcReadPortData<RemoteModule>(uint64_t address, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortDataORemoteModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortData<SystemModule>(uint64_t address, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortDataOSystemModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortData<InterfaceModule>(uint64_t address, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortDataOInterfaceModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortData<DeviceModule>(uint64_t address, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortDataODeviceModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortData<StreamModule>(uint64_t address, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortDataOStreamModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortData<RemoteModule>(uint64_t address, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortDataORemoteModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline std::vector<char> EGrabber<CallbackOnDemand>::gcReadPort<SystemModule>(uint64_t address, size_t size) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortOSystemModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<char> EGrabber<CallbackOnDemand>::gcReadPort<InterfaceModule>(uint64_t address, size_t size) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortOInterfaceModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<char> EGrabber<CallbackOnDemand>::gcReadPort<DeviceModule>(uint64_t address, size_t size) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortODeviceModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<char> EGrabber<CallbackOnDemand>::gcReadPort<StreamModule>(uint64_t address, size_t size) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortOStreamModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<char> EGrabber<CallbackOnDemand>::gcReadPort<RemoteModule>(uint64_t address, size_t size) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortORemoteModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePort<SystemModule>(uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortOSystemModuleFu64Svc(box, address, dataBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePort<InterfaceModule>(uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortOInterfaceModuleFu64Svc(box, address, dataBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePort<DeviceModule>(uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortODeviceModuleFu64Svc(box, address, dataBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePort<StreamModule>(uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortOStreamModuleFu64Svc(box, address, dataBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePort<RemoteModule>(uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortORemoteModuleFu64Svc(box, address, dataBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackOnDemand>::gcReadPortValue<SystemModule>(uint64_t address) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAsOSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackOnDemand>::gcReadPortValue<SystemModule>(uint64_t address) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi8OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackOnDemand>::gcReadPortValue<SystemModule>(uint64_t address) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi16OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackOnDemand>::gcReadPortValue<SystemModule>(uint64_t address) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi32OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackOnDemand>::gcReadPortValue<SystemModule>(uint64_t address) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi64OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackOnDemand>::gcReadPortValue<SystemModule>(uint64_t address) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu8OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackOnDemand>::gcReadPortValue<SystemModule>(uint64_t address) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu16OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackOnDemand>::gcReadPortValue<SystemModule>(uint64_t address) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu32OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackOnDemand>::gcReadPortValue<SystemModule>(uint64_t address) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu64OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackOnDemand>::gcReadPortValue<SystemModule>(uint64_t address) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAdOSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackOnDemand>::gcReadPortValue<SystemModule>(uint64_t address) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAfOSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackOnDemand>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAsOInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackOnDemand>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi8OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackOnDemand>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi16OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackOnDemand>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi32OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackOnDemand>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi64OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackOnDemand>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu8OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackOnDemand>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu16OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackOnDemand>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu32OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackOnDemand>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu64OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackOnDemand>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAdOInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackOnDemand>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAfOInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackOnDemand>::gcReadPortValue<DeviceModule>(uint64_t address) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAsODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackOnDemand>::gcReadPortValue<DeviceModule>(uint64_t address) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi8ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackOnDemand>::gcReadPortValue<DeviceModule>(uint64_t address) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi16ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackOnDemand>::gcReadPortValue<DeviceModule>(uint64_t address) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi32ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackOnDemand>::gcReadPortValue<DeviceModule>(uint64_t address) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi64ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackOnDemand>::gcReadPortValue<DeviceModule>(uint64_t address) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu8ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackOnDemand>::gcReadPortValue<DeviceModule>(uint64_t address) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu16ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackOnDemand>::gcReadPortValue<DeviceModule>(uint64_t address) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu32ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackOnDemand>::gcReadPortValue<DeviceModule>(uint64_t address) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu64ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackOnDemand>::gcReadPortValue<DeviceModule>(uint64_t address) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAdODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackOnDemand>::gcReadPortValue<DeviceModule>(uint64_t address) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAfODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackOnDemand>::gcReadPortValue<StreamModule>(uint64_t address) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAsOStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackOnDemand>::gcReadPortValue<StreamModule>(uint64_t address) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi8OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackOnDemand>::gcReadPortValue<StreamModule>(uint64_t address) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi16OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackOnDemand>::gcReadPortValue<StreamModule>(uint64_t address) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi32OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackOnDemand>::gcReadPortValue<StreamModule>(uint64_t address) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi64OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackOnDemand>::gcReadPortValue<StreamModule>(uint64_t address) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu8OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackOnDemand>::gcReadPortValue<StreamModule>(uint64_t address) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu16OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackOnDemand>::gcReadPortValue<StreamModule>(uint64_t address) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu32OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackOnDemand>::gcReadPortValue<StreamModule>(uint64_t address) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu64OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackOnDemand>::gcReadPortValue<StreamModule>(uint64_t address) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAdOStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackOnDemand>::gcReadPortValue<StreamModule>(uint64_t address) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAfOStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackOnDemand>::gcReadPortValue<RemoteModule>(uint64_t address) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAsORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackOnDemand>::gcReadPortValue<RemoteModule>(uint64_t address) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi8ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackOnDemand>::gcReadPortValue<RemoteModule>(uint64_t address) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi16ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackOnDemand>::gcReadPortValue<RemoteModule>(uint64_t address) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi32ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackOnDemand>::gcReadPortValue<RemoteModule>(uint64_t address) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAi64ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackOnDemand>::gcReadPortValue<RemoteModule>(uint64_t address) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu8ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackOnDemand>::gcReadPortValue<RemoteModule>(uint64_t address) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu16ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackOnDemand>::gcReadPortValue<RemoteModule>(uint64_t address) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu32ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackOnDemand>::gcReadPortValue<RemoteModule>(uint64_t address) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAu64ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackOnDemand>::gcReadPortValue<RemoteModule>(uint64_t address) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAdORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackOnDemand>::gcReadPortValue<RemoteModule>(uint64_t address) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortValueAfORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<SystemModule>(uint64_t address, size_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWsOSystemModuleFu64s(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<SystemModule>(uint64_t address, int8_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi8OSystemModuleFu64i8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<SystemModule>(uint64_t address, int16_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi16OSystemModuleFu64i16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<SystemModule>(uint64_t address, int32_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi32OSystemModuleFu64i32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<SystemModule>(uint64_t address, int64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi64OSystemModuleFu64i64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<SystemModule>(uint64_t address, uint8_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu8OSystemModuleFu64u8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<SystemModule>(uint64_t address, uint16_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu16OSystemModuleFu64u16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<SystemModule>(uint64_t address, uint32_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu32OSystemModuleFu64u32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<SystemModule>(uint64_t address, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu64OSystemModuleFu64u64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<SystemModule>(uint64_t address, double value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWdOSystemModuleFu64d(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<SystemModule>(uint64_t address, float value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWfOSystemModuleFu64f(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<InterfaceModule>(uint64_t address, size_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWsOInterfaceModuleFu64s(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<InterfaceModule>(uint64_t address, int8_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi8OInterfaceModuleFu64i8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<InterfaceModule>(uint64_t address, int16_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi16OInterfaceModuleFu64i16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<InterfaceModule>(uint64_t address, int32_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi32OInterfaceModuleFu64i32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<InterfaceModule>(uint64_t address, int64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi64OInterfaceModuleFu64i64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<InterfaceModule>(uint64_t address, uint8_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu8OInterfaceModuleFu64u8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<InterfaceModule>(uint64_t address, uint16_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu16OInterfaceModuleFu64u16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<InterfaceModule>(uint64_t address, uint32_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu32OInterfaceModuleFu64u32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<InterfaceModule>(uint64_t address, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu64OInterfaceModuleFu64u64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<InterfaceModule>(uint64_t address, double value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWdOInterfaceModuleFu64d(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<InterfaceModule>(uint64_t address, float value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWfOInterfaceModuleFu64f(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<DeviceModule>(uint64_t address, size_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWsODeviceModuleFu64s(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<DeviceModule>(uint64_t address, int8_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi8ODeviceModuleFu64i8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<DeviceModule>(uint64_t address, int16_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi16ODeviceModuleFu64i16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<DeviceModule>(uint64_t address, int32_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi32ODeviceModuleFu64i32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<DeviceModule>(uint64_t address, int64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi64ODeviceModuleFu64i64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<DeviceModule>(uint64_t address, uint8_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu8ODeviceModuleFu64u8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<DeviceModule>(uint64_t address, uint16_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu16ODeviceModuleFu64u16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<DeviceModule>(uint64_t address, uint32_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu32ODeviceModuleFu64u32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<DeviceModule>(uint64_t address, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu64ODeviceModuleFu64u64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<DeviceModule>(uint64_t address, double value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWdODeviceModuleFu64d(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<DeviceModule>(uint64_t address, float value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWfODeviceModuleFu64f(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<StreamModule>(uint64_t address, size_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWsOStreamModuleFu64s(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<StreamModule>(uint64_t address, int8_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi8OStreamModuleFu64i8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<StreamModule>(uint64_t address, int16_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi16OStreamModuleFu64i16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<StreamModule>(uint64_t address, int32_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi32OStreamModuleFu64i32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<StreamModule>(uint64_t address, int64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi64OStreamModuleFu64i64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<StreamModule>(uint64_t address, uint8_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu8OStreamModuleFu64u8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<StreamModule>(uint64_t address, uint16_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu16OStreamModuleFu64u16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<StreamModule>(uint64_t address, uint32_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu32OStreamModuleFu64u32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<StreamModule>(uint64_t address, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu64OStreamModuleFu64u64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<StreamModule>(uint64_t address, double value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWdOStreamModuleFu64d(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<StreamModule>(uint64_t address, float value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWfOStreamModuleFu64f(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<RemoteModule>(uint64_t address, size_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWsORemoteModuleFu64s(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<RemoteModule>(uint64_t address, int8_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi8ORemoteModuleFu64i8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<RemoteModule>(uint64_t address, int16_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi16ORemoteModuleFu64i16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<RemoteModule>(uint64_t address, int32_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi32ORemoteModuleFu64i32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<RemoteModule>(uint64_t address, int64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWi64ORemoteModuleFu64i64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<RemoteModule>(uint64_t address, uint8_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu8ORemoteModuleFu64u8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<RemoteModule>(uint64_t address, uint16_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu16ORemoteModuleFu64u16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<RemoteModule>(uint64_t address, uint32_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu32ORemoteModuleFu64u32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<RemoteModule>(uint64_t address, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWu64ORemoteModuleFu64u64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<RemoteModule>(uint64_t address, double value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWdORemoteModuleFu64d(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::gcWritePortValue<RemoteModule>(uint64_t address, float value) {
    int status = getGenTL().egrabberDll.euEGCOD_gcWritePortValueWfORemoteModuleFu64f(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline std::string EGrabber<CallbackOnDemand>::gcReadPortString<SystemModule>(uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortStringOSystemModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackOnDemand>::gcReadPortString<InterfaceModule>(uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortStringOInterfaceModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackOnDemand>::gcReadPortString<DeviceModule>(uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortStringODeviceModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackOnDemand>::gcReadPortString<StreamModule>(uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortStringOStreamModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackOnDemand>::gcReadPortString<RemoteModule>(uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_gcReadPortStringORemoteModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline int64_t EGrabber<CallbackOnDemand>::getInteger<SystemModule>(const std::string & feature) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getIntegerOSystemModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackOnDemand>::getInteger<InterfaceModule>(const std::string & feature) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getIntegerOInterfaceModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackOnDemand>::getInteger<DeviceModule>(const std::string & feature) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getIntegerODeviceModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackOnDemand>::getInteger<StreamModule>(const std::string & feature) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getIntegerOStreamModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackOnDemand>::getInteger<RemoteModule>(const std::string & feature) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getIntegerORemoteModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackOnDemand>::getFloat<SystemModule>(const std::string & feature) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getFloatOSystemModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackOnDemand>::getFloat<InterfaceModule>(const std::string & feature) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getFloatOInterfaceModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackOnDemand>::getFloat<DeviceModule>(const std::string & feature) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getFloatODeviceModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackOnDemand>::getFloat<StreamModule>(const std::string & feature) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getFloatOStreamModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackOnDemand>::getFloat<RemoteModule>(const std::string & feature) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getFloatORemoteModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackOnDemand>::getString<SystemModule>(const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getStringOSystemModuleFccp(box, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackOnDemand>::getString<InterfaceModule>(const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getStringOInterfaceModuleFccp(box, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackOnDemand>::getString<DeviceModule>(const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getStringODeviceModuleFccp(box, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackOnDemand>::getString<StreamModule>(const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getStringOStreamModuleFccp(box, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackOnDemand>::getString<RemoteModule>(const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getStringORemoteModuleFccp(box, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void EGrabber<CallbackOnDemand>::getStringData<SystemModule>(const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGCOD_getStringDataOSystemModuleFccpSvc(box, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::getStringData<InterfaceModule>(const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGCOD_getStringDataOInterfaceModuleFccpSvc(box, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::getStringData<DeviceModule>(const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGCOD_getStringDataODeviceModuleFccpSvc(box, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::getStringData<StreamModule>(const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGCOD_getStringDataOStreamModuleFccpSvc(box, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::getStringData<RemoteModule>(const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGCOD_getStringDataORemoteModuleFccpSvc(box, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackOnDemand>::getStringList<SystemModule>(const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getStringListOSystemModuleFccp(box, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackOnDemand>::getStringList<InterfaceModule>(const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getStringListOInterfaceModuleFccp(box, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackOnDemand>::getStringList<DeviceModule>(const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getStringListODeviceModuleFccp(box, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackOnDemand>::getStringList<StreamModule>(const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getStringListOStreamModuleFccp(box, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackOnDemand>::getStringList<RemoteModule>(const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_getStringListORemoteModuleFccp(box, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void EGrabber<CallbackOnDemand>::getRegister<SystemModule>(const std::string & feature, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_getRegisterOSystemModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::getRegister<InterfaceModule>(const std::string & feature, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_getRegisterOInterfaceModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::getRegister<DeviceModule>(const std::string & feature, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_getRegisterODeviceModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::getRegister<StreamModule>(const std::string & feature, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_getRegisterOStreamModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::getRegister<RemoteModule>(const std::string & feature, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_getRegisterORemoteModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setInteger<SystemModule>(const std::string & feature, int64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_setIntegerOSystemModuleFccpi64(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setInteger<InterfaceModule>(const std::string & feature, int64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_setIntegerOInterfaceModuleFccpi64(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setInteger<DeviceModule>(const std::string & feature, int64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_setIntegerODeviceModuleFccpi64(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setInteger<StreamModule>(const std::string & feature, int64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_setIntegerOStreamModuleFccpi64(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setInteger<RemoteModule>(const std::string & feature, int64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_setIntegerORemoteModuleFccpi64(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setFloat<SystemModule>(const std::string & feature, double value) {
    int status = getGenTL().egrabberDll.euEGCOD_setFloatOSystemModuleFccpd(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setFloat<InterfaceModule>(const std::string & feature, double value) {
    int status = getGenTL().egrabberDll.euEGCOD_setFloatOInterfaceModuleFccpd(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setFloat<DeviceModule>(const std::string & feature, double value) {
    int status = getGenTL().egrabberDll.euEGCOD_setFloatODeviceModuleFccpd(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setFloat<StreamModule>(const std::string & feature, double value) {
    int status = getGenTL().egrabberDll.euEGCOD_setFloatOStreamModuleFccpd(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setFloat<RemoteModule>(const std::string & feature, double value) {
    int status = getGenTL().egrabberDll.euEGCOD_setFloatORemoteModuleFccpd(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setString<SystemModule>(const std::string & feature, const std::string & value) {
    int status = getGenTL().egrabberDll.euEGCOD_setStringOSystemModuleFccpccp(box, feature.c_str(), value.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setString<InterfaceModule>(const std::string & feature, const std::string & value) {
    int status = getGenTL().egrabberDll.euEGCOD_setStringOInterfaceModuleFccpccp(box, feature.c_str(), value.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setString<DeviceModule>(const std::string & feature, const std::string & value) {
    int status = getGenTL().egrabberDll.euEGCOD_setStringODeviceModuleFccpccp(box, feature.c_str(), value.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setString<StreamModule>(const std::string & feature, const std::string & value) {
    int status = getGenTL().egrabberDll.euEGCOD_setStringOStreamModuleFccpccp(box, feature.c_str(), value.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setString<RemoteModule>(const std::string & feature, const std::string & value) {
    int status = getGenTL().egrabberDll.euEGCOD_setStringORemoteModuleFccpccp(box, feature.c_str(), value.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setRegister<SystemModule>(const std::string & feature, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_setRegisterOSystemModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setRegister<InterfaceModule>(const std::string & feature, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_setRegisterOInterfaceModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setRegister<DeviceModule>(const std::string & feature, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_setRegisterODeviceModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setRegister<StreamModule>(const std::string & feature, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_setRegisterOStreamModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::setRegister<RemoteModule>(const std::string & feature, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_setRegisterORemoteModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::execute<SystemModule>(const std::string & command) {
    int status = getGenTL().egrabberDll.euEGCOD_executeOSystemModuleFccp(box, command.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::execute<InterfaceModule>(const std::string & command) {
    int status = getGenTL().egrabberDll.euEGCOD_executeOInterfaceModuleFccp(box, command.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::execute<DeviceModule>(const std::string & command) {
    int status = getGenTL().egrabberDll.euEGCOD_executeODeviceModuleFccp(box, command.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::execute<StreamModule>(const std::string & command) {
    int status = getGenTL().egrabberDll.euEGCOD_executeOStreamModuleFccp(box, command.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::execute<RemoteModule>(const std::string & command) {
    int status = getGenTL().egrabberDll.euEGCOD_executeORemoteModuleFccp(box, command.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::attachEvent<SystemModule>(uint64_t eventId, const void * buffer, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_attachEventOSystemModuleFu64vps(box, eventId, buffer, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::attachEvent<InterfaceModule>(uint64_t eventId, const void * buffer, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_attachEventOInterfaceModuleFu64vps(box, eventId, buffer, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::attachEvent<DeviceModule>(uint64_t eventId, const void * buffer, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_attachEventODeviceModuleFu64vps(box, eventId, buffer, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::attachEvent<StreamModule>(uint64_t eventId, const void * buffer, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_attachEventOStreamModuleFu64vps(box, eventId, buffer, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::attachEvent<RemoteModule>(uint64_t eventId, const void * buffer, size_t size) {
    int status = getGenTL().egrabberDll.euEGCOD_attachEventORemoteModuleFu64vps(box, eventId, buffer, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::invalidate<SystemModule>(const std::string & feature) {
    int status = getGenTL().egrabberDll.euEGCOD_invalidateOSystemModuleFccp(box, feature.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::invalidate<InterfaceModule>(const std::string & feature) {
    int status = getGenTL().egrabberDll.euEGCOD_invalidateOInterfaceModuleFccp(box, feature.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::invalidate<DeviceModule>(const std::string & feature) {
    int status = getGenTL().egrabberDll.euEGCOD_invalidateODeviceModuleFccp(box, feature.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::invalidate<StreamModule>(const std::string & feature) {
    int status = getGenTL().egrabberDll.euEGCOD_invalidateOStreamModuleFccp(box, feature.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::invalidate<RemoteModule>(const std::string & feature) {
    int status = getGenTL().egrabberDll.euEGCOD_invalidateORemoteModuleFccp(box, feature.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::runScript(const std::string & script, void * context) {
    int status = getGenTL().egrabberDll.euEGCOD_runScriptFccpvp(box, script.c_str(), context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::interruptScript(const std::string & scriptId) {
    int status = getGenTL().egrabberDll.euEGCOD_interruptScriptFccp(box, scriptId.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline ge::GENAPI_UI_CALLBACK_RET_CODE EGrabber<CallbackOnDemand>::onScriptUiCallback(const std::string & operation, void * context, const std::map<std::string, std::string> & args, std::string & value) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onScriptUiCallback default implementation");
    return ge::GENAPI_UI_CALLBACK_RET_NOT_IMPLEMENTED;
}
template <> inline void EGrabber<CallbackOnDemand>::memento(const std::string & text) {
    int status = getGenTL().egrabberDll.euEGCOD_mementoFccp(box, text.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::memento(unsigned char verbosity, unsigned char kind, const std::string & text) {
    int status = getGenTL().egrabberDll.euEGCOD_mementoFucucccp(box, verbosity, kind, text.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::mementoWaveUp(unsigned char kind, unsigned char id) {
    int status = getGenTL().egrabberDll.euEGCOD_mementoWaveUpFucuc(box, kind, id);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::mementoWaveDown(unsigned char kind, unsigned char id) {
    int status = getGenTL().egrabberDll.euEGCOD_mementoWaveDownFucuc(box, kind, id);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::mementoWaveReset(unsigned char kind, unsigned char id) {
    int status = getGenTL().egrabberDll.euEGCOD_mementoWaveResetFucuc(box, kind, id);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::mementoWaveValue(unsigned char kind, unsigned char id, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGCOD_mementoWaveValueFucucu64(box, kind, id, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::mementoWaveNoValue(unsigned char kind, unsigned char id) {
    int status = getGenTL().egrabberDll.euEGCOD_mementoWaveNoValueFucuc(box, kind, id);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::enableEvent<NewBufferData>() {
    int status = getGenTL().egrabberDll.euEGCOD_enableEventWNewBufferData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::enableEvent<IoToolboxData>() {
    int status = getGenTL().egrabberDll.euEGCOD_enableEventWIoToolboxData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::enableEvent<CicData>() {
    int status = getGenTL().egrabberDll.euEGCOD_enableEventWCicData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::enableEvent<DataStreamData>() {
    int status = getGenTL().egrabberDll.euEGCOD_enableEventWDataStreamData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::enableEvent<CxpInterfaceData>() {
    int status = getGenTL().egrabberDll.euEGCOD_enableEventWCxpInterfaceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::enableEvent<DeviceErrorData>() {
    int status = getGenTL().egrabberDll.euEGCOD_enableEventWDeviceErrorData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::enableEvent<CxpDeviceData>() {
    int status = getGenTL().egrabberDll.euEGCOD_enableEventWCxpDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::enableEvent<RemoteDeviceData>() {
    int status = getGenTL().egrabberDll.euEGCOD_enableEventWRemoteDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::enableEvent<All>() {
    int status = getGenTL().egrabberDll.euEGCOD_enableEventWAll(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::disableEvent<NewBufferData>() {
    int status = getGenTL().egrabberDll.euEGCOD_disableEventWNewBufferData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::disableEvent<IoToolboxData>() {
    int status = getGenTL().egrabberDll.euEGCOD_disableEventWIoToolboxData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::disableEvent<CicData>() {
    int status = getGenTL().egrabberDll.euEGCOD_disableEventWCicData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::disableEvent<DataStreamData>() {
    int status = getGenTL().egrabberDll.euEGCOD_disableEventWDataStreamData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::disableEvent<CxpInterfaceData>() {
    int status = getGenTL().egrabberDll.euEGCOD_disableEventWCxpInterfaceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::disableEvent<DeviceErrorData>() {
    int status = getGenTL().egrabberDll.euEGCOD_disableEventWDeviceErrorData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::disableEvent<CxpDeviceData>() {
    int status = getGenTL().egrabberDll.euEGCOD_disableEventWCxpDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::disableEvent<RemoteDeviceData>() {
    int status = getGenTL().egrabberDll.euEGCOD_disableEventWRemoteDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::disableEvent<All>() {
    int status = getGenTL().egrabberDll.euEGCOD_disableEventWAll(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::flushEvent<NewBufferData>() {
    int status = getGenTL().egrabberDll.euEGCOD_flushEventWNewBufferData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::flushEvent<IoToolboxData>() {
    int status = getGenTL().egrabberDll.euEGCOD_flushEventWIoToolboxData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::flushEvent<CicData>() {
    int status = getGenTL().egrabberDll.euEGCOD_flushEventWCicData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::flushEvent<DataStreamData>() {
    int status = getGenTL().egrabberDll.euEGCOD_flushEventWDataStreamData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::flushEvent<CxpInterfaceData>() {
    int status = getGenTL().egrabberDll.euEGCOD_flushEventWCxpInterfaceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::flushEvent<DeviceErrorData>() {
    int status = getGenTL().egrabberDll.euEGCOD_flushEventWDeviceErrorData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::flushEvent<CxpDeviceData>() {
    int status = getGenTL().egrabberDll.euEGCOD_flushEventWCxpDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::flushEvent<RemoteDeviceData>() {
    int status = getGenTL().egrabberDll.euEGCOD_flushEventWRemoteDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::flushEvent<All>() {
    int status = getGenTL().egrabberDll.euEGCOD_flushEventWAll(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline NewBufferData EGrabber<CallbackOnDemand>::pop(uint64_t timeout) {
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGCOD_popFu64(box, timeout, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void EGrabber<CallbackOnDemand>::cancelPop() {
    int status = getGenTL().egrabberDll.euEGCOD_cancelPop(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::processEvent<NewBufferData>(uint64_t timeout) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_processEventWNewBufferDataFu64(box, timeout, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::processEvent<IoToolboxData>(uint64_t timeout) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_processEventWIoToolboxDataFu64(box, timeout, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::processEvent<CicData>(uint64_t timeout) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_processEventWCicDataFu64(box, timeout, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::processEvent<DataStreamData>(uint64_t timeout) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_processEventWDataStreamDataFu64(box, timeout, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::processEvent<CxpInterfaceData>(uint64_t timeout) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_processEventWCxpInterfaceDataFu64(box, timeout, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::processEvent<DeviceErrorData>(uint64_t timeout) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_processEventWDeviceErrorDataFu64(box, timeout, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::processEvent<CxpDeviceData>(uint64_t timeout) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_processEventWCxpDeviceDataFu64(box, timeout, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::processEvent<RemoteDeviceData>(uint64_t timeout) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_processEventWRemoteDeviceDataFu64(box, timeout, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::processEvent<Any>(uint64_t timeout) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_processEventWAnyFu64(box, timeout, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline void EGrabber<CallbackOnDemand>::cancelEvent<NewBufferData>() {
    int status = getGenTL().egrabberDll.euEGCOD_cancelEventWNewBufferData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::cancelEvent<IoToolboxData>() {
    int status = getGenTL().egrabberDll.euEGCOD_cancelEventWIoToolboxData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::cancelEvent<CicData>() {
    int status = getGenTL().egrabberDll.euEGCOD_cancelEventWCicData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::cancelEvent<DataStreamData>() {
    int status = getGenTL().egrabberDll.euEGCOD_cancelEventWDataStreamData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::cancelEvent<CxpInterfaceData>() {
    int status = getGenTL().egrabberDll.euEGCOD_cancelEventWCxpInterfaceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::cancelEvent<DeviceErrorData>() {
    int status = getGenTL().egrabberDll.euEGCOD_cancelEventWDeviceErrorData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::cancelEvent<CxpDeviceData>() {
    int status = getGenTL().egrabberDll.euEGCOD_cancelEventWCxpDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::cancelEvent<RemoteDeviceData>() {
    int status = getGenTL().egrabberDll.euEGCOD_cancelEventWRemoteDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackOnDemand>::cancelEvent<Any>() {
    int status = getGenTL().egrabberDll.euEGCOD_cancelEventWAny(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::getPendingEventCount<NewBufferData>() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getPendingEventCountWNewBufferData(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::getPendingEventCount<IoToolboxData>() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getPendingEventCountWIoToolboxData(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::getPendingEventCount<CicData>() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getPendingEventCountWCicData(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::getPendingEventCount<DataStreamData>() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getPendingEventCountWDataStreamData(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::getPendingEventCount<CxpInterfaceData>() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getPendingEventCountWCxpInterfaceData(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::getPendingEventCount<DeviceErrorData>() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getPendingEventCountWDeviceErrorData(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::getPendingEventCount<CxpDeviceData>() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getPendingEventCountWCxpDeviceData(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::getPendingEventCount<RemoteDeviceData>() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getPendingEventCountWRemoteDeviceData(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline size_t EGrabber<CallbackOnDemand>::getPendingEventCount<Any>() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getPendingEventCountWAny(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline void EGrabber<CallbackOnDemand>::onNewBufferEvent(const NewBufferData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onNewBufferEvent default implementation");
}
template <> inline void EGrabber<CallbackOnDemand>::onIoToolboxEvent(const IoToolboxData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onIoToolboxEvent default implementation");
}
template <> inline void EGrabber<CallbackOnDemand>::onCicEvent(const CicData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onCicEvent default implementation");
}
template <> inline void EGrabber<CallbackOnDemand>::onDataStreamEvent(const DataStreamData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onDataStreamEvent default implementation");
}
template <> inline void EGrabber<CallbackOnDemand>::onCxpInterfaceEvent(const CxpInterfaceData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onCxpInterfaceEvent default implementation");
}
template <> inline void EGrabber<CallbackOnDemand>::onDeviceErrorEvent(const DeviceErrorData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onDeviceErrorEvent default implementation");
}
template <> inline void EGrabber<CallbackOnDemand>::onCxpDeviceEvent(const CxpDeviceData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onCxpDeviceEvent default implementation");
}
template <> inline void EGrabber<CallbackOnDemand>::onRemoteDeviceEvent(const RemoteDeviceData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onRemoteDeviceEvent default implementation");
}
template <> inline void EGrabber<CallbackOnDemand>::onThreadStart(EventType) {}
template <> inline void EGrabber<CallbackOnDemand>::onThreadStop(EventType) {}
template <> inline int EGrabber<CallbackOnDemand>::getLastEventGrabberIndex() {
    int returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getLastEventGrabberIndex(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline void EGrabber<CallbackOnDemand>::shutdown() {
    int status = getGenTL().egrabberDll.euEGCOD_shutdown(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::push(const NewBufferData & buffer) {
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> bufferBoxed(getGenTL().egrabberDll, buffer);
    int status = getGenTL().egrabberDll.euEGCOD_pushFEur_NewBufferData(box, bufferBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline size_t EGrabber<CallbackOnDemand>::popEventFilter(size_t eventFilter, uint64_t timeout, OneOfAll & oneOf, int * position) {
    size_t returnValue;
    Internal::PositionOneOfAll positiononeOf = {position, oneOf};
    Internal::Box<Internal::PositionOneOfAll, ce::Eur_OneOfAll> oneOfBoxed(getGenTL().egrabberDll, positiononeOf);
    int status = getGenTL().egrabberDll.euEGCOD_popEventFilterFsu64EurOOAi_p(box, eventFilter, timeout, oneOfBoxed.getBox(), position, &returnValue);
    oneOfBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline size_t EGrabber<CallbackOnDemand>::processEventFilter(size_t eventFilter, uint64_t timeout) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_processEventFilterFsu64(box, eventFilter, timeout, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline size_t EGrabber<CallbackOnDemand>::processEventFilter(size_t eventFilter) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_processEventFilterFs(box, eventFilter, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline void EGrabber<CallbackOnDemand>::cancelEventFilter(size_t eventFilter) {
    int status = getGenTL().egrabberDll.euEGCOD_cancelEventFilterFs(box, eventFilter);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline size_t EGrabber<CallbackOnDemand>::getPendingEventCountFilter(size_t eventFilter) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getPendingEventCountFilterFs(box, eventFilter, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline size_t EGrabber<CallbackOnDemand>::announceBusBuffer(uint64_t busAddress, size_t size, void * userPointer) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_announceBusBufferFu64svp(box, busAddress, size, userPointer, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline size_t EGrabber<CallbackOnDemand>::announceNvidiaRdmaBuffer(void * deviceAddress, size_t size, void * userPointer) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_announceNvidiaRdmaBufferFvpsvp(box, deviceAddress, size, userPointer, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline gc::PORT_HANDLE EGrabber<CallbackOnDemand>::getSystemPort(int ix) {
    gc::PORT_HANDLE returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getSystemPortFi(box, ix, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline gc::PORT_HANDLE EGrabber<CallbackOnDemand>::getInterfacePort(int ix) {
    gc::PORT_HANDLE returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getInterfacePortFi(box, ix, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline gc::PORT_HANDLE EGrabber<CallbackOnDemand>::getDevicePort(int ix) {
    gc::PORT_HANDLE returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getDevicePortFi(box, ix, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline gc::PORT_HANDLE EGrabber<CallbackOnDemand>::getStreamPort(int ix) {
    gc::PORT_HANDLE returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getStreamPortFi(box, ix, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline gc::PORT_HANDLE EGrabber<CallbackOnDemand>::getRemotePort(int ix) {
    gc::PORT_HANDLE returnValue;
    int status = getGenTL().egrabberDll.euEGCOD_getRemotePortFi(box, ix, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline EGrabber<CallbackOnDemand>::EGrabber(EGenTL & gentl, gc::TL_HANDLE tlh, gc::IF_HANDLE ifh, gc::DEV_HANDLE devh, gc::DS_HANDLE dsh)
: gentl(gentl), box(0) {
    int status = getGenTL().egrabberDll.euEGCOD_createFEur_EGenTLTHIHDHDH(gentl.getBox(), tlh, ifh, devh, dsh, &box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    setCallbacks();
}
template <> inline void EGrabber<CallbackOnDemand>::onNewBufferEventC(ce::Eur_EGrabberBase box, ce::Eur_NewBufferData data, void * context) {
    EGrabber<CallbackOnDemand> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackOnDemand> *>(context);
        Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onNewBufferEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackOnDemand>::onIoToolboxEventC(ce::Eur_EGrabberBase box, ce::Eur_IoToolboxData data, void * context) {
    EGrabber<CallbackOnDemand> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackOnDemand> *>(context);
        Internal::Box<IoToolboxData, ce::Eur_IoToolboxData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onIoToolboxEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackOnDemand>::onCicEventC(ce::Eur_EGrabberBase box, ce::Eur_CicData data, void * context) {
    EGrabber<CallbackOnDemand> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackOnDemand> *>(context);
        Internal::Box<CicData, ce::Eur_CicData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onCicEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackOnDemand>::onDataStreamEventC(ce::Eur_EGrabberBase box, ce::Eur_DataStreamData data, void * context) {
    EGrabber<CallbackOnDemand> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackOnDemand> *>(context);
        Internal::Box<DataStreamData, ce::Eur_DataStreamData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onDataStreamEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackOnDemand>::onCxpInterfaceEventC(ce::Eur_EGrabberBase box, ce::Eur_CxpInterfaceData data, void * context) {
    EGrabber<CallbackOnDemand> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackOnDemand> *>(context);
        Internal::Box<CxpInterfaceData, ce::Eur_CxpInterfaceData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onCxpInterfaceEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackOnDemand>::onDeviceErrorEventC(ce::Eur_EGrabberBase box, ce::Eur_DeviceErrorData data, void * context) {
    EGrabber<CallbackOnDemand> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackOnDemand> *>(context);
        Internal::Box<DeviceErrorData, ce::Eur_DeviceErrorData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onDeviceErrorEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackOnDemand>::onCxpDeviceEventC(ce::Eur_EGrabberBase box, ce::Eur_CxpDeviceData data, void * context) {
    EGrabber<CallbackOnDemand> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackOnDemand> *>(context);
        Internal::Box<CxpDeviceData, ce::Eur_CxpDeviceData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onCxpDeviceEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackOnDemand>::onRemoteDeviceEventC(ce::Eur_EGrabberBase box, ce::Eur_RemoteDeviceData data, void * context) {
    EGrabber<CallbackOnDemand> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackOnDemand> *>(context);
        Internal::Box<RemoteDeviceData, ce::Eur_RemoteDeviceData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onRemoteDeviceEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline ge::GENAPI_UI_CALLBACK_RET_CODE EGrabber<CallbackOnDemand>::onScriptUiCallbackC(ce::Eur_EGrabberBase box, const char * operation, void * context, ce::std_map_std_string_std_string args, ce::std_string value, void * callbackContext) {
    EGrabber<CallbackOnDemand> *grabber;
    ge::GENAPI_UI_CALLBACK_RET_CODE returnValue = ge::GENAPI_UI_CALLBACK_RET_FATAL_ERROR;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackOnDemand> *>(callbackContext);
        Internal::Box<std::map<std::string, std::string>, ce::std_map_std_string_std_string> argsBoxed(grabber->getGenTL().egrabberDll);
        argsBoxed.setBox(args);
        Internal::Box<std::string, ce::std_string> valueBoxed(grabber->getGenTL().egrabberDll);
        valueBoxed.setSharedBox(value);
        std::string valueUnboxed = valueBoxed.unbox();
        returnValue = grabber->onScriptUiCallback(operation, context, argsBoxed.unbox(), valueUnboxed);
        Internal::Box<std::string, ce::std_string> valueUnboxedBoxed(grabber->getGenTL().egrabberDll, valueUnboxed);
        valueBoxed.copyDataFrom(valueUnboxedBoxed);
    }
    EGRABBER_CALLBACK_CATCH
    return returnValue;
}
template <> inline void EGrabber<CallbackOnDemand>::onThreadStartC(ce::Eur_EGrabberBase, ce::cEventType, void *) {}
template <> inline void EGrabber<CallbackOnDemand>::onThreadStopC(ce::Eur_EGrabberBase, ce::cEventType, void *) {}
template <> inline void EGrabber<CallbackOnDemand>::setNewBufferEventCallback(ce::Euresys_NewBufferEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGCOD_setNewBufferEventCallbackF_NBECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::setIoToolboxEventCallback(ce::Euresys_IoToolboxEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGCOD_setIoToolboxEventCallbackF_ITECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::setCicEventCallback(ce::Euresys_CicEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGCOD_setCicEventCallbackF_CECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::setDataStreamEventCallback(ce::Euresys_DataStreamEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGCOD_setDataStreamEventCallbackF_DSECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::setCxpInterfaceEventCallback(ce::Euresys_CxpInterfaceEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGCOD_setCxpInterfaceEventCallbackF_CIECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::setDeviceErrorEventCallback(ce::Euresys_DeviceErrorEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGCOD_setDeviceErrorEventCallbackF_DEECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::setCxpDeviceEventCallback(ce::Euresys_CxpDeviceEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGCOD_setCxpDeviceEventCallbackF_CDECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::setRemoteDeviceEventCallback(ce::Euresys_RemoteDeviceEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGCOD_setRemoteDeviceEventCallbackF_RDECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::setScriptUiCallback(ce::Euresys_ScriptUiCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGCOD_setScriptUiCallbackFScriptUiCallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackOnDemand>::setThreadStartCallback(ce::Euresys_ThreadStartCallback, void *) {}
template <> inline void EGrabber<CallbackOnDemand>::setThreadStopCallback(ce::Euresys_ThreadStopCallback, void *) {}
template <> inline EGrabber<CallbackSingleThread>::EGrabber(EGenTL & gentl, int interfaceIndex, int deviceIndex, int dataStreamIndex, gc::DEVICE_ACCESS_FLAGS deviceOpenFlags, bool remoteRequired)
: gentl(gentl), box(0) {
    int status = getGenTL().egrabberDll.euEGST_createFEur_EGenTLiiiDAFb8(gentl.getBox(), interfaceIndex, deviceIndex, dataStreamIndex, deviceOpenFlags, static_cast<bool8_t>(remoteRequired), &box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    setCallbacks();
}
template <> inline EGrabber<CallbackSingleThread>::EGrabber(const EGrabberInfo & grabber, gc::DEVICE_ACCESS_FLAGS deviceOpenFlags, bool remoteRequired)
: gentl(*grabber.gentl), box(0) {
    Internal::Box<EGrabberInfo, ce::Eur_EGrabberInfo> grabberBoxed(getGenTL(), grabber);
    int status = getGenTL().egrabberDll.euEGST_createFEurEGInfoDAFb8(grabberBoxed.getBox(), deviceOpenFlags, static_cast<bool8_t>(remoteRequired), &box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    setCallbacks();
}
template <> inline EGrabber<CallbackSingleThread>::EGrabber(const EGrabberCameraInfo & camera, gc::DEVICE_ACCESS_FLAGS deviceOpenFlags)
: gentl(*camera.grabbers.at(0).gentl), box(0) {
    Internal::Box<EGrabberCameraInfo, ce::Eur_EGrabberCameraInfo> cameraBoxed(getGenTL(), camera);
    int status = getGenTL().egrabberDll.euEGST_createFEurEGCameraInfoDAF(cameraBoxed.getBox(), deviceOpenFlags, &box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    setCallbacks();
}
template <> inline EGrabber<CallbackSingleThread>::~EGrabber() {
    int status = getGenTL().egrabberDll.euEGST_destroy(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline BufferIndexRange EGrabber<CallbackSingleThread>::reallocBuffers(size_t bufferCount, size_t bufferSize) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_reallocBuffersFss(box, bufferCount, bufferSize, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackSingleThread>::announceAndQueue(const GenTLMemory & memory, size_t bufferCount) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<GenTLMemory, ce::Eur_GenTLMemory> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGST_announceAndQueueFEur_GenTLMemorys(box, memoryBoxed.getBox(), bufferCount, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackSingleThread>::announceAndQueue(const UserMemory & memory) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<UserMemory, ce::Eur_UserMemory> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGST_announceAndQueueFEur_UserMemory(box, memoryBoxed.getBox(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackSingleThread>::announceAndQueue(const UserMemoryArray & memory) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<UserMemoryArray, ce::Eur_UserMemoryArray> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGST_announceAndQueueFEur_UserMemoryArray(box, memoryBoxed.getBox(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackSingleThread>::announceAndQueue(const UserMemoryArray & memory, bool reverse) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<UserMemoryArray, ce::Eur_UserMemoryArray> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGST_announceAndQueueFEur_UserMemoryArrayb8(box, memoryBoxed.getBox(), static_cast<bool8_t>(reverse), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackSingleThread>::announceAndQueue(const BusMemory & memory) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<BusMemory, ce::Eur_BusMemory> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGST_announceAndQueueFEur_BusMemory(box, memoryBoxed.getBox(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackSingleThread>::announceAndQueue(const NvidiaRdmaMemory & memory) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<NvidiaRdmaMemory, ce::Eur_NvidiaRdmaMemory> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGST_announceAndQueueFEur_NvidiaRdmaMemory(box, memoryBoxed.getBox(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void EGrabber<CallbackSingleThread>::flushBuffers(gc::ACQ_QUEUE_TYPE operation) {
    int status = getGenTL().egrabberDll.euEGST_flushBuffersFAQT(box, operation);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::resetBufferQueue() {
    int status = getGenTL().egrabberDll.euEGST_resetBufferQueue(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::resetBufferQueue(const BufferIndexRange & range) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> rangeBoxed(getGenTL().egrabberDll, range);
    int status = getGenTL().egrabberDll.euEGST_resetBufferQueueFEur_BufferIndexRange(box, rangeBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::queue(const BufferIndexRange & range) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> rangeBoxed(getGenTL().egrabberDll, range);
    int status = getGenTL().egrabberDll.euEGST_queueFEur_BufferIndexRange(box, rangeBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::revoke(const BufferIndexRange & range) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> rangeBoxed(getGenTL().egrabberDll, range);
    int status = getGenTL().egrabberDll.euEGST_revokeFEur_BufferIndexRange(box, rangeBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline bool EGrabber<CallbackSingleThread>::shouldReannounceBuffers() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_shouldReannounceBuffers(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> inline bool EGrabber<CallbackSingleThread>::shouldReallocBuffers() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_shouldReallocBuffers(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> inline void EGrabber<CallbackSingleThread>::start(uint64_t frameCount, bool controlRemoteDevice) {
    int status = getGenTL().egrabberDll.euEGST_startFu64b8(box, frameCount, static_cast<bool8_t>(controlRemoteDevice));
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::stop() {
    int status = getGenTL().egrabberDll.euEGST_stop(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline size_t EGrabber<CallbackSingleThread>::getWidth() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getWidth(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline size_t EGrabber<CallbackSingleThread>::getHeight() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getHeight(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline size_t EGrabber<CallbackSingleThread>::getPayloadSize() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getPayloadSize(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGrabber<CallbackSingleThread>::getPixelFormat() {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getPixelFormat(box, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAsOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi8OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi16OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi32OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi64OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu8OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu16OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu32OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu64OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAdOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAfOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t * EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    uint8_t * returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu8pOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoASsOSystemModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void * EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    void * returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAvptrOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::vector<char> EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoASvcOSystemModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoASv_std_stringOSystemModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAb8OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline char * EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    char * returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAcptrOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline InfoCommandInfo EGrabber<CallbackSingleThread>::getInfo<SystemModule>(int32_t cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoA_CINFOOSystemModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAsOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi8OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi16OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi32OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi64OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu8OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu16OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu32OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu64OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAdOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAfOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t * EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    uint8_t * returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu8pOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoASsOInterfaceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void * EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    void * returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAvptrOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::vector<char> EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoASvcOInterfaceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoASv_std_stringOInterfaceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAb8OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline char * EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    char * returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAcptrOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline InfoCommandInfo EGrabber<CallbackSingleThread>::getInfo<InterfaceModule>(int32_t cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoA_CINFOOInterfaceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAsODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi8ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi16ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi32ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi64ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu8ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu16ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu32ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu64ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAdODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAfODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t * EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    uint8_t * returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu8pODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoASsODeviceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void * EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    void * returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAvptrODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::vector<char> EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoASvcODeviceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoASv_std_stringODeviceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAb8ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline char * EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    char * returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAcptrODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline InfoCommandInfo EGrabber<CallbackSingleThread>::getInfo<DeviceModule>(int32_t cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoA_CINFOODeviceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAsOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi8OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi16OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi32OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAi64OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu8OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu16OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu32OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu64OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAdOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAfOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t * EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    uint8_t * returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAu8pOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoASsOStreamModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void * EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    void * returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAvptrOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::vector<char> EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoASvcOStreamModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoASv_std_stringOStreamModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAb8OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline char * EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    char * returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInfoAcptrOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline InfoCommandInfo EGrabber<CallbackSingleThread>::getInfo<StreamModule>(int32_t cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getInfoA_CINFOOStreamModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoAsFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoAi8FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoAi16FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoAi32FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoAi64FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoAu8FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoAu16FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoAu32FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoAu64FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoAdFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoAfFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t * EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoAu8pFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoASsFsBIC(box, bufferIndex, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void * EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    void * returnValue;
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoAvptrFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::vector<char> EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoASvcFsBIC(box, bufferIndex, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoASv_std_stringFsBIC(box, bufferIndex, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoAb8FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline char * EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    char * returnValue;
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoAcptrFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline InfoCommandInfo EGrabber<CallbackSingleThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getBufferInfoA_CINFOFsBIC(box, bufferIndex, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline NewBufferData EGrabber<CallbackSingleThread>::getBufferData(size_t bufferIndex) {
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getBufferDataFs(box, bufferIndex, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackSingleThread>::isOpen<SystemModule>() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_isOpenOSystemModule(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline bool EGrabber<CallbackSingleThread>::isOpen<InterfaceModule>() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_isOpenOInterfaceModule(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline bool EGrabber<CallbackSingleThread>::isOpen<DeviceModule>() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_isOpenODeviceModule(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline bool EGrabber<CallbackSingleThread>::isOpen<StreamModule>() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_isOpenOStreamModule(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline bool EGrabber<CallbackSingleThread>::isOpen<RemoteModule>() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_isOpenORemoteModule(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcReadPortData<SystemModule>(uint64_t address, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_gcReadPortDataOSystemModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcReadPortData<InterfaceModule>(uint64_t address, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_gcReadPortDataOInterfaceModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcReadPortData<DeviceModule>(uint64_t address, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_gcReadPortDataODeviceModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcReadPortData<StreamModule>(uint64_t address, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_gcReadPortDataOStreamModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcReadPortData<RemoteModule>(uint64_t address, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_gcReadPortDataORemoteModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortData<SystemModule>(uint64_t address, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortDataOSystemModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortData<InterfaceModule>(uint64_t address, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortDataOInterfaceModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortData<DeviceModule>(uint64_t address, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortDataODeviceModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortData<StreamModule>(uint64_t address, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortDataOStreamModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortData<RemoteModule>(uint64_t address, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortDataORemoteModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline std::vector<char> EGrabber<CallbackSingleThread>::gcReadPort<SystemModule>(uint64_t address, size_t size) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_gcReadPortOSystemModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<char> EGrabber<CallbackSingleThread>::gcReadPort<InterfaceModule>(uint64_t address, size_t size) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_gcReadPortOInterfaceModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<char> EGrabber<CallbackSingleThread>::gcReadPort<DeviceModule>(uint64_t address, size_t size) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_gcReadPortODeviceModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<char> EGrabber<CallbackSingleThread>::gcReadPort<StreamModule>(uint64_t address, size_t size) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_gcReadPortOStreamModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<char> EGrabber<CallbackSingleThread>::gcReadPort<RemoteModule>(uint64_t address, size_t size) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_gcReadPortORemoteModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePort<SystemModule>(uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGST_gcWritePortOSystemModuleFu64Svc(box, address, dataBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePort<InterfaceModule>(uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGST_gcWritePortOInterfaceModuleFu64Svc(box, address, dataBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePort<DeviceModule>(uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGST_gcWritePortODeviceModuleFu64Svc(box, address, dataBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePort<StreamModule>(uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGST_gcWritePortOStreamModuleFu64Svc(box, address, dataBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePort<RemoteModule>(uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGST_gcWritePortORemoteModuleFu64Svc(box, address, dataBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackSingleThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAsOSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackSingleThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi8OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackSingleThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi16OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackSingleThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi32OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackSingleThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi64OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackSingleThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu8OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackSingleThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu16OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackSingleThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu32OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackSingleThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu64OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackSingleThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAdOSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackSingleThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAfOSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackSingleThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAsOInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackSingleThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi8OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackSingleThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi16OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackSingleThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi32OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackSingleThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi64OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackSingleThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu8OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackSingleThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu16OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackSingleThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu32OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackSingleThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu64OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackSingleThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAdOInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackSingleThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAfOInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackSingleThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAsODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackSingleThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi8ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackSingleThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi16ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackSingleThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi32ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackSingleThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi64ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackSingleThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu8ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackSingleThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu16ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackSingleThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu32ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackSingleThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu64ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackSingleThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAdODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackSingleThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAfODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackSingleThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAsOStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackSingleThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi8OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackSingleThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi16OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackSingleThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi32OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackSingleThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi64OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackSingleThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu8OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackSingleThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu16OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackSingleThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu32OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackSingleThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu64OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackSingleThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAdOStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackSingleThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAfOStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackSingleThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAsORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackSingleThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi8ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackSingleThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi16ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackSingleThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi32ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackSingleThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAi64ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackSingleThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu8ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackSingleThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu16ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackSingleThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu32ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackSingleThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAu64ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackSingleThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAdORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackSingleThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGST_gcReadPortValueAfORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<SystemModule>(uint64_t address, size_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWsOSystemModuleFu64s(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<SystemModule>(uint64_t address, int8_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi8OSystemModuleFu64i8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<SystemModule>(uint64_t address, int16_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi16OSystemModuleFu64i16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<SystemModule>(uint64_t address, int32_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi32OSystemModuleFu64i32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<SystemModule>(uint64_t address, int64_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi64OSystemModuleFu64i64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<SystemModule>(uint64_t address, uint8_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu8OSystemModuleFu64u8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<SystemModule>(uint64_t address, uint16_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu16OSystemModuleFu64u16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<SystemModule>(uint64_t address, uint32_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu32OSystemModuleFu64u32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<SystemModule>(uint64_t address, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu64OSystemModuleFu64u64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<SystemModule>(uint64_t address, double value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWdOSystemModuleFu64d(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<SystemModule>(uint64_t address, float value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWfOSystemModuleFu64f(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<InterfaceModule>(uint64_t address, size_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWsOInterfaceModuleFu64s(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<InterfaceModule>(uint64_t address, int8_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi8OInterfaceModuleFu64i8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<InterfaceModule>(uint64_t address, int16_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi16OInterfaceModuleFu64i16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<InterfaceModule>(uint64_t address, int32_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi32OInterfaceModuleFu64i32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<InterfaceModule>(uint64_t address, int64_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi64OInterfaceModuleFu64i64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<InterfaceModule>(uint64_t address, uint8_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu8OInterfaceModuleFu64u8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<InterfaceModule>(uint64_t address, uint16_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu16OInterfaceModuleFu64u16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<InterfaceModule>(uint64_t address, uint32_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu32OInterfaceModuleFu64u32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<InterfaceModule>(uint64_t address, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu64OInterfaceModuleFu64u64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<InterfaceModule>(uint64_t address, double value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWdOInterfaceModuleFu64d(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<InterfaceModule>(uint64_t address, float value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWfOInterfaceModuleFu64f(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<DeviceModule>(uint64_t address, size_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWsODeviceModuleFu64s(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<DeviceModule>(uint64_t address, int8_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi8ODeviceModuleFu64i8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<DeviceModule>(uint64_t address, int16_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi16ODeviceModuleFu64i16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<DeviceModule>(uint64_t address, int32_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi32ODeviceModuleFu64i32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<DeviceModule>(uint64_t address, int64_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi64ODeviceModuleFu64i64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<DeviceModule>(uint64_t address, uint8_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu8ODeviceModuleFu64u8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<DeviceModule>(uint64_t address, uint16_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu16ODeviceModuleFu64u16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<DeviceModule>(uint64_t address, uint32_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu32ODeviceModuleFu64u32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<DeviceModule>(uint64_t address, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu64ODeviceModuleFu64u64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<DeviceModule>(uint64_t address, double value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWdODeviceModuleFu64d(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<DeviceModule>(uint64_t address, float value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWfODeviceModuleFu64f(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<StreamModule>(uint64_t address, size_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWsOStreamModuleFu64s(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<StreamModule>(uint64_t address, int8_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi8OStreamModuleFu64i8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<StreamModule>(uint64_t address, int16_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi16OStreamModuleFu64i16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<StreamModule>(uint64_t address, int32_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi32OStreamModuleFu64i32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<StreamModule>(uint64_t address, int64_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi64OStreamModuleFu64i64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<StreamModule>(uint64_t address, uint8_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu8OStreamModuleFu64u8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<StreamModule>(uint64_t address, uint16_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu16OStreamModuleFu64u16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<StreamModule>(uint64_t address, uint32_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu32OStreamModuleFu64u32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<StreamModule>(uint64_t address, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu64OStreamModuleFu64u64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<StreamModule>(uint64_t address, double value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWdOStreamModuleFu64d(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<StreamModule>(uint64_t address, float value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWfOStreamModuleFu64f(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<RemoteModule>(uint64_t address, size_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWsORemoteModuleFu64s(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<RemoteModule>(uint64_t address, int8_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi8ORemoteModuleFu64i8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<RemoteModule>(uint64_t address, int16_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi16ORemoteModuleFu64i16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<RemoteModule>(uint64_t address, int32_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi32ORemoteModuleFu64i32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<RemoteModule>(uint64_t address, int64_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWi64ORemoteModuleFu64i64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<RemoteModule>(uint64_t address, uint8_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu8ORemoteModuleFu64u8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<RemoteModule>(uint64_t address, uint16_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu16ORemoteModuleFu64u16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<RemoteModule>(uint64_t address, uint32_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu32ORemoteModuleFu64u32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<RemoteModule>(uint64_t address, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWu64ORemoteModuleFu64u64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<RemoteModule>(uint64_t address, double value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWdORemoteModuleFu64d(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::gcWritePortValue<RemoteModule>(uint64_t address, float value) {
    int status = getGenTL().egrabberDll.euEGST_gcWritePortValueWfORemoteModuleFu64f(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline std::string EGrabber<CallbackSingleThread>::gcReadPortString<SystemModule>(uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_gcReadPortStringOSystemModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackSingleThread>::gcReadPortString<InterfaceModule>(uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_gcReadPortStringOInterfaceModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackSingleThread>::gcReadPortString<DeviceModule>(uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_gcReadPortStringODeviceModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackSingleThread>::gcReadPortString<StreamModule>(uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_gcReadPortStringOStreamModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackSingleThread>::gcReadPortString<RemoteModule>(uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_gcReadPortStringORemoteModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline int64_t EGrabber<CallbackSingleThread>::getInteger<SystemModule>(const std::string & feature) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getIntegerOSystemModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackSingleThread>::getInteger<InterfaceModule>(const std::string & feature) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getIntegerOInterfaceModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackSingleThread>::getInteger<DeviceModule>(const std::string & feature) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getIntegerODeviceModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackSingleThread>::getInteger<StreamModule>(const std::string & feature) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getIntegerOStreamModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackSingleThread>::getInteger<RemoteModule>(const std::string & feature) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_getIntegerORemoteModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackSingleThread>::getFloat<SystemModule>(const std::string & feature) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGST_getFloatOSystemModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackSingleThread>::getFloat<InterfaceModule>(const std::string & feature) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGST_getFloatOInterfaceModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackSingleThread>::getFloat<DeviceModule>(const std::string & feature) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGST_getFloatODeviceModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackSingleThread>::getFloat<StreamModule>(const std::string & feature) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGST_getFloatOStreamModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackSingleThread>::getFloat<RemoteModule>(const std::string & feature) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGST_getFloatORemoteModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackSingleThread>::getString<SystemModule>(const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getStringOSystemModuleFccp(box, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackSingleThread>::getString<InterfaceModule>(const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getStringOInterfaceModuleFccp(box, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackSingleThread>::getString<DeviceModule>(const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getStringODeviceModuleFccp(box, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackSingleThread>::getString<StreamModule>(const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getStringOStreamModuleFccp(box, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackSingleThread>::getString<RemoteModule>(const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getStringORemoteModuleFccp(box, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void EGrabber<CallbackSingleThread>::getStringData<SystemModule>(const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGST_getStringDataOSystemModuleFccpSvc(box, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::getStringData<InterfaceModule>(const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGST_getStringDataOInterfaceModuleFccpSvc(box, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::getStringData<DeviceModule>(const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGST_getStringDataODeviceModuleFccpSvc(box, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::getStringData<StreamModule>(const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGST_getStringDataOStreamModuleFccpSvc(box, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::getStringData<RemoteModule>(const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGST_getStringDataORemoteModuleFccpSvc(box, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackSingleThread>::getStringList<SystemModule>(const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getStringListOSystemModuleFccp(box, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackSingleThread>::getStringList<InterfaceModule>(const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getStringListOInterfaceModuleFccp(box, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackSingleThread>::getStringList<DeviceModule>(const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getStringListODeviceModuleFccp(box, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackSingleThread>::getStringList<StreamModule>(const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getStringListOStreamModuleFccp(box, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackSingleThread>::getStringList<RemoteModule>(const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGST_getStringListORemoteModuleFccp(box, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void EGrabber<CallbackSingleThread>::getRegister<SystemModule>(const std::string & feature, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_getRegisterOSystemModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::getRegister<InterfaceModule>(const std::string & feature, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_getRegisterOInterfaceModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::getRegister<DeviceModule>(const std::string & feature, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_getRegisterODeviceModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::getRegister<StreamModule>(const std::string & feature, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_getRegisterOStreamModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::getRegister<RemoteModule>(const std::string & feature, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_getRegisterORemoteModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setInteger<SystemModule>(const std::string & feature, int64_t value) {
    int status = getGenTL().egrabberDll.euEGST_setIntegerOSystemModuleFccpi64(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setInteger<InterfaceModule>(const std::string & feature, int64_t value) {
    int status = getGenTL().egrabberDll.euEGST_setIntegerOInterfaceModuleFccpi64(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setInteger<DeviceModule>(const std::string & feature, int64_t value) {
    int status = getGenTL().egrabberDll.euEGST_setIntegerODeviceModuleFccpi64(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setInteger<StreamModule>(const std::string & feature, int64_t value) {
    int status = getGenTL().egrabberDll.euEGST_setIntegerOStreamModuleFccpi64(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setInteger<RemoteModule>(const std::string & feature, int64_t value) {
    int status = getGenTL().egrabberDll.euEGST_setIntegerORemoteModuleFccpi64(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setFloat<SystemModule>(const std::string & feature, double value) {
    int status = getGenTL().egrabberDll.euEGST_setFloatOSystemModuleFccpd(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setFloat<InterfaceModule>(const std::string & feature, double value) {
    int status = getGenTL().egrabberDll.euEGST_setFloatOInterfaceModuleFccpd(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setFloat<DeviceModule>(const std::string & feature, double value) {
    int status = getGenTL().egrabberDll.euEGST_setFloatODeviceModuleFccpd(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setFloat<StreamModule>(const std::string & feature, double value) {
    int status = getGenTL().egrabberDll.euEGST_setFloatOStreamModuleFccpd(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setFloat<RemoteModule>(const std::string & feature, double value) {
    int status = getGenTL().egrabberDll.euEGST_setFloatORemoteModuleFccpd(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setString<SystemModule>(const std::string & feature, const std::string & value) {
    int status = getGenTL().egrabberDll.euEGST_setStringOSystemModuleFccpccp(box, feature.c_str(), value.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setString<InterfaceModule>(const std::string & feature, const std::string & value) {
    int status = getGenTL().egrabberDll.euEGST_setStringOInterfaceModuleFccpccp(box, feature.c_str(), value.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setString<DeviceModule>(const std::string & feature, const std::string & value) {
    int status = getGenTL().egrabberDll.euEGST_setStringODeviceModuleFccpccp(box, feature.c_str(), value.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setString<StreamModule>(const std::string & feature, const std::string & value) {
    int status = getGenTL().egrabberDll.euEGST_setStringOStreamModuleFccpccp(box, feature.c_str(), value.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setString<RemoteModule>(const std::string & feature, const std::string & value) {
    int status = getGenTL().egrabberDll.euEGST_setStringORemoteModuleFccpccp(box, feature.c_str(), value.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setRegister<SystemModule>(const std::string & feature, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_setRegisterOSystemModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setRegister<InterfaceModule>(const std::string & feature, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_setRegisterOInterfaceModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setRegister<DeviceModule>(const std::string & feature, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_setRegisterODeviceModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setRegister<StreamModule>(const std::string & feature, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_setRegisterOStreamModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::setRegister<RemoteModule>(const std::string & feature, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_setRegisterORemoteModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::execute<SystemModule>(const std::string & command) {
    int status = getGenTL().egrabberDll.euEGST_executeOSystemModuleFccp(box, command.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::execute<InterfaceModule>(const std::string & command) {
    int status = getGenTL().egrabberDll.euEGST_executeOInterfaceModuleFccp(box, command.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::execute<DeviceModule>(const std::string & command) {
    int status = getGenTL().egrabberDll.euEGST_executeODeviceModuleFccp(box, command.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::execute<StreamModule>(const std::string & command) {
    int status = getGenTL().egrabberDll.euEGST_executeOStreamModuleFccp(box, command.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::execute<RemoteModule>(const std::string & command) {
    int status = getGenTL().egrabberDll.euEGST_executeORemoteModuleFccp(box, command.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::attachEvent<SystemModule>(uint64_t eventId, const void * buffer, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_attachEventOSystemModuleFu64vps(box, eventId, buffer, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::attachEvent<InterfaceModule>(uint64_t eventId, const void * buffer, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_attachEventOInterfaceModuleFu64vps(box, eventId, buffer, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::attachEvent<DeviceModule>(uint64_t eventId, const void * buffer, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_attachEventODeviceModuleFu64vps(box, eventId, buffer, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::attachEvent<StreamModule>(uint64_t eventId, const void * buffer, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_attachEventOStreamModuleFu64vps(box, eventId, buffer, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::attachEvent<RemoteModule>(uint64_t eventId, const void * buffer, size_t size) {
    int status = getGenTL().egrabberDll.euEGST_attachEventORemoteModuleFu64vps(box, eventId, buffer, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::invalidate<SystemModule>(const std::string & feature) {
    int status = getGenTL().egrabberDll.euEGST_invalidateOSystemModuleFccp(box, feature.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::invalidate<InterfaceModule>(const std::string & feature) {
    int status = getGenTL().egrabberDll.euEGST_invalidateOInterfaceModuleFccp(box, feature.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::invalidate<DeviceModule>(const std::string & feature) {
    int status = getGenTL().egrabberDll.euEGST_invalidateODeviceModuleFccp(box, feature.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::invalidate<StreamModule>(const std::string & feature) {
    int status = getGenTL().egrabberDll.euEGST_invalidateOStreamModuleFccp(box, feature.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::invalidate<RemoteModule>(const std::string & feature) {
    int status = getGenTL().egrabberDll.euEGST_invalidateORemoteModuleFccp(box, feature.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::runScript(const std::string & script, void * context) {
    int status = getGenTL().egrabberDll.euEGST_runScriptFccpvp(box, script.c_str(), context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::interruptScript(const std::string & scriptId) {
    int status = getGenTL().egrabberDll.euEGST_interruptScriptFccp(box, scriptId.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline ge::GENAPI_UI_CALLBACK_RET_CODE EGrabber<CallbackSingleThread>::onScriptUiCallback(const std::string & operation, void * context, const std::map<std::string, std::string> & args, std::string & value) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onScriptUiCallback default implementation");
    return ge::GENAPI_UI_CALLBACK_RET_NOT_IMPLEMENTED;
}
template <> inline void EGrabber<CallbackSingleThread>::memento(const std::string & text) {
    int status = getGenTL().egrabberDll.euEGST_mementoFccp(box, text.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::memento(unsigned char verbosity, unsigned char kind, const std::string & text) {
    int status = getGenTL().egrabberDll.euEGST_mementoFucucccp(box, verbosity, kind, text.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::mementoWaveUp(unsigned char kind, unsigned char id) {
    int status = getGenTL().egrabberDll.euEGST_mementoWaveUpFucuc(box, kind, id);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::mementoWaveDown(unsigned char kind, unsigned char id) {
    int status = getGenTL().egrabberDll.euEGST_mementoWaveDownFucuc(box, kind, id);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::mementoWaveReset(unsigned char kind, unsigned char id) {
    int status = getGenTL().egrabberDll.euEGST_mementoWaveResetFucuc(box, kind, id);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::mementoWaveValue(unsigned char kind, unsigned char id, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGST_mementoWaveValueFucucu64(box, kind, id, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::mementoWaveNoValue(unsigned char kind, unsigned char id) {
    int status = getGenTL().egrabberDll.euEGST_mementoWaveNoValueFucuc(box, kind, id);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::enableEvent<NewBufferData>() {
    int status = getGenTL().egrabberDll.euEGST_enableEventWNewBufferData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::enableEvent<IoToolboxData>() {
    int status = getGenTL().egrabberDll.euEGST_enableEventWIoToolboxData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::enableEvent<CicData>() {
    int status = getGenTL().egrabberDll.euEGST_enableEventWCicData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::enableEvent<DataStreamData>() {
    int status = getGenTL().egrabberDll.euEGST_enableEventWDataStreamData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::enableEvent<CxpInterfaceData>() {
    int status = getGenTL().egrabberDll.euEGST_enableEventWCxpInterfaceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::enableEvent<DeviceErrorData>() {
    int status = getGenTL().egrabberDll.euEGST_enableEventWDeviceErrorData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::enableEvent<CxpDeviceData>() {
    int status = getGenTL().egrabberDll.euEGST_enableEventWCxpDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::enableEvent<RemoteDeviceData>() {
    int status = getGenTL().egrabberDll.euEGST_enableEventWRemoteDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::enableEvent<All>() {
    int status = getGenTL().egrabberDll.euEGST_enableEventWAll(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::disableEvent<NewBufferData>() {
    int status = getGenTL().egrabberDll.euEGST_disableEventWNewBufferData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::disableEvent<IoToolboxData>() {
    int status = getGenTL().egrabberDll.euEGST_disableEventWIoToolboxData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::disableEvent<CicData>() {
    int status = getGenTL().egrabberDll.euEGST_disableEventWCicData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::disableEvent<DataStreamData>() {
    int status = getGenTL().egrabberDll.euEGST_disableEventWDataStreamData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::disableEvent<CxpInterfaceData>() {
    int status = getGenTL().egrabberDll.euEGST_disableEventWCxpInterfaceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::disableEvent<DeviceErrorData>() {
    int status = getGenTL().egrabberDll.euEGST_disableEventWDeviceErrorData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::disableEvent<CxpDeviceData>() {
    int status = getGenTL().egrabberDll.euEGST_disableEventWCxpDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::disableEvent<RemoteDeviceData>() {
    int status = getGenTL().egrabberDll.euEGST_disableEventWRemoteDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::disableEvent<All>() {
    int status = getGenTL().egrabberDll.euEGST_disableEventWAll(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::flushEvent<NewBufferData>() {
    int status = getGenTL().egrabberDll.euEGST_flushEventWNewBufferData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::flushEvent<IoToolboxData>() {
    int status = getGenTL().egrabberDll.euEGST_flushEventWIoToolboxData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::flushEvent<CicData>() {
    int status = getGenTL().egrabberDll.euEGST_flushEventWCicData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::flushEvent<DataStreamData>() {
    int status = getGenTL().egrabberDll.euEGST_flushEventWDataStreamData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::flushEvent<CxpInterfaceData>() {
    int status = getGenTL().egrabberDll.euEGST_flushEventWCxpInterfaceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::flushEvent<DeviceErrorData>() {
    int status = getGenTL().egrabberDll.euEGST_flushEventWDeviceErrorData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::flushEvent<CxpDeviceData>() {
    int status = getGenTL().egrabberDll.euEGST_flushEventWCxpDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::flushEvent<RemoteDeviceData>() {
    int status = getGenTL().egrabberDll.euEGST_flushEventWRemoteDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackSingleThread>::flushEvent<All>() {
    int status = getGenTL().egrabberDll.euEGST_flushEventWAll(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::onNewBufferEvent(const NewBufferData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onNewBufferEvent default implementation");
}
template <> inline void EGrabber<CallbackSingleThread>::onIoToolboxEvent(const IoToolboxData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onIoToolboxEvent default implementation");
}
template <> inline void EGrabber<CallbackSingleThread>::onCicEvent(const CicData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onCicEvent default implementation");
}
template <> inline void EGrabber<CallbackSingleThread>::onDataStreamEvent(const DataStreamData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onDataStreamEvent default implementation");
}
template <> inline void EGrabber<CallbackSingleThread>::onCxpInterfaceEvent(const CxpInterfaceData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onCxpInterfaceEvent default implementation");
}
template <> inline void EGrabber<CallbackSingleThread>::onDeviceErrorEvent(const DeviceErrorData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onDeviceErrorEvent default implementation");
}
template <> inline void EGrabber<CallbackSingleThread>::onCxpDeviceEvent(const CxpDeviceData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onCxpDeviceEvent default implementation");
}
template <> inline void EGrabber<CallbackSingleThread>::onRemoteDeviceEvent(const RemoteDeviceData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onRemoteDeviceEvent default implementation");
}
template <> inline void EGrabber<CallbackSingleThread>::onThreadStart(EventType) {}
template <> inline void EGrabber<CallbackSingleThread>::onThreadStop(EventType) {}
template <> inline int EGrabber<CallbackSingleThread>::getLastEventGrabberIndex() {
    int returnValue;
    int status = getGenTL().egrabberDll.euEGST_getLastEventGrabberIndex(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline void EGrabber<CallbackSingleThread>::shutdown() {
    int status = getGenTL().egrabberDll.euEGST_shutdown(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::push(const NewBufferData & buffer) {
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> bufferBoxed(getGenTL().egrabberDll, buffer);
    int status = getGenTL().egrabberDll.euEGST_pushFEur_NewBufferData(box, bufferBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline size_t EGrabber<CallbackSingleThread>::announceBusBuffer(uint64_t busAddress, size_t size, void * userPointer) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_announceBusBufferFu64svp(box, busAddress, size, userPointer, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline size_t EGrabber<CallbackSingleThread>::announceNvidiaRdmaBuffer(void * deviceAddress, size_t size, void * userPointer) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGST_announceNvidiaRdmaBufferFvpsvp(box, deviceAddress, size, userPointer, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline gc::PORT_HANDLE EGrabber<CallbackSingleThread>::getSystemPort(int ix) {
    gc::PORT_HANDLE returnValue;
    int status = getGenTL().egrabberDll.euEGST_getSystemPortFi(box, ix, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline gc::PORT_HANDLE EGrabber<CallbackSingleThread>::getInterfacePort(int ix) {
    gc::PORT_HANDLE returnValue;
    int status = getGenTL().egrabberDll.euEGST_getInterfacePortFi(box, ix, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline gc::PORT_HANDLE EGrabber<CallbackSingleThread>::getDevicePort(int ix) {
    gc::PORT_HANDLE returnValue;
    int status = getGenTL().egrabberDll.euEGST_getDevicePortFi(box, ix, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline gc::PORT_HANDLE EGrabber<CallbackSingleThread>::getStreamPort(int ix) {
    gc::PORT_HANDLE returnValue;
    int status = getGenTL().egrabberDll.euEGST_getStreamPortFi(box, ix, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline gc::PORT_HANDLE EGrabber<CallbackSingleThread>::getRemotePort(int ix) {
    gc::PORT_HANDLE returnValue;
    int status = getGenTL().egrabberDll.euEGST_getRemotePortFi(box, ix, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline EGrabber<CallbackSingleThread>::EGrabber(EGenTL & gentl, gc::TL_HANDLE tlh, gc::IF_HANDLE ifh, gc::DEV_HANDLE devh, gc::DS_HANDLE dsh)
: gentl(gentl), box(0) {
    int status = getGenTL().egrabberDll.euEGST_createFEur_EGenTLTHIHDHDH(gentl.getBox(), tlh, ifh, devh, dsh, &box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    setCallbacks();
}
template <> inline void EGrabber<CallbackSingleThread>::onNewBufferEventC(ce::Eur_EGrabberBase box, ce::Eur_NewBufferData data, void * context) {
    EGrabber<CallbackSingleThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackSingleThread> *>(context);
        Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onNewBufferEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackSingleThread>::onIoToolboxEventC(ce::Eur_EGrabberBase box, ce::Eur_IoToolboxData data, void * context) {
    EGrabber<CallbackSingleThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackSingleThread> *>(context);
        Internal::Box<IoToolboxData, ce::Eur_IoToolboxData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onIoToolboxEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackSingleThread>::onCicEventC(ce::Eur_EGrabberBase box, ce::Eur_CicData data, void * context) {
    EGrabber<CallbackSingleThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackSingleThread> *>(context);
        Internal::Box<CicData, ce::Eur_CicData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onCicEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackSingleThread>::onDataStreamEventC(ce::Eur_EGrabberBase box, ce::Eur_DataStreamData data, void * context) {
    EGrabber<CallbackSingleThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackSingleThread> *>(context);
        Internal::Box<DataStreamData, ce::Eur_DataStreamData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onDataStreamEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackSingleThread>::onCxpInterfaceEventC(ce::Eur_EGrabberBase box, ce::Eur_CxpInterfaceData data, void * context) {
    EGrabber<CallbackSingleThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackSingleThread> *>(context);
        Internal::Box<CxpInterfaceData, ce::Eur_CxpInterfaceData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onCxpInterfaceEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackSingleThread>::onDeviceErrorEventC(ce::Eur_EGrabberBase box, ce::Eur_DeviceErrorData data, void * context) {
    EGrabber<CallbackSingleThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackSingleThread> *>(context);
        Internal::Box<DeviceErrorData, ce::Eur_DeviceErrorData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onDeviceErrorEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackSingleThread>::onCxpDeviceEventC(ce::Eur_EGrabberBase box, ce::Eur_CxpDeviceData data, void * context) {
    EGrabber<CallbackSingleThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackSingleThread> *>(context);
        Internal::Box<CxpDeviceData, ce::Eur_CxpDeviceData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onCxpDeviceEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackSingleThread>::onRemoteDeviceEventC(ce::Eur_EGrabberBase box, ce::Eur_RemoteDeviceData data, void * context) {
    EGrabber<CallbackSingleThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackSingleThread> *>(context);
        Internal::Box<RemoteDeviceData, ce::Eur_RemoteDeviceData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onRemoteDeviceEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline ge::GENAPI_UI_CALLBACK_RET_CODE EGrabber<CallbackSingleThread>::onScriptUiCallbackC(ce::Eur_EGrabberBase box, const char * operation, void * context, ce::std_map_std_string_std_string args, ce::std_string value, void * callbackContext) {
    EGrabber<CallbackSingleThread> *grabber;
    ge::GENAPI_UI_CALLBACK_RET_CODE returnValue = ge::GENAPI_UI_CALLBACK_RET_FATAL_ERROR;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackSingleThread> *>(callbackContext);
        Internal::Box<std::map<std::string, std::string>, ce::std_map_std_string_std_string> argsBoxed(grabber->getGenTL().egrabberDll);
        argsBoxed.setBox(args);
        Internal::Box<std::string, ce::std_string> valueBoxed(grabber->getGenTL().egrabberDll);
        valueBoxed.setSharedBox(value);
        std::string valueUnboxed = valueBoxed.unbox();
        returnValue = grabber->onScriptUiCallback(operation, context, argsBoxed.unbox(), valueUnboxed);
        Internal::Box<std::string, ce::std_string> valueUnboxedBoxed(grabber->getGenTL().egrabberDll, valueUnboxed);
        valueBoxed.copyDataFrom(valueUnboxedBoxed);
    }
    EGRABBER_CALLBACK_CATCH
    return returnValue;
}
template <> inline void EGrabber<CallbackSingleThread>::onThreadStartC(ce::Eur_EGrabberBase box, ce::cEventType type, void * context) {
    EGrabber<CallbackSingleThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackSingleThread> *>(context);
        grabber->onThreadStart(static_cast<EventType>(type));
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackSingleThread>::onThreadStopC(ce::Eur_EGrabberBase box, ce::cEventType type, void * context) {
    EGrabber<CallbackSingleThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackSingleThread> *>(context);
        grabber->onThreadStop(static_cast<EventType>(type));
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackSingleThread>::setNewBufferEventCallback(ce::Euresys_NewBufferEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGST_setNewBufferEventCallbackF_NBECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::setIoToolboxEventCallback(ce::Euresys_IoToolboxEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGST_setIoToolboxEventCallbackF_ITECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::setCicEventCallback(ce::Euresys_CicEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGST_setCicEventCallbackF_CECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::setDataStreamEventCallback(ce::Euresys_DataStreamEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGST_setDataStreamEventCallbackF_DSECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::setCxpInterfaceEventCallback(ce::Euresys_CxpInterfaceEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGST_setCxpInterfaceEventCallbackF_CIECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::setDeviceErrorEventCallback(ce::Euresys_DeviceErrorEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGST_setDeviceErrorEventCallbackF_DEECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::setCxpDeviceEventCallback(ce::Euresys_CxpDeviceEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGST_setCxpDeviceEventCallbackF_CDECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::setRemoteDeviceEventCallback(ce::Euresys_RemoteDeviceEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGST_setRemoteDeviceEventCallbackF_RDECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::setScriptUiCallback(ce::Euresys_ScriptUiCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGST_setScriptUiCallbackFScriptUiCallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::setThreadStartCallback(ce::Euresys_ThreadStartCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGST_setThreadStartCallbackF_TStartCvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackSingleThread>::setThreadStopCallback(ce::Euresys_ThreadStopCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGST_setThreadStopCallbackF_TStopCvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline EGrabber<CallbackMultiThread>::EGrabber(EGenTL & gentl, int interfaceIndex, int deviceIndex, int dataStreamIndex, gc::DEVICE_ACCESS_FLAGS deviceOpenFlags, bool remoteRequired)
: gentl(gentl), box(0) {
    int status = getGenTL().egrabberDll.euEGMT_createFEur_EGenTLiiiDAFb8(gentl.getBox(), interfaceIndex, deviceIndex, dataStreamIndex, deviceOpenFlags, static_cast<bool8_t>(remoteRequired), &box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    setCallbacks();
}
template <> inline EGrabber<CallbackMultiThread>::EGrabber(const EGrabberInfo & grabber, gc::DEVICE_ACCESS_FLAGS deviceOpenFlags, bool remoteRequired)
: gentl(*grabber.gentl), box(0) {
    Internal::Box<EGrabberInfo, ce::Eur_EGrabberInfo> grabberBoxed(getGenTL(), grabber);
    int status = getGenTL().egrabberDll.euEGMT_createFEurEGInfoDAFb8(grabberBoxed.getBox(), deviceOpenFlags, static_cast<bool8_t>(remoteRequired), &box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    setCallbacks();
}
template <> inline EGrabber<CallbackMultiThread>::EGrabber(const EGrabberCameraInfo & camera, gc::DEVICE_ACCESS_FLAGS deviceOpenFlags)
: gentl(*camera.grabbers.at(0).gentl), box(0) {
    Internal::Box<EGrabberCameraInfo, ce::Eur_EGrabberCameraInfo> cameraBoxed(getGenTL(), camera);
    int status = getGenTL().egrabberDll.euEGMT_createFEurEGCameraInfoDAF(cameraBoxed.getBox(), deviceOpenFlags, &box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    setCallbacks();
}
template <> inline EGrabber<CallbackMultiThread>::~EGrabber() {
    int status = getGenTL().egrabberDll.euEGMT_destroy(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline BufferIndexRange EGrabber<CallbackMultiThread>::reallocBuffers(size_t bufferCount, size_t bufferSize) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_reallocBuffersFss(box, bufferCount, bufferSize, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackMultiThread>::announceAndQueue(const GenTLMemory & memory, size_t bufferCount) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<GenTLMemory, ce::Eur_GenTLMemory> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGMT_announceAndQueueFEur_GenTLMemorys(box, memoryBoxed.getBox(), bufferCount, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackMultiThread>::announceAndQueue(const UserMemory & memory) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<UserMemory, ce::Eur_UserMemory> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGMT_announceAndQueueFEur_UserMemory(box, memoryBoxed.getBox(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackMultiThread>::announceAndQueue(const UserMemoryArray & memory) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<UserMemoryArray, ce::Eur_UserMemoryArray> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGMT_announceAndQueueFEur_UserMemoryArray(box, memoryBoxed.getBox(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackMultiThread>::announceAndQueue(const UserMemoryArray & memory, bool reverse) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<UserMemoryArray, ce::Eur_UserMemoryArray> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGMT_announceAndQueueFEur_UserMemoryArrayb8(box, memoryBoxed.getBox(), static_cast<bool8_t>(reverse), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackMultiThread>::announceAndQueue(const BusMemory & memory) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<BusMemory, ce::Eur_BusMemory> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGMT_announceAndQueueFEur_BusMemory(box, memoryBoxed.getBox(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferIndexRange EGrabber<CallbackMultiThread>::announceAndQueue(const NvidiaRdmaMemory & memory) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> returnBoxed(getGenTL().egrabberDll);
    Internal::Box<NvidiaRdmaMemory, ce::Eur_NvidiaRdmaMemory> memoryBoxed(getGenTL().egrabberDll, memory);
    int status = getGenTL().egrabberDll.euEGMT_announceAndQueueFEur_NvidiaRdmaMemory(box, memoryBoxed.getBox(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void EGrabber<CallbackMultiThread>::flushBuffers(gc::ACQ_QUEUE_TYPE operation) {
    int status = getGenTL().egrabberDll.euEGMT_flushBuffersFAQT(box, operation);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::resetBufferQueue() {
    int status = getGenTL().egrabberDll.euEGMT_resetBufferQueue(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::resetBufferQueue(const BufferIndexRange & range) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> rangeBoxed(getGenTL().egrabberDll, range);
    int status = getGenTL().egrabberDll.euEGMT_resetBufferQueueFEur_BufferIndexRange(box, rangeBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::queue(const BufferIndexRange & range) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> rangeBoxed(getGenTL().egrabberDll, range);
    int status = getGenTL().egrabberDll.euEGMT_queueFEur_BufferIndexRange(box, rangeBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::revoke(const BufferIndexRange & range) {
    Internal::Box<BufferIndexRange, ce::Eur_BufferIndexRange> rangeBoxed(getGenTL().egrabberDll, range);
    int status = getGenTL().egrabberDll.euEGMT_revokeFEur_BufferIndexRange(box, rangeBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline bool EGrabber<CallbackMultiThread>::shouldReannounceBuffers() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_shouldReannounceBuffers(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> inline bool EGrabber<CallbackMultiThread>::shouldReallocBuffers() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_shouldReallocBuffers(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> inline void EGrabber<CallbackMultiThread>::start(uint64_t frameCount, bool controlRemoteDevice) {
    int status = getGenTL().egrabberDll.euEGMT_startFu64b8(box, frameCount, static_cast<bool8_t>(controlRemoteDevice));
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::stop() {
    int status = getGenTL().egrabberDll.euEGMT_stop(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline size_t EGrabber<CallbackMultiThread>::getWidth() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getWidth(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline size_t EGrabber<CallbackMultiThread>::getHeight() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getHeight(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline size_t EGrabber<CallbackMultiThread>::getPayloadSize() {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getPayloadSize(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGrabber<CallbackMultiThread>::getPixelFormat() {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getPixelFormat(box, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAsOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi8OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi16OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi32OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi64OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu8OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu16OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu32OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu64OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAdOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAfOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t * EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    uint8_t * returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu8pOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoASsOSystemModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void * EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    void * returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAvptrOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::vector<char> EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoASvcOSystemModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoASv_std_stringOSystemModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAb8OSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline char * EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    char * returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAcptrOSystemModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline InfoCommandInfo EGrabber<CallbackMultiThread>::getInfo<SystemModule>(int32_t cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoA_CINFOOSystemModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAsOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi8OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi16OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi32OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi64OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu8OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu16OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu32OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu64OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAdOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAfOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t * EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    uint8_t * returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu8pOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoASsOInterfaceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void * EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    void * returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAvptrOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::vector<char> EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoASvcOInterfaceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoASv_std_stringOInterfaceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAb8OInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline char * EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    char * returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAcptrOInterfaceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline InfoCommandInfo EGrabber<CallbackMultiThread>::getInfo<InterfaceModule>(int32_t cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoA_CINFOOInterfaceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAsODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi8ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi16ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi32ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi64ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu8ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu16ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu32ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu64ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAdODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAfODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t * EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    uint8_t * returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu8pODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoASsODeviceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void * EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    void * returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAvptrODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::vector<char> EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoASvcODeviceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoASv_std_stringODeviceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAb8ODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline char * EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    char * returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAcptrODeviceModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline InfoCommandInfo EGrabber<CallbackMultiThread>::getInfo<DeviceModule>(int32_t cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoA_CINFOODeviceModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAsOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi8OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi16OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi32OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAi64OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu8OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu16OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu32OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu64OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAdOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAfOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t * EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    uint8_t * returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAu8pOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoASsOStreamModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void * EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    void * returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAvptrOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::vector<char> EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoASvcOStreamModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoASv_std_stringOStreamModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAb8OStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline char * EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    char * returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInfoAcptrOStreamModuleFi32(box, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline InfoCommandInfo EGrabber<CallbackMultiThread>::getInfo<StreamModule>(int32_t cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getInfoA_CINFOOStreamModuleFi32(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoAsFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoAi8FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoAi16FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoAi32FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoAi64FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoAu8FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoAu16FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoAu32FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoAu64FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoAdFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoAfFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t * EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoAu8pFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoASsFsBIC(box, bufferIndex, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void * EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    void * returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoAvptrFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::vector<char> EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoASvcFsBIC(box, bufferIndex, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoASv_std_stringFsBIC(box, bufferIndex, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoAb8FsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline char * EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    char * returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoAcptrFsBIC(box, bufferIndex, cmd, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline InfoCommandInfo EGrabber<CallbackMultiThread>::getBufferInfo<>(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getBufferInfoA_CINFOFsBIC(box, bufferIndex, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline NewBufferData EGrabber<CallbackMultiThread>::getBufferData(size_t bufferIndex) {
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getBufferDataFs(box, bufferIndex, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline bool EGrabber<CallbackMultiThread>::isOpen<SystemModule>() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_isOpenOSystemModule(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline bool EGrabber<CallbackMultiThread>::isOpen<InterfaceModule>() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_isOpenOInterfaceModule(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline bool EGrabber<CallbackMultiThread>::isOpen<DeviceModule>() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_isOpenODeviceModule(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline bool EGrabber<CallbackMultiThread>::isOpen<StreamModule>() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_isOpenOStreamModule(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline bool EGrabber<CallbackMultiThread>::isOpen<RemoteModule>() {
    bool8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_isOpenORemoteModule(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcReadPortData<SystemModule>(uint64_t address, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortDataOSystemModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcReadPortData<InterfaceModule>(uint64_t address, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortDataOInterfaceModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcReadPortData<DeviceModule>(uint64_t address, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortDataODeviceModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcReadPortData<StreamModule>(uint64_t address, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortDataOStreamModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcReadPortData<RemoteModule>(uint64_t address, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortDataORemoteModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortData<SystemModule>(uint64_t address, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortDataOSystemModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortData<InterfaceModule>(uint64_t address, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortDataOInterfaceModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortData<DeviceModule>(uint64_t address, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortDataODeviceModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortData<StreamModule>(uint64_t address, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortDataOStreamModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortData<RemoteModule>(uint64_t address, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortDataORemoteModuleFu64vps(box, address, data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline std::vector<char> EGrabber<CallbackMultiThread>::gcReadPort<SystemModule>(uint64_t address, size_t size) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortOSystemModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<char> EGrabber<CallbackMultiThread>::gcReadPort<InterfaceModule>(uint64_t address, size_t size) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortOInterfaceModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<char> EGrabber<CallbackMultiThread>::gcReadPort<DeviceModule>(uint64_t address, size_t size) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortODeviceModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<char> EGrabber<CallbackMultiThread>::gcReadPort<StreamModule>(uint64_t address, size_t size) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortOStreamModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<char> EGrabber<CallbackMultiThread>::gcReadPort<RemoteModule>(uint64_t address, size_t size) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortORemoteModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePort<SystemModule>(uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortOSystemModuleFu64Svc(box, address, dataBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePort<InterfaceModule>(uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortOInterfaceModuleFu64Svc(box, address, dataBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePort<DeviceModule>(uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortODeviceModuleFu64Svc(box, address, dataBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePort<StreamModule>(uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortOStreamModuleFu64Svc(box, address, dataBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePort<RemoteModule>(uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortORemoteModuleFu64Svc(box, address, dataBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackMultiThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAsOSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackMultiThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi8OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackMultiThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi16OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackMultiThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi32OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackMultiThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi64OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackMultiThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu8OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackMultiThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu16OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackMultiThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu32OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackMultiThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu64OSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackMultiThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAdOSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackMultiThread>::gcReadPortValue<SystemModule>(uint64_t address) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAfOSystemModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackMultiThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAsOInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackMultiThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi8OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackMultiThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi16OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackMultiThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi32OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackMultiThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi64OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackMultiThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu8OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackMultiThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu16OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackMultiThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu32OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackMultiThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu64OInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackMultiThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAdOInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackMultiThread>::gcReadPortValue<InterfaceModule>(uint64_t address) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAfOInterfaceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackMultiThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAsODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackMultiThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi8ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackMultiThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi16ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackMultiThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi32ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackMultiThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi64ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackMultiThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu8ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackMultiThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu16ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackMultiThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu32ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackMultiThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu64ODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackMultiThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAdODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackMultiThread>::gcReadPortValue<DeviceModule>(uint64_t address) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAfODeviceModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackMultiThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAsOStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackMultiThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi8OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackMultiThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi16OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackMultiThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi32OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackMultiThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi64OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackMultiThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu8OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackMultiThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu16OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackMultiThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu32OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackMultiThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu64OStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackMultiThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAdOStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackMultiThread>::gcReadPortValue<StreamModule>(uint64_t address) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAfOStreamModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline size_t EGrabber<CallbackMultiThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAsORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline int8_t EGrabber<CallbackMultiThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    int8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi8ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int16_t EGrabber<CallbackMultiThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    int16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi16ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int32_t EGrabber<CallbackMultiThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    int32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi32ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackMultiThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAi64ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint8_t EGrabber<CallbackMultiThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    uint8_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu8ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint16_t EGrabber<CallbackMultiThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    uint16_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu16ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint32_t EGrabber<CallbackMultiThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    uint32_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu32ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline uint64_t EGrabber<CallbackMultiThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    uint64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAu64ORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackMultiThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAdORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline float EGrabber<CallbackMultiThread>::gcReadPortValue<RemoteModule>(uint64_t address) {
    float returnValue;
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortValueAfORemoteModuleFu64(box, address, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<SystemModule>(uint64_t address, size_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWsOSystemModuleFu64s(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<SystemModule>(uint64_t address, int8_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi8OSystemModuleFu64i8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<SystemModule>(uint64_t address, int16_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi16OSystemModuleFu64i16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<SystemModule>(uint64_t address, int32_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi32OSystemModuleFu64i32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<SystemModule>(uint64_t address, int64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi64OSystemModuleFu64i64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<SystemModule>(uint64_t address, uint8_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu8OSystemModuleFu64u8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<SystemModule>(uint64_t address, uint16_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu16OSystemModuleFu64u16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<SystemModule>(uint64_t address, uint32_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu32OSystemModuleFu64u32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<SystemModule>(uint64_t address, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu64OSystemModuleFu64u64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<SystemModule>(uint64_t address, double value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWdOSystemModuleFu64d(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<SystemModule>(uint64_t address, float value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWfOSystemModuleFu64f(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<InterfaceModule>(uint64_t address, size_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWsOInterfaceModuleFu64s(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<InterfaceModule>(uint64_t address, int8_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi8OInterfaceModuleFu64i8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<InterfaceModule>(uint64_t address, int16_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi16OInterfaceModuleFu64i16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<InterfaceModule>(uint64_t address, int32_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi32OInterfaceModuleFu64i32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<InterfaceModule>(uint64_t address, int64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi64OInterfaceModuleFu64i64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<InterfaceModule>(uint64_t address, uint8_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu8OInterfaceModuleFu64u8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<InterfaceModule>(uint64_t address, uint16_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu16OInterfaceModuleFu64u16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<InterfaceModule>(uint64_t address, uint32_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu32OInterfaceModuleFu64u32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<InterfaceModule>(uint64_t address, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu64OInterfaceModuleFu64u64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<InterfaceModule>(uint64_t address, double value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWdOInterfaceModuleFu64d(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<InterfaceModule>(uint64_t address, float value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWfOInterfaceModuleFu64f(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<DeviceModule>(uint64_t address, size_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWsODeviceModuleFu64s(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<DeviceModule>(uint64_t address, int8_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi8ODeviceModuleFu64i8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<DeviceModule>(uint64_t address, int16_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi16ODeviceModuleFu64i16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<DeviceModule>(uint64_t address, int32_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi32ODeviceModuleFu64i32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<DeviceModule>(uint64_t address, int64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi64ODeviceModuleFu64i64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<DeviceModule>(uint64_t address, uint8_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu8ODeviceModuleFu64u8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<DeviceModule>(uint64_t address, uint16_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu16ODeviceModuleFu64u16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<DeviceModule>(uint64_t address, uint32_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu32ODeviceModuleFu64u32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<DeviceModule>(uint64_t address, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu64ODeviceModuleFu64u64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<DeviceModule>(uint64_t address, double value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWdODeviceModuleFu64d(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<DeviceModule>(uint64_t address, float value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWfODeviceModuleFu64f(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<StreamModule>(uint64_t address, size_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWsOStreamModuleFu64s(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<StreamModule>(uint64_t address, int8_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi8OStreamModuleFu64i8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<StreamModule>(uint64_t address, int16_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi16OStreamModuleFu64i16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<StreamModule>(uint64_t address, int32_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi32OStreamModuleFu64i32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<StreamModule>(uint64_t address, int64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi64OStreamModuleFu64i64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<StreamModule>(uint64_t address, uint8_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu8OStreamModuleFu64u8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<StreamModule>(uint64_t address, uint16_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu16OStreamModuleFu64u16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<StreamModule>(uint64_t address, uint32_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu32OStreamModuleFu64u32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<StreamModule>(uint64_t address, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu64OStreamModuleFu64u64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<StreamModule>(uint64_t address, double value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWdOStreamModuleFu64d(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<StreamModule>(uint64_t address, float value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWfOStreamModuleFu64f(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<RemoteModule>(uint64_t address, size_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWsORemoteModuleFu64s(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<RemoteModule>(uint64_t address, int8_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi8ORemoteModuleFu64i8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<RemoteModule>(uint64_t address, int16_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi16ORemoteModuleFu64i16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<RemoteModule>(uint64_t address, int32_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi32ORemoteModuleFu64i32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<RemoteModule>(uint64_t address, int64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWi64ORemoteModuleFu64i64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<RemoteModule>(uint64_t address, uint8_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu8ORemoteModuleFu64u8(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<RemoteModule>(uint64_t address, uint16_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu16ORemoteModuleFu64u16(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<RemoteModule>(uint64_t address, uint32_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu32ORemoteModuleFu64u32(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<RemoteModule>(uint64_t address, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWu64ORemoteModuleFu64u64(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<RemoteModule>(uint64_t address, double value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWdORemoteModuleFu64d(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::gcWritePortValue<RemoteModule>(uint64_t address, float value) {
    int status = getGenTL().egrabberDll.euEGMT_gcWritePortValueWfORemoteModuleFu64f(box, address, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline std::string EGrabber<CallbackMultiThread>::gcReadPortString<SystemModule>(uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortStringOSystemModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackMultiThread>::gcReadPortString<InterfaceModule>(uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortStringOInterfaceModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackMultiThread>::gcReadPortString<DeviceModule>(uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortStringODeviceModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackMultiThread>::gcReadPortString<StreamModule>(uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortStringOStreamModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackMultiThread>::gcReadPortString<RemoteModule>(uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_gcReadPortStringORemoteModuleFu64s(box, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline int64_t EGrabber<CallbackMultiThread>::getInteger<SystemModule>(const std::string & feature) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getIntegerOSystemModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackMultiThread>::getInteger<InterfaceModule>(const std::string & feature) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getIntegerOInterfaceModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackMultiThread>::getInteger<DeviceModule>(const std::string & feature) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getIntegerODeviceModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackMultiThread>::getInteger<StreamModule>(const std::string & feature) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getIntegerOStreamModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline int64_t EGrabber<CallbackMultiThread>::getInteger<RemoteModule>(const std::string & feature) {
    int64_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getIntegerORemoteModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackMultiThread>::getFloat<SystemModule>(const std::string & feature) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getFloatOSystemModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackMultiThread>::getFloat<InterfaceModule>(const std::string & feature) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getFloatOInterfaceModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackMultiThread>::getFloat<DeviceModule>(const std::string & feature) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getFloatODeviceModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackMultiThread>::getFloat<StreamModule>(const std::string & feature) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getFloatOStreamModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline double EGrabber<CallbackMultiThread>::getFloat<RemoteModule>(const std::string & feature) {
    double returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getFloatORemoteModuleFccp(box, feature.c_str(), &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> template <> inline std::string EGrabber<CallbackMultiThread>::getString<SystemModule>(const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getStringOSystemModuleFccp(box, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackMultiThread>::getString<InterfaceModule>(const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getStringOInterfaceModuleFccp(box, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackMultiThread>::getString<DeviceModule>(const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getStringODeviceModuleFccp(box, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackMultiThread>::getString<StreamModule>(const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getStringOStreamModuleFccp(box, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::string EGrabber<CallbackMultiThread>::getString<RemoteModule>(const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getStringORemoteModuleFccp(box, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void EGrabber<CallbackMultiThread>::getStringData<SystemModule>(const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGMT_getStringDataOSystemModuleFccpSvc(box, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::getStringData<InterfaceModule>(const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGMT_getStringDataOInterfaceModuleFccpSvc(box, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::getStringData<DeviceModule>(const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGMT_getStringDataODeviceModuleFccpSvc(box, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::getStringData<StreamModule>(const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGMT_getStringDataOStreamModuleFccpSvc(box, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::getStringData<RemoteModule>(const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(getGenTL().egrabberDll, data);
    int status = getGenTL().egrabberDll.euEGMT_getStringDataORemoteModuleFccpSvc(box, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackMultiThread>::getStringList<SystemModule>(const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getStringListOSystemModuleFccp(box, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackMultiThread>::getStringList<InterfaceModule>(const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getStringListOInterfaceModuleFccp(box, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackMultiThread>::getStringList<DeviceModule>(const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getStringListODeviceModuleFccp(box, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackMultiThread>::getStringList<StreamModule>(const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getStringListOStreamModuleFccp(box, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline std::vector<std::string> EGrabber<CallbackMultiThread>::getStringList<RemoteModule>(const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(getGenTL().egrabberDll);
    int status = getGenTL().egrabberDll.euEGMT_getStringListORemoteModuleFccp(box, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> template <> inline void EGrabber<CallbackMultiThread>::getRegister<SystemModule>(const std::string & feature, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_getRegisterOSystemModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::getRegister<InterfaceModule>(const std::string & feature, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_getRegisterOInterfaceModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::getRegister<DeviceModule>(const std::string & feature, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_getRegisterODeviceModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::getRegister<StreamModule>(const std::string & feature, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_getRegisterOStreamModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::getRegister<RemoteModule>(const std::string & feature, void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_getRegisterORemoteModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setInteger<SystemModule>(const std::string & feature, int64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_setIntegerOSystemModuleFccpi64(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setInteger<InterfaceModule>(const std::string & feature, int64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_setIntegerOInterfaceModuleFccpi64(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setInteger<DeviceModule>(const std::string & feature, int64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_setIntegerODeviceModuleFccpi64(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setInteger<StreamModule>(const std::string & feature, int64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_setIntegerOStreamModuleFccpi64(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setInteger<RemoteModule>(const std::string & feature, int64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_setIntegerORemoteModuleFccpi64(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setFloat<SystemModule>(const std::string & feature, double value) {
    int status = getGenTL().egrabberDll.euEGMT_setFloatOSystemModuleFccpd(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setFloat<InterfaceModule>(const std::string & feature, double value) {
    int status = getGenTL().egrabberDll.euEGMT_setFloatOInterfaceModuleFccpd(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setFloat<DeviceModule>(const std::string & feature, double value) {
    int status = getGenTL().egrabberDll.euEGMT_setFloatODeviceModuleFccpd(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setFloat<StreamModule>(const std::string & feature, double value) {
    int status = getGenTL().egrabberDll.euEGMT_setFloatOStreamModuleFccpd(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setFloat<RemoteModule>(const std::string & feature, double value) {
    int status = getGenTL().egrabberDll.euEGMT_setFloatORemoteModuleFccpd(box, feature.c_str(), value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setString<SystemModule>(const std::string & feature, const std::string & value) {
    int status = getGenTL().egrabberDll.euEGMT_setStringOSystemModuleFccpccp(box, feature.c_str(), value.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setString<InterfaceModule>(const std::string & feature, const std::string & value) {
    int status = getGenTL().egrabberDll.euEGMT_setStringOInterfaceModuleFccpccp(box, feature.c_str(), value.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setString<DeviceModule>(const std::string & feature, const std::string & value) {
    int status = getGenTL().egrabberDll.euEGMT_setStringODeviceModuleFccpccp(box, feature.c_str(), value.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setString<StreamModule>(const std::string & feature, const std::string & value) {
    int status = getGenTL().egrabberDll.euEGMT_setStringOStreamModuleFccpccp(box, feature.c_str(), value.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setString<RemoteModule>(const std::string & feature, const std::string & value) {
    int status = getGenTL().egrabberDll.euEGMT_setStringORemoteModuleFccpccp(box, feature.c_str(), value.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setRegister<SystemModule>(const std::string & feature, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_setRegisterOSystemModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setRegister<InterfaceModule>(const std::string & feature, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_setRegisterOInterfaceModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setRegister<DeviceModule>(const std::string & feature, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_setRegisterODeviceModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setRegister<StreamModule>(const std::string & feature, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_setRegisterOStreamModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::setRegister<RemoteModule>(const std::string & feature, const void * data, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_setRegisterORemoteModuleFccpvps(box, feature.c_str(), data, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::execute<SystemModule>(const std::string & command) {
    int status = getGenTL().egrabberDll.euEGMT_executeOSystemModuleFccp(box, command.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::execute<InterfaceModule>(const std::string & command) {
    int status = getGenTL().egrabberDll.euEGMT_executeOInterfaceModuleFccp(box, command.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::execute<DeviceModule>(const std::string & command) {
    int status = getGenTL().egrabberDll.euEGMT_executeODeviceModuleFccp(box, command.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::execute<StreamModule>(const std::string & command) {
    int status = getGenTL().egrabberDll.euEGMT_executeOStreamModuleFccp(box, command.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::execute<RemoteModule>(const std::string & command) {
    int status = getGenTL().egrabberDll.euEGMT_executeORemoteModuleFccp(box, command.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::attachEvent<SystemModule>(uint64_t eventId, const void * buffer, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_attachEventOSystemModuleFu64vps(box, eventId, buffer, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::attachEvent<InterfaceModule>(uint64_t eventId, const void * buffer, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_attachEventOInterfaceModuleFu64vps(box, eventId, buffer, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::attachEvent<DeviceModule>(uint64_t eventId, const void * buffer, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_attachEventODeviceModuleFu64vps(box, eventId, buffer, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::attachEvent<StreamModule>(uint64_t eventId, const void * buffer, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_attachEventOStreamModuleFu64vps(box, eventId, buffer, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::attachEvent<RemoteModule>(uint64_t eventId, const void * buffer, size_t size) {
    int status = getGenTL().egrabberDll.euEGMT_attachEventORemoteModuleFu64vps(box, eventId, buffer, size);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::invalidate<SystemModule>(const std::string & feature) {
    int status = getGenTL().egrabberDll.euEGMT_invalidateOSystemModuleFccp(box, feature.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::invalidate<InterfaceModule>(const std::string & feature) {
    int status = getGenTL().egrabberDll.euEGMT_invalidateOInterfaceModuleFccp(box, feature.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::invalidate<DeviceModule>(const std::string & feature) {
    int status = getGenTL().egrabberDll.euEGMT_invalidateODeviceModuleFccp(box, feature.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::invalidate<StreamModule>(const std::string & feature) {
    int status = getGenTL().egrabberDll.euEGMT_invalidateOStreamModuleFccp(box, feature.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::invalidate<RemoteModule>(const std::string & feature) {
    int status = getGenTL().egrabberDll.euEGMT_invalidateORemoteModuleFccp(box, feature.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::runScript(const std::string & script, void * context) {
    int status = getGenTL().egrabberDll.euEGMT_runScriptFccpvp(box, script.c_str(), context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::interruptScript(const std::string & scriptId) {
    int status = getGenTL().egrabberDll.euEGMT_interruptScriptFccp(box, scriptId.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline ge::GENAPI_UI_CALLBACK_RET_CODE EGrabber<CallbackMultiThread>::onScriptUiCallback(const std::string & operation, void * context, const std::map<std::string, std::string> & args, std::string & value) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onScriptUiCallback default implementation");
    return ge::GENAPI_UI_CALLBACK_RET_NOT_IMPLEMENTED;
}
template <> inline void EGrabber<CallbackMultiThread>::memento(const std::string & text) {
    int status = getGenTL().egrabberDll.euEGMT_mementoFccp(box, text.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::memento(unsigned char verbosity, unsigned char kind, const std::string & text) {
    int status = getGenTL().egrabberDll.euEGMT_mementoFucucccp(box, verbosity, kind, text.c_str());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::mementoWaveUp(unsigned char kind, unsigned char id) {
    int status = getGenTL().egrabberDll.euEGMT_mementoWaveUpFucuc(box, kind, id);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::mementoWaveDown(unsigned char kind, unsigned char id) {
    int status = getGenTL().egrabberDll.euEGMT_mementoWaveDownFucuc(box, kind, id);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::mementoWaveReset(unsigned char kind, unsigned char id) {
    int status = getGenTL().egrabberDll.euEGMT_mementoWaveResetFucuc(box, kind, id);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::mementoWaveValue(unsigned char kind, unsigned char id, uint64_t value) {
    int status = getGenTL().egrabberDll.euEGMT_mementoWaveValueFucucu64(box, kind, id, value);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::mementoWaveNoValue(unsigned char kind, unsigned char id) {
    int status = getGenTL().egrabberDll.euEGMT_mementoWaveNoValueFucuc(box, kind, id);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::enableEvent<NewBufferData>() {
    int status = getGenTL().egrabberDll.euEGMT_enableEventWNewBufferData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::enableEvent<IoToolboxData>() {
    int status = getGenTL().egrabberDll.euEGMT_enableEventWIoToolboxData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::enableEvent<CicData>() {
    int status = getGenTL().egrabberDll.euEGMT_enableEventWCicData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::enableEvent<DataStreamData>() {
    int status = getGenTL().egrabberDll.euEGMT_enableEventWDataStreamData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::enableEvent<CxpInterfaceData>() {
    int status = getGenTL().egrabberDll.euEGMT_enableEventWCxpInterfaceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::enableEvent<DeviceErrorData>() {
    int status = getGenTL().egrabberDll.euEGMT_enableEventWDeviceErrorData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::enableEvent<CxpDeviceData>() {
    int status = getGenTL().egrabberDll.euEGMT_enableEventWCxpDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::enableEvent<RemoteDeviceData>() {
    int status = getGenTL().egrabberDll.euEGMT_enableEventWRemoteDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::enableEvent<All>() {
    int status = getGenTL().egrabberDll.euEGMT_enableEventWAll(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::disableEvent<NewBufferData>() {
    int status = getGenTL().egrabberDll.euEGMT_disableEventWNewBufferData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::disableEvent<IoToolboxData>() {
    int status = getGenTL().egrabberDll.euEGMT_disableEventWIoToolboxData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::disableEvent<CicData>() {
    int status = getGenTL().egrabberDll.euEGMT_disableEventWCicData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::disableEvent<DataStreamData>() {
    int status = getGenTL().egrabberDll.euEGMT_disableEventWDataStreamData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::disableEvent<CxpInterfaceData>() {
    int status = getGenTL().egrabberDll.euEGMT_disableEventWCxpInterfaceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::disableEvent<DeviceErrorData>() {
    int status = getGenTL().egrabberDll.euEGMT_disableEventWDeviceErrorData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::disableEvent<CxpDeviceData>() {
    int status = getGenTL().egrabberDll.euEGMT_disableEventWCxpDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::disableEvent<RemoteDeviceData>() {
    int status = getGenTL().egrabberDll.euEGMT_disableEventWRemoteDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::disableEvent<All>() {
    int status = getGenTL().egrabberDll.euEGMT_disableEventWAll(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::flushEvent<NewBufferData>() {
    int status = getGenTL().egrabberDll.euEGMT_flushEventWNewBufferData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::flushEvent<IoToolboxData>() {
    int status = getGenTL().egrabberDll.euEGMT_flushEventWIoToolboxData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::flushEvent<CicData>() {
    int status = getGenTL().egrabberDll.euEGMT_flushEventWCicData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::flushEvent<DataStreamData>() {
    int status = getGenTL().egrabberDll.euEGMT_flushEventWDataStreamData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::flushEvent<CxpInterfaceData>() {
    int status = getGenTL().egrabberDll.euEGMT_flushEventWCxpInterfaceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::flushEvent<DeviceErrorData>() {
    int status = getGenTL().egrabberDll.euEGMT_flushEventWDeviceErrorData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::flushEvent<CxpDeviceData>() {
    int status = getGenTL().egrabberDll.euEGMT_flushEventWCxpDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::flushEvent<RemoteDeviceData>() {
    int status = getGenTL().egrabberDll.euEGMT_flushEventWRemoteDeviceData(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> template <> inline void EGrabber<CallbackMultiThread>::flushEvent<All>() {
    int status = getGenTL().egrabberDll.euEGMT_flushEventWAll(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::onNewBufferEvent(const NewBufferData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onNewBufferEvent default implementation");
}
template <> inline void EGrabber<CallbackMultiThread>::onIoToolboxEvent(const IoToolboxData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onIoToolboxEvent default implementation");
}
template <> inline void EGrabber<CallbackMultiThread>::onCicEvent(const CicData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onCicEvent default implementation");
}
template <> inline void EGrabber<CallbackMultiThread>::onDataStreamEvent(const DataStreamData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onDataStreamEvent default implementation");
}
template <> inline void EGrabber<CallbackMultiThread>::onCxpInterfaceEvent(const CxpInterfaceData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onCxpInterfaceEvent default implementation");
}
template <> inline void EGrabber<CallbackMultiThread>::onDeviceErrorEvent(const DeviceErrorData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onDeviceErrorEvent default implementation");
}
template <> inline void EGrabber<CallbackMultiThread>::onCxpDeviceEvent(const CxpDeviceData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onCxpDeviceEvent default implementation");
}
template <> inline void EGrabber<CallbackMultiThread>::onRemoteDeviceEvent(const RemoteDeviceData & data) {
    gentl.memento(MEMENTO_VERBOSITY_WARNING, 0, "onRemoteDeviceEvent default implementation");
}
template <> inline void EGrabber<CallbackMultiThread>::onThreadStart(EventType) {}
template <> inline void EGrabber<CallbackMultiThread>::onThreadStop(EventType) {}
template <> inline int EGrabber<CallbackMultiThread>::getLastEventGrabberIndex() {
    int returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getLastEventGrabberIndex(box, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline void EGrabber<CallbackMultiThread>::shutdown() {
    int status = getGenTL().egrabberDll.euEGMT_shutdown(box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::push(const NewBufferData & buffer) {
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> bufferBoxed(getGenTL().egrabberDll, buffer);
    int status = getGenTL().egrabberDll.euEGMT_pushFEur_NewBufferData(box, bufferBoxed.getBox());
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline size_t EGrabber<CallbackMultiThread>::announceBusBuffer(uint64_t busAddress, size_t size, void * userPointer) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_announceBusBufferFu64svp(box, busAddress, size, userPointer, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline size_t EGrabber<CallbackMultiThread>::announceNvidiaRdmaBuffer(void * deviceAddress, size_t size, void * userPointer) {
    size_t returnValue;
    int status = getGenTL().egrabberDll.euEGMT_announceNvidiaRdmaBufferFvpsvp(box, deviceAddress, size, userPointer, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline gc::PORT_HANDLE EGrabber<CallbackMultiThread>::getSystemPort(int ix) {
    gc::PORT_HANDLE returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getSystemPortFi(box, ix, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline gc::PORT_HANDLE EGrabber<CallbackMultiThread>::getInterfacePort(int ix) {
    gc::PORT_HANDLE returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getInterfacePortFi(box, ix, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline gc::PORT_HANDLE EGrabber<CallbackMultiThread>::getDevicePort(int ix) {
    gc::PORT_HANDLE returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getDevicePortFi(box, ix, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline gc::PORT_HANDLE EGrabber<CallbackMultiThread>::getStreamPort(int ix) {
    gc::PORT_HANDLE returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getStreamPortFi(box, ix, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline gc::PORT_HANDLE EGrabber<CallbackMultiThread>::getRemotePort(int ix) {
    gc::PORT_HANDLE returnValue;
    int status = getGenTL().egrabberDll.euEGMT_getRemotePortFi(box, ix, &returnValue);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline EGrabber<CallbackMultiThread>::EGrabber(EGenTL & gentl, gc::TL_HANDLE tlh, gc::IF_HANDLE ifh, gc::DEV_HANDLE devh, gc::DS_HANDLE dsh)
: gentl(gentl), box(0) {
    int status = getGenTL().egrabberDll.euEGMT_createFEur_EGenTLTHIHDHDH(gentl.getBox(), tlh, ifh, devh, dsh, &box);
    Internal::checkStatus(getGenTL().egrabberDll, status);
    setCallbacks();
}
template <> inline void EGrabber<CallbackMultiThread>::onNewBufferEventC(ce::Eur_EGrabberBase box, ce::Eur_NewBufferData data, void * context) {
    EGrabber<CallbackMultiThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackMultiThread> *>(context);
        Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onNewBufferEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackMultiThread>::onIoToolboxEventC(ce::Eur_EGrabberBase box, ce::Eur_IoToolboxData data, void * context) {
    EGrabber<CallbackMultiThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackMultiThread> *>(context);
        Internal::Box<IoToolboxData, ce::Eur_IoToolboxData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onIoToolboxEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackMultiThread>::onCicEventC(ce::Eur_EGrabberBase box, ce::Eur_CicData data, void * context) {
    EGrabber<CallbackMultiThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackMultiThread> *>(context);
        Internal::Box<CicData, ce::Eur_CicData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onCicEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackMultiThread>::onDataStreamEventC(ce::Eur_EGrabberBase box, ce::Eur_DataStreamData data, void * context) {
    EGrabber<CallbackMultiThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackMultiThread> *>(context);
        Internal::Box<DataStreamData, ce::Eur_DataStreamData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onDataStreamEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackMultiThread>::onCxpInterfaceEventC(ce::Eur_EGrabberBase box, ce::Eur_CxpInterfaceData data, void * context) {
    EGrabber<CallbackMultiThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackMultiThread> *>(context);
        Internal::Box<CxpInterfaceData, ce::Eur_CxpInterfaceData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onCxpInterfaceEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackMultiThread>::onDeviceErrorEventC(ce::Eur_EGrabberBase box, ce::Eur_DeviceErrorData data, void * context) {
    EGrabber<CallbackMultiThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackMultiThread> *>(context);
        Internal::Box<DeviceErrorData, ce::Eur_DeviceErrorData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onDeviceErrorEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackMultiThread>::onCxpDeviceEventC(ce::Eur_EGrabberBase box, ce::Eur_CxpDeviceData data, void * context) {
    EGrabber<CallbackMultiThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackMultiThread> *>(context);
        Internal::Box<CxpDeviceData, ce::Eur_CxpDeviceData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onCxpDeviceEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackMultiThread>::onRemoteDeviceEventC(ce::Eur_EGrabberBase box, ce::Eur_RemoteDeviceData data, void * context) {
    EGrabber<CallbackMultiThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackMultiThread> *>(context);
        Internal::Box<RemoteDeviceData, ce::Eur_RemoteDeviceData> dataBoxed(grabber->getGenTL().egrabberDll);
        dataBoxed.setBox(data);
        grabber->onRemoteDeviceEvent(dataBoxed.unbox());
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline ge::GENAPI_UI_CALLBACK_RET_CODE EGrabber<CallbackMultiThread>::onScriptUiCallbackC(ce::Eur_EGrabberBase box, const char * operation, void * context, ce::std_map_std_string_std_string args, ce::std_string value, void * callbackContext) {
    EGrabber<CallbackMultiThread> *grabber;
    ge::GENAPI_UI_CALLBACK_RET_CODE returnValue = ge::GENAPI_UI_CALLBACK_RET_FATAL_ERROR;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackMultiThread> *>(callbackContext);
        Internal::Box<std::map<std::string, std::string>, ce::std_map_std_string_std_string> argsBoxed(grabber->getGenTL().egrabberDll);
        argsBoxed.setBox(args);
        Internal::Box<std::string, ce::std_string> valueBoxed(grabber->getGenTL().egrabberDll);
        valueBoxed.setSharedBox(value);
        std::string valueUnboxed = valueBoxed.unbox();
        returnValue = grabber->onScriptUiCallback(operation, context, argsBoxed.unbox(), valueUnboxed);
        Internal::Box<std::string, ce::std_string> valueUnboxedBoxed(grabber->getGenTL().egrabberDll, valueUnboxed);
        valueBoxed.copyDataFrom(valueUnboxedBoxed);
    }
    EGRABBER_CALLBACK_CATCH
    return returnValue;
}
template <> inline void EGrabber<CallbackMultiThread>::onThreadStartC(ce::Eur_EGrabberBase box, ce::cEventType type, void * context) {
    EGrabber<CallbackMultiThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackMultiThread> *>(context);
        grabber->onThreadStart(static_cast<EventType>(type));
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackMultiThread>::onThreadStopC(ce::Eur_EGrabberBase box, ce::cEventType type, void * context) {
    EGrabber<CallbackMultiThread> *grabber;
    try {
        grabber = reinterpret_cast<EGrabber<CallbackMultiThread> *>(context);
        grabber->onThreadStop(static_cast<EventType>(type));
    }
    EGRABBER_CALLBACK_CATCH
}
template <> inline void EGrabber<CallbackMultiThread>::setNewBufferEventCallback(ce::Euresys_NewBufferEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGMT_setNewBufferEventCallbackF_NBECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::setIoToolboxEventCallback(ce::Euresys_IoToolboxEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGMT_setIoToolboxEventCallbackF_ITECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::setCicEventCallback(ce::Euresys_CicEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGMT_setCicEventCallbackF_CECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::setDataStreamEventCallback(ce::Euresys_DataStreamEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGMT_setDataStreamEventCallbackF_DSECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::setCxpInterfaceEventCallback(ce::Euresys_CxpInterfaceEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGMT_setCxpInterfaceEventCallbackF_CIECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::setDeviceErrorEventCallback(ce::Euresys_DeviceErrorEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGMT_setDeviceErrorEventCallbackF_DEECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::setCxpDeviceEventCallback(ce::Euresys_CxpDeviceEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGMT_setCxpDeviceEventCallbackF_CDECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::setRemoteDeviceEventCallback(ce::Euresys_RemoteDeviceEventCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGMT_setRemoteDeviceEventCallbackF_RDECallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::setScriptUiCallback(ce::Euresys_ScriptUiCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGMT_setScriptUiCallbackFScriptUiCallbackvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::setThreadStartCallback(ce::Euresys_ThreadStartCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGMT_setThreadStartCallbackF_TStartCvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
template <> inline void EGrabber<CallbackMultiThread>::setThreadStopCallback(ce::Euresys_ThreadStopCallback callback, void * context) {
    int status = getGenTL().egrabberDll.euEGMT_setThreadStopCallbackF_TStopCvp(box, callback, context);
    Internal::checkStatus(getGenTL().egrabberDll, status);
}
} // namespace EURESYS_NAMESPACE

#endif // EURESYS_EGRABBER_GENERATED_HEADER_FILE
