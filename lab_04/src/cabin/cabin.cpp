#include "cabin.h"

#include <QString>

#include "qdebug.h"

Cabin::Cabin(QObject *parent) : QObject(parent),
                                current_floor(1),
                                target(-1),
                                new_target(false),
                                cabin_readiness(true),
                                current_state(STOP),
                                current_direction(STAY)
{
    crossing_floor_timer.setSingleShot(true);

    QObject::connect(this, SIGNAL(cabin_called()), &doors, SLOT(start_closing()));
    QObject::connect(this, SIGNAL(cabin_called()), this, SLOT(cabin_move()));
    QObject::connect(this, SIGNAL(cabin_reached_target(int)), this, SLOT(cabin_stopping()));
    QObject::connect(this, SIGNAL(cabin_stopped(int)), &doors, SLOT(start_openning()));
    QObject::connect(&doors, SIGNAL(closed_doors()), this, SLOT(cabin_ready()));
    QObject::connect(&doors, SIGNAL(opening_doors()), this, SLOT(cabin_notready()));
    QObject::connect(&crossing_floor_timer, SIGNAL(timeout()), this, SLOT(cabin_move()));
}

void Cabin::cabin_move() 
{
    qDebug() << target;
    if (new_target && current_state == WAIT && cabin_readiness == true) 
    {
        current_state = MOVE;
        if (current_floor == target) 
        {
            emit cabin_reached_target(current_floor);
        } 
        else 
        {
            crossing_floor_timer.start(CROSSING_FLOOR);
        }
    } 
    else if (current_state == MOVE) 
    {
        current_state = MOVE;

        current_floor += current_direction;

        if (current_floor == target) 
        {
            emit cabin_reached_target(current_floor);
        } 
        else 
        {
            emit cabin_crossing_floor(current_floor, current_direction);
            crossing_floor_timer.start(CROSSING_FLOOR);
        }
    }
}

void Cabin::cabin_stopping() 
{
    if (current_state == MOVE) 
    {
        current_state = STOP;
        qDebug() << "Stopped at floor " << QString::number(current_floor) << ".";
        emit cabin_stopped(current_floor);
    }
}

void Cabin::cabin_call(int floor, direction dir) 
{
    if (current_state == STOP) 
    {
        new_target = true;
        current_state = WAIT;
        target = floor;

        current_direction = dir;
        emit cabin_called();
    }
    if (current_state == MOVE || current_state == WAIT)
    {
        
        if ((dir == UP && current_floor + 1 < floor && floor < target) || (dir == DOWN && current_floor - 1 > floor && floor > target)) 
        {
            
            target = floor;

            emit cabin_called();
        }
    }
}

void Cabin::cabin_notready()
{
    cabin_readiness = false;
}

void Cabin::cabin_ready()
{
    cabin_readiness = true;
    emit cabin_called();
}