//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_VISITOR_H
#define OOP_LAB_03_VISITOR_H

//#include "camera.h"
//#include "model.h"
//#include "composite.h"
class Camera;
class Model;
class Composite;
class Visitor
{
public:
    Visitor() = default;
    virtual ~Visitor() = default;

    virtual void visit(const Camera &camera) = 0;
    virtual void visit(const Model &model) = 0;
    virtual void visit(const Composite &composite) = 0;
};


#endif //OOP_LAB_03_VISITOR_H
