#include "Rotationable.hpp"

using engine::Rotationable;

Rotationable::Rotationable(): rotation(0){}

vec3& Rotationable::getRotation(){

    return rotation;

}

void Rotationable::setRotation(float rx, float ry, float rz){

    rotation.x = rx;
    rotation.y = ry;
    rotation.z = rz;

}

void Rotationable::setRotation(vec3 _rotation){

    rotation.x = _rotation.x;
    rotation.y = _rotation.y;
    rotation.z = _rotation.z;

}

void Rotationable::rotate(float rx, float ry, float rz){

    rotation.x = rx;
    rotation.y = ry;
    rotation.z = rz;

}

void Rotationable::rotate(vec3 v){

    rotation.x = v.x;
    rotation.y = v.y;
    rotation.z = v.z;

}
