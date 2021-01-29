#include "OpenGLBackend.hpp"

using engine::OpenGLBackend;

MeshPtr OpenGLBackend::createMesh(vector<Vertex>& vertices, vector<Index>& indices, vector<Texture>& textures) const {

    ID vaoId, vboId, eboId;

    glGenVertexArrays(1, &vaoId);
    glGenBuffers(1, &vboId);
    glGenBuffers(1, &eboId);

    glBindVertexArray(vaoId);

    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(Index), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, texCoords));

    glBindVertexArray(0);

    MeshPtr mesh(new Mesh(vertices, indices, textures, vaoId, vboId, eboId));

    return mesh;

}

void OpenGLBackend::renderMesh() const {

}
