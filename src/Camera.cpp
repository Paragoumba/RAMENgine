#include <glm/ext/matrix_transform.hpp>
#include "Camera.hpp"

using engine::Camera;

mat4 engine::Camera::getViewMatrix() const {

    mat4 viewMatrix = glm::rotate(mat4(1.0f), glm::radians(rotation.x), vec3(1, 0, 0));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(rotation.y), vec3(0, 1, 0));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(rotation.z), vec3(0, 0, 1));

    viewMatrix = glm::translate(viewMatrix, vec3(-position.x, -position.y, -position.z));

    return viewMatrix;

}