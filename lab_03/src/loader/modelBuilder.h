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
    ModelBuilder(std::unique_ptr<BaseLoader> ldr);
    ~ModelBuilder() override = default;

    void addPoints(const Vector<Point> &points) override;
    void addEdges(const Vector<Edge> &edges) override;

    void addPoint(float x, float y, float z) override;
    void addEdge(size_t idPointA, size_t idPointB) override;

    std::shared_ptr<Model> buildModel() override;
private:
    Vector<Point> points;
    Vector<Edge> edges;
    std::shared_ptr<BaseLoader> loader;
};


#endif //OOP_LAB_03_MODELBUILDER_H
