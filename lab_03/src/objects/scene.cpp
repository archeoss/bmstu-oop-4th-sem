//
// Created by thebi on 21.05.2022.
//

#include "scene.h"

Scene::Scene() : models(new Composite)
{}

void Scene::addObj(std::shared_ptr<Object> obj)
{
    models->addObj(obj);
}

void Scene::removeObj(const size_t index)
{
    models->removeObj(models->begin() + index);
}

std::shared_ptr<Composite> Scene::getObjs()
{
    return models;
}

std::shared_ptr<Object> Scene::getObj(size_t index)
{
    auto tmp = models->begin();
    tmp += index;

    return *tmp;
}

void Scene::addCamera(std::shared_ptr<Camera> camera)
{
    this->cams.push(camera);
}

void Scene::removeCamera(const size_t index)
{
//    this->cams.remove(index);
}

Vector<std::shared_ptr<Camera>> Scene::getCams()
{
    return cams;
}

std::shared_ptr<Camera> Scene::getCam(size_t id)
{
    auto tmp = cams.begin();
    tmp += id;

    return *tmp;
}
