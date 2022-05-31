//
// Created by thebi on 21.05.2022.
//

#include "factory.h"

std::unique_ptr<BaseDrawer> QtFactory::createGraphics()
{
    return std::unique_ptr<BaseDrawer> (new QtDrawer);
}