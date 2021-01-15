#ifndef CONFINED_WINDOWEXCEPTION_HPP
#define CONFINED_WINDOWEXCEPTION_HPP

#include "Exception.hpp"

class WindowException : public Exception {
public:
    WindowException(const char* message);
};

#endif //CONFINED_WINDOWEXCEPTION_HPP
