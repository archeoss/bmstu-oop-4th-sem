//
// Created by thebi on 21.05.2022.
//

#include "fileLoader.h"

FileLoader::~FileLoader()
{
    close();
}

void FileLoader::open(std::string fileName)
{
    if (isOpen())
    {
        close();
    }

    time_t t = time(NULL);
    stream.open(fileName);
    if (!stream)
    {
        //throw
    }
}

bool FileLoader::isOpen()
{
    return stream.is_open();
}

void FileLoader::close()
{
    stream.close();
}

Vector<Point> FileLoader::readPoints()
{

    time_t t = time(NULL);

    if (!isOpen())
    {
        //throw
    }

    size_t countPoints;
    stream >> countPoints;

    if (countPoints < 1)
    {
//        throw
    }

    Vector<Point> points(countPoints);
    for (size_t i = 0; i < countPoints; i++)
    {
        float x, y, z;
        if (!(stream >> x >> y >> z))
        {
            // throw
        }
        points.push(Point(x, y, z));
    }

    return points;
}

Vector<Edge> FileLoader::readEdges()
{

    time_t t = time(NULL);

    if (!isOpen())
    {
        //throw
    }

    size_t countEdges;
    stream >> countEdges;

    if (countEdges < 1)
    {
//        throw
    }

    Vector<Edge> edges(countEdges);
    for (size_t i = 0; i < countEdges; i++)
    {
        size_t idA, idB;
        if (!(stream >> idA >> idB))
        {
            // throw
        }
        edges.push(Edge(idA, idB));
    }

    return edges;
}

