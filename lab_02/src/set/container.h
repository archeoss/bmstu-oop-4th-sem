#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include <cstdlib>

class Container
{
public:
    virtual void clear() = 0;
    virtual bool is_empty() const;
    virtual ~Container();

protected:
    size_t size = 0;
};


#endif