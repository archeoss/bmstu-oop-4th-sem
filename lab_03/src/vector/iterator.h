//
// Created by thebi on 17.05.2022.
//

#ifndef OOP_LAB_01_ITERATOR_H
#define OOP_LAB_01_ITERATOR_H

#include <memory>

template<class T>
class Vector;

template<class T>
class Iterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
    Iterator();
    Iterator(Iterator<T> &iter);
    explicit Iterator(Vector<T> &vector);
    Iterator(const Iterator<T> &iter);
    explicit Iterator(const Vector<T> &vector);

    T &operator*();
    T *operator->();

    const T &operator*() const;
    const T *operator->() const;

    std::weak_ptr<T[]> getCur();
    const std::weak_ptr<T[]> getCur() const;

    explicit operator bool() const;

    Iterator<T> &operator+=(size_t number);
    Iterator<T> operator+(size_t number);

    Iterator<T> &operator++(int);

    Iterator<T> &operator--();
    Iterator<T> &operator--(int);

    bool operator==(const Iterator<T> &iter) const;

    bool operator!=(const Iterator<T> &iter) const;

    Iterator<T> &operator++();

private:
    T *getCurrent() const;

    std::weak_ptr<T[]> ptr;
    size_t currentIndex;
    size_t vectorSize;
};

#include "iterator.hpp"

#endif //OOP_LAB_01_ITERATOR_H
