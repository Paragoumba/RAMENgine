#ifndef CONFINED_ENGINE_HPP
#define CONFINED_ENGINE_HPP

#include "Window.hpp"
#include "GameLogic.hpp"

class Engine {
private:
    int fps = 60;
    Window* window;
    GameLogicPtr gameLogicPtr;

public:
    Engine(GameLogicPtr& gameLogicPtr);

    void loop();
};

#endif //CONFINED_ENGINE_HPP
