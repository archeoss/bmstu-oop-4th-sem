//
// Created by thebi on 21.05.2022.
//

#include "modelLoader.h"

std::shared_ptr<Model> ModelLoader::load(std::string fileName)
{
    auto director = LoadDirector();
    std::shared_ptr<BaseModelBuilder> builder(new ModelBuilder);
    director.setBuilder(builder);

    return director.buildModel(fileName);
}
