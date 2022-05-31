//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_INVISIBLEOBJECT_H
#define OOP_LAB_03_INVISIBLEOBJECT_H

#include "object.h"

class InvisibleObject : public Object
{
public:
    InvisibleObject() = default;
    ~InvisibleObject() override = default;

    virtual bool is_visible() { return false;};
};

#endif //OOP_LAB_03_INVISIBLEOBJECT_H
