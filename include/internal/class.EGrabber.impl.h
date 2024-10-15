/* Copyright Euresys 2021*/

#ifndef EURESYS_CLASS_EGRABBER_IMPL_HEADER_FILE
#define EURESYS_CLASS_EGRABBER_IMPL_HEADER_FILE

namespace EURESYS_NAMESPACE {

template <>
template <typename D1, typename D2, typename D3,
          typename D4, typename D5, typename D6,
          typename D7, typename D8>
inline size_t EGrabber<CallbackOnDemand>::pop(OneOf<D1, D2, D3, D4, D5, D6, D7, D8> &oneOf, int &position, uint64_t timeout) {
    OneOfAll oneOfAll;
    int ooaPosition;
    size_t numInQueue = popEventFilter(Internal::filter<D1, D2, D3, D4, D5, D6, D7, D8>(), timeout, oneOfAll, &ooaPosition);
    switch (ooaPosition) {
        case 1: Internal::setOneOf(oneOf, position, oneOfAll.data1); break;
        case 2: Internal::setOneOf(oneOf, position, oneOfAll.data2); break;
        case 3: Internal::setOneOf(oneOf, position, oneOfAll.data3); break;
        case 4: Internal::setOneOf(oneOf, position, oneOfAll.data4); break;
        case 5: Internal::setOneOf(oneOf, position, oneOfAll.data5); break;
        case 6: Internal::setOneOf(oneOf, position, oneOfAll.data6); break;
        case 7: Internal::setOneOf(oneOf, position, oneOfAll.data7); break;
        case 8: Internal::setOneOf(oneOf, position, oneOfAll.data8); break;
        default: position = 0; break;
    }
    return numInQueue;
}

template <>
template <typename DATA>
inline size_t EGrabber<CallbackOnDemand>::processEvent(uint64_t timeout) {
    return doProcessEvent(Internal::EventTag<DATA>(), timeout);
}
template <>
template <typename DATA>
inline void EGrabber<CallbackOnDemand>::cancelEvent() {
    doCancelEvent(Internal::EventTag<DATA>());
}
template <>
template <typename DATA>
inline size_t EGrabber<CallbackOnDemand>::getPendingEventCount() {
    return doGetPendingEventCount(Internal::EventTag<DATA>());
}

template <typename CBM>
inline EGenTL & EGrabber<CBM>::getGenTL() {
    return gentl;
}

template <typename CBM>
inline void EGrabber<CBM>::setCallbacks() {
    setNewBufferEventCallback(&onNewBufferEventC, this);
    setIoToolboxEventCallback(&onIoToolboxEventC, this);
    setCicEventCallback(&onCicEventC, this);
    setDataStreamEventCallback(&onDataStreamEventC, this);
    setCxpInterfaceEventCallback(&onCxpInterfaceEventC, this);
    setDeviceErrorEventCallback(&onDeviceErrorEventC, this);
    setCxpDeviceEventCallback(&onCxpDeviceEventC, this);
    setRemoteDeviceEventCallback(&onRemoteDeviceEventC, this);
    setScriptUiCallback(&onScriptUiCallbackC, this);
    setThreadStartCallback(&onThreadStartC, this);
    setThreadStopCallback(&onThreadStopC, this);
}

template <>
template <typename D1, typename D2, typename D3,
          typename D4, typename D5, typename D6,
          typename D7, typename D8>
inline size_t EGrabber<CallbackOnDemand>::doProcessEvent(Internal::EventTag<OneOf<D1, D2, D3, D4, D5, D6, D7, D8> > tag, uint64_t timeout) {
    return processEventFilter(Internal::filter<D1, D2, D3, D4, D5, D6, D7, D8>(), timeout);
}
template <>
template <typename DATA>
inline size_t EGrabber<CallbackOnDemand>::doProcessEvent(Internal::EventTag<DATA> tag, uint64_t timeout) {
    return processEventFilter(Internal::getEventFilter<DATA>(), timeout);
}
template <>
template <typename D1, typename D2, typename D3,
          typename D4, typename D5, typename D6,
          typename D7, typename D8>
inline void EGrabber<CallbackOnDemand>::doCancelEvent(Internal::EventTag<OneOf<D1, D2, D3, D4, D5, D6, D7, D8> > tag) {
    cancelEventFilter(Internal::filter<D1, D2, D3, D4, D5, D6, D7, D8>());
}
template <>
template <typename DATA>
inline void EGrabber<CallbackOnDemand>::doCancelEvent(Internal::EventTag<DATA> tag) {
    cancelEventFilter(Internal::getEventFilter<DATA>());
}
template <>
template <typename D1, typename D2, typename D3,
          typename D4, typename D5, typename D6,
          typename D7, typename D8>
inline size_t EGrabber<CallbackOnDemand>::doGetPendingEventCount(Internal::EventTag<OneOf<D1, D2, D3, D4, D5, D6, D7, D8> > tag) {
    return getPendingEventCountFilter(Internal::filter<D1, D2, D3, D4, D5, D6, D7, D8>());
}
template <>
template <typename DATA>
inline size_t EGrabber<CallbackOnDemand>::doGetPendingEventCount(Internal::EventTag<DATA> tag) {
    return getPendingEventCountFilter(Internal::getEventFilter<DATA>());
}

template <typename CBM>
inline EGrabberGenICam EGrabber<CBM>::grabbers(int ix) {
    return EGrabberGenICam(gentl,
                           getSystemPort(ix),
                           getInterfacePort(ix),
                           getDevicePort(ix),
                           getStreamPort(ix),
                           getRemotePort(ix));
}

} // namespace EURESYS_NAMESPACE

#endif
