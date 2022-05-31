//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_BASELOADER_H
#define OOP_LAB_03_BASELOADER_H

#include "vector.h"
#include "point.h"
#include "edge.h"

class BaseLoader
{
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual void open(std::string fileName) = 0;
    virtual bool isOpen() = 0;
    virtual void close() = 0;

    virtual Vector<Point> readPoints() = 0;
    virtual Vector<Edge> readEdges() = 0;
};


#endif //OOP_LAB_03_BASELOADER_H
