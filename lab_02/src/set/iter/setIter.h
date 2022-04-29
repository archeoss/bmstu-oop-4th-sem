#ifndef _ITER_H_
#define _ITER_H_

#include "set_node.h"
#include "errors.h"

template <typename T>
class setIterBase : public std::iterator<std::bidirectional_iterator_tag, T>
{
public:
    setIterBase();
    setIterBase(const setIterBase<T> &setItr);
    explicit setIterBase(std::shared_ptr<set_node<T>> node);

    setIterBase<T> &operator=(const setIterBase<T> &setItr);

	setIterBase<T> &next();
	setIterBase<T> &prev();
	setIterBase<T> &operator++();
	setIterBase<T> operator++(int);
	setIterBase<T> &operator--();
	setIterBase<T> operator--(int);

	bool operator!=(const setIterBase<T> &setItr);
    bool operator==(const setIterBase<T> &setItr);

    virtual ~setIterBase() = default;
protected:
    std::weak_ptr<set_node<T>> ptrCur;
};

template <typename T>
class setIter : public setIterBase<T>
{
public:
    setIter();
    setIter(const setIter<T> &setItr);
    explicit setIter(std::shared_ptr<set_node<T>> node);
    
    setIter<T> &operator=(const setIter<T> &setItr);
    
    bool operator!=(const setIter<T> &setItr);
    bool operator==(const setIter<T> &setItr);

    const T &getCur() const;
    const T &getNext() const;
    const T &operator*() const;
    const T *operator->() const;

    operator bool() const;

    virtual ~setIter() = default;
};

template <typename T>
class constSetIter : public setIterBase<T>
{
public:
    constSetIter();
    constSetIter(const constSetIter<T> &setItr);
    explicit constSetIter(std::shared_ptr<set_node<T>> node);

    constSetIter<T> &operator=(const constSetIter<T> &xetItr);

    const T &getCur() const;
    const T &getNext() const;
    const T &operator*() const;
    const T *operator->() const;
    
    operator bool() const;
};

#include "setIter.hpp"

#endif
