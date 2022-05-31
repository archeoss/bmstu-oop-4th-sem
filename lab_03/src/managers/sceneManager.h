//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_SCENEMANAGER_H
#define OOP_LAB_03_SCENEMANAGER_H

#include <memory>
#include "baseManager.h"
#include "scene.h"

class SceneManager : public BaseManager
{
public:
    SceneManager();
    ~SceneManager() override = default;

    std::shared_ptr<Scene> getScene();
    std::shared_ptr<Camera> getCam();

    void setScene(std::shared_ptr<Scene> &scn);
    void setCam(size_t camId);
    void nextCam();

private:
    std::shared_ptr<Scene> scene;
    std::shared_ptr<Camera> camera;
    size_t curId;
};


#endif //OOP_LAB_03_SCENEMANAGER_H
