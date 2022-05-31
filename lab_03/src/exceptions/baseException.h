//
// Created by crypto_samurai on 28.05.22.
//

#ifndef OOP_LAB_03_BASEEXCEPTION_H
#define OOP_LAB_03_BASEEXCEPTION_H

#include <exception>
#include <string>

class BaseException : std::exception
{
public:
    explicit BaseException(
            const std::string &filename,
            const std::string &classname,
            const int line,
            const char *time,
            const std::string &info)
    {
        msg_ = "In: " + filename +
               "\n inside: " + classname +
               "\nat line: " + std::to_string(line) +
               "\nat: " + time +
               "\noccured: " + info;
    }
    const char *what() const noexcept override
    {
        return msg_.c_str();
    }

private:
    std::string msg_;
};


#endif //OOP_LAB_03_BASEEXCEPTION_H
