#ifndef RAMENGINE_ENGINE_HPP
#define RAMENGINE_ENGINE_HPP

#include "Window.hpp"
#include "GameLogic.hpp"
#include "backends/Backend.hpp"

using engine::Window;

namespace engine {

    class Engine {
    private:
        int fps = 60;
        WindowPtr window;
        GameLogicPtr gameLogicPtr;
        BackendPtr backendPtr;

    public:
        Engine(GameLogicPtr& gameLogicPtr, BackendPtr& backendPtr);

        [[nodiscard]] BackendPtr getBackend() const;
        [[nodiscard]] WindowPtr getWindow() const;

        void loop();
    };
}

#endif //RAMENGINE_ENGINE_HPP
