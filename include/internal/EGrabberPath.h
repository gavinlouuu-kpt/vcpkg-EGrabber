/* Copyright Euresys 2022 */

#ifndef EURESYS_EGRABBER_PATH_HEADER_FILE
#define EURESYS_EGRABBER_PATH_HEADER_FILE

#include <cstdlib>
#include "common/ctiPath.h"

namespace EURESYS_NAMESPACE {
namespace Internal {

static inline std::string getLibraryFileName(const std::string &name) {
#if defined(__APPLE__)
    return "lib" + name + ".dylib";
#elif defined(linux) || defined(__linux) || defined(__linux__)
    return "lib" + name + ".so";
#else
    return name + ".dll";
#endif
}

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4996 ) // 'getenv': This function or variable may be unsafe
#endif

static inline std::string getEGrabberLibPath() {
    std::string envvar("EURESYS_EGRABBER_LIB64");
    const char *value = std::getenv(envvar.c_str());
    if (!value || !value[0]) {
#if !(defined(__linux__) || defined(__APPLE__))
        throw client_error(envvar + " is not set");
#endif
        std::string path("/opt/euresys/egrabber/lib/");
        path += getArch() + "/" + getLibraryFileName("egrabber");
#if defined(__APPLE__)
        path = std::string("/usr/local") + path;
#endif
        return path;
    }
    return std::string(value) + "/" + getLibraryFileName("egrabber");
}

#ifdef _MSC_VER
#pragma warning( pop )
#endif

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
