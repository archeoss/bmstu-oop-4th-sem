//
// Created by thebi on 16.05.2022.
//

#include "figure.h"

Figure::Figure(Figure &fig)
{
    this->edges = fig.edges;
    this->points = fig.points;
}

Figure::Figure(Figure &&fig) noexcept : Figure(fig)
{
    fig.~Figure();
}

Figure::Figure(Vector<Point> points, Vector<Edge> edges)
{
    this->edges = edges;
    this->points = points;
}

void Figure::addPoint(const Point &point)
{
    this->points.push(point);
}

void Figure::addEdge(const Edge &edge)
{
    this->edges.push(edge);
}

Vector<Edge> &Figure::getEdges()
{
    return this->edges;
}

Vector<Point> &Figure::getPoints()
{
    return this->points;
}

void Figure::transform(const Point &move, const Point &scale, const Point &rotate)
{
    if (fabs(move.getX()) > 0 || fabs(move.getY()) > 0 || fabs(move.getZ()) > 0)
    {
        for (auto &elem: points)
        {
            elem += move;
        }
    }

    if (scale.getX() != 1.0 || scale.getY() != 1.0 || scale.getZ() != 1.0)
    {
        for (auto &elem: points)
        {
            elem *= scale;
        }
    }
    float
    x = rotate.getX(),
    y = rotate.getY(),
    z = rotate.getZ();
    if (fabs(x) > 0 || fabs(y) > 0 || fabs(z) > 0)
    {
        for (auto &elem: points)
        {
            elem.rotate(x, y, z);
        }
    }
}