#include "setIter.h"

template <typename T>
setIterBase<T>::setIterBase()
{
    this->ptrCur.lock() = nullptr;
}

template <typename T>
setIterBase<T>::setIterBase(const setIterBase<T> &setItr)
{
    this->ptrCur = setItr.ptrCur.lock();
}

template <typename T>
setIterBase<T>::setIterBase(const std::shared_ptr<set_node<T>> node)
{
    this->ptrCur = node;
}

template <typename T>
setIterBase<T> &setIterBase<T>::next()
{
	if (this->ptrCur.expired())
	{
		time_t t = time(nullptr);
		throw iterator_error(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
	}
	this->ptrCur = this->ptrCur.lock()->get_next();
	return *this;
}

template <typename T>
setIterBase<T> &setIterBase<T>::prev()
{
	if (this->ptrCur.expired())
	{
		time_t t = time(nullptr);
		throw iterator_error(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
	}
	this->ptrCur = this->ptrCur.lock()->get_prev();
	return *this;
}

template <typename T>
setIterBase<T> &setIterBase<T>::operator=(const setIterBase<T> &setItr)
{
    if (this != &setItr)
    {
        this->ptrCur = setItr.ptrCur.lock();
    }
    return *this;
}

template <typename T>
setIterBase<T> &setIterBase<T>::operator++()
{
	this->next();
	return *this;
}

template <typename T>
setIterBase<T> setIterBase<T>::operator++(int)
{
	setIterBase<T> tmp(*this);
	this->operator++();
	return tmp;
}

template <typename T>
setIterBase<T> &setIterBase<T>::operator--()
{
	this->prev();
	return *this;
}

template <typename T>
setIterBase<T> setIterBase<T>::operator--(int)
{
	setIterBase<T> tmp(*this);
	this->operator--();
	return tmp;
}

template <typename T>
bool setIterBase<T>::operator==(const setIterBase<T> &setItr)
{
    return this->ptrCur.lock() == setItr.ptrCur.lock();
}

template <typename T>
bool setIterBase<T>::operator!=(const setIterBase<T> &setItr)
{
    return this->ptrCur.lock() != setItr.ptrCur.lock();
}

/*
    setIter's methods
*/

template <typename T>
setIter<T>::setIter()
{
    this->ptrCur.lock() = nullptr;
}

template <typename T>
setIter<T>::setIter(const setIter<T> &setItr)
{
    this->ptrCur = setItr.ptrCur.lock();
}

template <typename T>
setIter<T>::setIter(const std::shared_ptr<set_node<T>> node)
{
    this->ptrCur = node;
}

template <typename T>
setIter<T> &setIter<T>::operator=(const setIter<T> &setItr)
{
    if (this != &setItr)
    {
        this->ptrCur = setItr.ptrCur;
    }

    return *this;
}

template <typename T>
const T &setIter<T>::getCur() const
{
    if (this->ptrCur.expired())
    {
        time_t t = time(nullptr);
        throw iterator_error(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
    }

    return this->ptrCur.lock()->value();
}

template <typename T>
const T &setIter<T>::getNext() const
{
    if (this->ptrCur.expired() || this->ptrCur.lock() == this->c_end() || this->ptrCur.next().lock() == this->c_end())
    {
        time_t t = time(nullptr);
        throw iterator_error(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    return this->ptrCur.next().lock()->value();
}

template <typename T>
const T &setIter<T>::operator*() const
{
    if (this->ptrCur.expired())
    {
        time_t t = time(nullptr);
        throw iterator_error(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    return this->ptrCur.lock()->value();
}

template <typename T>
const T *setIter<T>::operator->() const
{
    if (this->ptrCur.expired())
    {
        time_t t = time(nullptr);
        throw iterator_error(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    return &this->ptrCur.lock()->value();
}

template <typename T>
bool setIter<T>::operator==(const setIter<T> &setItr)
{
    return this->ptrCur.lock() == setItr.ptrCur.lock();
}

template <typename T>
bool setIter<T>::operator!=(const setIter<T> &setItr)
{
    return this->ptrCur.lock() != setItr.ptrCur.lock();
}

template <typename T>
setIter<T>::operator bool() const
{
    return nullptr != this->ptrCur.lock();
}


/*
    constSetInter's methods
*/

template <typename T>
constSetIter<T>::constSetIter()
{
    this->ptrCur.lock() = nullptr;
}

template <typename T>
constSetIter<T>::constSetIter(const constSetIter<T> &setItr)
{
    this->ptrCur = setItr.ptrCur;
}

template <typename T>
constSetIter<T>::constSetIter(const std::shared_ptr<set_node<T>> node)
{
    this->ptrCur = node;
}

template <typename T>
constSetIter<T> &constSetIter<T>::operator=(const constSetIter<T> &setItr)
{
    if (this != &setItr)
    {
        this->ptrCur = setItr.ptrCur;
    }

    return *this;
}

template <typename T>
const T &constSetIter<T>::getCur() const
{
    if (this->ptrCur.expired())
    {
        time_t t = time(nullptr);
        throw iterator_error(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    
    return this->ptrCur.lock()->value();
}

template <typename T>
const T &constSetIter<T>::getNext() const
{
    if (this->ptrCur.expired() || this->ptrCur.lock() == this->c_end() || this->ptrCur.next().lock() == this->c_end())
    {
        time_t t = time(nullptr);
        throw iterator_error(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    return this->ptrCur.next().lock()->value();
}

template <typename T>
const T &constSetIter<T>::operator*() const
{
    if (this->ptrCur.expired())
    {
        time_t t = time(nullptr);
        throw iterator_error(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    return this->ptrCur.lock()->value();
}

template <typename T>
const T *constSetIter<T>::operator->() const
{
    if (this->ptrCur.expired())
    {
        time_t t = time(nullptr);
        throw iterator_error(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
    return &this->ptrCur.lock()->value();
}

template <typename T>
constSetIter<T>::operator bool() const
{
    return nullptr != this->ptrCur.lock();
}