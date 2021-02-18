#include <chrono>

#include "Engine.hpp"
#include "GlfwWindow.hpp"

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using engine::Engine;

Engine::Engine(GameLogicPtr& gameLogicPtr, BackendPtr& backendPtr) :
gameLogicPtr(gameLogicPtr),
backendPtr(backendPtr),
window(new GlfwWindow("RAMENgine", 800, 600)){}

void Engine::loop(){

    gameLogicPtr->init();

    timespec waitingTime{0, 0};
    long waitingTimeNano = (long) (1.0 / fps * 1'000'000'000.0);
    double lastLoopTime = glfwGetTime();
    int i = 0;

    while (!window->shouldClose()){

        backendPtr->clear();

        auto loopStart = high_resolution_clock::now();

        gameLogicPtr->input();
        gameLogicPtr->update();
        gameLogicPtr->render();

        window->swapBuffers();
        window->pollEvents();

        waitingTime.tv_nsec = waitingTimeNano -
                duration_cast<nanoseconds>(
                        high_resolution_clock::now() - loopStart
                        ).count();

        nanosleep(&waitingTime, nullptr);

        ++i;

        if (glfwGetTime() - lastLoopTime >= 1){

            lastLoopTime = glfwGetTime();
            window->setTitle((std::string() + std::to_string(i) + "FPS").c_str());
            i = 0;

        }
    }
}
