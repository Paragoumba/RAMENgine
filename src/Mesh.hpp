#ifndef RAMENGINE_MESH_HPP
#define RAMENGINE_MESH_HPP

#include <vector>
#include <memory>
#include <glm/vec3.hpp>

using std::vector;

typedef unsigned int ID;
typedef unsigned int Index;

namespace engine {

    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec3 texCoords;
    };

    struct Texture {
        ID id;
    };

    class Mesh {
    private:
        ID vboId, eboId;

    public:
        vector<Vertex> vertices;
        vector<ID> indices;
        vector<Texture> textures;
        ID vaoId;

        Mesh(vector<Vertex>& vertices, vector<ID>& indices, vector<Texture>& textures, ID vaoID, ID vboId, ID eboId);
    };
}

typedef std::shared_ptr<engine::Mesh> MeshPtr;

#endif //RAMENGINE_MESH_HPP
