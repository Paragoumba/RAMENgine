#ifndef RAMENGINE_BACKEND_HPP
#define RAMENGINE_BACKEND_HPP

#include "../Mesh.hpp"

namespace engine {

    class Backend {
    public:
        virtual MeshPtr createMesh(
                vector<Vertex>& vertices, vector<Index>& indices, vector<Texture>& textures) const = 0;

        virtual void renderMesh() const = 0;
    };
}

#endif //RAMENGINE_BACKEND_HPP
