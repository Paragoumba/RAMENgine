#ifndef RAMENGINE_ENGINE_HPP
#define RAMENGINE_ENGINE_HPP

#include "Window.hpp"
#include "GameLogic.hpp"

using engine::Window;

namespace engine {

    class Engine {
    private:
        int fps = 60;
        Window* window;
        GameLogicPtr gameLogicPtr;

    public:
        Engine(GameLogicPtr& gameLogicPtr);

        void loop();
    };
}

#endif //RAMENGINE_ENGINE_HPP
