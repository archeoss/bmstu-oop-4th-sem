//
// Created by thebi on 17.05.2022.
//

#ifndef BMSTU_OOP_4TH_SEM_VECTOR_H
#define BMSTU_OOP_4TH_SEM_VECTOR_H

#include <memory>
#include "iterator.h"

class BaseVector
{
public:
    virtual size_t getSize() const = 0;
    virtual bool isEmpty() = 0;
    virtual  ~BaseVector() = default;
protected:
    size_t size;
};

template<class T>
class Vector : public BaseVector
{
public:
    friend class Iterator<T>;
    Vector();
    Vector(Vector<T> &vector);
    Vector(Vector<T> &&vector);
    Vector(const T *array, size_t size);
    explicit Vector(size_t size);
    explicit Vector(T elem, size_t size = 2);

    Vector &operator=(Vector<T> const &vector);
    Vector &operator=(Vector<T> &&vector) noexcept;

    T &operator[](size_t pos);
    ~Vector() override = default;

    void push(const T &elem);

    std::shared_ptr<T[]> getValue();
    const std::shared_ptr<T[]> getValue() const;

    void remove(Iterator<T> &iter);
    void remove(size_t pos);

    size_t getSize() const override;
    bool isEmpty()  override;

    void allocateNew(size_t size);

    Iterator<T> begin();
    Iterator<T> end();
    const Iterator<T> begin() const;
    const Iterator<T> end() const;

private:
    std::shared_ptr<T[]> value;
    size_t memory_allocated;
};

#include "vector.hpp"
#endif //BMSTU_OOP_4TH_SEM_VECTOR_H
