#ifndef RAMENGINE_POSITIONABLE_HPP
#define RAMENGINE_POSITIONABLE_HPP

#include <glm/vec3.hpp>

using glm::vec3;

namespace engine {
    class Positionable {
    protected:
        vec3 position;

    public:
        Positionable();

        [[nodiscard]] vec3 getPosition() const;

        void setPosition(float x, float y, float z);
        void setPosition(vec3 position);

        void move(float x, float y, float z);
        void move(vec3 v);
    };
}

#endif //RAMENGINE_POSITIONABLE_HPP
