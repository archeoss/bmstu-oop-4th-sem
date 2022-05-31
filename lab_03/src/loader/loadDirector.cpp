//
// Created by thebi on 21.05.2022.
//

#include "loadDirector.h"

void LoadDirector::setBuilder(std::shared_ptr<BaseModelBuilder> &bld)
{
    this->builder = std::move(bld);
}

std::shared_ptr<Model> LoadDirector::buildModel(std::string &fileName)
{
    builder->setLdr(std::make_shared<FileLoader>());
    return builder->buildModel();
}



