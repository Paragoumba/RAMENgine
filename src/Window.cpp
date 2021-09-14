#include "Window.hpp"

using engine::Window;

Window::Window(int width, int height) : m_width(width), m_height(height){}

int engine::Window::getWidth() const {

    return m_width;

}

int engine::Window::getHeight() const {

    return m_height;

}

Window::~Window() = default;
