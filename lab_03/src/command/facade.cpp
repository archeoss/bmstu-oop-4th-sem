//
// Created by thebi on 16.05.2022.
//

#include "facade.h"

template <class T>
void Facade::execute(std::shared_ptr<BaseCommand<T>> command,
                     std::shared_ptr<T> obj)
{
    command->execute(obj);
}

