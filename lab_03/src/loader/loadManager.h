//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_LOADMANAGER_H
#define OOP_LAB_03_LOADMANAGER_H

#include "baseManager.h"
#include "object.h"
#include "loader.h"
#include "modelLoader.h"
class LoadManager : public BaseManager
{
public:
    LoadManager() = default;
    ~LoadManager() override = default;
    std::shared_ptr<Model> loadModel(std::string &name);
    void setLoader(std::shared_ptr<ModelLoader> _loader);
private:
    std::shared_ptr<ModelLoader> loader;
};


#endif //OOP_LAB_03_LOADMANAGER_H
