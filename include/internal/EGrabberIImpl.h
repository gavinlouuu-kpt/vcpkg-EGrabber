/* Copyright Euresys 2015 */

#ifndef EGRABBER_IIMPL_HEADER_FILE
#define EGRABBER_IIMPL_HEADER_FILE

#include "generated/EGrabber.generated.h"
#include "class.EGrabber.impl.h"
#include "../deprecated/class.EGrabber.impl.h"
#include "generated/ECameraBuffer.generated.h"

namespace EURESYS_NAMESPACE {

inline Buffer::Buffer(const NewBufferData &data)
: data(data)
{}
inline void Buffer::push(Internal::EGrabberBase &grabber) {
    switch (data.ownerType) {
        case Internal::EGrabberTypeCameraCod:
            Internal::ECameraBufferPush<CallbackOnDemand>(grabber, data);
            break;
        case Internal::EGrabberTypeCameraCst:
            Internal::ECameraBufferPush<CallbackSingleThread>(grabber, data);
            break;
        case Internal::EGrabberTypeCameraCmt:
            Internal::ECameraBufferPush<CallbackMultiThread>(grabber, data);
            break;
        default:
            grabber.getGenTL().dsQueueBuffer(data.dsh, data.bh);
            break;
    }
}
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
inline std::string Buffer::getInfoString(Internal::EGrabberBase &grabber, gc::BUFFER_INFO_CMD cmd) {
    switch (data.ownerType) {
        case Internal::EGrabberTypeCameraCod:
            return Internal::ECameraBufferGetInfo<CallbackOnDemand, std::string>(grabber, data, cmd);
        case Internal::EGrabberTypeCameraCst:
            return Internal::ECameraBufferGetInfo<CallbackSingleThread, std::string>(grabber, data, cmd);
        case Internal::EGrabberTypeCameraCmt:
            return Internal::ECameraBufferGetInfo<CallbackMultiThread, std::string>(grabber, data, cmd);
        default:
            return grabber.getGenTL().dsGetBufferInfoString(data.dsh, data.bh, cmd);
    }
}
#endif
template <typename T> inline T Buffer::getInfo(Internal::EGrabberBase &grabber, gc::BUFFER_INFO_CMD cmd) {
    switch (data.ownerType) {
        case Internal::EGrabberTypeCameraCod:
            return Internal::ECameraBufferGetInfo<CallbackOnDemand, T>(grabber, data, cmd);
        case Internal::EGrabberTypeCameraCst:
            return Internal::ECameraBufferGetInfo<CallbackSingleThread, T>(grabber, data, cmd);
        case Internal::EGrabberTypeCameraCmt:
            return Internal::ECameraBufferGetInfo<CallbackMultiThread, T>(grabber, data, cmd);
        default:
            return grabber.getGenTL().dsGetBufferInfo<T>(data.dsh, data.bh, cmd);
    }
}
inline void *Buffer::getUserPointer() {
    return data.userPointer;
}
inline void Buffer::saveToDisk(Internal::EGrabberBase &grabber, const std::string &filepath, int64_t index, const ge::ImageSaveToDiskParams *params) {
    BufferInfo bi(getInfo(grabber));
    ge::ImageConvertInput input = IMAGE_CONVERT_INPUT(static_cast<int>(bi.width),
                                                      static_cast<int>(bi.deliveredHeight),
                                                      bi.base,
                                                      bi.pixelFormat.c_str(),
                                                      &bi.size,
                                                      &bi.linePitch);
    return grabber.getGenTL().imageSaveToDisk(input, filepath, index, params);
}
inline BufferInfo Buffer::getInfo(Internal::EGrabberBase &grabber) {
    switch (data.ownerType) {
        case Internal::EGrabberTypeCameraCod:
            return Internal::ECameraBufferGetInfo<CallbackOnDemand>(grabber, data);
        case Internal::EGrabberTypeCameraCst:
            return Internal::ECameraBufferGetInfo<CallbackSingleThread>(grabber, data);
        case Internal::EGrabberTypeCameraCmt:
            return Internal::ECameraBufferGetInfo<CallbackMultiThread>(grabber, data);
        default:
            return grabber.getGenTL().dsGetBufferInfo(data.dsh, data.bh);
    }
}

inline ScopedBuffer::ScopedBuffer(EGrabber<CallbackOnDemand> &grabberSimple, uint64_t timeout)
: grabber(grabberSimple)
, buffer(grabberSimple.pop(timeout))
{}
inline ScopedBuffer::ScopedBuffer(Internal::EGrabberBase &grabber, const NewBufferData &data)
: grabber(grabber)
, buffer(data)
{}
inline ScopedBuffer::~ScopedBuffer() {
    try {
        buffer.push(grabber);
    } catch (...) {
    }
}
#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API
inline std::string ScopedBuffer::getInfoString(gc::BUFFER_INFO_CMD cmd) {
    return buffer.getInfoString(grabber, cmd);
}
#endif
template <typename T> inline T ScopedBuffer::getInfo(gc::BUFFER_INFO_CMD cmd) {
    return buffer.template getInfo<T>(grabber, cmd);
}
inline void *ScopedBuffer::getUserPointer() {
    return buffer.getUserPointer();
}
inline void ScopedBuffer::saveToDisk(const std::string &filepath, int64_t index, const ge::ImageSaveToDiskParams *params) {
    return buffer.saveToDisk(grabber, filepath, index, params);
}
inline BufferInfo ScopedBuffer::getInfo() {
    return buffer.getInfo(grabber);
}


} // namespace EURESYS_NAMESPACE

#include "generated/numid.h"

#endif
