#ifndef RAMENGINE_WINDOWEXCEPTION_HPP
#define RAMENGINE_WINDOWEXCEPTION_HPP

#include "Exception.hpp"

class WindowException : public Exception {
public:
    WindowException(const char* message);
};

#endif //RAMENGINE_WINDOWEXCEPTION_HPP
