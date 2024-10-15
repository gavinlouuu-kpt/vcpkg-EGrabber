/* Copyright Euresys 2021 */

#ifndef INTERNAL_EGRABBER_TYPES_HEADER_FILE
#define INTERNAL_EGRABBER_TYPES_HEADER_FILE

namespace EURESYS_NAMESPACE {

namespace Internal {

enum EGrabberTypeId {
    EGrabberTypeNone        = 0,
    EGrabberTypeCameraCod   = 1,
    EGrabberTypeCameraCst   = 2,
    EGrabberTypeCameraCmt   = 3,
};

template <typename M> struct ModuleInfo;

} // Internal

} // EURESYS_NAMESPACE

#endif
