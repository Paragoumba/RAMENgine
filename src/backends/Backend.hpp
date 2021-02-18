#ifndef RAMENGINE_BACKEND_HPP
#define RAMENGINE_BACKEND_HPP

#include "../Mesh.hpp"
#include "../Material.hpp"

namespace engine {

    class Backend {
    public:
        virtual MeshPtr createMesh(
                vector<Vertex>& vertices, vector<Index>& indices, vector<Texture>& textures) const = 0;

        virtual void renderMesh(MeshPtr mesh) const = 0;

        virtual void destroyMesh(MeshPtr mesh) const = 0;

        virtual Texture createTexture(const char* path, unsigned char* data, int width, int height, int nbChannels) const = 0;

        virtual void setClearColor(Color color) const = 0;

        virtual void clear() const = 0;
    };
}

typedef std::shared_ptr<engine::Backend> BackendPtr;

#endif //RAMENGINE_BACKEND_HPP
