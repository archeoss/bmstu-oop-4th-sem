//
// Created by crypto_samurai on 28.05.22.
//

#ifndef OOP_LAB_03_DRAWEXCEPTION_H
#define OOP_LAB_03_DRAWEXCEPTION_H

#include "baseException.h"

class DrawerError : public BaseException
{
public:
    DrawerError(
            const std::string &filename,
            const std::string &classname,
            const int line,
            const char *time,
            const std::string &info = "Drawer wasn't set") : BaseException(filename, classname, line, time, info) {}
};


#endif //OOP_LAB_03_DRAWEXCEPTION_H
