//
// Created by thebi on 21.05.2022.
//

#include "modelBuilder.h"

void ModelBuilder::addPoints(const Vector<Point> &points)
{
    for (auto &point: points)
    {
        model->addPoint(point);
    }
}

void ModelBuilder::setLdr(std::shared_ptr<BaseLoader> &ldr)
{
    loader = std::move(ldr);
}

void ModelBuilder::addEdges(const Vector<Edge> &edges)
{
    for (auto &edge: edges)
    {
        model->addEdge(edge);
    }
}

void ModelBuilder::addPoint(float x, float y, float z)
{
    model->addPoint(Point(x, y ,z));
}

void ModelBuilder::addEdge(size_t idPointA, size_t idPointB)
{
    model->addEdge(Edge(idPointA, idPointB));
}

std::shared_ptr<Model> ModelBuilder::buildModel()
{
    return model;
}