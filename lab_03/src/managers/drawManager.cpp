//
// Created by thebi on 21.05.2022.
//

#include "drawManager.h"

void DrawManager::visit(const Model &model)
{
    auto points = model.getFigure()->getPoints();

//    time_t t_time = time(NULL);
//    if (!drawer)
//    {
//        throw DrawerError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
//    }
//    if (!camera)
//    {
//        throw CameraError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
//    }

    for (auto edge: model.getFigure()->getEdges())
    {
        drawer->drawLine(projectPoint(points[edge.getFirst()]),
                         projectPoint(points[edge.getSecond()]));
    }
}

void DrawManager::setDrawer(std::shared_ptr<BaseDrawer> &drw)
{
    drawer = drw;
}

void DrawManager::setCamera(std::shared_ptr<Camera> &cam)
{
    camera = cam;
}

Point DrawManager::projectPoint(const Point &point)
{
    Point tmp = point;
    tmp += camera->getPos();

    return tmp;
}

void DrawManager::visit(const Camera &cam)
{};

void DrawManager::visit(const Composite &composite)
{};