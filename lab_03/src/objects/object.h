//
// Created by thebi on 16.05.2022.
//

#ifndef BMSTU_OOP_4TH_SEM_OBJECT_H
#define BMSTU_OOP_4TH_SEM_OBJECT_H

#include <memory>
#include "vector.h"
#include "point.h"
//#include "visitor.h"

class Object
{
public:
    Object() = default;
    virtual ~Object() = default;

    virtual void add(const std::shared_ptr<Object> &) {};
    virtual void remove(const Iterator<std::shared_ptr<Object>> &) {};

    virtual Iterator<std::shared_ptr<Object>> begin() {};
    virtual Iterator<std::shared_ptr<Object>> end() {};

//    virtual void accept(std::shared_ptr)
    virtual void transform(const Point &move, const Point &scale, const Point &rotate) = 0;
};

#endif //BMSTU_OOP_4TH_SEM_OBJECT_H
