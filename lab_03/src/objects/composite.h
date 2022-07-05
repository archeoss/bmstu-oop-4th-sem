//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_COMPOSITE_H
#define OOP_LAB_03_COMPOSITE_H

#include <memory>
#include "object.h"
#include "visitor.h"
using Component = std::shared_ptr<Object>;
class Composite : public Object
{
public:
    Composite() = default;
    explicit Composite(Component &obj);
    explicit Composite(Vector<Component> &vector);

    size_t size() const;

    bool add(const Component &obj) override;
    bool remove(const Iterator<Component> &iter) override;

    Vector<Component> &getObjs();

    Iterator<Component> begin() override;
    Iterator<Component> end() override;

    void accept(std::shared_ptr<Visitor> &visitor) override;
    void transform(const Point &move, const Point &scale, const Point &turn) override;
    
private:
    Vector<Component> objects;
};


#endif //OOP_LAB_03_COMPOSITE_H
