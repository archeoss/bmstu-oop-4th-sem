//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_CAMERA_H
#define OOP_LAB_03_CAMERA_H

#include "invisibleObject.h"
#include "point.h"

class Camera : public InvisibleObject
{
public:
    Camera();
    Camera(Point &pos);

    Camera &operator=(Camera &cam);
    Camera(Camera &cam);
    void transform(const Point &move, const Point &scale, const Point &rotate) override;

    Point getPos();
    ~Camera() override = default;
private:
    Point curPos;
};


#endif //OOP_LAB_03_CAMERA_H
