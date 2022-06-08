//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_VISIBLEOBJECT_H
#define OOP_LAB_03_VISIBLEOBJECT_H

#include "object.h"

//class Object;
class VisibleObject : public Object
{
public:
    VisibleObject() = default;
    virtual ~VisibleObject() = default;

    virtual bool isVisible() { return true;};
};

#endif //OOP_LAB_03_VISIBLEOBJECT_H
