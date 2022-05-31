//
// Created by thebi on 21.05.2022.
//

#ifndef OOP_LAB_03_LOADER_H
#define OOP_LAB_03_LOADER_H


template<class T>
class Loader
{
public:
    Loader() = default;
    virtual ~Loader() = default;

    virtual std::shared_ptr<T> load(std::string sourceName) = 0;
};


#endif //OOP_LAB_03_LOADER_H
