//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_FILELOADER_H
#define OOP_LAB_03_FILELOADER_H

#include "baseLoader.h"
#include <fstream>
#include <iostream>
class FileLoader : public BaseLoader
{
public:
    FileLoader() = default;
    explicit FileLoader(std::string &path);
    ~FileLoader() override;

    void open(std::string fileName) override;
    bool isOpen() override;
    void close() override;

    Vector<Point> readPoints() override;
    Vector<Edge> readEdges() override;
private:
    std::ifstream stream;
};


#endif //OOP_LAB_03_FILELOADER_H
