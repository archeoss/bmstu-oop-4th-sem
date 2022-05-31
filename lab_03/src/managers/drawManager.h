//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_DRAWMANAGER_H
#define OOP_LAB_03_DRAWMANAGER_H

#include <memory>
#include "visitor.h"
#include "baseManager.h"
#include "point.h"
#include "drawer.h"

class DrawManager : public Visitor, public BaseManager
{
public:
    DrawManager() = default;
    ~DrawManager() override = default;

    void setDrawer(std::shared_ptr<BaseDrawer> &drw);
    void setCamera(std::shared_ptr<Camera> &cam);

    void visit(const Camera &cam) override;
    void visit(const Model &model) override;
    void visit(const Composite &composite) override;
private:
    Point projectPoint(const Point &point);
    std::shared_ptr<Camera> camera;
    std::shared_ptr<BaseDrawer> drawer;
};


#endif //OOP_LAB_03_DRAWMANAGER_H
