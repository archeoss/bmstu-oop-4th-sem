//
// Created by crypto_samurai on 28.05.22.
//

#ifndef OOP_LAB_03_SCENEXCEPTION_H
#define OOP_LAB_03_SCENEXCEPTION_H

#include "baseException.h"

class CameraError : public BaseException
{
public:
    CameraError(
            const std::string &filename,
            const std::string &classname,
            const int line,
            const char *time,
            const std::string &info = "Camera wasn't set") : BaseException(filename, classname, line, time, info) {}
};

class ObjectError : public BaseException
{
public:
    ObjectError(
            const std::string &filename,
            const std::string &classname,
            const int line,
            const char *time,
            const std::string &info = "Object wasn't found.") : BaseException(filename, classname, line, time, info) {}
};

#endif //OOP_LAB_03_SCENEXCEPTION_H
