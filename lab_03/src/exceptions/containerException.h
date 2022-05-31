//
// Created by crypto_samurai on 28.05.22.
//

#ifndef OOP_LAB_03_CONTAINEREXCEPTION_H
#define OOP_LAB_03_CONTAINEREXCEPTION_H

#include "baseException.h"

class MemError : public BaseException
{
public:
    MemError(
            const std::string &filename,
            const std::string &classname,
            const int line,
            const char *time,
            const std::string &info = "A memory allocation error") : BaseException(filename, classname, line, time, info) {}
};

class RangeError : public BaseException
{
public:
    RangeError(
            const std::string &filename,
            const std::string &classname,
            const int line,
            const char *time,
            const std::string &info = "Out of range error") : BaseException(filename, classname, line, time, info) {}
};

#endif


#endif //OOP_LAB_03_CONTAINEREXCEPTION_H
