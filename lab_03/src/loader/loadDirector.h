//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_LOADDIRECTOR_H
#define OOP_LAB_03_LOADDIRECTOR_H

#include <memory>
#include "modelBuilder.h"
#include "baseModelBuilder.h"
#include "fileLoader.h"
class LoadDirector
{
public:
    LoadDirector() = default;
    ~LoadDirector() = default;

    void setBuilder(std::shared_ptr<ModelBuilder> &bld);

    std::shared_ptr<Model> buildModel();
private:
    std::shared_ptr<ModelBuilder> builder;
};


#endif //OOP_LAB_03_LOADDIRECTOR_H
