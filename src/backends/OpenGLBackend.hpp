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

        void renderMesh(MeshPtr mesh) const override;

        void destroyMesh(MeshPtr mesh) const override;

        Texture createTexture(const char *path, unsigned char* data, int width, int height, int nbChannels) const override;

        void setClearColor(Color color) const override;

        void clear() const override;
    };
}

#endif //RAMENGINE_OPENGLBACKEND_HPP
