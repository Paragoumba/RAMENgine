#ifndef RAMENGINE_MATERIAL_HPP
#define RAMENGINE_MATERIAL_HPP

namespace engine {
    class Color {
    public:
        Color(float r, float g, float b, float a);

        Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

        float r;
        float g;
        float b;
        float a;
    };

    class Material {

    };
}

#endif //RAMENGINE_MATERIAL_HPP
