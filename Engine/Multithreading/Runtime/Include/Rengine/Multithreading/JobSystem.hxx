#pragma once

#include <Rengine/Core/Definitions.hxx>
#include <Rengine/Multithreading/LockFreeJobQueue.hxx>
#include <atomic>
#include <functional>
#include <mutex>
#include <thread>
#include <vector>

// NOTE: Different values of this macro means different things:
// 0 < : Positve numbers indicate the number of threads to use.
//       It clamps to std::thread::hardware_concurrency() if higher than that.
// 0 = : Whatever the std::thread::hardware_concurrency is
// 0 > : Negative numbers indicate the number of threads to leave.
//       It clamps to 2 ... SOMETHING I CANNOT EXPLAIN RN ...
#ifndef REN_MT_JOB_SYSTEM_HW_CONCURRENCY
    #define REN_MT_JOB_SYSTEM_HW_CONCURRENCY 0
#endif

namespace Ren::MT
{
class JobSystem final
{
public:
    static JobSystem& GetInstance();

    JobSystem(const JobSystem&)            = delete;
    JobSystem& operator=(const JobSystem&) = delete;

    void Enqueue(std::function<void()> job);
    void Stop();

public:
    const static Int32 hardwareConcurrency;

private:
    JobSystem() = default;

    void Worker();

    LockFreeJobQueue _jobQueue;
    std::atomic<bool> _isRunning{true};
    std::mutex _queueMutex;

    std::vector<std::thread> _workers;
};
} // namespace Ren::MT
