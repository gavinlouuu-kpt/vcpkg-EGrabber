/* Copyright Euresys 2021 */

#ifndef EURESYS_MONOTONIC_TIME_HEADER_FILE
#define EURESYS_MONOTONIC_TIME_HEADER_FILE

namespace EURESYS_NAMESPACE {
namespace Internal {

class MonotonicTime
{
    public:
        MonotonicTime(EGenTL &gentl)
        : tick(gentl.getTimestampUs())
        {
        }
        static uint64_t elapsedMilliseconds(const MonotonicTime &t0,
                                            const MonotonicTime &t1)
        {
            return (t1.tick - t0.tick) / 1000;
        }
    private:
        uint64_t tick;
};

} // namespace Internal
} // namespace EURESYS_NAMESPACE

#endif
