cmake_minimum_required(VERSION 3.16)

add_library(RAMENgine
        Engine.cpp
        Logger.cpp
        GlfwWindow.cpp
        Window.cpp
        exceptions/Exception.cpp
        exceptions/WindowException.cpp
        GameLogic.hpp
        backends/OpenGLBackend.cpp
        Shader.cpp
        Camera.cpp
        Material.cpp
        interfaces/Positionable.cpp
        interfaces/Rotationable.cpp
        interfaces/Scalable.cpp)

target_include_directories(RAMENgine PUBLIC .)
target_link_libraries(RAMENgine GLAD glfw GL)