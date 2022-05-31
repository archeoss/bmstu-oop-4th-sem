//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_DRAWER_H
#define OOP_LAB_03_DRAWER_H

#include "point.h"
#include <QGraphicsScene>

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void drawLine(const Point &pointA, const Point &pointB) = 0;
    virtual void clearScene() = 0;
};

class QtDrawer : public BaseDrawer
{
public:
    QtDrawer();
    explicit QtDrawer(QGraphicsScene *scene);
    QtDrawer(const QtDrawer &drawer);

    void drawLine(const Point &pointA, const Point &pointB) override;
    void clearScene() override;

    ~QtDrawer() override = default;

private:
    QGraphicsScene *scene;
};


#endif //OOP_LAB_03_DRAWER_H
