#pragma once

#include <Rengine/Application/IApplication.hpp>
#include <Rengine/Application/Window.hpp>
#include <Rengine/Core/Definitions.hpp>

namespace Ren
{

class GameApplication : public IApplication
{
public:
    GameApplication(int argc, char* argv[]);

    virtual Window* GetWindow() override;

    virtual void Close(Int32 exitCode = 0) override;
    virtual bool IsRunning() const override { return _isRunning; }

protected:
    virtual void Initialize() override;
    virtual void Run() override;
    virtual Int32 Cleanup() override;

private:
    Bool _isRunning{false};
    Int32 _exitCode{0};
    Window* _window{nullptr};
};

} // namespace Ren
