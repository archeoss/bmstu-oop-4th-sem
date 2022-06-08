//
// Created by thebi on 21.05.2022.
//

#include "sceneManager.h"

#include <memory>
SceneManager::SceneManager()
{
    scene = std::make_shared<Scene>();
}

std::shared_ptr<Scene> SceneManager::getScene()
{
    return scene;
}

std::shared_ptr<Camera> SceneManager::getCam()
{
    return camera;
}

void SceneManager::setScene(std::shared_ptr<Scene> &scn)
{
    scene = scn;
}

void SceneManager::setCam(size_t camId)
{
    auto cam = scene->getCams()[camId];
    this->camera = cam;
}

void SceneManager::nextCam()
{
    curId++;
    if (curId >= scene->getCams().getSize())
    {
        curId = 0;
    }
    setCam(curId);
}

void SceneManager::removeObj(size_t id)
{
    scene->removeObj(id);
}

void SceneManager::removeCam(size_t id)
{
    scene->removeCamera(id);
}
