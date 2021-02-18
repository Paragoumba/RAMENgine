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
    };
}

#endif //RAMENGINE_SCALABLE_HPP
