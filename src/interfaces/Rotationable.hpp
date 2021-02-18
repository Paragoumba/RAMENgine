#ifndef RAMENGINE_ROTATIONABLE_HPP
#define RAMENGINE_ROTATIONABLE_HPP

#include <glm/vec3.hpp>

using glm::vec3;

namespace engine {
    class Rotationable {
    protected:
        vec3 rotation;

    public:
        Rotationable();

        [[nodiscard]] vec3 getRotation() const;

        void setRotation(float rx, float ry, float rz);
        void setRotation(vec3 rotation);

        void rotate(float rx, float ry, float rz);
        void rotate(vec3 v);
    };
}

#endif //RAMENGINE_ROTATIONABLE_HPP
