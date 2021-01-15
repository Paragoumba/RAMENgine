#include <cstring>
#include "Exception.hpp"

Exception::Exception(const char* message){

    this->message = new char[strlen(message)];
    std::strcpy(this->message, message);

}

const char* Exception::what() const noexcept {

    return message;

}

Exception::~Exception(){

    delete[] message;

}
