#ifndef RAMENGINE_CAMERA_HPP
#define RAMENGINE_CAMERA_HPP

#include <glm/glm.hpp>
#include <interfaces/Positionable.hpp>
#include <interfaces/Rotationable.hpp>

using glm::vec3;
using glm::mat4;

namespace engine {

    class Camera : public Positionable, public Rotationable {
    public:
        [[nodiscard]] mat4 getViewMatrix() const;
    };
}

#endif //RAMENGINE_CAMERA_HPP
