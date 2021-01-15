#include <bits/types/struct_timespec.h>
#include <chrono>

#include "Engine.hpp"
#include "GlfwWindow.hpp"
#include "Logger.hpp"

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

Engine::Engine(GameLogicPtr& gameLogicPtr) :
gameLogicPtr(gameLogicPtr),
window(new GlfwWindow("Confined", 800, 600)){}

void Engine::loop(){

    timespec waitingTime{0, 0};
    long waitingTimeNano = (long) (1.0 / fps * 1'000'000'000.0);
    double lastLoopTime = glfwGetTime();
    int i = 0;

    while (!window->shouldClose()){

        glClear(GL_COLOR_BUFFER_BIT);

        window->swapBuffers();

        auto loopStart = high_resolution_clock::now();

        waitingTime.tv_nsec = waitingTimeNano -
                duration_cast<nanoseconds>(
                        high_resolution_clock::now() - loopStart
                        ).count();

        nanosleep(&waitingTime, nullptr);
        window->update();

        ++i;

        if (glfwGetTime() - lastLoopTime >= 1){

            lastLoopTime = glfwGetTime();
            window->setTitle((std::string() + std::to_string(i) + "FPS").c_str());
            i = 0;

        }
    }
}
