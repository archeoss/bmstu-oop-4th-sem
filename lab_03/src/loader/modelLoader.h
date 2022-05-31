//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_MODELLOADER_H
#define OOP_LAB_03_MODELLOADER_H

#include "modelBuilder.h"
#include "fileLoader.h"
#include "loader.h"
#include "loadDirector.h"

#include <memory>
#include "loadDirector.h"

class ModelLoader : public Loader<Model>
{
public:
    ModelLoader() = default;
    ~ModelLoader() override = default;

    std::shared_ptr<Model> load(std::string sourceName) override;
};


#endif //OOP_LAB_03_MODELLOADER_H
