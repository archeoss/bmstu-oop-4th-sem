//
// Created by thebi on 21.05.2022.
//

#include "loadDirector.h"

void LoadDirector::setBuilder(std::shared_ptr<ModelBuilder> &bld)
{
    this->builder = std::move(bld);
}

std::shared_ptr<Model> LoadDirector::buildModel()
{
    return builder->buildModel();
}



