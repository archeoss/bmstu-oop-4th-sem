//
// Created by thebi on 21.05.2022.
//

#include "transformManager.h"

void TransformManager::transformObj(std::shared_ptr<Object> &obj, const Point &move, const Point &scale, const Point &rotate)
{
    obj->transform(move, scale, rotate);
}

void TransformManager::moveObj(std::shared_ptr<Object> &obj, const float dx, const float dy, const float dz)
{
    obj->transform(Point(dx,dy,dz), Point(1, 1, 1), Point());
}

void TransformManager::scaleObj(std::shared_ptr<Object> &obj, const float kx, const float ky, const float kz)
{
    obj->transform(Point(), Point(kx, ky, kz), Point());
}

void TransformManager::rotateObj(std::shared_ptr<Object> &obj, const float ox, const float oy, const float oz)
{
    obj->transform(Point(), Point(1, 1, 1), Point(ox, oy, oz));
}

//void TransformManager::setObj(std::shared_ptr<Object> &object)
//{
//    this->obj = object;
//}

//std::shared_ptr<Object> &TransformManager::getObj()
//{
//    return this->obj;
//}
