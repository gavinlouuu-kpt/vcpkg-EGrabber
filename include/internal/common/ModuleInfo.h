/* Copyright Euresys 2021 */

#ifndef EURESYS_MODULE_INFO_HEADER_FILE
#define EURESYS_MODULE_INFO_HEADER_FILE

namespace EURESYS_NAMESPACE {
namespace Internal {

template <typename M> struct ModuleInfo {
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
    std::string getInfoString(EGenTL &gentl, void *handle, int32_t cmd);
#endif
    template <typename T> T getInfo(EGenTL &gentl, void *handle, int32_t cmd);
};
template <> struct ModuleInfo<SystemModule> {
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
    std::string getInfoString(EGenTL &gentl, void *handle, int32_t cmd) {
        return gentl.tlGetInfoString(handle, cmd);
    }
#endif
    template <typename T> T getInfo(EGenTL &gentl, void *handle, int32_t cmd) {
        return gentl.tlGetInfo<T>(handle, cmd);
    }
};
template <> struct ModuleInfo<InterfaceModule> {
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
    std::string getInfoString(EGenTL &gentl, void *handle, int32_t cmd) {
        return gentl.ifGetInfoString(handle, cmd);
    }
#endif
    template <typename T> T getInfo(EGenTL &gentl, void *handle, int32_t cmd) {
        return gentl.ifGetInfo<T>(handle, cmd);
    }
};
template <> struct ModuleInfo<DeviceModule> {
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
    std::string getInfoString(EGenTL &gentl, void *handle, int32_t cmd) {
        return gentl.devGetInfoString(handle, cmd);
    }
#endif
    template <typename T> T getInfo(EGenTL &gentl, void *handle, int32_t cmd) {
        return gentl.devGetInfo<T>(handle, cmd);
    }
};
template <> struct ModuleInfo<StreamModule> {
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
    std::string getInfoString(EGenTL &gentl, void *handle, int32_t cmd) {
        return gentl.dsGetInfoString(handle, cmd);
    }
#endif
    template <typename T> T getInfo(EGenTL &gentl, void *handle, int32_t cmd) {
        return gentl.dsGetInfo<T>(handle, cmd);
    }
};

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
