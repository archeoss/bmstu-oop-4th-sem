//
// Created by thebi on 16.05.2022.
//

#ifndef BMSTU_OOP_4TH_SEM_FIGURE_H
#define BMSTU_OOP_4TH_SEM_FIGURE_H

#include "vector.h"
#include "point.h"
#include "edge.h"

class Figure {
public:
    Figure() = default;
    Figure(Figure &&fig) noexcept;
    Figure(Figure &fig);
    Figure(Vector<Point> points, Vector<Edge> edges);
    ~Figure() = default;

    void addPoint(const Point &point);
    void addEdge(const Edge &edge);

    void transform(const Point &move, const Point &scale, const Point &rotate);

    Vector<Point> &getPoints();
    Vector<Edge> &getEdges();
private:
    Vector<Edge> edges;
    Vector<Point> points;
};


#endif //BMSTU_OOP_4TH_SEM_FIGURE_H
