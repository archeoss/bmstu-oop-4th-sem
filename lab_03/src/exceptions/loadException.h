//
// Created by crypto_samurai on 28.05.22.
//

#ifndef OOP_LAB_03_LOADEXCEPTION_H
#define OOP_LAB_03_LOADEXCEPTION_H

#include "baseException.h"

class OpenStreamError : public BaseException
{
public:
    OpenStreamError(
            const std::string &filename,
            const std::string &classname,
            const int line,
            const char *time,
            const std::string &info = "Error while opening stream") : BaseException(filename, classname, line, time, info) {}
};

class ReadStreamError : public BaseException
{
public:
    ReadStreamError(
            const std::string &filename,
            const std::string &classname,
            const int line,
            const char *time,
            const std::string &info = "Error while reading stream") : BaseException(filename, classname, line, time, info) {}
};

class FileFormatError : public BaseException
{
public:
    FileFormatError(
            const std::string &filename,
            const std::string &classname,
            const int line,
            const char *time,
            const std::string &info = "Wrong format of file") : BaseException(filename, classname, line, time, info) {}
};

class ModelOutOfRangeError : public BaseException
{
public:
    ModelOutOfRangeError(
            const std::string &filename,
            const std::string &classname,
            const int line,
            const char *time,
            const std::string &info = "Model is out of range") : BaseException(filename, classname, line, time, info) {}
};


#endif //OOP_LAB_03_LOADEXCEPTION_H
