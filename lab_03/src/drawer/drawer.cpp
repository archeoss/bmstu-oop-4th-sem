//
// Created by thebi on 21.05.2022.
//

#include "drawer.h"

QtDrawer::QtDrawer()
{
    scene = nullptr;
}

QtDrawer::QtDrawer(QGraphicsScene *scene) : scene(scene)
{}

QtDrawer::QtDrawer(const QtDrawer &drawer)
{
    this->scene = drawer.scene;
}

void QtDrawer::clearScene()
{
    scene->clear();
}

void QtDrawer::drawLine(const Point &pointA, const Point &pointB)
{
    this->scene->addLine(pointA.getX(), pointA.getY(), pointB.getX(), pointB.getY());
}