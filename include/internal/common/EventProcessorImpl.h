/* Copyright Euresys 2021 */

#ifndef COMMON_EVENTPROCESSOR_IMPL_HEADER_FILE
#define COMMON_EVENTPROCESSOR_IMPL_HEADER_FILE

namespace EURESYS_NAMESPACE {
namespace Internal {

template <typename DATA> struct EventTag {};

template <typename T> struct EventQueueIndex         { /* enum { VALUE = index }; */ };
template <> struct EventQueueIndex<NewBufferData>    { enum { VALUE = 0 }; };
template <> struct EventQueueIndex<IoToolboxData>    { enum { VALUE = 1 }; };
template <> struct EventQueueIndex<CicData>          { enum { VALUE = 2 }; };
template <> struct EventQueueIndex<DataStreamData>   { enum { VALUE = 3 }; };
template <> struct EventQueueIndex<CxpInterfaceData> { enum { VALUE = 4 }; };
template <> struct EventQueueIndex<DeviceErrorData>  { enum { VALUE = 5 }; };
template <> struct EventQueueIndex<CxpDeviceData>    { enum { VALUE = 6 }; };
template <> struct EventQueueIndex<RemoteDeviceData> { enum { VALUE = 7 }; };

struct             EventQueueCount                   { enum { VALUE = 8 }; };
template <> struct EventQueueIndex<Undefined>        { enum { VALUE = EventQueueCount::VALUE }; }; // -> index to ignore

template <typename T> struct EventFilter             { enum { VALUE = 1 << EventQueueIndex<T>::VALUE }; };
template <>           struct EventFilter<Undefined>  { enum { VALUE = 0 }; };
template <>           struct EventFilter<OneOfAll>   { enum { VALUE = -1 }; };
template <>           struct EventFilter<All>        { enum { VALUE = -1 }; };

template <typename DATA> inline size_t getEventFilter() {
    return EventFilter<DATA>::VALUE;
}

template <typename D1, typename D2, typename D3,
          typename D4, typename D5, typename D6,
          typename D7, typename D8>
inline size_t filter() {
    return EventFilter<D1>::VALUE |
           EventFilter<D2>::VALUE |
           EventFilter<D3>::VALUE |
           EventFilter<D4>::VALUE |
           EventFilter<D5>::VALUE |
           EventFilter<D6>::VALUE |
           EventFilter<D7>::VALUE |
           EventFilter<D8>::VALUE;
}

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
