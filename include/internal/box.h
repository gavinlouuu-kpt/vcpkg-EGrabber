/* Copyright Euresys 2021*/

#ifndef EURESYS_BOX_HEADER_FILE
#define EURESYS_BOX_HEADER_FILE

#include "../EGrabberTypes.h"
#include <map>

namespace EURESYS_NAMESPACE {
namespace Internal {

static void checkStatus(const EGrabberDll &dll, int status);
static void checkStatusCritical(int status);
static void checkStatusCriticalCallback(const EGrabberDll &dll, int status);

template <typename T, typename cT>
class Box {
    public:
        Box(const EGrabberDll& dll, const T &t)
        : gentl(0)
        , dll(dll)
        , t(&t)
        , b(0)
        , autoDelete(true)
        {
            initBox();
        }
        Box(const EGrabberDll& dll)
        : gentl(0)
        , dll(dll)
        , t(0)
        , b(0)
        , autoDelete(true)
        {}
        Box(EGenTL &gentl, const T &t)
        : gentl(&gentl)
        , dll(gentl.egrabberDll)
        , t(&t)
        , b(0)
        , autoDelete(true)
        {
            initBox();
        }
        Box(EGenTL &gentl)
        : gentl(&gentl)
        , dll(gentl.egrabberDll)
        , t(0)
        , b(0)
        , autoDelete(true)
        {}
        ~Box() {
            try {
                if (isSet() && autoDelete) {
                    deleteBox();
                }
            } catch (...) {
            }
        }

        T unbox();

        void setBox(cT box) {
            if (isSet()) {
                throw std::runtime_error("Box is already set");
            }
            b = box;
        }

        void setSharedBox(cT box) {
            autoDelete = false;
            setBox(box);
        }

        cT getBox() {
            return b;
        }

        cT *getBoxAddr() {
            return &b;
        }

        void copyDataFrom(Box<T, cT> &B);

    private:
        void initBox();
        void deleteBox();
        bool isSet() {
            return (b != 0);
        }
        EGenTL &getGenTL() {
            if (!gentl) {
                throw std::runtime_error("Box::gentl is not set");
            }
            return *gentl;
        }

        EGenTL *gentl;
        const EGrabberDll &dll;
        const T *t;
        cT b;
        bool autoDelete;
};

struct PositionOneOfAll {
    int *position;
    OneOfAll &oneOf;
};

template <> inline void Box<std::string, ce::std_string>::deleteBox() {
    checkStatus(dll, dll.eustd_string_destroy(b));
}
template <> inline void Box<std::vector<char>, ce::std_vector_char>::deleteBox() {
    checkStatus(dll, dll.eustd_vector_char_destroy(b));
}
template <> inline void Box<std::vector<gc::PORT_REGISTER_STACK_ENTRY>, ce::std_vector_PORT_REGISTER_STACK_ENTRY>::deleteBox() {
    checkStatus(dll, dll.eustd_vector_PORT_REGISTER_STACK_ENTRY_destroy(b));
}
template <> inline void Box<std::vector<ge::EURESYS_EVENT_GET_DATA_ENTRY>, ce::std_vector_EURESYS_EVENT_GET_DATA_ENTRY>::deleteBox() {
    checkStatus(dll, dll.eustd_vector_EURESYS_EVENT_GET_DATA_ENTRY_destroy(b));
}
template <> inline void Box<std::vector<gc::BUFFER_HANDLE>, ce::std_vector_BUFFER_HANDLE>::deleteBox() {
    checkStatus(dll, dll.eustd_vector_BUFFER_HANDLE_destroy(b));
}
template <> inline void Box<std::vector<gc::PORT_HANDLE>, ce::std_vector_PORT_HANDLE>::deleteBox() {
    checkStatus(dll, dll.eustd_vector_PORT_HANDLE_destroy(b));
}
template <> inline void Box<std::vector<std::string>, ce::std_vector_std_string>::deleteBox() {
    checkStatus(dll, dll.eustd_vector_std_string_destroy(b));
}
template <> inline void Box<BufferInfo, ce::Eur_BufferInfo>::deleteBox() {
    checkStatus(dll, dll.euBufferInfo_destroy(b));
}
template <> inline void Box<InfoCommandInfo, ce::Eur_InfoCommandInfo>::deleteBox() {
    checkStatus(dll, dll.euEurCINFO_destroy(b));
}
template <> inline void Box<BufferIndexRange, ce::Eur_BufferIndexRange>::deleteBox() {
    checkStatus(dll, dll.euBufferIndexRange_destroy(b));
}
template <> inline void Box<GenTLMemory, ce::Eur_GenTLMemory>::deleteBox() {
    checkStatus(dll, dll.euGenTLMemory_destroy(b));
}
template <> inline void Box<UserMemory, ce::Eur_UserMemory>::deleteBox() {
    checkStatus(dll, dll.euUserMemory_destroy(b));
}
template <> inline void Box<UserMemoryArray, ce::Eur_UserMemoryArray>::deleteBox() {
    checkStatus(dll, dll.euUserMemoryArray_destroy(b));
}
template <> inline void Box<BusMemory, ce::Eur_BusMemory>::deleteBox() {
    checkStatus(dll, dll.euBusMemory_destroy(b));
}
template <> inline void Box<NvidiaRdmaMemory, ce::Eur_NvidiaRdmaMemory>::deleteBox() {
    checkStatus(dll, dll.euNvidiaRdmaMemory_destroy(b));
}
template <> inline void Box<std::map<std::string, std::string>, ce::std_map_std_string_std_string>::deleteBox() {
    checkStatus(dll, dll.eustd_map_std_string_std_string_destroy(b));
}
template <> inline void Box<NewBufferData, ce::Eur_NewBufferData>::deleteBox() {
    checkStatus(dll, dll.euNewBufferData_destroy(b));
}
template <> inline void Box<IoToolboxData, ce::Eur_IoToolboxData>::deleteBox() {
    checkStatus(dll, dll.euIoToolboxData_destroy(b));
}
template <> inline void Box<CicData, ce::Eur_CicData>::deleteBox() {
    checkStatus(dll, dll.euCicData_destroy(b));
}
template <> inline void Box<DataStreamData, ce::Eur_DataStreamData>::deleteBox() {
    checkStatus(dll, dll.euDataStreamData_destroy(b));
}
template <> inline void Box<CxpInterfaceData, ce::Eur_CxpInterfaceData>::deleteBox() {
    checkStatus(dll, dll.euCxpInterfaceData_destroy(b));
}
template <> inline void Box<DeviceErrorData, ce::Eur_DeviceErrorData>::deleteBox() {
    checkStatus(dll, dll.euDeviceErrorData_destroy(b));
}
template <> inline void Box<CxpDeviceData, ce::Eur_CxpDeviceData>::deleteBox() {
    checkStatus(dll, dll.euCxpDeviceData_destroy(b));
}
template <> inline void Box<RemoteDeviceData, ce::Eur_RemoteDeviceData>::deleteBox() {
    checkStatus(dll, dll.euRemoteDeviceData_destroy(b));
}
template <> inline void Box<PositionOneOfAll, ce::Eur_OneOfAll>::deleteBox() {
    checkStatus(dll, dll.euEurOOA_destroy(b));
}
template <> inline void Box<cti_loading_error, ce::Eur_cti_loading_error>::deleteBox() {
    dll.eucti_loading_error_destroy(b);
}
template <> inline void Box<missing_gentl_symbol, ce::Eur_missing_gentl_symbol>::deleteBox() {
    dll.eumissing_gentl_symbol_destroy(b);
}
template <> inline void Box<unexpected_data_type, ce::Eur_unexpected_data_type>::deleteBox() {
    dll.euunexpected_data_type_destroy(b);
}
template <> inline void Box<unexpected_data_size, ce::Eur_unexpected_data_size>::deleteBox() {
    dll.euunexpected_data_size_destroy(b);
}
template <> inline void Box<client_error, ce::Eur_client_error>::deleteBox() {
    dll.euclient_error_destroy(b);
}
template <> inline void Box<gentl_error, ce::Eur_gentl_error>::deleteBox() {
    dll.eugentl_error_destroy(b);
}
template <> inline void Box<genapi_error, ce::Eur_genapi_error>::deleteBox() {
    dll.eugenapi_error_destroy(b);
}
template <> inline void Box<thread_error, ce::Eur_thread_error>::deleteBox() {
    dll.euthread_error_destroy(b);
}
template <> inline void Box<internal_error, ce::Eur_internal_error>::deleteBox() {
    dll.euinternal_error_destroy(b);
}
template <> inline void Box<not_allowed, ce::Eur_not_allowed>::deleteBox() {
    dll.eunot_allowed_destroy(b);
}
template <> inline void Box<std::runtime_error, ce::std_runtime_error>::deleteBox() {
    dll.eustd_runtime_error_destroy(b);
}
template <> inline void Box<std::logic_error, ce::std_logic_error>::deleteBox() {
    dll.eustd_logic_error_destroy(b);
}
template <> inline void Box<std::exception, ce::std_exception>::deleteBox() {
    dll.eustd_exception_destroy(b);
}
template <> inline void Box<EGrabberInfo, ce::Eur_EGrabberInfo>::deleteBox() {
    dll.euEurEGInfo_destroy(b);
}
template <> inline void Box<EGrabberCameraInfo, ce::Eur_EGrabberCameraInfo>::deleteBox() {
    dll.euEurEGCameraInfo_destroy(b);
}

template <> inline void Box<std::string, ce::std_string>::initBox() {
    checkStatus(dll, dll.euto_box_std_stringFccps(t->data(), t->size(), &b));
}
template <> inline void Box<std::vector<char>, ce::std_vector_char>::initBox() {
    checkStatus(dll, dll.euto_box_std_vector_charFccps(t->data(), t->size(), &b));
}
template <> inline void Box<std::vector<gc::PORT_REGISTER_STACK_ENTRY>, ce::std_vector_PORT_REGISTER_STACK_ENTRY>::initBox() {
    checkStatus(dll, dll.euto_box_std_vector_PORT_REGISTER_STACK_ENTRYFconst_PORT_REGISTER_STACK_ENTRY_ps(t->data(), t->size(), &b));
}
template <> inline void Box<std::vector<ge::EURESYS_EVENT_GET_DATA_ENTRY>, ce::std_vector_EURESYS_EVENT_GET_DATA_ENTRY>::initBox() {
    checkStatus(dll, dll.euto_box_std_vector_EURESYS_EVENT_GET_DATA_ENTRYFconst_EURESYS_EVENT_GET_DATA_ENTRY_ps(t->data(), t->size(), &b));
}
template <> inline void Box<std::vector<gc::BUFFER_HANDLE>, ce::std_vector_BUFFER_HANDLE>::initBox() {
    checkStatus(dll, dll.euto_box_std_vector_BUFFER_HANDLEFconst_BUFFER_HANDLE_ps(t->data(), t->size(), &b));
}
template <> inline void Box<std::vector<gc::PORT_HANDLE>, ce::std_vector_PORT_HANDLE>::initBox() {
    checkStatus(dll, dll.euto_box_std_vector_PORT_HANDLEFconst_PORT_HANDLE_ps(t->data(), t->size(), &b));
}
template <> inline void Box<BufferIndexRange, ce::Eur_BufferIndexRange>::initBox() {
    checkStatus(dll, dll.euBufferIndexRange_createFssb8(t->begin, t->end, static_cast<bool8_t>(t->reverse), &b));
}
template <> inline void Box<GenTLMemory, ce::Eur_GenTLMemory>::initBox() {
    checkStatus(dll, dll.euGenTLMemory_createFsvp(t->bufferSize, t->userPointer, &b));
}
template <> inline void Box<UserMemory, ce::Eur_UserMemory>::initBox() {
    checkStatus(dll, dll.euUserMemory_createFvpsvp(t->base, t->size, t->userPointer, &b));
}
template <> inline void Box<UserMemoryArray, ce::Eur_UserMemoryArray>::initBox() {
    Box<UserMemory, ce::Eur_UserMemory> memoryBoxed(dll, UserMemory(t->memory.base, t->memory.size, t->memory.userPointer));
    checkStatus(dll, dll.euUserMemoryArray_createFEur_UserMemorys(memoryBoxed.getBox(), t->bufferSize, &b));
}
template <> inline void Box<BusMemory, ce::Eur_BusMemory>::initBox() {
    checkStatus(dll, dll.euBusMemory_createFu64svp(t->busAddress, t->size, t->userPointer, &b));
}
template <> inline void Box<NvidiaRdmaMemory, ce::Eur_NvidiaRdmaMemory>::initBox() {
    checkStatus(dll, dll.euNvidiaRdmaMemory_createFvpsvp(t->deviceAddress, t->size, t->userPointer, &b));
}
template <> inline void Box<NewBufferData, ce::Eur_NewBufferData>::initBox() {
    checkStatus(dll, dll.euto_box_Eur_NewBufferDataFcst_NewBufferData_s_p(reinterpret_cast<const ce::Euresys_NewBufferData *>(t), &b));
}
template <> inline void Box<PositionOneOfAll, ce::Eur_OneOfAll>::initBox() {
    checkStatus(dll, dll.euEurOOA_create(&b));
}
template <> inline void Box<cti_loading_error, ce::Eur_cti_loading_error>::initBox() {
    checkStatusCriticalCallback(dll, dll.eucti_loading_error_createFccp(t->path.c_str(), &b));
}
template <> inline void Box<missing_gentl_symbol, ce::Eur_missing_gentl_symbol>::initBox() {
    checkStatusCriticalCallback(dll, dll.eumissing_gentl_symbol_createFccpccp(t->path.c_str(), t->symbol.c_str(), &b));
}
template <> inline void Box<unexpected_data_type, ce::Eur_unexpected_data_type>::initBox() {
    checkStatusCriticalCallback(dll, dll.euunexpected_data_type_createFID(t->type, &b));
}
template <> inline void Box<unexpected_data_size, ce::Eur_unexpected_data_size>::initBox() {
    checkStatusCriticalCallback(dll, dll.euunexpected_data_size_createFss(t->expected, t->returned, &b));
}
template <> inline void Box<client_error, ce::Eur_client_error>::initBox() {
    checkStatusCriticalCallback(dll, dll.euclient_error_createFccp(t->what(), &b));
}
template <> inline void Box<gentl_error, ce::Eur_gentl_error>::initBox() {
    if (t->description.empty()) {
        checkStatusCriticalCallback(dll, dll.eugentl_error_createFGE(t->gc_err, &b));
    } else {
        checkStatusCriticalCallback(dll, dll.eugentl_error_createFGEccp(t->gc_err, t->description.c_str(), &b));
    }
}
template <> inline void Box<genapi_error, ce::Eur_genapi_error>::initBox() {
    checkStatusCriticalCallback(dll, dll.eugenapi_error_createFGEC(t->genapi_error_code, &b));
    for (size_t i = 0; i < t->parameter_count(); ++i) {
        switch (t->parameter_type(i)) {
            case ge::GENAPI_ERROR_PARAMETER_TYPE_STRING:
                checkStatusCriticalCallback(dll, dll.eugenapi_error_add_string_parameterFcp(b, t->string_parameter(i).c_str()));
                break;
            case ge::GENAPI_ERROR_PARAMETER_TYPE_INTEGER:
                checkStatusCriticalCallback(dll, dll.eugenapi_error_add_integer_parameterFi64(b, t->integer_parameter(i)));
                break;
            case ge::GENAPI_ERROR_PARAMETER_TYPE_FLOAT:
                checkStatusCriticalCallback(dll, dll.eugenapi_error_add_float_parameterFd(b, t->float_parameter(i)));
                break;
            default:
                checkStatusCriticalCallback(dll, dll.eugenapi_error_add_string_parameterFcp(b, "?"));
                break;
        }
    }
}
template <> inline void Box<thread_error, ce::Eur_thread_error>::initBox() {
    checkStatusCriticalCallback(dll, dll.euthread_error_createFccp(t->what(), &b));
}
template <> inline void Box<internal_error, ce::Eur_internal_error>::initBox() {
    checkStatusCriticalCallback(dll, dll.euinternal_error_create(&b));
}
template <> inline void Box<not_allowed, ce::Eur_not_allowed>::initBox() {
    checkStatusCriticalCallback(dll, dll.eunot_allowed_create(&b));
}
template <> inline void Box<std::runtime_error, ce::std_runtime_error>::initBox() {
    checkStatusCriticalCallback(dll, dll.eustd_runtime_error_createFccp(t->what(), &b));
}
template <> inline void Box<std::logic_error, ce::std_logic_error>::initBox() {
    checkStatusCriticalCallback(dll, dll.eustd_logic_error_createFccp(t->what(), &b));
}
template <> inline void Box<std::exception, ce::std_exception>::initBox() {
    checkStatusCriticalCallback(dll, dll.eustd_exception_createFccp(t->what(), &b));
}
template <> inline void Box<EGrabberInfo, ce::Eur_EGrabberInfo>::initBox() {
    ce::cEGrabberInfo cInfo = {
        t->interfaceIndex,
        t->deviceIndex,
        t->streamIndex,
        {0, 0, 0, 0},
        t->interfaceID.data(),
        t->interfaceID.size(),
        t->deviceID.data(),
        t->deviceID.size(),
        t->streamID.data(),
        t->streamID.size(),
        t->deviceVendorName.data(),
        t->deviceVendorName.size(),
        t->deviceModelName.data(),
        t->deviceModelName.size(),
        t->deviceDescription.data(),
        t->deviceDescription.size(),
        t->streamDescription.data(),
        t->streamDescription.size(),
        t->deviceUserID.data(),
        t->deviceUserID.size(),
        static_cast<bool8_t>(t->isRemoteAvailable),
        static_cast<bool8_t>(t->isDeviceReadOnly),
        {0, 0, 0, 0, 0, 0},
        getGenTL().getBox()
    };
    checkStatus(dll, dll.euto_box_EurEGInfoFcEGrabberInfo(cInfo, &b));
    ce::cEGrabberInfoExt1 cInfoExt1 = {
        t->tlType.data(),
        t->tlType.size(),
        t->firmwareStatus.data(),
        t->firmwareStatus.size(),
        t->fanStatus.data(),
        t->fanStatus.size(),
    };
    checkStatus(dll, dll.euto_box_EurEGInfoFcEGrabberInfoExt1_p(b, &cInfoExt1));
    ce::cEGrabberInfoExt2 cInfoExt2 = {
        t->licenseStatus.data(),
        t->licenseStatus.size(),
    };
    checkStatus(dll, dll.euto_box_EurEGInfoFcEGrabberInfoExt2_p(b, &cInfoExt2));
    ce::cEGrabberInfoExt3 cInfoExt3 = {
        t->deviceSerialNumber.data(),
        t->deviceSerialNumber.size(),
        t->deviceLicenseStatus.data(),
        t->deviceLicenseStatus.size(),
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    checkStatus(dll, dll.euto_box_EurEGInfoFcEGrabberInfoExt3_p(b, &cInfoExt3));
}
template <> inline void Box<EGrabberCameraInfo, ce::Eur_EGrabberCameraInfo>::initBox() {
    checkStatus(dll, dll.euEurEGCameraInfo_create(&b));
    for (std::vector<EGrabberInfo>::const_iterator it = t->grabbers.begin(); it != t->grabbers.end(); ++it) {
        Box<EGrabberInfo, ce::Eur_EGrabberInfo> grabber(getGenTL(), *it);
        checkStatus(dll, dll.euEurEGCameraInfo_grabbers_push_backFEurEGInfo(b, grabber.getBox()));
    }
    ce::cEGrabberCameraInfoExt1 cInfoExt1 = {
        t->script.data(),
        t->script.size(),
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        ,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    checkStatus(dll, dll.euto_box_EurEGCameraInfoFcEGrabberCameraInfoExt1_p(b, &cInfoExt1));
}

template <> inline std::string Box<std::string, ce::std_string>::unbox() {
    const char *data;
    size_t size;
    checkStatus(dll, dll.eufrom_box_std_stringFccppsp(b, &data, &size));
    return std::string(data, size);
}
template <> inline std::vector<char> Box<std::vector<char>, ce::std_vector_char>::unbox() {
    const char *data;
    size_t size;
    checkStatus(dll, dll.eufrom_box_std_vector_charFccppsp(b, &data, &size));
    return std::vector<char>(data, data + size);
}
template <> inline std::vector<gc::PORT_REGISTER_STACK_ENTRY> Box<std::vector<gc::PORT_REGISTER_STACK_ENTRY>, ce::std_vector_PORT_REGISTER_STACK_ENTRY>::unbox() {
    const gc::PORT_REGISTER_STACK_ENTRY *data;
    size_t size;
    checkStatus(dll, dll.eufrom_box_std_vector_PORT_REGISTER_STACK_ENTRYFconst_PORT_REGISTER_STACK_ENTRY_ppsp(b, &data, &size));
    return std::vector<gc::PORT_REGISTER_STACK_ENTRY>(data, data + size);
}
template <> inline std::vector<ge::EURESYS_EVENT_GET_DATA_ENTRY> Box<std::vector<ge::EURESYS_EVENT_GET_DATA_ENTRY>, ce::std_vector_EURESYS_EVENT_GET_DATA_ENTRY>::unbox() {
    const ge::EURESYS_EVENT_GET_DATA_ENTRY *data;
    size_t size;
    checkStatus(dll, dll.eufrom_box_std_vector_EURESYS_EVENT_GET_DATA_ENTRYFconst_EURESYS_EVENT_GET_DATA_ENTRY_ppsp(b, &data, &size));
    return std::vector<ge::EURESYS_EVENT_GET_DATA_ENTRY>(data, data + size);
}
template <> inline std::vector<gc::BUFFER_HANDLE> Box<std::vector<gc::BUFFER_HANDLE>, ce::std_vector_BUFFER_HANDLE>::unbox() {
    const gc::BUFFER_HANDLE *data;
    size_t size;
    checkStatus(dll, dll.eufrom_box_std_vector_BUFFER_HANDLEFconst_BUFFER_HANDLE_ppsp(b, &data, &size));
    return std::vector<gc::BUFFER_HANDLE>(data, data + size);
}
template <> inline std::vector<gc::PORT_HANDLE> Box<std::vector<gc::PORT_HANDLE>, ce::std_vector_PORT_HANDLE>::unbox() {
    const gc::PORT_HANDLE *data;
    size_t size;
    checkStatus(dll, dll.eufrom_box_std_vector_PORT_HANDLEFconst_PORT_HANDLE_ppsp(b, &data, &size));
    return std::vector<gc::PORT_HANDLE>(data, data + size);
}
template <> inline std::vector<std::string> Box<std::vector<std::string>, ce::std_vector_std_string>::unbox() {
    size_t size;
    checkStatus(dll, dll.eustd_vector_std_string_size(b, &size));
    std::vector<std::string> returnValue(size);
    for (size_t i = 0; i < size; ++i) {
        Box<std::string, ce::std_string> stringBox(dll);
        checkStatus(dll, dll.eustd_vector_std_string_atFs(b, i, stringBox.getBoxAddr()));
        returnValue[i] = stringBox.unbox();
    }
    return returnValue;
}
template <> inline BufferInfo Box<BufferInfo, ce::Eur_BufferInfo>::unbox() {
    ce::cBufferInfo info;
    checkStatus(dll, dll.eufrom_box_Eur_BufferInfoFcBufferInfo_p(b, &info));
    BufferInfo returnValue = {
        info.base,
        info.size,
        info.linePitch,
        info.width,
        info.deliveredHeight,
        std::string(info.pixelFormat, info.pixelFormatSize),
        info.bitsPerPixel
    };
    return returnValue;
}
template <> inline InfoCommandInfo Box<InfoCommandInfo, ce::Eur_InfoCommandInfo>::unbox() {
    ce::cInfoCommandInfo info;
    checkStatus(dll, dll.eufrom_box_EurCINFOFcInfoCommandInfo_p(b, &info));
    InfoCommandInfo returnValue = {
        info.dataType,
        info.dataSize,
    };
    return returnValue;
}
template <> inline BufferIndexRange Box<BufferIndexRange, ce::Eur_BufferIndexRange>::unbox() {
    size_t begin;
    size_t end;
    bool8_t reverse;
    checkStatus(dll, dll.eufrom_box_Eur_BufferIndexRangeFspspb8_p(b, &begin, &end, &reverse));
    return BufferIndexRange(begin, end, (reverse != 0));
}
template <> inline NewBufferData Box<NewBufferData, ce::Eur_NewBufferData>::unbox() {
    const ce::Euresys_NewBufferData *data;
    checkStatus(dll, dll.euNewBufferDataANewBufferData(b, &data));
    return *(reinterpret_cast<const NewBufferData *>(data));
}
template <> inline IoToolboxData Box<IoToolboxData, ce::Eur_IoToolboxData>::unbox() {
    const ce::Euresys_IoToolboxData *data;
    checkStatus(dll, dll.euIoToolboxDataAIoToolboxData(b, &data));
    return *(reinterpret_cast<const IoToolboxData *>(data));
}
template <> inline CicData Box<CicData, ce::Eur_CicData>::unbox() {
    const ce::Euresys_CicData *data;
    checkStatus(dll, dll.euCicDataACicData(b, &data));
    return *(reinterpret_cast<const CicData *>(data));
}
template <> inline DataStreamData Box<DataStreamData, ce::Eur_DataStreamData>::unbox() {
    const ce::Euresys_DataStreamData *data;
    checkStatus(dll, dll.euDataStreamDataADataStreamData(b, &data));
    return *(reinterpret_cast<const DataStreamData *>(data));
}
template <> inline CxpInterfaceData Box<CxpInterfaceData, ce::Eur_CxpInterfaceData>::unbox() {
    const ce::Euresys_CxpInterfaceData *data;
    checkStatus(dll, dll.euCxpInterfaceDataACxpInterfaceData(b, &data));
    return *(reinterpret_cast<const CxpInterfaceData *>(data));
}
template <> inline DeviceErrorData Box<DeviceErrorData, ce::Eur_DeviceErrorData>::unbox() {
    const ce::Euresys_DeviceErrorData *data;
    checkStatus(dll, dll.euDeviceErrorDataADeviceErrorData(b, &data));
    return *(reinterpret_cast<const DeviceErrorData *>(data));
}
template <> inline CxpDeviceData Box<CxpDeviceData, ce::Eur_CxpDeviceData>::unbox() {
    const ce::Euresys_CxpDeviceData *data;
    checkStatus(dll, dll.euCxpDeviceDataACxpDeviceData(b, &data));
    return *(reinterpret_cast<const CxpDeviceData *>(data));
}
template <> inline RemoteDeviceData Box<RemoteDeviceData, ce::Eur_RemoteDeviceData>::unbox() {
    const ce::Euresys_RemoteDeviceData *data;
    checkStatus(dll, dll.euRemoteDeviceDataARemoteDeviceData(b, &data));
    return *(reinterpret_cast<const RemoteDeviceData *>(data));
}
template <> inline std::map<std::string, std::string> Box<std::map<std::string, std::string>, ce::std_map_std_string_std_string>::unbox() {
    size_t size;
    checkStatus(dll, dll.eustd_map_std_string_std_string_size(b, &size));
    std::map<std::string, std::string> returnValue;
    for (size_t i = 0; i < size; ++i) {
        Box<std::string, ce::std_string> keyBox(dll);
        Box<std::string, ce::std_string> valueBox(dll);
        checkStatus(dll, dll.eustd_map_std_string_std_string_atFsSs_pSs_p(b, i, keyBox.getBoxAddr(), valueBox.getBoxAddr()));
        returnValue[keyBox.unbox()] = valueBox.unbox();
    }
    return returnValue;
}
template <> inline PositionOneOfAll Box<PositionOneOfAll, ce::Eur_OneOfAll>::unbox() {
    switch (*(t->position)) {
        case 1:
        {
            Box<NewBufferData, ce::Eur_NewBufferData> data(dll);
            checkStatus(dll, dll.euEurOOA_at_position_1(b, data.getBoxAddr()));
            t->oneOf.data1 = data.unbox();
            break;
        }
        case 2:
        {
            Box<IoToolboxData, ce::Eur_IoToolboxData> data(dll);
            checkStatus(dll, dll.euEurOOA_at_position_2(b, data.getBoxAddr()));
            t->oneOf.data2 = data.unbox();
            break;
        }
        case 3:
        {
            Box<CicData, ce::Eur_CicData> data(dll);
            checkStatus(dll, dll.euEurOOA_at_position_3(b, data.getBoxAddr()));
            t->oneOf.data3 = data.unbox();
            break;
        }
        case 4:
        {
            Box<DataStreamData, ce::Eur_DataStreamData> data(dll);
            checkStatus(dll, dll.euEurOOA_at_position_4(b, data.getBoxAddr()));
            t->oneOf.data4 = data.unbox();
            break;
        }
        case 5:
        {
            Box<CxpInterfaceData, ce::Eur_CxpInterfaceData> data(dll);
            checkStatus(dll, dll.euEurOOA_at_position_5(b, data.getBoxAddr()));
            t->oneOf.data5 = data.unbox();
            break;
        }
        case 6:
        {
            Box<DeviceErrorData, ce::Eur_DeviceErrorData> data(dll);
            checkStatus(dll, dll.euEurOOA_at_position_6(b, data.getBoxAddr()));
            t->oneOf.data6 = data.unbox();
            break;
        }
        case 7:
        {
            Box<CxpDeviceData, ce::Eur_CxpDeviceData> data(dll);
            checkStatus(dll, dll.euEurOOA_at_position_7(b, data.getBoxAddr()));
            t->oneOf.data7 = data.unbox();
            break;
        }
        case 8:
        {
            Box<RemoteDeviceData, ce::Eur_RemoteDeviceData> data(dll);
            checkStatus(dll, dll.euEurOOA_at_position_8(b, data.getBoxAddr()));
            t->oneOf.data8 = data.unbox();
            break;
        }
        default:
            break;
    }
    return *t;
}
template <> inline cti_loading_error Box<cti_loading_error, ce::Eur_cti_loading_error>::unbox() {
    Box<std::string, ce::std_string> pathBox(dll);
    checkStatusCritical(dll.eufrom_box_Eur_cti_loading_error_path(b, pathBox.getBoxAddr()));
    return cti_loading_error(pathBox.unbox());
}
template <> inline missing_gentl_symbol Box<missing_gentl_symbol, ce::Eur_missing_gentl_symbol>::unbox() {
    Box<std::string, ce::std_string> pathBox(dll);
    Box<std::string, ce::std_string> symbolBox(dll);
    checkStatusCritical(dll.eufrom_box_Eur_missing_gentl_symbol_path(b, pathBox.getBoxAddr()));
    checkStatusCritical(dll.eufrom_box_Eur_missing_gentl_symbol_symbol(b, symbolBox.getBoxAddr()));
    return missing_gentl_symbol(pathBox.unbox(), symbolBox.unbox());
}
template <> inline unexpected_data_type Box<unexpected_data_type, ce::Eur_unexpected_data_type>::unbox() {
    gc::INFO_DATATYPE type;
    checkStatusCritical(dll.eufrom_box_Eur_unexpected_data_type(b, &type));
    return unexpected_data_type(type);
}
template <> inline unexpected_data_size Box<unexpected_data_size, ce::Eur_unexpected_data_size>::unbox() {
    size_t expected;
    size_t returned;
    checkStatusCritical(dll.eufrom_box_Eur_unexpected_data_sizeFspsp(b, &expected, &returned));
    return unexpected_data_size(expected, returned);
}
template <> inline client_error Box<client_error, ce::Eur_client_error>::unbox() {
    const char *w;
    checkStatusCritical(dll.eustd_runtime_error_what(reinterpret_cast<ce::std_runtime_error>(b), &w));
    return client_error(std::string(w));
}
template <> inline gentl_error Box<gentl_error, ce::Eur_gentl_error>::unbox() {
    gc::GC_ERROR gc_err;
    Box<std::string, ce::std_string> descriptionBox(dll);
    checkStatusCritical(dll.eufrom_box_Eur_gentl_error_gc_err(b, &gc_err));
    checkStatusCritical(dll.eufrom_box_Eur_gentl_error_description(b, descriptionBox.getBoxAddr()));
    if (descriptionBox.unbox().empty()) {
        return gentl_error(gc_err);
    } else {
        return gentl_error(gc_err, descriptionBox.unbox());
    }
}
template <> inline genapi_error Box<genapi_error, ce::Eur_genapi_error>::unbox() {
    ge::GENAPI_ERROR_CODE code;
    checkStatusCritical(dll.eufrom_box_Eur_genapi_error(b, &code));
    genapi_error returnValue(code);
    size_t count;
    checkStatusCritical(dll.eugenapi_error_parameter_count(b, &count));
    for (size_t i = 0; i < count; ++i) {
        ge::GENAPI_ERROR_PARAMETER_TYPE type;
        checkStatusCritical(dll.eugenapi_error_parameter_typeFs(b, i, &type));
        switch (type) {
            case ge::GENAPI_ERROR_PARAMETER_TYPE_STRING:
            {
                Box<std::string, ce::std_string> parameterBox(dll);
                checkStatusCritical(dll.eugenapi_error_string_parameterASsFs(b, i, parameterBox.getBoxAddr()));
                std::string parameter = parameterBox.unbox();
                returnValue.add_string_parameter(parameter.c_str());
                break;
            }
            case ge::GENAPI_ERROR_PARAMETER_TYPE_INTEGER:
            {
                int64_t parameter;
                checkStatusCritical(dll.eugenapi_error_integer_parameterFs(b, i, &parameter));
                returnValue.add_integer_parameter(parameter);
                break;
            }
            case ge::GENAPI_ERROR_PARAMETER_TYPE_FLOAT:
            {
                double parameter;
                checkStatusCritical(dll.eugenapi_error_float_parameterFs(b, i, &parameter));
                returnValue.add_float_parameter(parameter);
                break;
            }
            default:
                returnValue.add_string_parameter("?");
                break;
        }
    }
    return returnValue;
}
template <> inline thread_error Box<thread_error, ce::Eur_thread_error>::unbox() {
    const char *w;
    checkStatusCritical(dll.eustd_runtime_error_what(reinterpret_cast<ce::std_runtime_error>(b), &w));
    return thread_error(std::string(w));
}
template <> inline internal_error Box<internal_error, ce::Eur_internal_error>::unbox() {
    return internal_error();
}
template <> inline not_allowed Box<not_allowed, ce::Eur_not_allowed>::unbox() {
    return not_allowed();
}
template <> inline std::runtime_error Box<std::runtime_error, ce::std_runtime_error>::unbox() {
    const char *w;
    checkStatusCritical(dll.eustd_runtime_error_what(b, &w));
    return std::runtime_error(std::string(w));
}
template <> inline std::logic_error Box<std::logic_error, ce::std_logic_error>::unbox() {
    const char *w;
    checkStatusCritical(dll.eustd_logic_error_what(b, &w));
    return std::logic_error(std::string(w));
}
template <> inline std::exception Box<std::exception, ce::std_exception>::unbox() {
#if defined(_MSC_VER)
    const char *w;
    checkStatusCritical(dll.eustd_exception_what(b, &w));
    return std::exception(w);
#else
    return std::exception();
#endif
}
template <> inline EGrabberInfo Box<EGrabberInfo, ce::Eur_EGrabberInfo>::unbox() {
    ce::cEGrabberInfo cInfo;
    checkStatus(dll, dll.eufrom_box_EurEGInfoFcEGrabberInfo_p(b, &cInfo));
    ce::cEGrabberInfoExt1 cInfoExt1;
    checkStatus(dll, dll.eufrom_box_EurEGInfoFcEGrabberInfoExt1_p(b, &cInfoExt1));
    ce::cEGrabberInfoExt2 cInfoExt2;
    checkStatus(dll, dll.eufrom_box_EurEGInfoFcEGrabberInfoExt2_p(b, &cInfoExt2));
    ce::cEGrabberInfoExt3 cInfoExt3;
    checkStatus(dll, dll.eufrom_box_EurEGInfoFcEGrabberInfoExt3_p(b, &cInfoExt3));
    EGrabberInfo returnValue = {
        cInfo.interfaceIndex,
        cInfo.deviceIndex,
        cInfo.streamIndex,
        std::string(cInfo.interfaceID, cInfo.interfaceIDSize),
        std::string(cInfo.deviceID, cInfo.deviceIDSize),
        std::string(cInfo.streamID, cInfo.streamIDSize),
        std::string(cInfo.deviceVendorName, cInfo.deviceVendorNameSize),
        std::string(cInfo.deviceModelName, cInfo.deviceModelNameSize),
        std::string(cInfo.deviceDescription, cInfo.deviceDescriptionSize),
        std::string(cInfo.streamDescription, cInfo.streamDescriptionSize),
        std::string(cInfo.deviceUserID, cInfo.deviceUserIDSize),
        std::string(cInfoExt3.deviceSerialNumber, cInfoExt3.deviceSerialNumberSize),
        std::string(cInfoExt3.deviceLicenseStatus, cInfoExt3.deviceLicenseStatusSize),
        std::string(cInfoExt1.tlType, cInfoExt1.tlTypeSize),
        std::string(cInfoExt1.firmwareStatus, cInfoExt1.firmwareStatusSize),
        std::string(cInfoExt1.fanStatus, cInfoExt1.fanStatusSize),
        std::string(cInfoExt2.licenseStatus, cInfoExt2.licenseStatusSize),
        (cInfo.isRemoteAvailable != 0),
        (cInfo.isDeviceReadOnly != 0),
        &getGenTL()
    };
    return returnValue;
}
template <> inline EGrabberCameraInfo Box<EGrabberCameraInfo, ce::Eur_EGrabberCameraInfo>::unbox() {
    size_t size;
    checkStatus(dll, dll.euEurEGCameraInfo_grabber_count(b, &size));
    EGrabberCameraInfo returnValue;
    for (size_t i = 0; i < size; ++i) {
        Box<EGrabberInfo, ce::Eur_EGrabberInfo> grabberBox(getGenTL());
        checkStatus(dll, dll.euEurEGCameraInfo_grabber_atFs(b, i, grabberBox.getBoxAddr()));
        returnValue.grabbers.push_back(grabberBox.unbox());
    }
    ce::cEGrabberCameraInfoExt1 cInfo;
    checkStatus(dll, dll.eufrom_box_EurEGCameraInfoFcEGrabberCameraInfoExt1_p(b, &cInfo));
    returnValue.script = std::string(cInfo.script, cInfo.scriptSize);
    return returnValue;
}

template <> inline void Box<std::string, ce::std_string>::copyDataFrom(Box<std::string, ce::std_string> &B) {
    checkStatus(dll, dll.eustd_string_assign_operatorFSs(b, B.b));
}

} // Internal
} // namespace EURESYS_NAMESPACE

#endif // EURESYS_BOX_HEADER_FILE
