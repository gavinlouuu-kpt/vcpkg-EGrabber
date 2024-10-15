/* Copyright Euresys 2015 */

#ifndef EGRABBER_IMPL_HEADER_FILE
#define EGRABBER_IMPL_HEADER_FILE

#include <map>
#include "common/EGrabberBase.h"
#include "common/EventProcessorImpl.h"
#include "common/ModuleInfo.h"

namespace EURESYS_NAMESPACE {
namespace Internal {

template <typename CallbackModel> struct EGrabberBox {};
template <> struct EGrabberBox<CallbackOnDemand>     { typedef ce::Eur_EGrabber_CallbackOnDemand Type; };
template <> struct EGrabberBox<CallbackSingleThread> { typedef ce::Eur_EGrabber_CallbackSingleThread Type; };
template <> struct EGrabberBox<CallbackMultiThread>  { typedef ce::Eur_EGrabber_CallbackMultiThread Type; };

template <typename D1, typename D2>
static inline bool isSameEventDataType() {
    return (static_cast<int>(EventQueueIndex<D1>::VALUE) == static_cast<int>(EventQueueIndex<D2>::VALUE));
}

template <typename Dx, typename D>
static inline Dx eventdata_cast(const D &data) {
    if (!isSameEventDataType<Dx, D>()) {
        throw client_error("Internal::eventdata_cast: event data types are different");
    } else {
        return *(reinterpret_cast<const Dx *>(&data));
    }
}

template <typename D1, typename D2, typename D3,
          typename D4, typename D5, typename D6,
          typename D7, typename D8, typename D>
static inline void setOneOf(OneOf<D1, D2, D3, D4, D5, D6, D7, D8> &oneOf, int &position, const D &data) {
         if (isSameEventDataType<D, D1>()) { oneOf.data1 = eventdata_cast<D1>(data); position = 1; }
    else if (isSameEventDataType<D, D2>()) { oneOf.data2 = eventdata_cast<D2>(data); position = 2; }
    else if (isSameEventDataType<D, D3>()) { oneOf.data3 = eventdata_cast<D3>(data); position = 3; }
    else if (isSameEventDataType<D, D4>()) { oneOf.data4 = eventdata_cast<D4>(data); position = 4; }
    else if (isSameEventDataType<D, D5>()) { oneOf.data5 = eventdata_cast<D5>(data); position = 5; }
    else if (isSameEventDataType<D, D6>()) { oneOf.data6 = eventdata_cast<D6>(data); position = 6; }
    else if (isSameEventDataType<D, D7>()) { oneOf.data7 = eventdata_cast<D7>(data); position = 7; }
    else if (isSameEventDataType<D, D8>()) { oneOf.data8 = eventdata_cast<D8>(data); position = 8; }
    else { position = 0; }
}

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
