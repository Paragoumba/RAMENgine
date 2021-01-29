#ifndef RAMENGINE_OPENGLBACKEND_HPP
#define RAMENGINE_OPENGLBACKEND_HPP

#include <glad/glad.h>

#include "backends/Backend.hpp"

using engine::Mesh;
using engine::Backend;

namespace engine {

    class OpenGLBackend : public Backend {
    public:
        MeshPtr createMesh(vector<Vertex>& vertices, vector<Index>& indices, vector<Texture>& textures) const override;

        void renderMesh() const override;
    };
}

#endif //RAMENGINE_OPENGLBACKEND_HPP
