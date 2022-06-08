//
// Created by crypto_samurai on 01.06.22.
//

#ifndef OOP_LAB_03_BUILDERFACTORY_H
#define OOP_LAB_03_BUILDERFACTORY_H

#include <memory>
#include "fileLoader.h"
class BuilderFactory
{
public:
    static std::unique_ptr<BaseLoader> create(std::string &path);
};

#endif //OOP_LAB_03_BUILDERFACTORY_H
