//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_SCENE_H
#define OOP_LAB_03_SCENE_H

#include <memory>
#include "composite.h"

class Scene
{
public:
    Scene();
    ~Scene() = default;

    void addObj(std::shared_ptr<Object> obj);
    void removeObj(const size_t index);

    std::shared_ptr<Composite> getObjs();
    std::shared_ptr<Object> getObj(size_t index);
    Vector<std::shared_ptr<Camera>> getCams();
    std::shared_ptr<Camera> getCam(size_t id);

    void addCamera(std::shared_ptr<Camera> camera);
    void removeCamera(const size_t cam_index);
private:
    std::shared_ptr<Composite> models;
    Vector<std::shared_ptr<Camera>> cams;
};


#endif //OOP_LAB_03_SCENE_H
