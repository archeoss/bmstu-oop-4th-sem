//
// Created by thebi on 20.05.2022.
//

#ifndef OOP_LAB_03_MODEL_H
#define OOP_LAB_03_MODEL_H

#include "visibleObject.h"
#include "vector.h"
#include "figure.h"

class BaseModel : VisibleObject
{
public:
    BaseModel() = default;
    virtual void accept() = 0;
    ~BaseModel() override = default;
};

class Model : BaseModel
{
public:
    Model();
    explicit Model(const std::shared_ptr<Figure>& fig);
    Model(const Model &model);

    std::unique_ptr<Model> clone();

    void addPoint(const Point &point);
    void addEdge(const Edge &edge);

    void transform(const Point &move, const Point &scale, const Point &rotate) override;
    void accept() override;

    std::shared_ptr<Figure> getFigure() const;

    ~Model() override = default;
private:
    std::shared_ptr<Figure> figure;
};


#endif //OOP_LAB_03_MODEL_H
