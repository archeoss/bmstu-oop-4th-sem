//
// Created by thebi on 21.05.2022.
//

#include "camera.h"

Camera::Camera() : curPos(0, 0, 0)
{}

Camera::Camera(Point &pos) : curPos(pos)
{}

void Camera::transform(const Point &move, const Point &scale, const Point &rotate)
{
    this->curPos += move;
}

Camera::Camera(Camera &cam)
{
    curPos = cam.curPos;
}

Camera &Camera::operator=(Camera &cam)
{
    curPos = cam.curPos;

    return *this;
}

Point Camera::getPos()
{
    return curPos;
}

void Camera::accept(std::shared_ptr<Visitor> visitor)
{

}

