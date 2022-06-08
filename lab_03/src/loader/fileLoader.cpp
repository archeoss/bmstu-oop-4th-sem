//
// Created by thebi on 21.05.2022.
//

#include "fileLoader.h"
#include "loadException.h"

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
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t));
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
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t));
    }

    size_t countPoints;
    stream >> countPoints;

    if (countPoints < 1)
    {
        throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t));
    }

    Vector<Point> points(countPoints);
    for (size_t i = 0; i < countPoints; i++)
    {
        float x, y, z;
        if (!(stream >> x >> y >> z))
        {
            throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t));
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
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t));
    }

    size_t countEdges;
    stream >> countEdges;

    if (countEdges < 1)
    {
        throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t));
    }

    Vector<Edge> edges(countEdges);
    for (size_t i = 0; i < countEdges; i++)
    {
        size_t idA, idB;
        if (!(stream >> idA >> idB))
        {
            throw ReadStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t));
        }
        edges.push(Edge(idA, idB));
    }

    return edges;
}

FileLoader::FileLoader(std::string &path)
{
    time_t t = time(nullptr);
    stream = std::ifstream(path);
    if (stream.fail())
        throw OpenStreamError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t));
}

