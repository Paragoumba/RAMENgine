#include "Scalable.hpp"

using engine::Scalable;

Scalable::Scalable(): scale(1){}

vec3& engine::Scalable::getScale(){
    
    return scale;
    
}

void engine::Scalable::setScale(float x, float y, float z){

    scale.x = x;
    scale.y = y;
    scale.z = z;
    
}

void engine::Scalable::setScale(vec3 _scale){

    scale.x = _scale.x;
    scale.y = _scale.y;
    scale.z = _scale.z;
    
}

void engine::Scalable::rescale(float x, float y, float z){

    scale.x *= x;
    scale.y *= y;
    scale.z *= z;

}

void engine::Scalable::rescale(vec3 v){

    scale.x *= v.x;
    scale.y *= v.y;
    scale.z *= v.z;

}
