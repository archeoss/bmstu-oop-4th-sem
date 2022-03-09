#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, ui->mainFrame->width() - 10, ui->mainFrame->height() - 10);
    connect(ui->moveButton, SIGNAL(clicked()), this, SLOT(move_clicked()));
    connect(ui->rotateButton, SIGNAL(clicked()), this, SLOT(rotate_clicked()));
    connect(ui->scaleButton, SIGNAL(clicked()), this, SLOT(scale_clicked()));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(exit()));
    connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(reset()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(load_clicked()));
    connect(ui->actionSave_as, SIGNAL(triggered()), this, SLOT(save_clicked()));
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(exit()));
}

MainWindow::~MainWindow()
{
    request_t request;
    request.task = EXIT;
    event_handler(request);

    delete ui;
}

int MainWindow::draw_obj(void)
{
    painter_t painter;
    painter.scene = ui->graphicsView->scene();
    painter.scene->clear();
    painter.width = painter.scene->width();
    painter.height = painter.scene->height();

    request_t request;
    request.task = DRAW;
    fill_draw_request(request.draw, painter);

    int error_code = event_handler(request);

    return error_code;
}

void MainWindow::load_clicked(void)
{
    int error_code = OK;
    QFileDialog dialog(this);
    QStringList filename;
    if (dialog.exec())
        filename = dialog.selectedFiles();
    else
    {
        error_code = CANNOT_OPEN_DIALOG;
        log_error(error_code);
        return;
    }
    const char *name = filename.at(0).toLocal8Bit().constData();
    request_t request;

    request.task = LOAD;
    fill_load_request(request.load, name);

    error_code = event_handler(request);
    if (error_code == OK)
    {
        error_code = draw_obj();
    }
    if (error_code == OK)
    {
        request.task = SAVE_BACKUP;
        error_code = event_handler(request);
    }

    if (error_code != OK)
    {
        log_error(error_code);
    }
}

void MainWindow::save_clicked(void)
{
    int error_code = OK;
    QFileDialog dialog(this);
    QStringList filename;
    if (dialog.exec())
        filename = dialog.selectedFiles();
    else
    {
        error_code = CANNOT_OPEN_DIALOG;
        log_error(error_code);
        return;
    }
    const char *name = filename.at(0).toLocal8Bit().constData();
    request_t request;

    request.task = SAVE;
    fill_save_request(request.save, name);

    error_code = event_handler(request);
    if (error_code != OK)
    {
        log_error(error_code);
    }
}

void MainWindow::move_clicked(void)
{
    transfer_t transform;
    transform.kx = ui->moveXForm->value();
    transform.ky = ui->moveYForm->value();
    transform.kz = ui->moveZForm->value();

    request_t request;
    request.task = MOVE;
    fill_move_request(request.move, transform);
    int error_code = event_handler(request);
    if (error_code == OK)
    {   
        error_code = draw_obj();
    }
    if (error_code != OK)
    {
        log_error(error_code);
    }
}

void MainWindow::scale_clicked(void)
{
    transfer_t scale;
    scale.kx = ui->scaleXForm->value();
    scale.ky = ui->scaleYForm->value();
    scale.kz = ui->scaleZForm->value();

    request_t request;
    request.task = FIND_CENTER;
    point_t center;
    request.center.point = center;
    int error_code = event_handler(request);
    if (error_code != OK)
    {
        log_error(error_code);
        return;
    }
    center = request.center.point;
    request.task = SCALE;
    fill_scale_request(request.scale, scale, center);
    
    error_code = event_handler(request);
    if (error_code == OK)
    {
        error_code = draw_obj();
    }
    if (error_code != OK)
    {
        log_error(error_code);
    }
}

void MainWindow::rotate_clicked(void)
{
    transfer_t rotate;
    rotate.kx = ui->rotateXForm->value();
    rotate.ky = ui->rotateYForm->value();
    rotate.kz = ui->rotateZForm->value();

    request_t request;
    request.task = FIND_CENTER;
    point_t center;
    request.center.point = center;
    int error_code = event_handler(request);
    if (error_code != OK)
    {
        log_error(error_code);
        return;
    }
    center = request.center.point;
    request.task = ROTATE;
    fill_rotate_request(request.rotate, rotate, center);
    
    error_code = event_handler(request);
    if (error_code == OK)
    {
        error_code = draw_obj();
    }

    if (error_code)
    {
        log_error(error_code);
    }
}

void MainWindow::reset(void)
{
    request_t request;
    request.task = RESET;
    
    int error_code = event_handler(request);
    if (error_code == OK)
    {
        error_code = draw_obj();
    }
    if (error_code != OK)
    {
        log_error(error_code);
    }
}

void MainWindow::exit(void)
{
    request_t request;
    request.task = EXIT;
    event_handler(request);

    QApplication::quit();
}