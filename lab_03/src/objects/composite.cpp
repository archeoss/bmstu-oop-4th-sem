//
// Created by thebi on 21.05.2022.
//

#include "composite.h"

Composite::Composite(Component &obj) : objects(obj)
{}

Composite::Composite(Vector<Component> &vector) : objects(vector)
{}

size_t Composite::size() const
{
    return objects.getSize();
}

bool Composite::add(const Component &obj)
{
    objects.push(obj);

    return true;
}

bool Composite::remove(const Iterator<Component> &iter)
{
//    objects.
}

Vector<Component> &Composite::getObjs()
{
    return objects;
}

Iterator<Component> Composite::begin()
{
    return objects.begin();
}

Iterator<Component> Composite::end()
{
    return objects.end();
}

void Composite::accept(std::shared_ptr<Visitor> &visitor)
{
    for (auto obj: objects)
    {
        obj->accept(visitor);
    }
}

void Composite::transform(const Point &move, const Point &scale, const Point &turn)
{
    for (auto elem = begin(), e = end(); elem != e; ++elem)
    {
        (*elem)->transform(move, scale, turn);
    }
}