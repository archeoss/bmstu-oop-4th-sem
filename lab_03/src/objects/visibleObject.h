//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_VISIBLEOBJECT_H
#define OOP_LAB_03_VISIBLEOBJECT_H

#include "object.h"

class VisibleObject : public Object
{
public:
    VisibleObject() = default;
    ~VisibleObject() override = default;

    virtual bool is_visible() { return true;};
};

#endif //OOP_LAB_03_VISIBLEOBJECT_H
