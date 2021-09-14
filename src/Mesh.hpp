#ifndef RAMENGINE_MESH_HPP
#define RAMENGINE_MESH_HPP

#include <vector>
#include <memory>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

using std::vector;
using glm::vec2;
using glm::vec3;

typedef unsigned int ID;
typedef unsigned int Index;

namespace engine {

    struct Vertex {
        vec3 position;
        vec3 normal;
        vec2 texCoords;
    };

    struct Texture {
        ID id;
    };

    class Mesh {
    public:
        vector<Vertex> vertices;
        vector<Index> indices;
        vector<Texture> textures;
        ID vaoId, vboId, eboId;

        Mesh(vector<Vertex>& vertices, vector<Index>& indices, vector<Texture>& textures, ID vaoID, ID vboId, ID eboId);
    };
}

typedef std::shared_ptr<engine::Mesh> MeshPtr;

#endif //RAMENGINE_MESH_HPP
