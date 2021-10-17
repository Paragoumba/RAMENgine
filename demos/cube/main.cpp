#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <glm/ext/matrix_clip_space.hpp>

#include <backends/OpenGLBackend.hpp>
#include <Engine.hpp>
#include <Shader.hpp>
#include <Camera.hpp>
#include <Object.hpp>
#include <GLFW/glfw3.h>

using engine::Engine;
using engine::GameLogic;
using engine::OpenGLBackend;
using engine::Object;
using engine::Camera;
using engine::Vertex;
using engine::Texture;
using engine::Color;

using glm::vec3;
using glm::vec2;

class CubeGameLogic : public GameLogic {
private:
    ObjectPtr cube;

public:
    Camera camera;
    Shader* shader{};

    void init(BackendPtr& backendPtr) override {

        Color white(1.0f, 1.0f, 1.0f, 1.0f);

        backendPtr->setClearColor(white);

        std::vector<Vertex> vertices{
                {vec3(-0.5, -0.5, -0.5), vec3(), vec2(0, 0)},
                {vec3(0.5, -0.5, -0.5),  vec3(), vec2(1, 0)},
                {vec3(0.5, 0.5, -0.5),   vec3(), vec2(1, 1)},
                {vec3(-0.5, 0.5, -0.5),  vec3(), vec2(0, 1)},
                {vec3(-0.5, -0.5, 0.5),  vec3(), vec2(0, 0)},
                {vec3(0.5, -0.5, 0.5),   vec3(), vec2(1, 0)},
                {vec3(0.5, 0.5, 0.5),    vec3(), vec2(1, 1)},
                {vec3(-0.5, 0.5, 0.5),   vec3(), vec2(0, 1)},
                {vec3(-0.5, 0.5, 0.5),   vec3(), vec2(1, 0)},
                {vec3(-0.5, 0.5, -0.5),  vec3(), vec2(1, 1)},
                {vec3(-0.5, -0.5, -0.5), vec3(), vec2(0, 1)},
                {vec3(0.5, 0.5, 0.5),    vec3(), vec2(1, 0)},
                {vec3(0.5, -0.5, -0.5),  vec3(), vec2(0, 1)},
                {vec3(0.5, -0.5, 0.5),   vec3(), vec2(0, 0)},
                {vec3(0.5, -0.5, -0.5),  vec3(), vec2(1, 1)},
                {vec3(-0.5, 0.5, 0.5),   vec3(), vec2(0, 0)}
        };

        std::vector<Index> indices {
                 0,  1,  2,  2,  3,  0,
                 4,  5,  6,  6,  7,  4,
                 8,  9, 10, 10,  4,  8,
                11,  2, 12, 12, 13, 11,
                10, 14,  5,  5,  4, 10,
                 3,  2, 11, 11, 15,  3
        };

        std::vector<Texture> textures {};

        MeshPtr cubeMeshPtr = backendPtr->createMesh(vertices, indices, textures);
        cube = std::make_shared<Object>(cubeMeshPtr);

        cube->move(0, 0, -2);

    }

    void update(double delta) override {

        cube->rotate((float) (std::cos(glfwGetTime() / 2) + 1) * 180,
                     0,
                     (float) (std::cos(glfwGetTime() / 2) + 1) * 180);

    }

    void render(BackendPtr& backendPtr) const override {

        shader->setMat4f("model", cube->getModelMatrix());
        backendPtr->renderMesh(cube->getMesh());

    }
};

int main(){

    auto* cubeLogic = new CubeGameLogic;
    GameLogicPtr gameLogicPtr(cubeLogic);
    BackendPtr backendPtr(new OpenGLBackend);

    Engine engine(gameLogicPtr, backendPtr);

    Shader shader("../../../res/shaders/scene_shader.vs", "../../../res/shaders/scene_shader.fs");

    cubeLogic->shader = &shader;
    shader.use();

    WindowPtr window = engine.getWindow();

    shader.setMat4f("projection", glm::perspective(
            glm::radians(60.0f),
            (float) window->getWidth() / (float) window->getHeight(),
            0.1f, 1000.0f));
    shader.setMat4f("view", cubeLogic->camera.getViewMatrix());

    engine.loop();

}