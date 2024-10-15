    public:
        bool isShared() const;
        void eventKillQuiet(gc::EVENT_HANDLE eh);
        void lockUpdates();
        void unlockUpdates();
