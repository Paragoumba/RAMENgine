#include "Camera.hpp"

using engine::Camera;

Camera::Camera() : position(0), rotation(0){}

vec3 Camera::getPosition() const {

    return position;

}

vec3 Camera::getRotation() const {

    return rotation;

}

void Camera::setPosition(float x, float y, float z){

    position.x = x;
    position.y = y;
    position.z = z;

}

void Camera::setPosition(vec3 _position){

    position.x = _position.x;
    position.y = _position.y;
    position.z = _position.z;

}

void Camera::setRotation(float rx, float ry, float rz){

    rotation.x = rx;
    rotation.y = ry;
    rotation.z = rz;

}

void Camera::setRotation(vec3 _rotation){

    rotation.x = _rotation.x;
    rotation.y = _rotation.y;
    rotation.z = _rotation.z;

}

void Camera::move(float x, float y, float z){

    position.x += x;
    position.y += y;
    position.z += z;

}

void Camera::move(vec3 v){

    position.x = v.x;
    position.y = v.y;
    position.z = v.z;

}

void Camera::rotate(float rx, float ry, float rz){

    rotation.x = rx;
    rotation.y = ry;
    rotation.z = rz;

}

void Camera::rotate(vec3 v){

    rotation.x = v.x;
    rotation.y = v.y;
    rotation.z = v.z;

}