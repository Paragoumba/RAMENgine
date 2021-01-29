#include "Mesh.hpp"

#include <utility>

using engine::Mesh;
using std::move;

Mesh::Mesh(vector<Vertex>& vertices, vector<ID>& indices, vector<Texture>& textures, ID vaoId, ID vboId, ID eboId) :
vertices(vertices), indices(indices), textures(textures), vaoId(vaoId), vboId(vboId), eboId(eboId){}
