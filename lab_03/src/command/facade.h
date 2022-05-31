//
// Created by thebi on 16.05.2022.
//

#ifndef BMSTU_OOP_4TH_SEM_FACADE_H
#define BMSTU_OOP_4TH_SEM_FACADE_H

#include "command.h"
#include "src/objects/object.h"
#include "cameraManager.h"
#include "drawManager.h"
#include "sceneManager.h"
#include "transformManager.h"
#include <memory>
#include <cstdlib>

class Facade
{
public:
    CameraManager   _camMan;
    DrawManager     _drawMan;
    SceneManager    _sceneMan;
    TransformManager _tranMan;
    Facade() = default;

    static std::shared_ptr<Facade> instance()
    {
        static std::shared_ptr<Facade> _facade(new Facade());

        return _facade;
    }

    template <class T>
    void execute(std::shared_ptr<BaseCommand<T>> command, std::shared_ptr<T> obj);

    ~Facade() = default;
};


#endif //BMSTU_OOP_4TH_SEM_FACADE_H
