#include "Positionable.hpp"

using engine::Positionable;

Positionable::Positionable(): position(0){}

vec3& Positionable::getPosition(){

    return position;

}

void Positionable::setPosition(float x, float y, float z){

    position.x = x;
    position.y = y;
    position.z = z;

}

void Positionable::setPosition(vec3 _position){

    position.x = _position.x;
    position.y = _position.y;
    position.z = _position.z;

}

void Positionable::move(float x, float y, float z){

    position.x += x;
    position.y += y;
    position.z += z;

}

void Positionable::move(vec3 v){

    position.x = v.x;
    position.y = v.y;
    position.z = v.z;

}
