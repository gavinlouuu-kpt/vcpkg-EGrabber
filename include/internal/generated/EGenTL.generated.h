/* Copyright Euresys 2021*/

#ifndef EURESYS_EGENTL_GENERATED_HEADER_FILE
#define EURESYS_EGENTL_GENERATED_HEADER_FILE

#include "../libutil.h"

namespace EURESYS_NAMESPACE {

inline EGenTL::EGenTL(const std::string & path, bool shared)
: egrabberDll(Internal::getEGrabberLibPath()), box(0) {
    int status = egrabberDll.euEGenTL_createFccpb8(path.c_str(), static_cast<bool8_t>(shared), &box);
    Internal::checkStatus(egrabberDll, status);
}
inline EGenTL::EGenTL(const char * path, bool shared)
: egrabberDll(Internal::getEGrabberLibPath()), box(0) {
    int status = egrabberDll.euEGenTL_createFcpb8(path, static_cast<bool8_t>(shared), &box);
    Internal::checkStatus(egrabberDll, status);
}
inline EGenTL::EGenTL(bool shared, const std::string & path)
: egrabberDll(Internal::getEGrabberLibPath()), box(0) {
    int status = egrabberDll.euEGenTL_createFb8ccp(static_cast<bool8_t>(shared), path.c_str(), &box);
    Internal::checkStatus(egrabberDll, status);
}
inline EGenTL::~EGenTL() {
    int status = egrabberDll.euEGenTL_destroy(box);
    Internal::checkStatus(egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    size_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetInfoAsFTIC(box, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    int8_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetInfoAi8FTIC(box, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int16_t EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    int16_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetInfoAi16FTIC(box, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int32_t EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    int32_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetInfoAi32FTIC(box, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int64_t EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    int64_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetInfoAi64FTIC(box, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetInfoAu8FTIC(box, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetInfoAu16FTIC(box, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetInfoAu32FTIC(box, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetInfoAu64FTIC(box, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline double EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    double returnValue;
    int status = egrabberDll.euEGenTL_gcGetInfoAdFTIC(box, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline float EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    float returnValue;
    int status = egrabberDll.euEGenTL_gcGetInfoAfFTIC(box, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = egrabberDll.euEGenTL_gcGetInfoAu8pFTIC(box, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_gcGetInfoASsFTIC(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    void * returnValue;
    int status = egrabberDll.euEGenTL_gcGetInfoAvptrFTIC(box, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_gcGetInfoASvcFTIC(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_gcGetInfoASv_std_stringFTIC(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetInfoAb8FTIC(box, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    char * returnValue;
    int status = egrabberDll.euEGenTL_gcGetInfoAcptrFTIC(box, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo EGenTL::gcGetInfo<>(gc::TL_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_gcGetInfoA_CINFOFTIC(box, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline void EGenTL::gcReadPort(gc::PORT_HANDLE ph, uint64_t address, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(egrabberDll, data);
    int status = egrabberDll.euEGenTL_gcReadPortFPHu64Svc(box, ph, address, dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(egrabberDll, status);
}
inline std::string EGenTL::gcReadPortString(gc::PORT_HANDLE ph, uint64_t address, size_t size) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_gcReadPortStringFPHu64s(box, ph, address, size, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline uint32_t EGenTL::gcReadPort(gc::PORT_HANDLE ph, uint64_t address) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_gcReadPortFPHu64(box, ph, address, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline void EGenTL::gcWritePort(gc::PORT_HANDLE ph, uint64_t address, const std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(egrabberDll, data);
    int status = egrabberDll.euEGenTL_gcWritePortFPHu64Svc(box, ph, address, dataBoxed.getBox());
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::gcReadPortData(gc::PORT_HANDLE ph, uint64_t address, void * data, size_t size) {
    int status = egrabberDll.euEGenTL_gcReadPortDataFPHu64vps(box, ph, address, data, size);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::gcWritePortData(gc::PORT_HANDLE ph, uint64_t address, const void * data, size_t size) {
    int status = egrabberDll.euEGenTL_gcWritePortDataFPHu64vps(box, ph, address, data, size);
    Internal::checkStatus(egrabberDll, status);
}
inline std::vector<std::string> EGenTL::gcGetPortURL(gc::PORT_HANDLE ph) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_gcGetPortURLFPH(box, ph, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    size_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortInfoAsFPHPIC(box, ph, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    int8_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortInfoAi8FPHPIC(box, ph, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int16_t EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    int16_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortInfoAi16FPHPIC(box, ph, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int32_t EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    int32_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortInfoAi32FPHPIC(box, ph, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int64_t EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    int64_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortInfoAi64FPHPIC(box, ph, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortInfoAu8FPHPIC(box, ph, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortInfoAu16FPHPIC(box, ph, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortInfoAu32FPHPIC(box, ph, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortInfoAu64FPHPIC(box, ph, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline double EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    double returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortInfoAdFPHPIC(box, ph, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline float EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    float returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortInfoAfFPHPIC(box, ph, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortInfoAu8pFPHPIC(box, ph, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_gcGetPortInfoASsFPHPIC(box, ph, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    void * returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortInfoAvptrFPHPIC(box, ph, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_gcGetPortInfoASvcFPHPIC(box, ph, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_gcGetPortInfoASv_std_stringFPHPIC(box, ph, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortInfoAb8FPHPIC(box, ph, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    char * returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortInfoAcptrFPHPIC(box, ph, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo EGenTL::gcGetPortInfo<>(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_gcGetPortInfoA_CINFOFPHPIC(box, ph, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline gc::EVENT_HANDLE EGenTL::gcRegisterEvent(gc::EVENTSRC_HANDLE h, gc::EVENT_TYPE event) {
    gc::EVENT_HANDLE returnValue;
    int status = egrabberDll.euEGenTL_gcRegisterEventFEHET(box, h, event, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline void EGenTL::gcUnregisterEvent(gc::EVENTSRC_HANDLE h, gc::EVENT_TYPE event) {
    int status = egrabberDll.euEGenTL_gcUnregisterEventFEHET(box, h, event);
    Internal::checkStatus(egrabberDll, status);
}
inline size_t EGenTL::eventGetData(gc::EVENT_HANDLE eh, void * buffer, size_t size, uint64_t timeout) {
    size_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataFEHvpsu64(box, eh, buffer, size, timeout, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline void EGenTL::eventsGetData(std::vector<ge::EURESYS_EVENT_GET_DATA_ENTRY> & entries, uint64_t * timeout) {
    Internal::Box<std::vector<ge::EURESYS_EVENT_GET_DATA_ENTRY>, ce::std_vector_EURESYS_EVENT_GET_DATA_ENTRY> entriesBoxed(egrabberDll, entries);
    int status = egrabberDll.euEGenTL_eventsGetDataFSv_EEGDEu64p(box, entriesBoxed.getBox(), timeout);
    entries = entriesBoxed.unbox();
    Internal::checkStatus(egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    size_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataInfoAsFEHvpsEDIC(box, eh, buffer, size, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    int8_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataInfoAi8FEHvpsEDIC(box, eh, buffer, size, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int16_t EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    int16_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataInfoAi16FEHvpsEDIC(box, eh, buffer, size, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int32_t EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    int32_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataInfoAi32FEHvpsEDIC(box, eh, buffer, size, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int64_t EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    int64_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataInfoAi64FEHvpsEDIC(box, eh, buffer, size, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataInfoAu8FEHvpsEDIC(box, eh, buffer, size, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataInfoAu16FEHvpsEDIC(box, eh, buffer, size, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataInfoAu32FEHvpsEDIC(box, eh, buffer, size, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataInfoAu64FEHvpsEDIC(box, eh, buffer, size, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline double EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    double returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataInfoAdFEHvpsEDIC(box, eh, buffer, size, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline float EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    float returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataInfoAfFEHvpsEDIC(box, eh, buffer, size, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataInfoAu8pFEHvpsEDIC(box, eh, buffer, size, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_eventGetDataInfoASsFEHvpsEDIC(box, eh, buffer, size, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    void * returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataInfoAvptrFEHvpsEDIC(box, eh, buffer, size, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_eventGetDataInfoASvcFEHvpsEDIC(box, eh, buffer, size, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_eventGetDataInfoASv_std_stringFEHvpsEDIC(box, eh, buffer, size, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataInfoAb8FEHvpsEDIC(box, eh, buffer, size, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    char * returnValue;
    int status = egrabberDll.euEGenTL_eventGetDataInfoAcptrFEHvpsEDIC(box, eh, buffer, size, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo EGenTL::eventGetDataInfo<>(gc::EVENT_HANDLE eh, const void * buffer, size_t size, gc::EVENT_DATA_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_eventGetDataInfoA_CINFOFEHvpsEDIC(box, eh, buffer, size, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    size_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetInfoAsFEHEIC(box, eh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    int8_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetInfoAi8FEHEIC(box, eh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int16_t EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    int16_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetInfoAi16FEHEIC(box, eh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int32_t EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    int32_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetInfoAi32FEHEIC(box, eh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int64_t EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    int64_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetInfoAi64FEHEIC(box, eh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetInfoAu8FEHEIC(box, eh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetInfoAu16FEHEIC(box, eh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetInfoAu32FEHEIC(box, eh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetInfoAu64FEHEIC(box, eh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline double EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    double returnValue;
    int status = egrabberDll.euEGenTL_eventGetInfoAdFEHEIC(box, eh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline float EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    float returnValue;
    int status = egrabberDll.euEGenTL_eventGetInfoAfFEHEIC(box, eh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = egrabberDll.euEGenTL_eventGetInfoAu8pFEHEIC(box, eh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_eventGetInfoASsFEHEIC(box, eh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    void * returnValue;
    int status = egrabberDll.euEGenTL_eventGetInfoAvptrFEHEIC(box, eh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_eventGetInfoASvcFEHEIC(box, eh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_eventGetInfoASv_std_stringFEHEIC(box, eh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_eventGetInfoAb8FEHEIC(box, eh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    char * returnValue;
    int status = egrabberDll.euEGenTL_eventGetInfoAcptrFEHEIC(box, eh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo EGenTL::eventGetInfo<>(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_eventGetInfoA_CINFOFEHEIC(box, eh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline void EGenTL::eventFlush(gc::EVENT_HANDLE eh) {
    int status = egrabberDll.euEGenTL_eventFlushFEH(box, eh);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::eventKill(gc::EVENT_HANDLE eh) {
    int status = egrabberDll.euEGenTL_eventKillFEH(box, eh);
    Internal::checkStatus(egrabberDll, status);
}
inline gc::TL_HANDLE EGenTL::tlOpen() {
    gc::TL_HANDLE returnValue;
    int status = egrabberDll.euEGenTL_tlOpen(box, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline void EGenTL::tlClose(gc::TL_HANDLE tlh) {
    int status = egrabberDll.euEGenTL_tlCloseFTH(box, tlh);
    Internal::checkStatus(egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    size_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInfoAsFTHTIC(box, tlh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    int8_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInfoAi8FTHTIC(box, tlh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int16_t EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    int16_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInfoAi16FTHTIC(box, tlh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int32_t EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    int32_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInfoAi32FTHTIC(box, tlh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int64_t EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    int64_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInfoAi64FTHTIC(box, tlh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInfoAu8FTHTIC(box, tlh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInfoAu16FTHTIC(box, tlh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInfoAu32FTHTIC(box, tlh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInfoAu64FTHTIC(box, tlh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline double EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    double returnValue;
    int status = egrabberDll.euEGenTL_tlGetInfoAdFTHTIC(box, tlh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline float EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    float returnValue;
    int status = egrabberDll.euEGenTL_tlGetInfoAfFTHTIC(box, tlh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = egrabberDll.euEGenTL_tlGetInfoAu8pFTHTIC(box, tlh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_tlGetInfoASsFTHTIC(box, tlh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    void * returnValue;
    int status = egrabberDll.euEGenTL_tlGetInfoAvptrFTHTIC(box, tlh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_tlGetInfoASvcFTHTIC(box, tlh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_tlGetInfoASv_std_stringFTHTIC(box, tlh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInfoAb8FTHTIC(box, tlh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    char * returnValue;
    int status = egrabberDll.euEGenTL_tlGetInfoAcptrFTHTIC(box, tlh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo EGenTL::tlGetInfo<>(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_tlGetInfoA_CINFOFTHTIC(box, tlh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline uint32_t EGenTL::tlGetNumInterfaces(gc::TL_HANDLE tlh) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetNumInterfacesFTH(box, tlh, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline std::string EGenTL::tlGetInterfaceID(gc::TL_HANDLE tlh, uint32_t index) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_tlGetInterfaceIDFTHu32(box, tlh, index, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    size_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoAsFTHccpTIC(box, tlh, ifID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    int8_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoAi8FTHccpTIC(box, tlh, ifID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int16_t EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    int16_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoAi16FTHccpTIC(box, tlh, ifID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int32_t EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    int32_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoAi32FTHccpTIC(box, tlh, ifID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int64_t EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    int64_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoAi64FTHccpTIC(box, tlh, ifID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoAu8FTHccpTIC(box, tlh, ifID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoAu16FTHccpTIC(box, tlh, ifID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoAu32FTHccpTIC(box, tlh, ifID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoAu64FTHccpTIC(box, tlh, ifID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline double EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    double returnValue;
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoAdFTHccpTIC(box, tlh, ifID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline float EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    float returnValue;
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoAfFTHccpTIC(box, tlh, ifID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoAu8pFTHccpTIC(box, tlh, ifID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoASsFTHccpTIC(box, tlh, ifID.c_str(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    void * returnValue;
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoAvptrFTHccpTIC(box, tlh, ifID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoASvcFTHccpTIC(box, tlh, ifID.c_str(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoASv_std_stringFTHccpTIC(box, tlh, ifID.c_str(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoAb8FTHccpTIC(box, tlh, ifID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    char * returnValue;
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoAcptrFTHccpTIC(box, tlh, ifID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo EGenTL::tlGetInterfaceInfo<>(gc::TL_HANDLE tlh, const std::string & ifID, gc::TL_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_tlGetInterfaceInfoA_CINFOFTHccpTIC(box, tlh, ifID.c_str(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline gc::IF_HANDLE EGenTL::tlOpenInterface(gc::TL_HANDLE tlh, const std::string & ifID) {
    gc::IF_HANDLE returnValue;
    int status = egrabberDll.euEGenTL_tlOpenInterfaceFTHccp(box, tlh, ifID.c_str(), &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline bool EGenTL::tlUpdateInterfaceList(gc::TL_HANDLE tlh, uint64_t timeout) {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_tlUpdateInterfaceListFTHu64(box, tlh, timeout, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
inline void EGenTL::ifClose(gc::IF_HANDLE ifh) {
    int status = egrabberDll.euEGenTL_ifCloseFIH(box, ifh);
    Internal::checkStatus(egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    size_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetInfoAsFIHIIC(box, ifh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    int8_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetInfoAi8FIHIIC(box, ifh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int16_t EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    int16_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetInfoAi16FIHIIC(box, ifh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int32_t EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    int32_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetInfoAi32FIHIIC(box, ifh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int64_t EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    int64_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetInfoAi64FIHIIC(box, ifh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetInfoAu8FIHIIC(box, ifh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetInfoAu16FIHIIC(box, ifh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetInfoAu32FIHIIC(box, ifh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetInfoAu64FIHIIC(box, ifh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline double EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    double returnValue;
    int status = egrabberDll.euEGenTL_ifGetInfoAdFIHIIC(box, ifh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline float EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    float returnValue;
    int status = egrabberDll.euEGenTL_ifGetInfoAfFIHIIC(box, ifh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = egrabberDll.euEGenTL_ifGetInfoAu8pFIHIIC(box, ifh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_ifGetInfoASsFIHIIC(box, ifh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    void * returnValue;
    int status = egrabberDll.euEGenTL_ifGetInfoAvptrFIHIIC(box, ifh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_ifGetInfoASvcFIHIIC(box, ifh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_ifGetInfoASv_std_stringFIHIIC(box, ifh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetInfoAb8FIHIIC(box, ifh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    char * returnValue;
    int status = egrabberDll.euEGenTL_ifGetInfoAcptrFIHIIC(box, ifh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo EGenTL::ifGetInfo<>(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_ifGetInfoA_CINFOFIHIIC(box, ifh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline uint32_t EGenTL::ifGetNumDevices(gc::IF_HANDLE ifh) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetNumDevicesFIH(box, ifh, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline std::string EGenTL::ifGetDeviceID(gc::IF_HANDLE ifh, uint32_t index) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_ifGetDeviceIDFIHu32(box, ifh, index, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline bool EGenTL::ifUpdateDeviceList(gc::IF_HANDLE ifh, uint64_t timeout) {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_ifUpdateDeviceListFIHu64(box, ifh, timeout, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    size_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoAsFIHccpIIC(box, ifh, devID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    int8_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoAi8FIHccpIIC(box, ifh, devID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int16_t EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    int16_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoAi16FIHccpIIC(box, ifh, devID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int32_t EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    int32_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoAi32FIHccpIIC(box, ifh, devID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int64_t EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    int64_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoAi64FIHccpIIC(box, ifh, devID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoAu8FIHccpIIC(box, ifh, devID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoAu16FIHccpIIC(box, ifh, devID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoAu32FIHccpIIC(box, ifh, devID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoAu64FIHccpIIC(box, ifh, devID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline double EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    double returnValue;
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoAdFIHccpIIC(box, ifh, devID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline float EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    float returnValue;
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoAfFIHccpIIC(box, ifh, devID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoAu8pFIHccpIIC(box, ifh, devID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoASsFIHccpIIC(box, ifh, devID.c_str(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    void * returnValue;
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoAvptrFIHccpIIC(box, ifh, devID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoASvcFIHccpIIC(box, ifh, devID.c_str(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoASv_std_stringFIHccpIIC(box, ifh, devID.c_str(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoAb8FIHccpIIC(box, ifh, devID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    char * returnValue;
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoAcptrFIHccpIIC(box, ifh, devID.c_str(), cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo EGenTL::ifGetDeviceInfo<>(gc::IF_HANDLE ifh, const std::string & devID, gc::INTERFACE_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_ifGetDeviceInfoA_CINFOFIHccpIIC(box, ifh, devID.c_str(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline gc::DEV_HANDLE EGenTL::ifOpenDevice(gc::IF_HANDLE ifh, const std::string & devID, gc::DEVICE_ACCESS_FLAGS flags) {
    gc::DEV_HANDLE returnValue;
    int status = egrabberDll.euEGenTL_ifOpenDeviceFIHccpDAF(box, ifh, devID.c_str(), flags, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline gc::PORT_HANDLE EGenTL::devGetPort(gc::DEV_HANDLE devh) {
    gc::PORT_HANDLE returnValue;
    int status = egrabberDll.euEGenTL_devGetPortFDH(box, devh, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline uint32_t EGenTL::devGetNumDataStreams(gc::DEV_HANDLE devh) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_devGetNumDataStreamsFDH(box, devh, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline std::string EGenTL::devGetDataStreamID(gc::DEV_HANDLE devh, uint32_t index) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_devGetDataStreamIDFDHu32(box, devh, index, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline gc::DS_HANDLE EGenTL::devOpenDataStream(gc::DEV_HANDLE devh, const std::string & dsID) {
    gc::DS_HANDLE returnValue;
    int status = egrabberDll.euEGenTL_devOpenDataStreamFDHccp(box, devh, dsID.c_str(), &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline void EGenTL::devClose(gc::DEV_HANDLE devh) {
    int status = egrabberDll.euEGenTL_devCloseFDH(box, devh);
    Internal::checkStatus(egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    size_t returnValue;
    int status = egrabberDll.euEGenTL_devGetInfoAsFDHDIC(box, devh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    int8_t returnValue;
    int status = egrabberDll.euEGenTL_devGetInfoAi8FDHDIC(box, devh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int16_t EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    int16_t returnValue;
    int status = egrabberDll.euEGenTL_devGetInfoAi16FDHDIC(box, devh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int32_t EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    int32_t returnValue;
    int status = egrabberDll.euEGenTL_devGetInfoAi32FDHDIC(box, devh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int64_t EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    int64_t returnValue;
    int status = egrabberDll.euEGenTL_devGetInfoAi64FDHDIC(box, devh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = egrabberDll.euEGenTL_devGetInfoAu8FDHDIC(box, devh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = egrabberDll.euEGenTL_devGetInfoAu16FDHDIC(box, devh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_devGetInfoAu32FDHDIC(box, devh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = egrabberDll.euEGenTL_devGetInfoAu64FDHDIC(box, devh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline double EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    double returnValue;
    int status = egrabberDll.euEGenTL_devGetInfoAdFDHDIC(box, devh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline float EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    float returnValue;
    int status = egrabberDll.euEGenTL_devGetInfoAfFDHDIC(box, devh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = egrabberDll.euEGenTL_devGetInfoAu8pFDHDIC(box, devh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_devGetInfoASsFDHDIC(box, devh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    void * returnValue;
    int status = egrabberDll.euEGenTL_devGetInfoAvptrFDHDIC(box, devh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_devGetInfoASvcFDHDIC(box, devh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_devGetInfoASv_std_stringFDHDIC(box, devh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_devGetInfoAb8FDHDIC(box, devh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    char * returnValue;
    int status = egrabberDll.euEGenTL_devGetInfoAcptrFDHDIC(box, devh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo EGenTL::devGetInfo<>(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_devGetInfoA_CINFOFDHDIC(box, devh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline gc::BUFFER_HANDLE EGenTL::dsAnnounceBuffer(gc::DS_HANDLE dsh, void * buffer, size_t size, void * userPointer) {
    gc::BUFFER_HANDLE returnValue;
    int status = egrabberDll.euEGenTL_dsAnnounceBufferFDHvpsvp(box, dsh, buffer, size, userPointer, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline gc::BUFFER_HANDLE EGenTL::dsAllocAndAnnounceBuffer(gc::DS_HANDLE dsh, size_t size, void * userPointer) {
    gc::BUFFER_HANDLE returnValue;
    int status = egrabberDll.euEGenTL_dsAllocAndAnnounceBufferFDHsvp(box, dsh, size, userPointer, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline gc::BUFFER_HANDLE EGenTL::dsAnnounceBusBuffer(gc::DS_HANDLE dsh, uint64_t busAddress, size_t size, void * userPointer) {
    gc::BUFFER_HANDLE returnValue;
    int status = egrabberDll.euEGenTL_dsAnnounceBusBufferFDHu64svp(box, dsh, busAddress, size, userPointer, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline gc::BUFFER_HANDLE EGenTL::dsAnnounceDeviceBuffer(gc::DS_HANDLE dsh, void * deviceAddress, size_t size, ge::MEMORY_TYPE memoryType, void * userPointer) {
    gc::BUFFER_HANDLE returnValue;
    int status = egrabberDll.euEGenTL_dsAnnounceDeviceBufferFDHvpsMTvp(box, dsh, deviceAddress, size, memoryType, userPointer, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline void EGenTL::dsAllocAndAnnounceBuffers(gc::DS_HANDLE dsh, size_t size, std::vector<gc::BUFFER_HANDLE> & buffers) {
    Internal::Box<std::vector<gc::BUFFER_HANDLE>, ce::std_vector_BUFFER_HANDLE> buffersBoxed(egrabberDll, buffers);
    int status = egrabberDll.euEGenTL_dsAllocAndAnnounceBuffersFDHsSv_BH(box, dsh, size, buffersBoxed.getBox());
    buffers = buffersBoxed.unbox();
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::dsFlushQueue(gc::DS_HANDLE dsh, gc::ACQ_QUEUE_TYPE operation) {
    int status = egrabberDll.euEGenTL_dsFlushQueueFDHAQT(box, dsh, operation);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::dsStartAcquisition(gc::DS_HANDLE dsh, gc::ACQ_START_FLAGS flags, uint64_t count) {
    int status = egrabberDll.euEGenTL_dsStartAcquisitionFDHASFu64(box, dsh, flags, count);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::dsStopAcquisition(gc::DS_HANDLE dsh, gc::ACQ_STOP_FLAGS flags) {
    int status = egrabberDll.euEGenTL_dsStopAcquisitionFDHASF(box, dsh, flags);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::dsClose(gc::DS_HANDLE dsh) {
    int status = egrabberDll.euEGenTL_dsCloseFDH(box, dsh);
    Internal::checkStatus(egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    size_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetInfoAsFDHSIC(box, dsh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    int8_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetInfoAi8FDHSIC(box, dsh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int16_t EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    int16_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetInfoAi16FDHSIC(box, dsh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int32_t EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    int32_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetInfoAi32FDHSIC(box, dsh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int64_t EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    int64_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetInfoAi64FDHSIC(box, dsh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetInfoAu8FDHSIC(box, dsh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetInfoAu16FDHSIC(box, dsh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetInfoAu32FDHSIC(box, dsh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetInfoAu64FDHSIC(box, dsh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline double EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    double returnValue;
    int status = egrabberDll.euEGenTL_dsGetInfoAdFDHSIC(box, dsh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline float EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    float returnValue;
    int status = egrabberDll.euEGenTL_dsGetInfoAfFDHSIC(box, dsh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = egrabberDll.euEGenTL_dsGetInfoAu8pFDHSIC(box, dsh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_dsGetInfoASsFDHSIC(box, dsh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    void * returnValue;
    int status = egrabberDll.euEGenTL_dsGetInfoAvptrFDHSIC(box, dsh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_dsGetInfoASvcFDHSIC(box, dsh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_dsGetInfoASv_std_stringFDHSIC(box, dsh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetInfoAb8FDHSIC(box, dsh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    char * returnValue;
    int status = egrabberDll.euEGenTL_dsGetInfoAcptrFDHSIC(box, dsh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo EGenTL::dsGetInfo<>(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_dsGetInfoA_CINFOFDHSIC(box, dsh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline gc::BUFFER_HANDLE EGenTL::dsGetBufferID(gc::DS_HANDLE dsh, uint32_t index) {
    gc::BUFFER_HANDLE returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferIDFDHu32(box, dsh, index, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline void EGenTL::dsRevokeBuffer(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, void * * buffer, void * * userPointer) {
    int status = egrabberDll.euEGenTL_dsRevokeBufferFDHBHvppvpp(box, dsh, bh, buffer, userPointer);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::dsRevokeBuffers(gc::DS_HANDLE dsh, std::vector<gc::BUFFER_HANDLE> & buffers) {
    Internal::Box<std::vector<gc::BUFFER_HANDLE>, ce::std_vector_BUFFER_HANDLE> buffersBoxed(egrabberDll, buffers);
    int status = egrabberDll.euEGenTL_dsRevokeBuffersFDHSv_BH(box, dsh, buffersBoxed.getBox());
    buffers = buffersBoxed.unbox();
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::dsQueueBuffer(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh) {
    int status = egrabberDll.euEGenTL_dsQueueBufferFDHBH(box, dsh, bh);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::dsQueueBuffers(gc::DS_HANDLE dsh, const std::vector<gc::BUFFER_HANDLE> & buffers) {
    Internal::Box<std::vector<gc::BUFFER_HANDLE>, ce::std_vector_BUFFER_HANDLE> buffersBoxed(egrabberDll, buffers);
    int status = egrabberDll.euEGenTL_dsQueueBuffersFDHSv_BH(box, dsh, buffersBoxed.getBox());
    Internal::checkStatus(egrabberDll, status);
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    size_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferInfoAsFDHBHBIC(box, dsh, bh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    int8_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferInfoAi8FDHBHBIC(box, dsh, bh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int16_t EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    int16_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferInfoAi16FDHBHBIC(box, dsh, bh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int32_t EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    int32_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferInfoAi32FDHBHBIC(box, dsh, bh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int64_t EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    int64_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferInfoAi64FDHBHBIC(box, dsh, bh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferInfoAu8FDHBHBIC(box, dsh, bh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferInfoAu16FDHBHBIC(box, dsh, bh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferInfoAu32FDHBHBIC(box, dsh, bh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferInfoAu64FDHBHBIC(box, dsh, bh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline double EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    double returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferInfoAdFDHBHBIC(box, dsh, bh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline float EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    float returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferInfoAfFDHBHBIC(box, dsh, bh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferInfoAu8pFDHBHBIC(box, dsh, bh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_dsGetBufferInfoASsFDHBHBIC(box, dsh, bh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    void * returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferInfoAvptrFDHBHBIC(box, dsh, bh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_dsGetBufferInfoASvcFDHBHBIC(box, dsh, bh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_dsGetBufferInfoASv_std_stringFDHBHBIC(box, dsh, bh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferInfoAb8FDHBHBIC(box, dsh, bh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    char * returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferInfoAcptrFDHBHBIC(box, dsh, bh, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo EGenTL::dsGetBufferInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_dsGetBufferInfoA_CINFOFDHBHBIC(box, dsh, bh, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline BufferInfo EGenTL::dsGetBufferInfo(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh) {
    Internal::Box<BufferInfo, ce::Eur_BufferInfo> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_dsGetBufferInfoFDHBH(box, dsh, bh, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline uint32_t EGenTL::dsGetNumBufferParts(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetNumBufferPartsFDHBH(box, dsh, bh, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    size_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoAsFDHBHu32BPIC(box, dsh, bh, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    int8_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoAi8FDHBHu32BPIC(box, dsh, bh, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int16_t EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    int16_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoAi16FDHBHu32BPIC(box, dsh, bh, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int32_t EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    int32_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoAi32FDHBHu32BPIC(box, dsh, bh, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int64_t EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    int64_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoAi64FDHBHu32BPIC(box, dsh, bh, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoAu8FDHBHu32BPIC(box, dsh, bh, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoAu16FDHBHu32BPIC(box, dsh, bh, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoAu32FDHBHu32BPIC(box, dsh, bh, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoAu64FDHBHu32BPIC(box, dsh, bh, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline double EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    double returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoAdFDHBHu32BPIC(box, dsh, bh, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline float EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    float returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoAfFDHBHu32BPIC(box, dsh, bh, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoAu8pFDHBHu32BPIC(box, dsh, bh, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoASsFDHBHu32BPIC(box, dsh, bh, index, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    void * returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoAvptrFDHBHu32BPIC(box, dsh, bh, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoASvcFDHBHu32BPIC(box, dsh, bh, index, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoASv_std_stringFDHBHu32BPIC(box, dsh, bh, index, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoAb8FDHBHu32BPIC(box, dsh, bh, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    char * returnValue;
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoAcptrFDHBHu32BPIC(box, dsh, bh, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo EGenTL::dsGetBufferPartInfo<>(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh, uint32_t index, gc::BUFFER_PART_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_dsGetBufferPartInfoA_CINFOFDHBHu32BPIC(box, dsh, bh, index, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline uint32_t EGenTL::gcGetNumPortURLs(gc::PORT_HANDLE h) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetNumPortURLsFPH(box, h, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    size_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoAsFPHu32UIC(box, h, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    int8_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoAi8FPHu32UIC(box, h, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int16_t EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    int16_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoAi16FPHu32UIC(box, h, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int32_t EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    int32_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoAi32FPHu32UIC(box, h, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline int64_t EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    int64_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoAi64FPHu32UIC(box, h, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    uint8_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoAu8FPHu32UIC(box, h, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    uint16_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoAu16FPHu32UIC(box, h, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    uint32_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoAu32FPHu32UIC(box, h, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    uint64_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoAu64FPHu32UIC(box, h, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline double EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    double returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoAdFPHu32UIC(box, h, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline float EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    float returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoAfFPHu32UIC(box, h, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    uint8_t * returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoAu8pFPHu32UIC(box, h, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::string EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoASsFPHu32UIC(box, h, index, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    void * returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoAvptrFPHu32UIC(box, h, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoASvcFPHu32UIC(box, h, index, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoASv_std_stringFPHu32UIC(box, h, index, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoAb8FPHu32UIC(box, h, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    char * returnValue;
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoAcptrFPHu32UIC(box, h, index, cmd, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo EGenTL::gcGetPortURLInfo<>(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_gcGetPortURLInfoA_CINFOFPHu32UIC(box, h, index, cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline void EGenTL::gcReadPortStacked(gc::PORT_HANDLE h, std::vector<gc::PORT_REGISTER_STACK_ENTRY> & entries) {
    Internal::Box<std::vector<gc::PORT_REGISTER_STACK_ENTRY>, ce::std_vector_PORT_REGISTER_STACK_ENTRY> entriesBoxed(egrabberDll, entries);
    int status = egrabberDll.euEGenTL_gcReadPortStackedFPHSv_PRSE(box, h, entriesBoxed.getBox());
    entries = entriesBoxed.unbox();
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::gcWritePortStacked(gc::PORT_HANDLE h, std::vector<gc::PORT_REGISTER_STACK_ENTRY> & entries) {
    Internal::Box<std::vector<gc::PORT_REGISTER_STACK_ENTRY>, ce::std_vector_PORT_REGISTER_STACK_ENTRY> entriesBoxed(egrabberDll, entries);
    int status = egrabberDll.euEGenTL_gcWritePortStackedFPHSv_PRSE(box, h, entriesBoxed.getBox());
    entries = entriesBoxed.unbox();
    Internal::checkStatus(egrabberDll, status);
}
inline gc::TL_HANDLE EGenTL::ifGetParent(gc::IF_HANDLE ifh) {
    gc::TL_HANDLE returnValue;
    int status = egrabberDll.euEGenTL_ifGetParentFIH(box, ifh, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline gc::IF_HANDLE EGenTL::devGetParent(gc::DEV_HANDLE devh) {
    gc::IF_HANDLE returnValue;
    int status = egrabberDll.euEGenTL_devGetParentFDH(box, devh, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline gc::DEV_HANDLE EGenTL::dsGetParent(gc::DS_HANDLE dsh) {
    gc::DEV_HANDLE returnValue;
    int status = egrabberDll.euEGenTL_dsGetParentFDH(box, dsh, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline void EGenTL::memento(const std::string & text) {
    int status = egrabberDll.euEGenTL_mementoFccp(box, text.c_str());
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::memento(unsigned char verbosity, unsigned char kind, const std::string & text) {
    int status = egrabberDll.euEGenTL_mementoFucucccp(box, verbosity, kind, text.c_str());
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::mementoWaveUp(unsigned char kind, unsigned char id) {
    int status = egrabberDll.euEGenTL_mementoWaveUpFucuc(box, kind, id);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::mementoWaveDown(unsigned char kind, unsigned char id) {
    int status = egrabberDll.euEGenTL_mementoWaveDownFucuc(box, kind, id);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::mementoWaveReset(unsigned char kind, unsigned char id) {
    int status = egrabberDll.euEGenTL_mementoWaveResetFucuc(box, kind, id);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::mementoWaveValue(unsigned char kind, unsigned char id, uint64_t value) {
    int status = egrabberDll.euEGenTL_mementoWaveValueFucucu64(box, kind, id, value);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::mementoWaveNoValue(unsigned char kind, unsigned char id) {
    int status = egrabberDll.euEGenTL_mementoWaveNoValueFucuc(box, kind, id);
    Internal::checkStatus(egrabberDll, status);
}
inline uint64_t EGenTL::getTimestampUs() {
    uint64_t returnValue;
    int status = egrabberDll.euEGenTL_getTimestampUs(box, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline void EGenTL::genapiSetString(gc::PORT_HANDLE h, const std::string & feature, const std::string & value) {
    int status = egrabberDll.euEGenTL_genapiSetStringFPHccpccp(box, h, feature.c_str(), value.c_str());
    Internal::checkStatus(egrabberDll, status);
}
inline std::string EGenTL::genapiGetString(gc::PORT_HANDLE h, const std::string & feature) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_genapiGetStringFPHccp(box, h, feature.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline void EGenTL::genapiGetStringData(gc::PORT_HANDLE h, const std::string & feature, std::vector<char> & data) {
    Internal::Box<std::vector<char>, ce::std_vector_char> dataBoxed(egrabberDll, data);
    int status = egrabberDll.euEGenTL_genapiGetStringDataFPHccpSvc(box, h, feature.c_str(), dataBoxed.getBox());
    data = dataBoxed.unbox();
    Internal::checkStatus(egrabberDll, status);
}
inline std::vector<std::string> EGenTL::genapiGetStringList(gc::PORT_HANDLE h, const std::string & what) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_genapiGetStringListFPHccp(box, h, what.c_str(), returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline void EGenTL::genapiSetInteger(gc::PORT_HANDLE h, const std::string & feature, int64_t value) {
    int status = egrabberDll.euEGenTL_genapiSetIntegerFPHccpi64(box, h, feature.c_str(), value);
    Internal::checkStatus(egrabberDll, status);
}
inline int64_t EGenTL::genapiGetInteger(gc::PORT_HANDLE h, const std::string & feature) {
    int64_t returnValue;
    int status = egrabberDll.euEGenTL_genapiGetIntegerFPHccp(box, h, feature.c_str(), &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline int64_t EGenTL::genapiGetIntegerWithDefault(gc::PORT_HANDLE h, const std::string & feature, int64_t defaultValue) {
    int64_t returnValue;
    int status = egrabberDll.euEGenTL_genapiGetIntegerWithDefaultFPHccpi64(box, h, feature.c_str(), defaultValue, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline void EGenTL::genapiSetFloat(gc::PORT_HANDLE h, const std::string & feature, double value) {
    int status = egrabberDll.euEGenTL_genapiSetFloatFPHccpd(box, h, feature.c_str(), value);
    Internal::checkStatus(egrabberDll, status);
}
inline double EGenTL::genapiGetFloat(gc::PORT_HANDLE h, const std::string & feature) {
    double returnValue;
    int status = egrabberDll.euEGenTL_genapiGetFloatFPHccp(box, h, feature.c_str(), &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline double EGenTL::genapiGetFloatWithDefault(gc::PORT_HANDLE h, const std::string & feature, double defaultValue) {
    double returnValue;
    int status = egrabberDll.euEGenTL_genapiGetFloatWithDefaultFPHccpd(box, h, feature.c_str(), defaultValue, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline void EGenTL::genapiSetRegister(gc::PORT_HANDLE h, const std::string & feature, const void * data, size_t size) {
    int status = egrabberDll.euEGenTL_genapiSetRegisterFPHccpvps(box, h, feature.c_str(), data, size);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::genapiGetRegister(gc::PORT_HANDLE h, const std::string & feature, void * data, size_t size) {
    int status = egrabberDll.euEGenTL_genapiGetRegisterFPHccpvps(box, h, feature.c_str(), data, size);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::genapiExecuteCommand(gc::PORT_HANDLE h, const std::string & feature) {
    int status = egrabberDll.euEGenTL_genapiExecuteCommandFPHccp(box, h, feature.c_str());
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::genapiAttachEvent(gc::PORT_HANDLE h, uint64_t eventId, const void * buffer, size_t size) {
    int status = egrabberDll.euEGenTL_genapiAttachEventFPHu64vps(box, h, eventId, buffer, size);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::genapiInvalidate(gc::PORT_HANDLE h, const std::string & feature) {
    int status = egrabberDll.euEGenTL_genapiInvalidateFPHccp(box, h, feature.c_str());
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::genapiRunScript(gc::PORT_HANDLE h, const std::string & script, ge::GENAPI_UI_SCRIPT_CONTEXT * context) {
    int status = egrabberDll.euEGenTL_genapiRunScriptFPHccpGENAPI_UI_SCRIPT_CONTEXT_p(box, h, script.c_str(), context);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::genapiRunScript(const std::vector<gc::PORT_HANDLE> & handles, const std::string & script, ge::GENAPI_UI_SCRIPT_CONTEXT * context) {
    Internal::Box<std::vector<gc::PORT_HANDLE>, ce::std_vector_PORT_HANDLE> handlesBoxed(egrabberDll, handles);
    int status = egrabberDll.euEGenTL_genapiRunScriptFSv_PHccpGENAPI_UI_SCRIPT_CONTEXT_p(box, handlesBoxed.getBox(), script.c_str(), context);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::genapiInterruptScript(const std::string & scriptId) {
    int status = egrabberDll.euEGenTL_genapiInterruptScriptFccp(box, scriptId.c_str());
    Internal::checkStatus(egrabberDll, status);
}
inline unsigned int EGenTL::imageGetPixelFormatValue(const std::string & format, unsigned int ns) {
    unsigned int returnValue;
    int status = egrabberDll.euEGenTL_imageGetPixelFormatValueFccpui(box, format.c_str(), ns, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline std::string EGenTL::imageGetPixelFormat(uint64_t format) {
    Internal::Box<std::string, ce::std_string> returnBoxed(egrabberDll);
    int status = egrabberDll.euEGenTL_imageGetPixelFormatFu64(box, format, returnBoxed.getBoxAddr());
    Internal::checkStatus(egrabberDll, status);
    return returnBoxed.unbox();
}
inline unsigned int EGenTL::imageGetBytesPerPixel(const std::string & format) {
    unsigned int returnValue;
    int status = egrabberDll.euEGenTL_imageGetBytesPerPixelFccp(box, format.c_str(), &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline unsigned int EGenTL::imageGetBitsPerPixel(const std::string & format) {
    unsigned int returnValue;
    int status = egrabberDll.euEGenTL_imageGetBitsPerPixelFccp(box, format.c_str(), &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline void EGenTL::imageConvert(const ge::ImageConvertInput & input, const ge::ImageConvertOutput & output, const ge::ImageConvertROI * roi) {
    int status = egrabberDll.euEGenTL_imageConvertF_ICI_p_ICO_pImageConvertROI_p(box, &input, &output, roi);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::imageSaveToDisk(const ge::ImageConvertInput & input, const std::string & filepath, int64_t index, const ge::ImageSaveToDiskParams * params) {
    int status = egrabberDll.euEGenTL_imageSaveToDiskF_ICI_pccpi64_ISTDP_p(box, &input, filepath.c_str(), index, params);
    Internal::checkStatus(egrabberDll, status);
}
inline void * EGenTL::imageGet(ge::ImageId id, size_t * outSize) {
    void * returnValue;
    int status = egrabberDll.euEGenTL_imageGetFImageIdsp(box, id, outSize, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return returnValue;
}
inline void EGenTL::imageRelease(ge::ImageId id) {
    int status = egrabberDll.euEGenTL_imageReleaseFImageId(box, id);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::imagePrepareBuffers(size_t bufferSize, size_t count) {
    int status = egrabberDll.euEGenTL_imagePrepareBuffersFss(box, bufferSize, count);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::imageTrimBuffers() {
    int status = egrabberDll.euEGenTL_imageTrimBuffers(box);
    Internal::checkStatus(egrabberDll, status);
}
inline bool EGenTL::isShared() const {
    bool8_t returnValue;
    int status = egrabberDll.euEGenTL_isShared(box, &returnValue);
    Internal::checkStatus(egrabberDll, status);
    return (returnValue != 0);
}
inline void EGenTL::eventKillQuiet(gc::EVENT_HANDLE eh) {
    int status = egrabberDll.euEGenTL_eventKillQuietFEH(box, eh);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::lockUpdates() {
    int status = egrabberDll.euEGenTL_lockUpdates(box);
    Internal::checkStatus(egrabberDll, status);
}
inline void EGenTL::unlockUpdates() {
    int status = egrabberDll.euEGenTL_unlockUpdates(box);
    Internal::checkStatus(egrabberDll, status);
}
} // namespace EURESYS_NAMESPACE

#endif // EURESYS_EGENTL_GENERATED_HEADER_FILE
