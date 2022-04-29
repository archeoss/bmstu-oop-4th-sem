#ifndef _SET_H_
#define _SET_H_

#include "container.h"
#include <initializer_list>
#include <memory>
#include <cstdarg>
#include "set_node.h"
#include "setIter.h"
#include "errors.h"

template <typename T>
class set : public Container
{
public:
    set();

    set(const set<T> &sset);    // copy
    set(set<T> &&sset) noexcept;   // move
    set(const T* arr, const size_t n);
    set(std::initializer_list<T> nodes);
    explicit set(size_t n, ...);

    bool append(const T &value);
    bool append(T &&value);
    
    void append(std::initializer_list<T> nodes);
    void append(const T *arr, size_t n);
    
    set<T> update(const T &value);
    set<T> update(T &&value);
    
    set<T> update(std::initializer_list<T> nodes);
    set<T> update(const T *arr, size_t n);

    set<T> &operator=(const set<T> &set);
    set<T> &operator=(const T &data);
    
    size_t get_size();

    bool inSet(const T &val) const;

    /* 
        Combine
    */

    set<T> operator+(const set<T> &set);
    set<T> operator+(const T &data);
    set<T> &operator+=(const set<T> &set);
    set<T> &operator+=(const T &data);
        
    set<T> operator|(const set<T> &set);
    set<T> operator|(const T &data);
    set<T> &operator|=(const set<T> &set);
    set<T> &operator|=(const T &data);

    set<T> combine(const set<T> &set);
    set<T> combine(const T &data);

    /*
        Difference
    */
    set<T> operator-(const set<T> &set);
    set<T> operator-(const T &data);
    set<T> &operator-=(const set<T> &set);
    set<T> &operator-=(const T &data);

    set<T> difference(const set<T> &set);
    set<T> difference(const T &data);
    
    /*
        Intersection
    */

    set<T> operator&(const set<T> &set);
    set<T> operator&(const T &data);
    set<T> &operator&=(const set<T> &set);
    set<T> &operator&=(const T &data);

    set<T> intersect(const set<T> &set);
    set<T> intersect(const T &data);

    /*
        Symmetric difference
    */

    set<T> operator^(const set<T> &set);
    set<T> operator^(const T &data);
    set<T> &operator^=(const set<T> &set);
    set<T> &operator^=(const T &data);

    set<T> symmetric_difference(const set<T> &set);
    set<T> symmetric_difference(const T &data);

    /*
        Equal - Not Equal
    */

    bool operator==(const set<T> &sset);
    bool operator!=(const set<T> &sset);

    constSetIter<T> begin() const;
    constSetIter<T> end() const;

    void clear() override;

    void erase(const T &value);
    void erase(constSetIter<T> pos);
    void erase(setIter<T> pos);

    // Destructor
    ~set() override = default;
private:
    std::shared_ptr<set_node<T>> head;
    std::shared_ptr<set_node<T>> tail;
protected:
    bool append(const std::shared_ptr<set_node<T>> &node);
};

#include "set.hpp"

#endif