#ifndef CONFINED_GLFWWINDOW_HPP
#define CONFINED_GLFWWINDOW_HPP

#include <GLFW/glfw3.h>

#include "Window.hpp"

class GlfwWindow : public Window {
public:
    GlfwWindow(const char* title, int width, int height);

    void setTitle(const char* title) override;
    [[nodiscard]] bool shouldClose() const override;
    void swapBuffers() const override;
    void update() const override;

    ~GlfwWindow();

private:
    GLFWwindow* handle;
};

#endif //CONFINED_GLFWWINDOW_HPP
