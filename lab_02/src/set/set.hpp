#include "set.h"
#include "set_node.h"

template <typename T>
set<T>::set()
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
set<T>::set(const set<T> &sset) : set()
{
	for (auto it = sset.begin(); it != sset.end(); ++it)
	{
		append(*it);
	}
}

template<typename T>
set<T>::set(std::initializer_list<T> nodes) : set() 
{
    for (auto it = nodes.begin(); it != nodes.end(); ++it) 
    {
        std::shared_ptr<set_node<T>> temp_node = nullptr;

        try 
        {
            temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
        } 
        catch (std::bad_alloc &error) 
        {
            time_t t = time(NULL);
            throw bad_alloc_err(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
        }

        temp_node->set(*it);
        append(temp_node);
    }
}

template <typename T>
set<T>::set(set<T> &&sset) noexcept
{
	this->size = sset.size;
	this->head = sset.head;
	this->tail = sset.tail;

	sset.size = 0;
	sset.head = nullptr;
	sset.tail = nullptr;
}

template <typename T>
set<T>::set(size_t n, ...) : set()
{
    va_list vlist;
    va_start(vlist, n);
    for (size_t i = 0; i < n; i++)
    {
        std::shared_ptr<set_node<T>> temp_node = nullptr;

        try 
        {
            temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
        }
        catch (std::bad_alloc &error)
        {
            time_t t = time(NULL);
            throw bad_alloc_err(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
        }

        temp_node->set(va_arg(vlist, T));
        append(temp_node);
    }
    va_end(vlist);
}

template <typename T>
set<T>::set(const T* arr, size_t n) : set()
{
    for (size_t i = 0; i < n; i++)
    {
        std::shared_ptr<set_node<T>> temp_node = nullptr;

        try 
        {
            temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
        }
        catch (std::bad_alloc &error)
        {
            time_t t = time(NULL);
            throw bad_alloc_err(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
        }

        temp_node->set(arr[i]);
        append(temp_node);
    }
}

template<typename T>
bool set<T>::append(const T &value)
{
    std::shared_ptr<set_node<T>> temp_node;

    try 
    {
        temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
    }
    catch (std::bad_alloc &error)
    {
        time_t t = time(NULL);
        throw bad_alloc_err(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
    }

    temp_node->set(value);

    return append(temp_node);
}

template<typename T>
bool set<T>::append(T &&value)
{
    std::shared_ptr<set_node<T>> temp_node;

    try 
    {
        temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
    }
    catch (std::bad_alloc &error)
    {
        time_t t = time(NULL);
        throw bad_alloc_err(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
    }

    temp_node->set(value);

    return append(temp_node);
}

template <typename T>
bool set<T>::append(const std::shared_ptr<set_node<T>> &node)
{
    std::shared_ptr<set_node<T>> temp_node = nullptr;
    try
    {
        temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
    }
    catch (std::bad_alloc &e)
    {
        time_t t = time(NULL);
        throw bad_alloc_err(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
    }

    temp_node->set(node->get());
    T value = temp_node->get();
    int code = true;
    if (!size)
    {
        head = temp_node;
        tail = temp_node;
        size++;
    }
    else if (inSet(value))
    {
        code = false;
    }
    else 
    {
        temp_node->set_prev(tail);
        tail->set_next(temp_node);
        tail = temp_node;
        size++;
    }

    return code;
}

template <typename T>
void set<T>::append(std::initializer_list<T> nodes)
{
    for (auto it = nodes.begin(); it != nodes.end(); ++it)
    {
        std::shared_ptr<set_node<T>> temp_node = nullptr;

        try 
        {
            temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
        }
        catch (std::bad_alloc &error)
        {
            time_t t = time(NULL);
            throw bad_alloc_err(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
        }

        temp_node->set(*it);
        append(temp_node);
    }
}

template <typename T>
void set<T>::append(const T *arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        append(arr[i]);
    }
}

template <typename T>
set<T> set<T>::update(const T &value)
{
    set<T> res = set(*this);
    res.append(value);

    return res;
}

template <typename T>
set<T> set<T>::update(T &&value)
{
    set<T> res = set(*this);
    res.append(value);

    return res;
}

template <typename T>
set<T> set<T>::update(std::initializer_list<T> nodes)
{
    set<T> res = set(*this);
    res.append(nodes);

    return res;
}

template <typename T>
set<T> set<T>::update(const T *arr, size_t n)
{
    set<T> res = set(*this);
    res.append(arr, n);

    return res;
}

template<typename T>
set<T> set<T>::operator+(const set<T> &sset)
{
    set<T> sum = set(*this);
    sum += sset;
    
    return sum;
}

template<typename T>
set<T> set<T>::operator+(const T &data)
{
	set<T> sum = set(*this);
	sum += data;

	return sum;
}

template<typename T>
set<T> operator+(const T &data, set<T> sset)
{
	set<T> sum = sset;

	return sum + data;
}

template<typename T>
set<T> &set<T>::operator+=(const set<T> &sset)
{   
    for (auto it = sset.begin(); it != sset.end(); ++it)
    {
        append(*it);
    }
        
    return *this;
}

template<typename T>
set<T> &set<T>::operator+=(const T &data)
{
    append(data);
    return *this;
}

template<typename T>
set<T> &set<T>::operator=(const set<T> &sset)
{   
    if (&sset == this)
        return *this;

    this->clear();

    size = 0;
    head = nullptr;
    tail = nullptr;

    for (auto it = sset.begin(); it != sset.end() ; ++it)
    {
        std::shared_ptr<set_node<T>> temp_node = nullptr;

        try
        {
            temp_node = std::shared_ptr<set_node<T>>(new set_node<T>);
        }
        catch (std::bad_alloc &error)
        {
            time_t t = time(NULL);
            throw bad_alloc_err(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
        }

        temp_node->set(*it);
        append(temp_node);
    }

    return *this;
}

template<typename T>
set<T> &set<T>::operator=(const T &data)
{
    this->clear();
    this->append(data);

    return *this;
}

template<typename T>
set<T> set<T>::operator&(const set<T> &data) {
    set<T> res;
	auto j = data.begin();
    for (;j;)
    {
        if (inSet(*j)) 
        {
            res.append(*j);
            ++j;
        }
        else 
        {
            ++j;
        }
    }

    return res;
}

template<typename T>
set<T> set<T>::operator&(const T &data)
{
	if (inSet(data))
		return set<T>{data};

	return set<T>();
}

template<typename T>
set<T> operator&(const T &data, set<T> sset)
{
	if (sset.inSet(data))
		return set<T>{data};

	return set<T>();
}

template<typename T>
set<T> set<T>::operator|(const set<T> &set) 
{
    return *this + set;
}

template<typename T>
set<T> set<T>::operator|(const T &data)
{
	return *this + data;
}


template<typename T>
set<T> operator|(const T &data, set<T> sset)
{
	return sset + data;
}

template<typename T>
set<T> set<T>::operator-(const set<T> &data) 
{
    set<T> res;

    for (auto i : *this)
        res.append(i);
    for (auto i : data)
        res.erase(i);

    return res;
}

template<typename T>
set<T> set<T>::operator-(const T &data)
{
	set<T> res = *this;
	res.erase(data);

	return res;
}

template<typename T>
set<T> operator-(const T &data, set<T> sset)
{
	if (sset.inSet(data))
		return set<T>{};

	return set<T>{data};
}

template<typename T>
set<T> set<T>::operator^(const set<T> &data) 
{
    set<T> res;

    for (auto i : *this)
        if (!data.inSet(i))
            res.append(i);

    for (auto i : data)
        if (!inSet(i))
            res.append(i);
        else
            res.erase(i);

    return res;
}

template<typename T>
set<T> set<T>::operator^(const T &data)
{
	set<T> res;
	res = *this;
	res.erase(data);

	return res;
}

template<typename T>
set<T> operator^(const T &data, set<T> sset)
{
	set<T> res;
	res = sset;
	res.erase(data);

	return res;
}

template<typename T>
set<T> &set<T>::operator&=(const set<T> &list) 
{
    set<T> res;
    auto i = this->begin();
    auto j = list.begin();
    for (; i && j;)
    {
        auto data_i = *i, data_j = *j;
        if (data_i == data_j)
        {
            res.append(data_i);
            ++i;
            ++j;
        }
        else if (data_i < data_j)
        {
            ++i;
        } 
        else 
        {
            ++j;
        }
    }

    clear();

    for (auto k = res.begin(); k && (res.end() != k); ++k)
        append(*k);

    return *this;
}

template<typename T>
set<T> &set<T>::operator&=(const T &data)
{
    if (!inSet(data)) 
    {
        clear();
    } 
    else 
    {
        clear();
        append(data);
    }

    return *this;
}

template<typename T>
set<T> &set<T>::operator|=(const set<T> &set) {
    *this += set;

    return *this;
}

template<typename T>
set<T> &set<T>::operator|=(const T &data) {
    *this += data;

    return *this;
}

template<typename T>
set<T> &set<T>::operator-=(const set<T> &sset) 
{
    for (auto i = sset.begin(); sset.end() != i; ++i)
        erase(*i);

    return *this;
}

template<typename T>
set<T> &set<T>::operator-=(const T &data) 
{
    erase(data);

    return *this;
}

template<typename T>
set<T> &set<T>::operator^=(const set<T> &list) 
{
    set<T> temp = *this ^ list;

    clear();
    for (auto i = temp.begin(); i != temp.end(); ++i)
        append(*i);

    return *this;
}

template<typename T>
set<T> &set<T>::operator^=(const T &data) 
{
    if (!inSet(data))
        append(data);
    else
        erase(data);

    return *this;
}

template<typename T>
set<T> set<T>::intersect(const set<T> &set) 
{
    return *this & set;
}

template<typename T>
set<T> set<T>::intersect(const T &data) 
{
    return *this & data;
}

template<typename T>
set<T> set<T>::combine(const set<T> &set) 
{
    return *this | set;
}

template<typename T>
set<T> set<T>::combine(const T &data) 
{
    return *this | data;
}

template<typename T>
set<T> set<T>::difference(const set<T> &set) 
{
    return *this - set;
}

template<typename T>
set<T> set<T>::difference(const T &data) 
{
    return *this - data;
}

template<typename T>
set<T> set<T>::symmetric_difference(const set<T> &data) 
{
    return *this ^ data;
}

template<typename T>
set<T> set<T>::symmetric_difference(const T &data) 
{
    return *this ^ data;
}

template<typename T>
void erase(constSetIter<T> pos)
{
    erase(*pos);
}

template<typename T>
void erase(setIter<T> pos)
{
    erase(*pos);
}

template<typename T>
void set<T>::erase(const T &value) 
{
    if (!size)
    {
        return;
    }
    if (!inSet(value))
    {
        return;
    }

	std::shared_ptr<set_node<T>> cur_node = this->head;
	std::shared_ptr<set_node<T>> tmp = nullptr;
	constSetIter<T> cur = this->begin();

	for (; cur_node && *cur != value; tmp = cur_node, cur_node = cur_node->get_next(), cur.next()){}

	if (cur_node == nullptr)
	{
		time_t t = time(NULL);
		throw set_range_error(ctime(&t), __FILE__, typeid(*this).name(), __FUNCTION__);
	}

	if (cur_node->get_next() == nullptr)
	{
		this->tail = tmp;
	}

	if (cur_node == this->head)
	{
		this->head = this->head->get_next();
	}
	else
	{
		tmp->set_next(cur_node->get_next());
	}
	this->size -= 1;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, set<T> &list) 
{
    for (auto el = list.begin(); el != list.end(); ++el)
        os << *el << " ";

    return os;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const set<T> &list) 
{
    for (auto el = list.begin(); el != list.end(); ++el)
        os << *el << " ";

    return os;
}

template<typename T>
bool set<T>::operator==(const set<T> &sset)
{   
    bool flag = true;
    if (size != sset.size)
    {
        flag = false;
    }
    for (auto it = sset.begin(); flag && it != sset.end(); ++it)
    {
        if (!inSet(*it))
        {
            flag = false;
        }
    }

    return flag;
}

template<typename T>
bool set<T>::operator!=(const set<T> &sset)
{
    return !(this == sset);
}

template<typename T>
void set<T>::clear() 
{
    while (head) 
    {
        auto t = head;
        head = head->get_next();
        t->set_next(nullptr);

        t = tail;
        tail = tail->get_prev();
        t->set_prev(nullptr);
    }

    size = 0;
}

// Capacity
template<typename T>
size_t set<T>::get_size() 
{
    return size;
}

template<typename T>
bool set<T>::inSet(const T &val) const 
{
    for (auto it = begin(); it != end(); ++it)
    {
        if (val == *it)
        {
            return true;
        }
    }
    
    return false;
}

template<typename T>
constSetIter<T> set<T>::begin() const 
{
    return constSetIter<T>(head);
}

template<typename T>
constSetIter<T> set<T>::end() const 
{
    return constSetIter<T>(tail ? tail->get_next() : nullptr);
}
