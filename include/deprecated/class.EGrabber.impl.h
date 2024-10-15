#ifdef EURESYS_USE_EGRABBER_DEPRECATED_API

namespace EURESYS_NAMESPACE {

template <typename CallbackModel> inline size_t EGrabber<CallbackModel>::announceBuffer(void *ptr, size_t size, void *userPointer) {
    return announceAndQueue(UserMemory(ptr, size, userPointer)).begin;
}

template <typename CallbackModel> template <typename M> inline std::string EGrabber<CallbackModel>::getInfoString(int32_t cmd) {
    return getInfo<M, std::string>(cmd);
}

template <typename CallbackModel> inline std::string EGrabber<CallbackModel>::getBufferInfoString(size_t bufferIndex, gc::BUFFER_INFO_CMD cmd) {
    return getBufferInfo<std::string>(bufferIndex, cmd);
}

} // namespace EURESYS_NAMESPACE

#endif
