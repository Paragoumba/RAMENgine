#include <Logger.hpp>

#include "OpenGLBackend.hpp"

using engine::OpenGLBackend;
using engine::Texture;
using logger::Logger;

MeshPtr OpenGLBackend::createMesh(vector<Vertex>& vertices, vector<Index>& indices, vector<Texture>& textures) const {

    ID vaoId, vboId, eboId;

    glGenVertexArrays(1, &vaoId);
    glGenBuffers(1, &vboId);
    glGenBuffers(1, &eboId);

    glBindVertexArray(vaoId);

    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(Index), indices.data(), GL_STATIC_DRAW);

    /*glGenBuffers(1, &vboId);
    vboIds.push_back(vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, texCoordsNumber, texCoords, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
    glEnableVertexAttribArray(1);*/

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

void OpenGLBackend::renderMesh(MeshPtr mesh) const {

    for (auto it = mesh->textures.begin(); it != mesh->textures.end(); ++it){

        glActiveTexture(GL_TEXTURE0 + (it - mesh->textures.begin()));
        glBindTexture(GL_TEXTURE_2D, it->id);

    }

    glBindVertexArray(mesh->vaoId);
    glDrawElements(GL_TRIANGLES, mesh->indices.size(), GL_UNSIGNED_INT, nullptr) ;

}

void OpenGLBackend::destroyMesh(MeshPtr mesh) const {

    // Delete the EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &mesh->eboId);

    // Delete the VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &mesh->vboId);

    // Delete the VAO
    glBindVertexArray(0);
    glDeleteVertexArrays(1, &mesh->vaoId);

}

Texture OpenGLBackend::createTexture(const char* path, unsigned char* data, int width, int height, int nbChannels) const {

    Texture texture{0, path};

    glGenTextures(1, &texture.id);
    glBindTexture(GL_TEXTURE_2D, texture.id);

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    if (data){

        const GLenum format = nbChannels == 4 ? GL_RGBA : GL_RGB;

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

    } else {

        Logger::getLogger() << logger::Severity::ERROR << std::string ("Failed to load texture (") + path + ").";

    }

    return texture;

}

void OpenGLBackend::setClearColor(Color color) const {

    glClearColor(color.r, color.g, color.b, color.a);

}

void OpenGLBackend::clear() const {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}
