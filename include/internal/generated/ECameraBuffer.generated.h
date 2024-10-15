/* Copyright Euresys 2021*/

#ifndef EURESYS_ECAMERA_BUFFER_GENERATED_HEADER_FILE
#define EURESYS_ECAMERA_BUFFER_GENERATED_HEADER_FILE

#include "../libutil.h"

namespace EURESYS_NAMESPACE {
namespace Internal {

template <typename CallbackModel> void ECameraBufferPush(EGrabberBase &grabber, const NewBufferData & data);
template <> inline void ECameraBufferPush<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data) {
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferPush_CallbackOnDemandFEur_NewBufferData(dataBoxed.getBox());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
}
template <> inline void ECameraBufferPush<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data) {
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferPush_CallbackSingleThreadFEur_NewBufferData(dataBoxed.getBox());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
}
template <> inline void ECameraBufferPush<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data) {
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferPush_CallbackMultiThreadFEur_NewBufferData(dataBoxed.getBox());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
}
template <typename CallbackModel, typename T> T ECameraBufferGetInfo(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd);
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    size_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandAsFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    int8_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandAi8FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline int16_t ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    int16_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandAi16FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline int32_t ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    int32_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandAi32FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline int64_t ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    int64_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandAi64FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    uint8_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandAu8FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    uint16_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandAu16FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    uint32_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandAu32FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    uint64_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandAu64FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline double ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    double returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandAdFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline float ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    float returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandAfFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    uint8_t * returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandAu8pFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline std::string ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(grabber.getGenTL().egrabberDll);
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandASsFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    void * returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandAvptrFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(grabber.getGenTL().egrabberDll);
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandASvcFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(grabber.getGenTL().egrabberDll);
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandASv_std_stringFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    bool8_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandAb8FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    char * returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandAcptrFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(grabber.getGenTL().egrabberDll);
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandA_CINFOFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    size_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadAsFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    int8_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadAi8FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline int16_t ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    int16_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadAi16FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline int32_t ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    int32_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadAi32FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline int64_t ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    int64_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadAi64FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    uint8_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadAu8FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    uint16_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadAu16FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    uint32_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadAu32FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    uint64_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadAu64FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline double ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    double returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadAdFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline float ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    float returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadAfFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    uint8_t * returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadAu8pFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline std::string ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(grabber.getGenTL().egrabberDll);
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadASsFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    void * returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadAvptrFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(grabber.getGenTL().egrabberDll);
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadASvcFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(grabber.getGenTL().egrabberDll);
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadASv_std_stringFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    bool8_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadAb8FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    char * returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadAcptrFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(grabber.getGenTL().egrabberDll);
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadA_CINFOFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
#ifdef ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline size_t ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    size_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadAsFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
#endif // ENABLE_EGRABBER_SIZET_TEMPLATE_SPECIALIZATION
template <> inline int8_t ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    int8_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadAi8FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline int16_t ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    int16_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadAi16FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline int32_t ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    int32_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadAi32FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline int64_t ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    int64_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadAi64FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    uint8_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadAu8FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline uint16_t ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    uint16_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadAu16FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline uint32_t ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    uint32_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadAu32FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline uint64_t ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    uint64_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadAu64FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline double ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    double returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadAdFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline float ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    float returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadAfFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline uint8_t * ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    uint8_t * returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadAu8pFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline std::string ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::string, ce::std_string> returnBoxed(grabber.getGenTL().egrabberDll);
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadASsFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline void * ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    void * returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadAvptrFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline std::vector<char> ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::vector<char>, ce::std_vector_char> returnBoxed(grabber.getGenTL().egrabberDll);
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadASvcFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline std::vector<std::string> ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<std::vector<std::string>, ce::std_vector_std_string> returnBoxed(grabber.getGenTL().egrabberDll);
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadASv_std_stringFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline bool ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    bool8_t returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadAb8FEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return (returnValue != 0);
}
template <> inline char * ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    char * returnValue;
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadAcptrFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, &returnValue);
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnValue;
}
template <> inline InfoCommandInfo ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data, gc::BUFFER_INFO_CMD cmd) {
    Internal::Box<InfoCommandInfo, ce::Eur_InfoCommandInfo> returnBoxed(grabber.getGenTL().egrabberDll);
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadA_CINFOFEur_NewBufferDataBIC(dataBoxed.getBox(), cmd, returnBoxed.getBoxAddr());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <typename CallbackModel> BufferInfo ECameraBufferGetInfo(EGrabberBase &grabber, const NewBufferData & data);
template <> inline BufferInfo ECameraBufferGetInfo<CallbackOnDemand>(EGrabberBase &grabber, const NewBufferData & data) {
    Internal::Box<BufferInfo, ce::Eur_BufferInfo> returnBoxed(grabber.getGenTL().egrabberDll);
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackOnDemandFEur_NewBufferData(dataBoxed.getBox(), returnBoxed.getBoxAddr());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferInfo ECameraBufferGetInfo<CallbackSingleThread>(EGrabberBase &grabber, const NewBufferData & data) {
    Internal::Box<BufferInfo, ce::Eur_BufferInfo> returnBoxed(grabber.getGenTL().egrabberDll);
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackSingleThreadFEur_NewBufferData(dataBoxed.getBox(), returnBoxed.getBoxAddr());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
template <> inline BufferInfo ECameraBufferGetInfo<CallbackMultiThread>(EGrabberBase &grabber, const NewBufferData & data) {
    Internal::Box<BufferInfo, ce::Eur_BufferInfo> returnBoxed(grabber.getGenTL().egrabberDll);
    Internal::Box<NewBufferData, ce::Eur_NewBufferData> dataBoxed(grabber.getGenTL().egrabberDll, data);
    int status = grabber.getGenTL().egrabberDll.euECameraBufferGetInfo_CallbackMultiThreadFEur_NewBufferData(dataBoxed.getBox(), returnBoxed.getBoxAddr());
    Internal::checkStatus(grabber.getGenTL().egrabberDll, status);
    return returnBoxed.unbox();
}
} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif // EURESYS_ECAMERA_BUFFER_GENERATED_HEADER_FILE
