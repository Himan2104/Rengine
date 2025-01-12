#pragma once

namespace Ren
{
    class IApplication
    {
    public:
        virtual ~IApplication() = default;

    protected:
        virtual int Start(int argc, char** argv) = 0;

        friend class Engine;
    };
}