#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "requests.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    
private slots:

    int draw_obj(void);
    void load_clicked(void);
    void save_clicked(void);
    void move_clicked(void);
    void rotate_clicked(void);
    void scale_clicked(void);
    void center(void);
    void reset(void);
    void exit(void);

private:
    double get_value(QDoubleSpinBox *form);
    Ui::MainWindow *ui;
};

#endif 
