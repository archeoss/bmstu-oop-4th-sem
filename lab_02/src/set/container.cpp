#include "container.h"

Container::~Container() = default;

bool Container::is_empty() const
{
    return size == 0;
}