#ifndef RAMENGINE_OBJECT_HPP
#define RAMENGINE_OBJECT_HPP

#include <glm/glm.hpp>
#include <interfaces/Positionable.hpp>
#include <interfaces/Rotationable.hpp>
#include <interfaces/Scalable.hpp>

#include "Mesh.hpp"

using glm::vec3;
using glm::mat4;

namespace engine {

    class Object: public Positionable, public Rotationable, public Scalable {
    private:
        MeshPtr meshPtr;

    public:
        explicit Object(MeshPtr meshPtr);

        [[nodiscard]] MeshPtr getMesh() const;
        [[nodiscard]] mat4 getModelMatrix() const;
    };
}

typedef std::shared_ptr<engine::Object> ObjectPtr;

#endif //RAMENGINE_OBJECT_HPP
