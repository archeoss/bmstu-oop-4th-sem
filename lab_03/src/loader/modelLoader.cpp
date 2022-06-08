//
// Created by thebi on 21.05.2022.
//

#include "modelLoader.h"
#include "builderFactory.h"
std::shared_ptr<Model> ModelLoader::load(std::string fileName)
{
    auto director = LoadDirector();
    auto builder = std::make_shared<ModelBuilder>(BuilderFactory::create(fileName));
    director.setBuilder(builder);

    return director.buildModel();
}
