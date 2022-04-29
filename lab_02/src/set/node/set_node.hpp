#include "set_node.h"

template <typename T>
set_node<T>::set_node(const T &data)
{
    this->data = data;
}

template <typename T>
set_node<T>::set_node(std::shared_ptr<set_node<T>> &node) : set_node<T>(node.data)
{
    this->next = node.next;
}

template <typename T>
void set_node<T>::set(const T &val)
{
    this->data = val;
}

template <typename T>
void set_node<T>::set_next(const set_node<T> &node)
{
    this->next = std::make_shared<set_node<T>>(node);
}

template <typename T>
void set_node<T>::set_next(const std::shared_ptr<set_node<T>> &node)
{
    this->next = node;
}

template <typename T>
void set_node<T>::set_prev(const set_node<T> &node)
{
    this->prev = std::make_shared<set_node<T>>(node);
}

template<typename T>
std::shared_ptr<set_node<T>> set_node<T>::get_next() const {
    return next;
}

template<typename T>
std::shared_ptr<set_node<T>> set_node<T>::get_prev() const {
    return prev;
}

template <typename T>
void set_node<T>::set_prev(const std::shared_ptr<set_node<T>> &node)
{
    this->prev = node;
}

template <typename T>
void set_node<T>::set_null()
{
    this->next = nullptr;
    this->prev = nullptr;
}

template <typename T>
void set_node<T>::exclude()
{
    if (next)
        next->prev = prev;

    if (prev)
        prev->next = next;

    set_null();
}


template <typename T>
const T &set_node<T>::get()
{
    return this->data;
}

template <typename T>
T &set_node<T>::value()
{
    return this->data;
}

template <typename T>
std::shared_ptr<set_node<T>> set_node<T>::get_next()
{
    return this->next;
}

template <typename T>
std::shared_ptr<set_node<T>> set_node<T>::get_prev()
{
    return this->prev;
}

template<typename T>
bool set_node<T>::operator==(const std::shared_ptr<set_node<T>> &node) const 
{
    return this == node;
}

template<typename T>
bool set_node<T>::operator!=(const std::shared_ptr<set_node<T>> &node) const 
{
    return this != node;
}

template<typename T>
bool set_node<T>::operator<(const std::shared_ptr<set_node<T>> &node) const
{
    return this->data < node.lock()->data;
}

template<typename T>
bool set_node<T>::operator>(const std::shared_ptr<set_node<T>> &node) const
{
    return this->data > node.lock()->data;
}
