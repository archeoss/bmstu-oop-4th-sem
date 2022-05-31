//
// Created by thebi on 17.05.2022.
//

#include "vector.h"

template<class T>
Vector<T>::Vector()
{
    this->size = 0;
    this->memory_allocated = 0;
}

template<class T>
Vector<T>::Vector(const T *array, size_t size)
{
    this->size = 0;
    this->allocateNew(size);
    for (const auto &elem: array)
    {
        this->push(elem);
    }
}

template<class T>
Vector<T>::Vector(Vector<T> &vector)
{
    this->size = 0;
    this->allocateNew(vector.memory_allocated);
    for (const auto &elem: vector)
    {
        this->push(elem);
    }
}

template<class T>
Vector<T> &Vector<T>::operator=(Vector<T> const &vector)
{
    this->size = 0;
    this->allocateNew(vector.memory_allocated);
    for (auto &elem: vector)
    {
        this->push(elem);
    }

    return *this;
}

template<class T>
Vector<T> &Vector<T>::operator=(Vector<T> &&vector) noexcept
{
    this->value = vector.value;
    this->memory_allocated = vector.value;
    this->size = vector.size;
    vector.~Vector();
}

template<class T>
Vector<T>::Vector(Vector<T> &&vector)
{
    this->value = vector.value;
    this->memory_allocated = vector.memory_allocated;
    this->size = vector.size;
    vector.~Vector();
}

template<class T>
Vector<T>::Vector(const T elem, size_t size)
{
    this->size = 0;
    this->allocateNew(size);
    this->push(elem);
}

template<class T>
Vector<T>::Vector(size_t size)
{
    this->size = 0;
    allocateNew(size);
}

template<class T>
size_t Vector<T>::getSize() const
{
    return this->size;
}

template<class T>
bool Vector<T>::isEmpty()
{
    return this->size == 0;
}

template<class T>
void Vector<T>::allocateNew(size_t size)
{
    try
    {
        this->value.reset(new T[size]);
    }
    catch (std::bad_alloc &exception)
    {
        //todo
    }

    this->memory_allocated = size;
}

template<class T>
void Vector<T>::push(const T &elem)
{
    if (this->size >= this->memory_allocated)
    {
        allocateNew(size * 2);
    }
    this->value[static_cast<long long>(this->size++)] = elem;
}

template<class T>
const Iterator<T> Vector<T>::begin() const
{
    return Iterator<T>(*this);
}

template<class T>
const Iterator<T> Vector<T>::end() const
{
    Iterator<T> tmp = Iterator<T>(*this);
    return tmp + this->getSize();
}

template<class T>
Iterator<T> Vector<T>::begin()
{
    return Iterator<T>(*this);
}

template<class T>
Iterator<T> Vector<T>::end()
{
    Iterator<T> tmp = Iterator<T>(*this);
    return tmp + this->getSize();
}

template<class T>
T &Vector<T>::operator[](size_t pos)
{
//    Iterator<T> start = Iterator<T>(*this);
//    start += pos;
//
//    return *start;
}

template<class T>
void Vector<T>::remove(Iterator<T> &iter)
{
//    Iterator<T> iterB = iter + 1;
//    Iterator<T> e = end();
//    while (iterB != e)
//    {
//        iter.
//    }
}



