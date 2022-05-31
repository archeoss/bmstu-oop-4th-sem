//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_CAMERAMANAGER_H
#define OOP_LAB_03_CAMERAMANAGER_H

#include <memory>
#include "baseManager.h"
#include "camera.h"

class CameraManager : public BaseManager
{
public:
    void move(std::shared_ptr<Camera> camera, Point &mv);
    void yaw(std::shared_ptr<Camera> camera, float angle);
    void roll(std::shared_ptr<Camera> camera, float angle);
    void pitch(std::shared_ptr<Camera> camera, float angle);
};


#endif //OOP_LAB_03_CAMERAMANAGER_H
