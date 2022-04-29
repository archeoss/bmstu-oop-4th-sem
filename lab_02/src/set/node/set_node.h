#ifndef _SET_NODE_H_
#define _SET_NODE_H_

#include <memory>
#include "errors.h"

template <typename T>
class set_node
{
    T data;
    std::shared_ptr<set_node<T>> next;
    std::shared_ptr<set_node<T>> prev;
public:
    set_node() = default;
    explicit set_node(const T &data);
    explicit set_node(std::shared_ptr<set_node<T>> &node);

    void set_next(const set_node<T> &node);
    void set_next(const std::shared_ptr<set_node<T>> &node);

    void set_prev(const set_node<T> &node);
    void set_prev(const std::shared_ptr<set_node<T>> &node);
    std::shared_ptr<set_node<T>> get_next() const;
    std::shared_ptr<set_node<T>> get_prev() const;

    void set(const T &data);
    
    void set_null();
    
    void exclude();
    
    const T &get();

    std::shared_ptr<set_node<T>> get_next();
    std::shared_ptr<set_node<T>> get_prev();

    bool operator==(const std::shared_ptr<set_node<T>> &node) const;
    bool operator!=(const std::shared_ptr<set_node<T>> &node) const;
    bool operator<(const std::shared_ptr<set_node<T>> &node) const;
    bool operator>(const std::shared_ptr<set_node<T>> &node) const;

    ~set_node() = default;
};

#include "set_node.hpp"

#endif