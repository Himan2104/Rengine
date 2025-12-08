#include <Rengine/Core/Log.hxx>
#include <Rengine/Multithreading/JobSystem.hxx>

namespace Ren::MT
{

JobSystem& JobSystem::GetInstance()
{
    static JobSystem js;
    return js;
}

void JobSystem::Enqueue(std::function<void()> job)
{
    _jobQueue.push(job);

#ifdef REN_REPORT_NEW_JOB
    REN_LOG_INFO("[JobSystem] New job added!"); // TODO: Log something better than that lmao.
#endif
}

void JobSystem::Stop() { _isRunning.store(false); }

void JobSystem::Worker()
{
    while (_isRunning)
    {
        std::function<void()> job;
        if (_jobQueue.pop(job)) job();
    }
}

} // namespace Ren::MT
