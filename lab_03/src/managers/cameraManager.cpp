//
// Created by thebi on 21.05.2022.
//

#include "cameraManager.h"

void CameraManager::pitch(std::shared_ptr<Camera> camera, float angle)
{
    camera->transform(Point(), Point(1, 1, 1), Point(angle, 0,0));
}

void CameraManager::roll(std::shared_ptr<Camera> camera, float angle)
{
    camera->transform(Point(), Point(1, 1, 1), Point(0, angle,0));
}

void CameraManager::yaw(std::shared_ptr<Camera> camera, float angle)
{
    camera->transform(Point(), Point(1, 1, 1), Point(0, 0,angle));
}

void CameraManager::move(std::shared_ptr<Camera> camera, Point &mv)
{
    camera->transform(mv, Point(1, 1, 1), Point());
}
