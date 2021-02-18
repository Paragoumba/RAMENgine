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
        Window* window;
        GameLogicPtr gameLogicPtr;
        BackendPtr backendPtr;

    public:
        Engine(GameLogicPtr& gameLogicPtr, BackendPtr& backendPtr);

        void loop();
    };
}

#endif //RAMENGINE_ENGINE_HPP
