#ifndef BMSTU_OOP_4TH_SEM_CONTROLPANEL_H
#define BMSTU_OOP_4TH_SEM_CONTROLPANEL_H

#include <QObject>
#include <QVector>

#include "constants.h"

class ControlPanel : public QObject 
{
    Q_OBJECT
    enum panel_state 
    {
        FREE,
        BUSY
    };

public:
    explicit ControlPanel(QObject *parent = nullptr);
    void set_new_target(int floor);

signals:
    void set_target(int floor, direction dir);

public slots:
    void achieved_floor(int floor);
    void passed_floor(int floor);

private:
    int cur_floor;
    int cur_target = -1;
    void find_target(int floor);
    QVector<bool> is_target;
    panel_state current_state;
    direction cur_direction;
    bool next_target(int &floor);
    void find_new_target();
};

#endif