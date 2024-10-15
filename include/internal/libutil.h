/* Copyright Euresys 2021*/

#ifndef EURESYS_LIBUTIL_HEADER_FILE
#define EURESYS_LIBUTIL_HEADER_FILE

namespace EURESYS_NAMESPACE {
namespace Internal {

class egrabber_library_error: public std::runtime_error {
    public:
        int status;
        explicit egrabber_library_error(int status)
        : std::runtime_error(std::string("EGrabber library error status ") + intToString(status))
        , status(status)
        {}
        egrabber_library_error(int status, const std::string& description)
        : std::runtime_error(std::string("EGrabber library error status ") + intToString(status) + ", " + description)
        , status(status)
        {}
};

static inline void checkStatusCritical(int status) {
    if (status != 0) {
        throw egrabber_library_error(status, "an error occurred after an exception was already thrown");
    }
}

static inline void checkStatusCriticalCallback(const EGrabberDll &dll, int status) {
    if (status != 0) {
        dll.euInternal_lastCallbackError_setCallbackCriticalError();
    }
}

} // Internal
} // namespace EURESYS_NAMESPACE

#include "generated/libutil.generated.h"

#endif // EURESYS_LIBUTIL_HEADER_FILE
