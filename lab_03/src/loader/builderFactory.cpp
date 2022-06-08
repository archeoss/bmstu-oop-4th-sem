//
// Created by crypto_samurai on 01.06.22.
//
#include "builderFactory.h"

std::unique_ptr<BaseLoader> BuilderFactory::create(std::string &path)
{
    return std::make_unique<FileLoader>(path);
}