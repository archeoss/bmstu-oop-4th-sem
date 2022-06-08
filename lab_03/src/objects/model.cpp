//
// Created by thebi on 20.05.2022.
//

#include "model.h"

#include <memory>
Model::Model() : figure(new Figure){}

Model::Model(const Model &model)
{
    this->figure = model.getFigure();
}

std::shared_ptr<Figure> Model::getFigure() const
{
    return figure;
}

Model::Model(const std::shared_ptr<Figure>& fig)
{
    figure = fig;
}

std::unique_ptr<Model> Model::clone()
{
    return std::make_unique<Model>(*this);
}

void Model::transform(const Point &move, const Point &scale, const Point &rotate)
{
    this->figure->transform(move, scale, rotate);
}

Model::Model(Vector<Point> &points, Vector<Edge> &edges)
{
    figure = std::make_shared<Figure>(points, edges);
}

void Model::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}

Model::Model(Model &model)
{
    this->figure = model.getFigure();
}
