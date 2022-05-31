//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_TRANSFORMMANAGER_H
#define OOP_LAB_03_TRANSFORMMANAGER_H

#include <memory>
#include "baseManager.h"
#include "object.h"

class TransformManager : public BaseManager
{
public:
    TransformManager() = default;
    ~TransformManager() override = default;

//    void setObj(std::shared_ptr<Object>& object);
//    std::shared_ptr<Object> &getObj();

    void transformObj(std::shared_ptr<Object>& object, const Point &move,  const Point &scale,  const Point &rotate);

    void moveObj(std::shared_ptr<Object>& object, const float dx = 0, const float dy = 0, const float dz = 0);
    void scaleObj(std::shared_ptr<Object>& object, const float kx, const float ky, const float kz);
    void rotateObj(std::shared_ptr<Object>& object, const float ox, const float oy, const float oz);
};


#endif //OOP_LAB_03_TRANSFORMMANAGER_H
