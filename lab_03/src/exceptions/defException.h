//
// Created by crypto_samurai on 28.05.22.
//

#ifndef OOP_LAB_03_DEFEXCEPTION_H
#define OOP_LAB_03_DEFEXCEPTION_H

#include <exception>
#include <string>

class DefaultException : public std::exception
{
public:
    explicit DefaultException() = default;
    explicit DefaultException(const char *message);

    const char *what() const noexcept override;

protected:
    std::string message_;
};

DefaultException::DefaultException(const char *message) : message_(message) {}

const char *DefaultException::what() const noexcept
{
    return "DefaultException";
}



#endif //OOP_LAB_03_DEFEXCEPTION_H
