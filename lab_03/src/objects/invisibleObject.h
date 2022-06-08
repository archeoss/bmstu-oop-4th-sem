//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_INVISIBLEOBJECT_H
#define OOP_LAB_03_INVISIBLEOBJECT_H

#include "object.h"

//class Object;
class InvisibleObject : public Object
{
public:
    InvisibleObject() = default;
    virtual ~InvisibleObject() = default;

    virtual bool isVisible() { return false;};
};

#endif //OOP_LAB_03_INVISIBLEOBJECT_H
