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

        [[nodiscard]] vec3& getPosition();

        virtual void setPosition(float x, float y, float z);
        virtual void setPosition(vec3 position);

        virtual void move(float x, float y, float z);
        virtual void move(vec3 v);
    };
}

#endif //RAMENGINE_POSITIONABLE_HPP
