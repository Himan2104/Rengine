#pragma once

namespace Ren
{
namespace Application
{
    class IApplication
    {

    protected:
        virtual void Tick() = 0;

        friend class Bootstrapper;
    };
} // namespace Application
} // namespace Ren
