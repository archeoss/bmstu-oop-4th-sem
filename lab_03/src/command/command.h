//
// Created by thebi on 16.05.2022.
//

#ifndef BMSTU_OOP_4TH_SEM_COMMAND_H
#define BMSTU_OOP_4TH_SEM_COMMAND_H


#include <iostream>
#include <memory>
#include "point.h"
#include "camera.h"

class Model;
class BaseDrawer;
class Scene;

template <typename Receiver>
class BaseCommand
{
public:
    virtual ~BaseCommand() = default;
    virtual void execute(std::shared_ptr<Receiver>) = 0;
};

template <typename Receiver>
class BaseTransformModelCommand : public BaseCommand<Receiver>
{
    using Action = void(Receiver::*)(std::shared_ptr<Object>& object, float kx, float ky, float kz);
private:
    Action act;
    std::shared_ptr<Object> obj;
    float x, y, z;
public:
    explicit BaseTransformModelCommand(Action a, std::shared_ptr<Object>& object, float kx, float ky, float kz) : act(a)
    {
        obj = object;
        x = kx;
        y = ky;
        z = kz;
    }

    void execute(std::shared_ptr<Receiver> r) override { ((*r).*act)(obj, x, y, z); }
};

template <typename Receiver>
class SetObjectCommand : public BaseCommand<Receiver>
{
    using Action = void(Receiver::*)(std::shared_ptr<Object> &obj);
private:
    Action act;
    std::shared_ptr<Object> obj;
public:
    explicit SetObjectCommand(Action a, std::shared_ptr<Object> &object) : act(a)
    {
        this->obj = object;
    }

    void execute(std::shared_ptr<Receiver> r) override { ((*r).*act)(obj); }
};

template <typename Receiver>
class SetSceneCommand : public BaseCommand<Receiver>
{
    using Action = void(Receiver::*)(std::shared_ptr<Scene> &obj);
private:
    Action act;
    std::shared_ptr<Scene> obj;
public:
    explicit SetSceneCommand(Action a, std::shared_ptr<Scene> &object) : act(a)
    {
        this->obj = object;
    }

    void execute(std::shared_ptr<Receiver> r) override { ((*r).*act)(obj); }
};


template <typename Receiver>
class SetCameraCommand : public BaseCommand<Receiver>
{
    using Action = void(Receiver::*)(size_t id);
private:
    Action act;
    size_t id;
public:
    explicit SetCameraCommand(Action a, size_t id) : act(a)
    {
        this->id = id;
    }

    void execute(std::shared_ptr<Receiver> r) override { ((*r).*act)(id); }
};

template <typename Receiver>
class GetObjectCommand : public BaseCommand<Receiver>
{
    using Action = std::shared_ptr<Object> (Receiver::*)(size_t id);
private:
    Action act;
    std::shared_ptr<Object> obj = nullptr;
    size_t idModel;
public:
    GetObjectCommand(const Action &a, const size_t id)
    {
        act = a;
        idModel = id;
    }

    std::shared_ptr<Object> result() { return obj; }
    void execute(std::shared_ptr<Receiver> r) override { obj = ((*r).*act)(idModel); }
};


template <typename Receiver>
class GetCameraCommand : public BaseCommand<Receiver>
{
    using Action = std::shared_ptr<Camera> (Receiver::*)(size_t id);
private:
    Action act;
    std::shared_ptr<Camera> obj = nullptr;
    size_t idModel;
public:
    GetCameraCommand(const Action &a, const size_t id)
    {
        act = a;
        idModel = id;
    }

    std::shared_ptr<Camera> result() { return obj; }
    void execute(std::shared_ptr<Receiver> r) override { obj = ((*r).*act)(idModel); }
};

template <typename Receiver>
class GetSceneCommand : public BaseCommand<Receiver>
{
    using Action = std::shared_ptr<Scene> (Receiver::*)();
private:
    Action act;
    std::shared_ptr<Scene> obj = nullptr;
public:
    explicit GetSceneCommand(Action a) : act(a){}
    std::shared_ptr<Scene> result() { return obj; }
    void execute(std::shared_ptr<Receiver> r) override { obj = ((*r).*act)(); }
};

template <typename Receiver>
class loadModelCommand : public BaseCommand<Receiver>
{
    using Action = void(Receiver::*)(std::string src);
private:
    Action act;
    std::string fileName;
public:
    explicit loadModelCommand(Action a, std::string src) : act(a)
    {
        fileName = src;
    }

    void execute(std::shared_ptr<Receiver> r) override { ((*r).*act)(fileName); }
};

template <typename Receiver>
class addModelCommand : public BaseCommand<Receiver>
{
    using Action = void(Receiver::*)(std::shared_ptr<Model> &obj);
private:
    Action act;
    std::shared_ptr<Model> object;
public:
    explicit addModelCommand(Action a, std::shared_ptr<Model> &obj) : act(a)
    {
        object = obj;
    }

    void execute(std::shared_ptr<Receiver> r) override { ((*r).*act)(object); }
};

template <typename Receiver>
class removeModelCommand : public BaseCommand<Receiver>
{
    using Action = void(Receiver::*)(const size_t id);
private:
    Action act;
    size_t idToDelete;
public:
    explicit removeModelCommand(Action a, size_t id) : act(a)
    {
        idToDelete = id;
    }

    void execute(std::shared_ptr<Receiver> r) override { ((*r).*act)(idToDelete); }
};

template <typename Receiver>
class AddCameraCommand : public BaseCommand<Receiver>
{
    using Action = void(Receiver::*)(std::shared_ptr<Camera>);
private:
    Action act;
public:
    explicit AddCameraCommand(Action a) : act(a)
    {
    }

    void execute(std::shared_ptr<Receiver> r) override { ((*r).*act)(std::make_shared<Camera>()); }
};

template <typename Receiver>
class removeCameraCommand : public BaseCommand<Receiver>
{
    using Action = void(Receiver::*)(const size_t id);
private:
    Action act;
    size_t idToDelete;
public:
    explicit removeCameraCommand(Action a, size_t id) : act(a)
    {
        idToDelete = id;
    }

    void execute(std::shared_ptr<Receiver> r) override { ((*r).*act)(idToDelete); }
};

template <typename Receiver>
class drawSceneCommand : public BaseCommand<Receiver>
{
    using Action = void(Receiver::*)(std::shared_ptr<BaseDrawer> &drw);
private:
    Action act;
    std::shared_ptr<BaseDrawer> drawer;
public:
    explicit drawSceneCommand(Action a, std::shared_ptr<BaseDrawer> &drw) : act(a)
    {
        drawer = drw;
    }

    void execute(std::shared_ptr<Receiver> r) override { ((*r).*act)(drawer); }
};

template <typename Receiver>
class transformModelCommand : public BaseCommand<Receiver>
{
    using Action = void(Receiver::*)(size_t id, Point &move, Point &scale, Point &rotate);
private:
    Action act;

    size_t modelId;

    Point
            move,
            scale,
            rotate;
public:
    explicit transformModelCommand(Action a, size_t id, Point &mv, Point &scl, Point &rot) : act(a)
    {
        modelId = id;
        move = mv;
        scale = scl;
        rotate = rot;
    }

    void execute(std::shared_ptr<Receiver> r) override { ((*r).*act)(modelId, move, scale, rotate); }
};

template <typename Receiver>
class MoveCameraCommand : public BaseCommand<Receiver>
{
    using Action = void(Receiver::*)(size_t id, Point &move);
private:
    Action act;

    size_t cameraId;

    Point
            move;
public:
    explicit MoveCameraCommand(Action a, size_t id, Point &mv) : act(a)
    {
        cameraId = id;
        move = mv;
    }

    void execute(std::shared_ptr<Receiver> r) override { ((*r).*act)(cameraId, move); }
};


#endif //BMSTU_OOP_4TH_SEM_COMMAND_H
