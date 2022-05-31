//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_LOADDIRECTOR_H
#define OOP_LAB_03_LOADDIRECTOR_H

#include <memory>
#include "baseLoader.h"
#include "baseModelBuilder.h"
#include "fileLoader.h"
class LoadDirector
{
public:
    LoadDirector() = default;
    ~LoadDirector() = default;

    void setBuilder(std::shared_ptr<BaseModelBuilder> &bld);

    std::shared_ptr<Model> buildModel(std::string &fileName);
private:
    std::shared_ptr<BaseModelBuilder> builder;
};


#endif //OOP_LAB_03_LOADDIRECTOR_H
