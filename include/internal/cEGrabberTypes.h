/* Copyright Euresys 2021 */

#ifndef CEGRABBER_TYPES_HEADER_FILE
#define CEGRABBER_TYPES_HEADER_FILE

#include "generated/cEGrabberTypes.generated.h"

#ifdef __cplusplus
namespace EURESYS_NAMESPACE {
namespace Internal {
namespace cEGrabber {
using namespace GenTL;
using namespace EuresysCustomGenTL;
extern "C" {
#endif

#ifndef CEGRABBER_IMPL

#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (push, 1)
#endif
typedef struct Euresys_NewBufferData_s {
    DS_HANDLE dsh;
    BUFFER_HANDLE bh;
    void * userPointer;
    uint64_t timestamp;
    void * owner;
    size_t ownerType;
    size_t bufferId;
} Euresys_NewBufferData;
#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (pop)
#endif

#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (push, 1)
#endif
typedef struct Euresys_IoToolboxData_s {
    uint64_t timestamp;
    uint32_t numid;
    uint32_t context1;
    uint32_t context2;
    uint32_t context3;
} Euresys_IoToolboxData;
#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (pop)
#endif

#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (push, 1)
#endif
typedef struct Euresys_CicData_s {
    uint64_t timestamp;
    uint32_t numid;
    uint32_t context1;
    uint32_t context2;
    uint32_t context3;
} Euresys_CicData;
#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (pop)
#endif

#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (push, 1)
#endif
typedef struct Euresys_DataStreamData_s {
    uint64_t timestamp;
    uint32_t numid;
    uint32_t context1;
    uint32_t context2;
    uint32_t context3;
} Euresys_DataStreamData;
#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (pop)
#endif

#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (push, 1)
#endif
typedef struct Euresys_CxpInterfaceData_s {
    uint64_t timestamp;
    uint32_t numid;
    uint32_t context1;
    uint32_t context2;
    uint32_t context3;
} Euresys_CxpInterfaceData;
#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (pop)
#endif

#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (push, 1)
#endif
typedef struct Euresys_DeviceErrorData_s {
    uint64_t timestamp;
    uint32_t numid;
    uint32_t context1;
    uint32_t context2;
    uint32_t context3;
} Euresys_DeviceErrorData;
#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (pop)
#endif

#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (push, 1)
#endif
typedef struct Euresys_CxpDeviceData_s {
    uint64_t timestamp;
    uint32_t numid;
    uint32_t context1;
    uint32_t context2;
    uint32_t context3;
} Euresys_CxpDeviceData;
#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (pop)
#endif

#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (push, 1)
#endif
typedef struct Euresys_RemoteDeviceData_s {
    uint64_t timestamp;
    uint32_t eventNs;
    uint32_t eventId;
    uint32_t size;
    unsigned char data[1012];
} Euresys_RemoteDeviceData;
#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (pop)
#endif

#endif

typedef int64_t cEventType;

typedef void (*Euresys_NewBufferEventCallback)(Eur_EGrabberBase egrabber, Eur_NewBufferData data, void *context);
typedef void (*Euresys_IoToolboxEventCallback)(Eur_EGrabberBase egrabber, Eur_IoToolboxData data, void *context);
typedef void (*Euresys_CicEventCallback)(Eur_EGrabberBase egrabber, Eur_CicData data, void *context);
typedef void (*Euresys_DataStreamEventCallback)(Eur_EGrabberBase egrabber, Eur_DataStreamData data, void *context);
typedef void (*Euresys_CxpInterfaceEventCallback)(Eur_EGrabberBase egrabber, Eur_CxpInterfaceData data, void *context);
typedef void (*Euresys_DeviceErrorEventCallback)(Eur_EGrabberBase egrabber, Eur_DeviceErrorData data, void *context);
typedef void (*Euresys_CxpDeviceEventCallback)(Eur_EGrabberBase egrabber, Eur_CxpDeviceData data, void *context);
typedef void (*Euresys_RemoteDeviceEventCallback)(Eur_EGrabberBase egrabber, Eur_RemoteDeviceData data, void *context);
typedef GENAPI_UI_CALLBACK_RET_CODE (*Euresys_ScriptUiCallback)(Eur_EGrabberBase egrabber, const char *operation, void *context, std_map_std_string_std_string args, std_string value, void *callbackContext);
typedef void (*Euresys_ThreadStartCallback)(Eur_EGrabberBase egrabber, cEventType type, void *context);
typedef void (*Euresys_ThreadStopCallback)(Eur_EGrabberBase egrabber, cEventType type, void *context);

#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (push, 1)
#endif
typedef struct cBufferInfo_s {
    void * base;
    size_t size;
    size_t linePitch;
    size_t width;
    size_t deliveredHeight;
    const char *pixelFormat;
    size_t pixelFormatSize;
    uint32_t bitsPerPixel;
    uint8_t reserved3C[0x40-0x3C];
} cBufferInfo;
#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (pop)
#endif

#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (push, 1)
#endif
typedef struct cInfoCommandInfo_s {
    int dataType;
    uint8_t reserved04[0x08-0x04];
    size_t dataSize;
} cInfoCommandInfo;
#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (pop)
#endif

#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (push, 1)
#endif
typedef struct cEGrabberInfo_s {
    int32_t interfaceIndex;
    int32_t deviceIndex;
    int32_t streamIndex;
    uint8_t reserved0C[0x10-0x0C];
    const char *interfaceID;
    size_t interfaceIDSize;
    const char *deviceID;
    size_t deviceIDSize;
    const char *streamID;
    size_t streamIDSize;
    const char *deviceVendorName;
    size_t deviceVendorNameSize;
    const char *deviceModelName;
    size_t deviceModelNameSize;
    const char *deviceDescription;
    size_t deviceDescriptionSize;
    const char *streamDescription;
    size_t streamDescriptionSize;
    const char *deviceUserID;
    size_t deviceUserIDSize;
    bool8_t isRemoteAvailable;
    bool8_t isDeviceReadOnly;
    uint8_t reserved92[0x98-0x92];
    Eur_EGenTL gentl;
} cEGrabberInfo;
#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (pop)
#endif

#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (push, 1)
#endif
typedef struct cEGrabberInfoExt1_s {
    const char *tlType;
    size_t tlTypeSize;
    const char *firmwareStatus;
    size_t firmwareStatusSize;
    const char *fanStatus;
    size_t fanStatusSize;
} cEGrabberInfoExt1;
#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (pop)
#endif

#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (push, 1)
#endif
typedef struct cEGrabberInfoExt2_s {
    const char *licenseStatus;
    size_t licenseStatusSize;
} cEGrabberInfoExt2;
#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (pop)
#endif

#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (push, 1)
#endif
typedef struct cEGrabberInfoExt3_s {
    const char *deviceSerialNumber;
    size_t deviceSerialNumberSize;
    const char *deviceLicenseStatus;
    size_t deviceLicenseStatusSize;
    uint8_t reserved20[0x40-0x20];
} cEGrabberInfoExt3;
#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (pop)
#endif

#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (push, 1)
#endif
typedef struct cEGrabberCameraInfoExt1_s {
    const char *script;
    size_t scriptSize;
    uint8_t reserved10[0x40-0x10];
} cEGrabberCameraInfoExt1;
#ifndef CEGRABBER_DISABLE_PACKED_STRUCTURES
#pragma pack (pop)
#endif

#ifdef __cplusplus
} // extern "C"
} // namespace cEGrabber
} // namespace Internal

namespace ce = Internal::cEGrabber;

} // namespace EURESYS_NAMESPACE
#endif

#endif
