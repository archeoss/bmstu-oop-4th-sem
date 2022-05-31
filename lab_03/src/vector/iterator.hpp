//
// Created by thebi on 17.05.2022.
//

#include "iterator.h"
#include "object.h"

template<class T>
Iterator<T>::Iterator(const Iterator<T> &iter)
{
    this->ptr = iter.ptr;
    this->currentIndex = iter.currentIndex;
    this->vectorSize = iter.vectorSize;
}

template<class T>
Iterator<T>::Iterator(const Vector<T> &vector)
{
    this->currentIndex = 0;
    this->vectorSize = vector.getSize();
    this->ptr = vector.value;
}

template<class T>
Iterator<T>::operator bool() const
{
    return vectorSize && vectorSize <= currentIndex;
}

template<class T>
const T *Iterator<T>::operator->() const
{
    return getCurrent();
}

template<class T>
const T &Iterator<T>::operator*() const
{
    return getCurrent();
}

template<class T>
T *Iterator<T>::operator->()
{
    return getCurrent();
}

template<class T>
T &Iterator<T>::operator*()
{
    return *getCurrent();
}

template<class T>
Iterator<T> &Iterator<T>::operator++(int)
{
    Iterator<T> tmp(*this);
    this->operator++();
    return tmp;
}

template <typename T>
Iterator<T> &Iterator<T>::operator++()
{
    this->currentIndex++;
    return *this;
}

template<class T>
Iterator<T> &Iterator<T>::operator--(int)
{
    Iterator<T> tmp(*this);
    this->operator--();
    return tmp;
}

template <typename T>
Iterator<T> &Iterator<T>::operator--()
{
    this->currentIndex--;
    return *this;
}

template <typename T>
Iterator<T> &Iterator<T>::operator+=(size_t number)
{
    this->currentIndex += number;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator+(size_t number)
{
    Iterator<T> tmp(*this);
    tmp += number;
    return tmp;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator<T> &iter) const
{
    return this->currentIndex == iter.currentIndex;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T> &iter) const
{
    return this->currentIndex != iter.currentIndex;
}

template<class T>
T *Iterator<T>::getCurrent() const
{
    return this->ptr.lock().get() + currentIndex;
}

