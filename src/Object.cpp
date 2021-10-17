#include <glm/ext/matrix_transform.hpp>
#include <utility>
#include "Object.hpp"

using engine::Object;

Object::Object(MeshPtr meshPtr) : meshPtr(std::move(meshPtr)){}

MeshPtr engine::Object::getMesh() const {

    return meshPtr;

}

mat4 Object::getModelMatrix() const {

    glm::mat4 modelMatrix = glm::translate(glm::mat4(1.0f), position);

    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1, 0, 0));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0, 0, 1));

    modelMatrix = glm::scale(modelMatrix, scale);

    return modelMatrix;

}
