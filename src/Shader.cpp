#include <fstream>
#include <sstream>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.hpp"

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath){

    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vertexFile;
    std::ifstream fragmentFile;

    auto mask = std::ifstream::failbit | std::ifstream::badbit;

    vertexFile.exceptions(mask);
    fragmentFile.exceptions(mask);

    try {

        vertexFile.open(vertexPath);
        fragmentFile.open(fragmentPath);
        std::stringstream vertexStream, fragmentStream;

        vertexStream << vertexFile.rdbuf();
        fragmentStream << fragmentFile.rdbuf();

        vertexFile.close();
        fragmentFile.close();

        vertexCode = vertexStream.str();
        fragmentCode = fragmentStream.str();

    } catch (std::ifstream::failure& e){

        logger.loge(e.what());

    }

    const char* vertexCodeStr = vertexCode.c_str();
    const char* fragmentCodeStr = fragmentCode.c_str();
    unsigned int vertexId, fragmentId;

    vertexId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexId, 1, &vertexCodeStr, nullptr);
    glCompileShader(vertexId);
    checkCompileErrors(vertexId, VERTEX);

    fragmentId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentId, 1, &fragmentCodeStr, nullptr);
    glCompileShader(fragmentId);
    checkCompileErrors(fragmentId, FRAGMENT);

    id = glCreateProgram();

    glAttachShader(id, vertexId);
    glAttachShader(id, fragmentId);
    glLinkProgram(id);
    checkCompileErrors(id, PROGRAM);

    glDeleteShader(vertexId);
    glDeleteShader(fragmentId);

}

void Shader::use() const {

    glUseProgram(id);

}

void Shader::setBool(const char* name, bool value) const {

    setInt(name, value);

}

void Shader::setInt(const char* name, int value) const {

    glUniform1i(glGetUniformLocation(id, name), value);

}

void Shader::setFloat(const char* name, float value) const {

    glUniform1f(glGetUniformLocation(id, name), value);

}

void Shader::setMat4f(const char* name, glm::mat4 value) const {

    glUniformMatrix4fv(glGetUniformLocation(id, name), 1, GL_FALSE, glm::value_ptr(value));

}

Shader::~Shader(){

    glUseProgram(0);
    glDeleteProgram(id);

}

void Shader::checkCompileErrors(unsigned int shader, int type){

    int success;
    char buffer[BUFFER_SIZE];

    if (type != PROGRAM){

        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

        if (!success){

            glGetShaderInfoLog(shader, BUFFER_SIZE, nullptr, buffer);
            //logger.logw(std::string("Cannot link shader (") + type + ") for the following reason:\n\t" + buffer);

        }

    } else {



    }
}
