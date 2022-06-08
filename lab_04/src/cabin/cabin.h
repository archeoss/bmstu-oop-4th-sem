#ifndef BMSTU_OOP_4TH_SEM_CABIN_H
#define BMSTU_OOP_4TH_SEM_CABIN_H

#include <QObject>

#include "constants.h"
#include "controlpanel.h"
#include "doors.h"

class Cabin : public QObject 
{
    Q_OBJECT
    enum cabin_state 
    {
        MOVE,
        WAIT,
        STOP
    };

    // Q_OBJECT
    // enum cabin_preparedness
    // {
    //     NOTREADY,
    //     READY
    // };

public:
    explicit Cabin(QObject *parent = nullptr);

signals:
    void cabin_called();
    void cabin_crossing_floor(int floor, direction d);
    void cabin_reached_target(int floor);
    void cabin_stopped(int floor);

public slots:
    void cabin_move();
    void cabin_stopping();
    void cabin_call(int floor, direction dir);
    void cabin_ready();
    void cabin_notready();
    

private:
    int current_floor;
    int target;
    bool new_target;
    bool is_closed;

    cabin_state current_state;
    bool cabin_readiness;
    direction current_direction;
    Doors doors;
    QTimer crossing_floor_timer;
};

#endif