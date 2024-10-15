    protected:
        EGrabber(EGenTL &gentl, gc::TL_HANDLE tlh, gc::IF_HANDLE ifh, gc::DEV_HANDLE devh, gc::DS_HANDLE dsh);
    public:
        // push a buffer back to the input queue manually
        // Note: prefer using ScopedBuffer or Buffer object
        void push(const NewBufferData &buffer);
        // dynamic version of pop(OneOf<>)
        size_t popEventFilter(size_t eventFilter, uint64_t timeout, OneOfAll &oneOf, int *position);
        // dynamic version of processEvent<ANYDATA>
        // Note: this is an advanced usage, eventFilter is built by "or-ing"
        // event filters. E.g.
        // processEventFilter(getEventFilter<DATA1>() | getEventFilter<DATA2>())
        // Only available with CallbackOnDemand
        size_t processEventFilter(size_t eventFilter, uint64_t timeout);
        size_t processEventFilter(size_t eventFilter);
        // dynamic version of cancelEvent<ANYDATA>
        // Note: advanced usage, see processEventFilter
        // Only available with CallbackOnDemand
        void cancelEventFilter(size_t eventFilter);
        // dynamic version of getPendingEventCount<ANYDATA>
        // Only available with CallbackOnDemand
        size_t getPendingEventCountFilter(size_t eventFilter);
        // announceBusBuffer performs the following operations:
        // - announce a bus-addressable buffer to the data stream
        // - queue the bus-addressable buffer to the data stream input fifo
        // - return value is the buffer index
        // Note: announceBusBuffer does not invalidate existing buffer indexes
        // Prefer announceAndQueue(BusMemory(busAddress, size, userPointer))
        //   over announceBusBuffer(busAddress, size, userPointer)
        size_t announceBusBuffer(uint64_t busAddress, size_t size, void *userPointer = 0);
        // announceNvidiaRdmaBuffer performs the following operations:
        // - announce a device-addressable buffer to the data stream
        // - queue the device-addressable buffer to the data stream input fifo
        // - return value is the buffer index
        // Note: announceNvidiaRdmaBuffer does not invalidate existing buffer indexes
        // Prefer announceAndQueue(NvidiaRdmaMemory(deviceAddress, size, userPointer))
        //   over announceNvidiaRdmaBuffer(deviceAddress, size, userPointer)
        size_t announceNvidiaRdmaBuffer(void *deviceAddress, size_t size, void *userPointer = 0);
        // module ports of grabbers(ix)
        gc::PORT_HANDLE getSystemPort(int ix);
        gc::PORT_HANDLE getInterfacePort(int ix);
        gc::PORT_HANDLE getDevicePort(int ix);
        gc::PORT_HANDLE getStreamPort(int ix);
        gc::PORT_HANDLE getRemotePort(int ix);
    private:
        // for implementation purpose only
        static void onNewBufferEventC(ce::Eur_EGrabberBase box, ce::Eur_NewBufferData data, void *context);
        static void onIoToolboxEventC(ce::Eur_EGrabberBase box, ce::Eur_IoToolboxData data, void *context);
        static void onCicEventC(ce::Eur_EGrabberBase box, ce::Eur_CicData data, void *context);
        static void onDataStreamEventC(ce::Eur_EGrabberBase box, ce::Eur_DataStreamData data, void *context);
        static void onCxpInterfaceEventC(ce::Eur_EGrabberBase box, ce::Eur_CxpInterfaceData data, void *context);
        static void onDeviceErrorEventC(ce::Eur_EGrabberBase box, ce::Eur_DeviceErrorData data, void *context);
        static void onCxpDeviceEventC(ce::Eur_EGrabberBase box, ce::Eur_CxpDeviceData data, void *context);
        static void onRemoteDeviceEventC(ce::Eur_EGrabberBase box, ce::Eur_RemoteDeviceData data, void *context);
        static ge::GENAPI_UI_CALLBACK_RET_CODE onScriptUiCallbackC(ce::Eur_EGrabberBase box, const char *operation, void *context, ce::std_map_std_string_std_string args, ce::std_string value, void *callbackContext);
        static void onThreadStartC(ce::Eur_EGrabberBase box, ce::cEventType type, void *context);
        static void onThreadStopC(ce::Eur_EGrabberBase box, ce::cEventType type, void *context);
        void setNewBufferEventCallback(ce::Euresys_NewBufferEventCallback callback, void *context);
        void setIoToolboxEventCallback(ce::Euresys_IoToolboxEventCallback callback, void *context);
        void setCicEventCallback(ce::Euresys_CicEventCallback callback, void *context);
        void setDataStreamEventCallback(ce::Euresys_DataStreamEventCallback callback, void *context);
        void setCxpInterfaceEventCallback(ce::Euresys_CxpInterfaceEventCallback callback, void *context);
        void setDeviceErrorEventCallback(ce::Euresys_DeviceErrorEventCallback callback, void *context);
        void setCxpDeviceEventCallback(ce::Euresys_CxpDeviceEventCallback callback, void *context);
        void setRemoteDeviceEventCallback(ce::Euresys_RemoteDeviceEventCallback callback, void *context);
        void setScriptUiCallback(ce::Euresys_ScriptUiCallback callback, void *context);
        void setThreadStartCallback(ce::Euresys_ThreadStartCallback callback, void *context);
        void setThreadStopCallback(ce::Euresys_ThreadStopCallback callback, void *context);
