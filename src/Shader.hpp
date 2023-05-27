#ifndef RAMENGINE_SHADER_HPP
#define RAMENGINE_SHADER_HPP

#include "../libs/glad/gl.h"
#include <glm/glm.hpp>
#include <string>

#include "Logger.hpp"

#define VERTEX 1
#define FRAGMENT 2
#define PROGRAM 3

#define BUFFER_SIZE 1024

using logger::Logger;
using logger::Severity;

class Shader {
protected:
    unsigned int id;
    Logger& logger = Logger::getLogger();

    static void checkCompileErrors(unsigned int shader, int type);

public:
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);

    void use() const;

    void setBool(const char* name, bool value) const;
    void setInt(const char* name, int value) const;
    void setFloat(const char* name, float value) const;
    void setMat4f(const char* name, glm::mat4 value) const;

    ~Shader();
};

#endif //RAMENGINE_SHADER_HPP
