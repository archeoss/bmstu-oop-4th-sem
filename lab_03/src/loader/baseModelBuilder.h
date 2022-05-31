//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_BASEMODELBUILDER_H
#define OOP_LAB_03_BASEMODELBUILDER_H

#include "vector.h"
#include "point.h"
#include "edge.h"
#include "model.h"
#include "baseLoader.h"

class BaseModelBuilder
{
public:
    BaseModelBuilder() = default;
    virtual ~BaseModelBuilder() = default;

    virtual void addPoints(const Vector<Point> &points) = 0;
    virtual void addEdges(const Vector<Edge> &edges) = 0;
    virtual void addPoint(float x, float y, float z) = 0;
    virtual void addEdge(size_t idPointA, size_t idPointB) = 0;
    virtual std::shared_ptr<Model> buildModel() = 0;

    virtual void setLdr(std::shared_ptr<BaseLoader> &ldr) = 0;
};



#endif //OOP_LAB_03_BASEMODELBUILDER_H
