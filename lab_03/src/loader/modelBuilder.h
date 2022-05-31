//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_MODELBUILDER_H
#define OOP_LAB_03_MODELBUILDER_H

#include "baseModelBuilder.h"
#include "baseLoader.h"
class ModelBuilder : public BaseModelBuilder
{
public:
    ModelBuilder() = default;
    ~ModelBuilder() override = default;

    void addPoints(const Vector<Point> &points) override;
    void addEdges(const Vector<Edge> &edges) override;

    void addPoint(float x, float y, float z) override;
    void addEdge(size_t idPointA, size_t idPointB) override;

    void setLdr(std::shared_ptr<BaseLoader> &ldr) override;
    std::shared_ptr<Model> buildModel() override;
private:
    std::shared_ptr<Model> model;
    std::shared_ptr<BaseLoader> loader;
};


#endif //OOP_LAB_03_MODELBUILDER_H
