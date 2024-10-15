    public:
        // for implementation purpose only
        EGenTL &getGenTL();

    private:
        EGenTL &gentl;
        typename Internal::EGrabberBox<CallbackModel>::Type box;
        EGrabber(const EGrabber<CallbackModel>&); // EGrabber objects cannot be copied
        EGrabber<CallbackModel> &operator=(const EGrabber<CallbackModel>&); // EGrabber objects cannot be copied
        // for implementation purpose only
        void setCallbacks();
        template <typename D1, typename D2, typename D3,
                  typename D4, typename D5, typename D6,
                  typename D7, typename D8>
        size_t doProcessEvent(Internal::EventTag<OneOf<D1, D2, D3, D4, D5, D6, D7, D8> > tag, uint64_t timeout);
        template <typename DATA>
        size_t doProcessEvent(Internal::EventTag<DATA> tag, uint64_t timeout);
        template <typename D1, typename D2, typename D3,
                  typename D4, typename D5, typename D6,
                  typename D7, typename D8>
        void doCancelEvent(Internal::EventTag<OneOf<D1, D2, D3, D4, D5, D6, D7, D8> > tag);
        template <typename DATA>
        void doCancelEvent(Internal::EventTag<DATA> tag);
        template <typename D1, typename D2, typename D3,
                  typename D4, typename D5, typename D6,
                  typename D7, typename D8>
        size_t doGetPendingEventCount(Internal::EventTag<OneOf<D1, D2, D3, D4, D5, D6, D7, D8> > tag);
        template <typename DATA>
        size_t doGetPendingEventCount(Internal::EventTag<DATA> tag);
        #include "class.EGrabber.generate.h"
