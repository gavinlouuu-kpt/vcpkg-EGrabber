/* Copyright Euresys 2021 */

#ifndef EGRABBER_BASE_HEADER_FILE
#define EGRABBER_BASE_HEADER_FILE

namespace EURESYS_NAMESPACE {
namespace Internal {

class EGrabberBase {
    public:
        virtual ~EGrabberBase() {}
        virtual EGenTL &getGenTL() = 0;
};

class EGrabberEventCallbacks {
    public:
        virtual ~EGrabberEventCallbacks() {}
        virtual void onNewBufferEvent(const NewBufferData &data) = 0;
        virtual void onIoToolboxEvent(const IoToolboxData &data) = 0;
        virtual void onCicEvent(const CicData &data) = 0;
        virtual void onDataStreamEvent(const DataStreamData &data) = 0;
        virtual void onCxpInterfaceEvent(const CxpInterfaceData &data) = 0;
        virtual void onDeviceErrorEvent(const DeviceErrorData &data) = 0;
        virtual void onCxpDeviceEvent(const CxpDeviceData &data) = 0;
        virtual void onRemoteDeviceEvent(const RemoteDeviceData &data) = 0;

        virtual void onThreadStart(EventType type) = 0;
        virtual void onThreadStop(EventType type) = 0;
};

class EGrabberScriptCallbacks {
    public:
        virtual ~EGrabberScriptCallbacks() {}
        virtual ge::GENAPI_UI_CALLBACK_RET_CODE onScriptUiCallback(const std::string &, void *, const std::map<std::string, std::string> &, std::string &) = 0;
};

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
