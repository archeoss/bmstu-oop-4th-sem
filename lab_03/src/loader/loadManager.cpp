//
// Created by thebi on 21.05.2022.
//

#include "loadManager.h"

void LoadManager::setLoader(std::shared_ptr<ModelLoader> _loader) {
    loader = std::move(_loader); }

std::shared_ptr<Model> LoadManager::loadModel(std::string &name) {

    return loader->load(name);
}