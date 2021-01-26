#ifndef RAMENGINE_GLSLSHADER_HPP
#define RAMENGINE_GLSLSHADER_HPP

#include "Shader.hpp"
#include "SPIRVShader.hpp"

class GLSLShader : public Shader {
public:
    SPIRVShader compile(bool optimize = true) const;
};

#endif //RAMENGINE_GLSLSHADER_HPP
