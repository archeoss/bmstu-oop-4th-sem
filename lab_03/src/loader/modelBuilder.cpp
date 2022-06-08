//
// Created by thebi on 21.05.2022.
//

#include "modelBuilder.h"

void ModelBuilder::addPoints(const Vector<Point> &points)
{
    for (auto &point: points)
    {
        this->points.push(point);
    }
}

void ModelBuilder::addEdges(const Vector<Edge> &edges)
{
    for (auto &edge: edges)
    {
        this->edges.push(edge);
    }
}

void ModelBuilder::addPoint(float x, float y, float z)
{
    this->points.push(Point(x, y ,z));
}

void ModelBuilder::addEdge(size_t idPointA, size_t idPointB)
{
    this->edges.push(Edge(idPointA, idPointB));
}

std::shared_ptr<Model> ModelBuilder::buildModel()
{
    addPoints(loader->readPoints());
    addEdges(loader->readEdges());
    return std::make_shared<Model>(points, edges);
}

ModelBuilder::ModelBuilder(std::unique_ptr<BaseLoader> ldr)
{
    loader = std::move(ldr);
}
