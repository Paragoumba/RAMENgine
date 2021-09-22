#ifndef RAMENGINE_SCALABLE_HPP
#define RAMENGINE_SCALABLE_HPP

#include <glm/vec3.hpp>

using glm::vec3;

namespace engine {
    class Scalable {
    protected:
        vec3 scale;

    public:
        Scalable();

        [[nodiscard]] vec3& getScale();

        void setScale(float x, float y, float z);
        void setScale(vec3 scale);

        void rescale(float x = 1, float y = 1, float z = 1);
        void rescale(vec3 v);
    };
}

#endif //RAMENGINE_SCALABLE_HPP
