/* Copyright Euresys 2015 */

#ifndef EURESYS_THREADS_HEADER_FILE
#define EURESYS_THREADS_HEADER_FILE

#if defined(linux) || defined(__linux) || defined(__linux__) || defined(__APPLE__)

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 600
#endif
#include <pthread.h>
#include <unistd.h>
#include <errno.h>

#endif

namespace EURESYS_NAMESPACE {
namespace Internal {

#if defined(linux) || defined(__linux) || defined(__linux__) || defined(__APPLE__)

class Thread
{
    public:
        Thread()
        : created(false)
        , stopping(false)
        {}
        virtual ~Thread() {
        }
        virtual void onStop() {
        }
        virtual void run(volatile bool &isStopping) = 0;
        void start() {
            AutoLock lock1(startStopMutex);
            AutoLock lock2(stateMutex);
            if (created) {
                throw thread_error("already started");
            }
            stopping = false;
            int res = pthread_create(&thread_id, NULL, threadFunction, this);
            if (res) {
                throw thread_error("creation failure");
            }
            created = true;
        }
        void stop() {
            AutoLock lock1(startStopMutex);
            if (!created) {
                return;
            }
            stopping = true;
            onStop();
            int res = pthread_join(thread_id, NULL);
            AutoLock lock2(stateMutex);
            stopping = false;
            if (res) {
                throw thread_error("join error");
            }
            created = false;
        }
        bool isCurrentThread() {
            AutoLock lock(stateMutex);
            if (created) {
                return pthread_equal(pthread_self(), thread_id) != 0;
            }
            return false;
        }
        static void sleepMs(unsigned int ms) {
            useconds_t us = static_cast<useconds_t>(ms) * 1000;
            if (static_cast<unsigned long long>(us) != 1000ULL * ms) {
                throw thread_error("invalid number of ms passed to sleepMs");
            }
            if (usleep(us)) {
                if (us) {
                    switch (errno) {
                        case EINTR:     throw thread_error("usleep error (EINTR)");
                        case EINVAL:    throw thread_error("usleep error (EINVAL)");
                        default:        throw thread_error("usleep error");
                    }
                }
            }
        }
    private:
        static void *threadFunction(void *arg) {
            Thread *self = reinterpret_cast<Thread *>(arg);
            self->run(self->stopping);
            return 0;
        }
        ConcurrencyLock startStopMutex;
        ConcurrencyLock stateMutex;
        pthread_t thread_id;
        volatile bool created;
        volatile bool stopping;
};

#else

class Thread
{
    public:
        Thread()
        : handle(NULL)
        , stopping(false)
        {}
        virtual ~Thread() {
        }
        virtual void onStop() {
        }
        virtual void run(volatile bool &isStopping) = 0;
        void start() {
            AutoLock lock1(startStopMutex);
            AutoLock lock2(stateMutex);
            if (handle != NULL) {
                throw thread_error("already started");
            }
            stopping = false;
            handle = CreateThread(NULL, 0, threadFunction, this, 0, &id);
            if (handle == NULL) {
                throw thread_error("creation failure");
            }
        }
        void stop() {
            AutoLock lock1(startStopMutex);
            if (handle == NULL) {
                return;
            }
            stopping = true;
            onStop();
            DWORD res = WaitForSingleObject(handle, INFINITE);
            AutoLock lock2(stateMutex);
            stopping = false;
            if (res != WAIT_OBJECT_0) {
                throw thread_error("join error");
            }
            CloseHandle(handle);
            handle = NULL;
        }
        bool isCurrentThread() {
            AutoLock lock(stateMutex);
            if (handle != NULL) {
                return GetCurrentThreadId() == id;
            }
            return false;
        }
        static void sleepMs(unsigned int ms) {
            Sleep(ms);
        }
    private:
        static DWORD WINAPI threadFunction(LPVOID lpParam) {
            Thread *self = reinterpret_cast<Thread *>(lpParam);
            self->run(self->stopping);
            return 0;
        }
        ConcurrencyLock startStopMutex;
        ConcurrencyLock stateMutex;
        DWORD id;
        volatile HANDLE handle;
        volatile bool stopping;
};

#endif

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
