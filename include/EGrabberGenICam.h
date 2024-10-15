/* Copyright Euresys 2021 */

#ifndef EGRABBER_GENICAM_HEADER_FILE
#define EGRABBER_GENICAM_HEADER_FILE

/** @file

    Defines GenICam interface accessible from Euresys::EGrabber
 **/

namespace EURESYS_NAMESPACE {

/** @ingroup EGrabber
    @{
 **/

// --------------------------------------------------------------------------
// EGrabber interface to GenICam specific methods of an EGrabber instance
// --------------------------------------------------------------------------
class EGrabberGenICam {
    public:
        // this object should not be created manually; it is initialized by
        // EGrabber::grabbers(int ix) for a specific grabber object
        EGrabberGenICam(EGenTL &gentl,
                        gc::PORT_HANDLE tlh,
                        gc::PORT_HANDLE ifh,
                        gc::PORT_HANDLE devh,
                        gc::PORT_HANDLE dsh,
                        gc::PORT_HANDLE camh)
        : gentl(gentl)
        , tlh(tlh)
        , ifh(ifh)
        , devh(devh)
        , dsh(dsh)
        , camh(camh)
        {}
        template<typename M, typename T> T getInfo(int32_t cmd) {
            return Internal::ModuleInfo<M>().template getInfo<T>(gentl, getPort((M *)0), cmd);
        }
        template <typename P> bool isOpen() {
            return getPort((P *)0) != GENTL_INVALID_HANDLE;
        }
        template <typename P> void gcReadPortData(uint64_t address, void *data, size_t size) {
            gentl.gcReadPortData(getPort((P *)0), address, data, size);
        }
        template <typename P> void gcWritePortData(uint64_t address, const void *data, size_t size) {
            gentl.gcWritePortData(getPort((P *)0), address, data, size);
        }
        template <typename P> std::vector<char> gcReadPort(uint64_t address, size_t size) {
            std::vector<char> data(size);
            gentl.gcReadPort(getPort((P *)0), address, data);
            return data;
        }
        template <typename P> void gcWritePort(uint64_t address, const std::vector<char> &data) {
            gentl.gcWritePort(getPort((P *)0), address, data);
        }
        template <typename P, typename V> V gcReadPortValue(uint64_t address) {
            V value;
            gentl.gcReadPortData(getPort((P *)0), address, &value, sizeof(value));
            return value;
        }
        template <typename P, typename V> void gcWritePortValue(uint64_t address, V value) {
            gentl.gcWritePortData(getPort((P *)0), address, &value, sizeof(value));
        }
        template <typename P> std::string gcReadPortString(uint64_t address, size_t size) {
            return gentl.gcReadPortString(getPort((P *)0), address, size);
        }
        template <typename P> int64_t getInteger(const std::string &feature) {
            return gentl.genapiGetInteger(getPort((P *)0), feature);
        }
        template <typename P> double getFloat(const std::string &feature) {
            return gentl.genapiGetFloat(getPort((P *)0), feature);
        }
        template <typename P> std::string getString(const std::string &feature) {
            return gentl.genapiGetString(getPort((P *)0), feature);
        }
        template <typename P> void getStringData(const std::string &feature, std::vector<char> &data) {
            gentl.genapiGetStringData(getPort((P *)0), feature, data);
        }
        template <typename P> std::vector<std::string> getStringList(const std::string &what) {
            return gentl.genapiGetStringList(getPort((P *)0), what);
        }
        template <typename P> void getRegister(const std::string &feature, void *data, size_t size) {
            gentl.genapiGetRegister(getPort((P *)0), feature, data, size);
        }
        template <typename P> void setInteger(const std::string &feature, int64_t value) {
            gentl.genapiSetInteger(getPort((P *)0), feature, value);
        }
        template <typename P> void setFloat(const std::string &feature, double value) {
            gentl.genapiSetFloat(getPort((P *)0), feature, value);
        }
        template <typename P> void setString(const std::string &feature, const std::string &value) {
            gentl.genapiSetString(getPort((P *)0), feature, value);
        }
        template <typename P> void setRegister(const std::string &feature, const void *data, size_t size) {
            gentl.genapiSetRegister(getPort((P *)0), feature, data, size);
        }
        template <typename P> void execute(const std::string &command) {
            gentl.genapiExecuteCommand(getPort((P *)0), command);
        }
        template <typename P> void attachEvent(uint64_t eventId, const void *buffer, size_t size) {
            gentl.genapiAttachEvent(getPort((P *)0), eventId, buffer, size);
        }
        template <typename P> void invalidate(const std::string &feature) {
            gentl.genapiInvalidate(getPort((P *)0), feature);
        }
        void runScript(const std::string &script) {
            if (dsh != GENTL_INVALID_HANDLE) {
                gentl.genapiRunScript(dsh, script);
            } else if (devh != GENTL_INVALID_HANDLE) {
                gentl.genapiRunScript(devh, script);
            } else if (ifh != GENTL_INVALID_HANDLE) {
                gentl.genapiRunScript(ifh, script);
            } else {
                gentl.genapiRunScript(tlh, script);
            }
        }
    private:
        gc::PORT_HANDLE getPort(SystemModule *)    { return tlh;  }
        gc::PORT_HANDLE getPort(InterfaceModule *) { return ifh;  }
        gc::PORT_HANDLE getPort(DeviceModule *)    { return devh; }
        gc::PORT_HANDLE getPort(StreamModule *)    { return dsh;  }
        gc::PORT_HANDLE getPort(RemoteModule *)    { return camh; }
        EGenTL &gentl;
        gc::PORT_HANDLE tlh;
        gc::PORT_HANDLE ifh;
        gc::PORT_HANDLE devh;
        gc::PORT_HANDLE dsh;
        gc::PORT_HANDLE camh;
};

/** @} */

} // EURESYS_NAMESPACE

#endif
