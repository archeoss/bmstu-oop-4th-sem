//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_FACTORY_H
#define OOP_LAB_03_FACTORY_H

#include <memory>
#include "drawer.h"

class AbstractFactory
{
public:
    AbstractFactory() = default;
    virtual ~AbstractFactory() = default;
    virtual std::unique_ptr<BaseDrawer> createGraphics() = 0;
};

class QtFactory : public AbstractFactory
{
public:
    QtFactory() = default;
    ~QtFactory() override = default;
    std::unique_ptr<BaseDrawer> createGraphics() override;
};


#endif //OOP_LAB_03_FACTORY_H
