//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_COMPOSITE_H
#define OOP_LAB_03_COMPOSITE_H

#include <memory>
#include "object.h"
#include "visitor.h"
using Component = std::shared_ptr<Object>;
class Composite
{
public:
    Composite() = default;
    Composite(Component &obj);
    Composite(Vector<Component> &vector);

    size_t size() const;

    void addObj(Component &obj);
    void removeObj(Iterator<Object> &iter);

    Vector<Component> &getObjs();

    Iterator<Component> begin();
    Iterator<Component> end();

    void accept(std::shared_ptr<Visitor> &visitor);
    void transform(const Point &move, const Point &scale, const Point &turn);
    
private:
    Vector<Component> objects;
};


#endif //OOP_LAB_03_COMPOSITE_H
