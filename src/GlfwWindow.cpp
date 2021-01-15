#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GlfwWindow.hpp"
#include "exceptions/WindowException.hpp"
#include "Logger.hpp"

using logger::Logger;

GlfwWindow::GlfwWindow(const char* title, int width, int height) : Window(width, height){

    Logger& logger = Logger::getLogger();

    if (title == nullptr){

        logger.logw("Argument title is null in Window constructor.\nUsing default value (\"\") instead.");
        title = "";

    }

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    handle = glfwCreateWindow(width, height, title, nullptr, nullptr);

    glfwMakeContextCurrent(handle);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){

        glfwTerminate();

        throw WindowException("Failed to initialize GLAD.");

    }

    glViewport(0, 0, width, height);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glfwSetFramebufferSizeCallback(handle, [](GLFWwindow* _handle, int newWidth, int newHeight){

        /*Transformation::setProjectionMatrix(
                glm::radians(60.0f),
                (float) newWidth / (float) newHeight,
                0.1f,
                100.0f
        );*/

        glViewport(0, 0, newWidth, newHeight);

    });

    glfwSetKeyCallback(handle, [](GLFWwindow* window, int key, int scancode, int action, int mods){

        if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE){

            glfwSetWindowShouldClose(window, true);

        }
    });

    /*Transformation::setProjectionMatrix(
            glm::radians(60.0f),
            (float) width / (float) m_height,
            0.1f,
            100.0f
    );*/

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    /*setCursor(Utils::getPath("../res/imgs/cursor.png").c_str());*/

}

void GlfwWindow::setTitle(const char* title){

    glfwSetWindowTitle(handle, title);

}

bool GlfwWindow::shouldClose() const {

    return glfwWindowShouldClose(handle);

}

void GlfwWindow::swapBuffers() const {

    glfwSwapBuffers(handle);

}

void GlfwWindow::update() const{

    glfwPollEvents();

}

GlfwWindow::~GlfwWindow(){

    glfwTerminate();

}
