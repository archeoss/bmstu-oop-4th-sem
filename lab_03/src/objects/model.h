//
// Created by thebi on 20.05.2022.
//

#ifndef OOP_LAB_03_MODEL_H
#define OOP_LAB_03_MODEL_H

#include "visibleObject.h"
#include "vector.h"
#include "figure.h"
#include "visitor.h"

class BaseModel : public VisibleObject
{
public:
    BaseModel() = default;
    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;
    
    virtual ~BaseModel() = default;
};

class Model : public BaseModel
{
public:
    Model();
    explicit Model(const std::shared_ptr<Figure>& fig);
    Model(Vector<Point> &points, Vector<Edge> &edges);
    Model(const Model &model);

    void transform(const Point &move, const Point &scale, const Point &rotate) override;
    void accept(std::shared_ptr<Visitor> visitor) override;
    bool isVisible() override { return true; };
    std::shared_ptr<Figure> getFigure() const;

    ~Model() override = default;
private:
    std::shared_ptr<Figure> figure;
};


#endif //OOP_LAB_03_MODEL_H
