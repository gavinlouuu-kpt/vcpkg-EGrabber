#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API

namespace EURESYS_NAMESPACE {

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4996 ) // 'vsnprintf': This function or variable may be unsafe
#endif
inline void EGenTL::memento(const char *fmt, ...) {
    char text[256];
    va_list args;
    va_start(args, fmt);
    vsnprintf(text, sizeof(text), fmt, args);
    va_end(args);
    return memento(std::string(text));
}
#ifdef _MSC_VER
#pragma warning( pop )
#endif

inline std::string EGenTL::gcGetInfoString(gc::TL_INFO_CMD cmd) {
    return gcGetInfo<std::string>(cmd);
}

inline std::string EGenTL::gcGetPortInfoString(gc::PORT_HANDLE ph, gc::PORT_INFO_CMD cmd) {
    return gcGetPortInfo<std::string>(ph, cmd);
}

inline std::string EGenTL::eventGetDataInfoString(gc::EVENT_HANDLE eh,
                                   const void *buffer, size_t size,
                                   gc::EVENT_DATA_INFO_CMD cmd) {
    return eventGetDataInfo<std::string>(eh, buffer, size, cmd);
}

inline std::string EGenTL::eventGetInfoString(gc::EVENT_HANDLE eh, gc::EVENT_INFO_CMD cmd) {
    return eventGetInfo<std::string>(eh, cmd);
}

inline std::string EGenTL::tlGetInfoString(gc::TL_HANDLE tlh, gc::TL_INFO_CMD cmd) {
    return tlGetInfo<std::string>(tlh, cmd);
}

inline std::string EGenTL::tlGetInterfaceInfoString(gc::TL_HANDLE tlh, const std::string &ifID, gc::TL_INFO_CMD cmd) {
    return tlGetInterfaceInfo<std::string>(tlh, ifID, cmd);
}

inline std::string EGenTL::ifGetInfoString(gc::IF_HANDLE ifh, gc::INTERFACE_INFO_CMD cmd) {
    return ifGetInfo<std::string>(ifh, cmd);
}

inline std::string EGenTL::ifGetDeviceInfoString(gc::IF_HANDLE ifh, const std::string &devID, gc::INTERFACE_INFO_CMD cmd) {
    return ifGetDeviceInfo<std::string>(ifh, devID, cmd);
}

inline std::string EGenTL::devGetInfoString(gc::DEV_HANDLE devh, gc::DEVICE_INFO_CMD cmd) {
    return devGetInfo<std::string>(devh, cmd);
}

inline std::string EGenTL::dsGetInfoString(gc::DS_HANDLE dsh, gc::STREAM_INFO_CMD cmd) {
    return dsGetInfo<std::string>(dsh, cmd);
}

inline std::string EGenTL::dsGetBufferInfoString(gc::DS_HANDLE dsh, gc::BUFFER_HANDLE bh,
                                  gc::BUFFER_INFO_CMD cmd) {
    return dsGetBufferInfo<std::string>(dsh, bh, cmd);
}

inline std::string EGenTL::gcGetPortURLInfoString(gc::PORT_HANDLE h, uint32_t index, gc::URL_INFO_CMD cmd) {
    return gcGetPortURLInfo<std::string>(h, index, cmd);
}

} // namespace EURESYS_NAMESPACE

#endif

#ifdef EURESYS_USE_BAYER_DEPRECATED_API

namespace EURESYS_NAMESPACE {
namespace Internal {

static inline const char *PIXEL_FORMAT_to_const_char_p(ge::PIXEL_FORMAT format) {
    switch(format) {
        case ge::PIXEL_FORMAT_BAYER_GB8:
            return "BayerGB8";
        case ge::PIXEL_FORMAT_BAYER_BG8:
            return "BayerBG8";
        case ge::PIXEL_FORMAT_BAYER_RG8:
            return "BayerRG8";
        case ge::PIXEL_FORMAT_BAYER_GR8:
            return "BayerGR8";
        case ge::PIXEL_FORMAT_RGB24:
            return "RGB8";
        default:
            throw gentl_error(gc::GC_ERR_INVALID_PARAMETER, "BayerConvert: invalid bayer PIXEL_FORMAT " + intToString(format));
    }
}

static inline ge::IMAGE_CONVERT_OUTPUT_CONFIG BAYER_METHOD_to_IMAGE_CONVERT_OUTPUT_CONFIG(ge::BAYER_METHOD method) {
    switch (method) {
        case ge::BAYER_METHOD_LEGACY:
            return ge::IMAGE_CONVERT_OUTPUT_CONFIG_DEFAULT;
        case ge::BAYER_METHOD_ADVANCED:
            return ge::IMAGE_CONVERT_OUTPUT_CONFIG_BAYER_ADVANCED;
        default:
            throw gentl_error(gc::GC_ERR_INVALID_PARAMETER, "BayerConvert: invalid bayer method " + intToString(method));
    }
}

} // namespace Internal

inline void EGenTL::bayerConvert(ge::BAYER_METHOD method,
                  ge::PIXEL_FORMAT in_format, int in_width, int in_height, const void *in_pixels,
                  ge::PIXEL_FORMAT out_format, int out_width, int out_height, void *out_pixels,
                  const ge::ROI_DETAILS *roi_details,
                  void *reserved) {
    ge::ImageConvertInput input = IMAGE_CONVERT_INPUT(
        in_width,
        in_height,
        in_pixels,
        Internal::PIXEL_FORMAT_to_const_char_p(in_format),
        0, 0
    );
    ge::ImageConvertOutput output = IMAGE_CONVERT_OUTPUT(
        out_width,
        out_height,
        out_pixels,
        Internal::PIXEL_FORMAT_to_const_char_p(out_format),
        Internal::BAYER_METHOD_to_IMAGE_CONVERT_OUTPUT_CONFIG(method),
        ge::IMAGE_CONVERT_OUTPUT_OPERATION_COPY,
        0, 0
    );
    if (roi_details) {
        ge::ImageConvertROI roi = {
            roi_details->width,
            roi_details->height,
            roi_details->inOffsetX,
            roi_details->inOffsetY,
            roi_details->outOffsetX,
            roi_details->outOffsetY
        };
        return imageConvert(input, output, &roi);
    } else {
        return imageConvert(input, output, 0);
    }
}

} // namespace EURESYS_NAMESPACE

#endif
