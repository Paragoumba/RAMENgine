#ifndef RAMENGINE_GLFWWINDOW_HPP
#define RAMENGINE_GLFWWINDOW_HPP

#include <GLFW/glfw3.h>

#include "Window.hpp"

using engine::Window;

namespace engine {

    class GlfwWindow : public Window {
    public:
        GlfwWindow(const char* title, int width, int height);

        void setTitle(const char* title) override;
        [[nodiscard]] bool shouldClose() const override;
        void swapBuffers() const override;
        void pollEvents() const override;
        void setSize(int width, int height) override;

        ~GlfwWindow();

    private:
        GLFWwindow* handle;
    };
}

#endif //RAMENGINE_GLFWWINDOW_HPP
