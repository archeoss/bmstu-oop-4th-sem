//
// Created by thebi on 21.05.2022.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QMessageBox>

#include "facade.h"
#include "command.h"
//#include "../errors/camera_error.h"
//#include "../errors/model_error.h"
#include "ui_mainwindow.h"
#include "factory.h"
#include "drawer.h"
#include "cameraManager.h"
#include "sceneManager.h"
#include "command.h"
#include "transformManager.h"

#include <math.h>

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <memory>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    class DrawDirector
    {
        friend class MainWindow;

    private:
        std::shared_ptr<QGraphicsScene> _scene_view;

    public:
        DrawDirector() = default;
        void set_scene(std::shared_ptr<QGraphicsScene> &scene_view) { this->_scene_view = scene_view; }
        std::shared_ptr<BaseDrawer> get_drawer(const char *fp, std::shared_ptr<AbstractFactory> &f);
    };

private slots:
    void on_move_button_clicked();

    void on_scale_button_clicked();

    void on_pushButton_AddModel_clicked();

    void on_pushButton_AddCamera_clicked();

    void on_pushButton_SetCamera_clicked();

    void on_pushButton_RemoveCamera_clicked();

    void on_pushButton_RemoveModel_clicked();

    void on_pushButton_moveModel_clicked();

    void on_pushButton_scaleModel_clicked();

    void on_pushButton_rotateModel_clicked();

    void on_pushButton_moveCamera_clicked();

    void on_pushButton_rotateCamera_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<QGraphicsScene> scene_view;
    // QPixmap pixmap;
    DrawDirector director;
    std::unique_ptr<Facade> facade;
    size_t index_model;
    size_t index_camera;
    friend class DrawDirector;
    char *development_environment;
    void render();
    void getObj(std::shared_ptr<Object> &obj, std::shared_ptr<Scene> &sc);
    void getCam(std::shared_ptr<Camera> &obj, std::shared_ptr<Scene> &sc);
    void getScene(std::shared_ptr<Scene> &sc);
    void setCam(size_t id);
    void setScene(std::shared_ptr<Scene> &sc);
//    void setObj(size_t id);
    void addCam(std::shared_ptr<Scene> &sc, std::shared_ptr<Camera> &cmr);
    std::string readConfigFile(const char *filename);
};
#endif //OOP_LAB_03_MAINWINDOW_H
