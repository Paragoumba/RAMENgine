#ifndef RAMENGINE_CAMERA_HPP
#define RAMENGINE_CAMERA_HPP

#include <glm/glm.hpp>

using glm::vec3;

namespace engine {

    class Camera {
    private:
        vec3 position;
        vec3 rotation;

    public:
        Camera();

        [[nodiscard]] vec3 getPosition() const;
        [[nodiscard]] vec3 getRotation() const;

        void setPosition(float x, float y, float z);
        void setPosition(vec3 position);

        void setRotation(float rx, float ry, float rz);
        void setRotation(vec3 rotation);

        void move(float x, float y, float z);
        void move(vec3 v);

        void rotate(float rx, float ry, float rz);
        void rotate(vec3 v);
    };
}

#endif //RAMENGINE_CAMERA_HPP
