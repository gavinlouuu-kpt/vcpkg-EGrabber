/* Copyright Euresys 2022 */

#ifndef EURESYS_CTI_PATH_HEADER_FILE
#define EURESYS_CTI_PATH_HEADER_FILE

#include <cstdlib>
#include "producers.h"

namespace EURESYS_NAMESPACE {
namespace Internal {

static inline std::string getArch() {
#if defined(__aarch64__) || defined(__arm64__)
    return "aarch64";
#else
    return "x86_64";
#endif
}

#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4996 ) // 'getenv': This function or variable may be unsafe
#endif

template<enum ProducerType P>
static inline std::string getEuresysCtiPath() {
    std::string envvar = getEuresysCtiEnvVariable<P>();
    const char *value = std::getenv(envvar.c_str());
    if (!value || !value[0]) {
#if !(defined(__linux__) || defined(__APPLE__))
        throw client_error(envvar + " is not set");
#endif
        std::string path("/opt/euresys/egrabber/lib/");
        path += getArch() + "/" + getProducerName<P>();
#if defined(__APPLE__)
        path = std::string("/usr/local") + path;
#endif
        return path;
    }
    return std::string(value);
}

static inline bool isSameName(const char *it, const char *ref) {
    while (*ref != 0) {
        if (::tolower(*it++) != ::tolower(*ref++)) {
            return false;
        }
    }
    return *it == 0;
}

static inline std::string getEuresysCtiPath() {
    const char *producerName = std::getenv("EURESYS_DEFAULT_GENTL_PRODUCER");
    if (!producerName) {
        return getEuresysCtiPath<COAXLINK_PRODUCER>();
    }
    if (producerName && isSameName(producerName, "gigelink")) {
        return getEuresysCtiPath<GIGELINK_PRODUCER>();
    }
    if (producerName && isSameName(producerName, "grablink")) {
        return getEuresysCtiPath<GRABLINK_PRODUCER>();
    }
    if (producerName && isSameName(producerName, "coaxlink")) {
        return getEuresysCtiPath<COAXLINK_PRODUCER>();
    }
    if (producerName && isSameName(producerName, "playlink")) {
        return getEuresysCtiPath<PLAYLINK_PRODUCER>();
    }
    if (producerName && isSameName(producerName, "pattl")) {
        return getEuresysCtiPath<PATTL_PRODUCER>();
    }
    std::string requestedProducer = producerName;
    throw client_error("unknown EURESYS_DEFAULT_GENTL_PRODUCER: " + requestedProducer);
}

#ifdef _MSC_VER
#pragma warning( pop )
#endif

} // namespace Internal

static inline std::string Coaxlink() {
    return Internal::getEuresysCtiPath<Internal::COAXLINK_PRODUCER>();
}

static inline std::string Grablink() {
    return Internal::getEuresysCtiPath<Internal::GRABLINK_PRODUCER>();
}

static inline std::string Gigelink() {
    return Internal::getEuresysCtiPath<Internal::GIGELINK_PRODUCER>();
}

static inline std::string Playlink() {
    return Internal::getEuresysCtiPath<Internal::PLAYLINK_PRODUCER>();
}

} // namespace EURESYS_NAMESPACE

#endif
