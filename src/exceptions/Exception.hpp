#ifndef CONFINED_EXCEPTION_HPP
#define CONFINED_EXCEPTION_HPP

#include <exception>

class Exception : public std::exception {
protected:
    char* message{};

public:
    explicit Exception(const char* message);

    [[nodiscard]] const char* what() const noexcept override;

    ~Exception() override;
};

#endif //CONFINED_EXCEPTION_HPP
