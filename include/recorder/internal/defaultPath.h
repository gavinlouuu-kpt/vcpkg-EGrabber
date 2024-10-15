#ifndef DEFAULTPATH_H
#define DEFAULTPATH_H

#include <cstdlib>

#include <string>

namespace Euresys {
namespace EGrabberRecorder {
namespace Internal {

inline const char *getRecorderFileName() {
#if defined(__APPLE__)
    return "librecorder.dylib";
#elif defined(linux) || defined(__linux) || defined(__linux__)
    return "librecorder.so";
#else
    return "recorder.dll";
#endif
}

inline std::string join(const std::string &left, const std::string &right) {
    #if defined(_WIN32)
        return left + "\\" + right;
    #else
        return left + "/" + right;
    #endif
}

#if defined(_M_AMD64) || defined(__amd64__) || defined(__x86_64__)
#   define EURESYS_ARCH_DIR_NAME "x86_64"
#elif defined(_M_ARM64) || defined(__aarch64__)
#   define EURESYS_ARCH_DIR_NAME "aarch64"
#else
#   error "Unsupported architecture"
#endif

inline std::string defaultLibDir() {
    #if defined(__APPLE__)
        return "/usr/local/opt/euresys/egrabber/lib/" EURESYS_ARCH_DIR_NAME;
    #elif defined(linux) || defined(__linux) || defined(__linux__)
        return "/opt/euresys/egrabber/lib/" EURESYS_ARCH_DIR_NAME;
    #elif defined(_WIN32)
        return "C:\\Program Files\\Euresys\\eGrabber\\cti\\" EURESYS_ARCH_DIR_NAME;
    #else
    #   error "Unsupported platform"
    #endif
}

#undef EURESYS_ARCH_DIR_NAME

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4996 ) // 'getenv': This function or variable may be unsafe
#endif

inline std::string getDefaultLibraryPath() {

    std::string fileName = getRecorderFileName();
    std::string libDir;

    if (const char *path = std::getenv("EURESYS_RECORDER_LIB64")) {
        libDir = path;
    } else if (const char *path = std::getenv("EURESYS_EGRABBER_LIB64")) {
        libDir = path;
    } else {
        libDir = defaultLibDir();
    }

    return join(libDir, fileName);
}

#ifdef _MSC_VER
#pragma warning( pop )
#endif

} // namespace Internal
} // namespace EGrabberRecorder
} // namespace Euresys

#endif
