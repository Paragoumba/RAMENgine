#ifndef CONFINED_GLSLSHADER_HPP
#define CONFINED_GLSLSHADER_HPP

#include "Shader.hpp"
#include "SPIRVShader.hpp"

class GLSLShader : public Shader {
public:
    SPIRVShader compile(bool optimize = true) const;
};

#endif //CONFINED_GLSLSHADER_HPP
