#include "Material.hpp"

using engine::Color;

#define MAX_VALUE 255

Color::Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a){}

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) :
    r((float) r / MAX_VALUE), g((float) g / MAX_VALUE), b((float) b / MAX_VALUE), a((float) a / MAX_VALUE){}