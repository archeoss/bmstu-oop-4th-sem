#ifndef BMSTU_OOP_4TH_SEM_DOORS_H
#define BMSTU_OOP_4TH_SEM_DOORS_H

#include <QObject>

#include "constants.h"

class Doors : public QObject 
{
    Q_OBJECT
    enum doors_state 
    {
        OPENED,
        CLOSED,
        OPENNING,
        CLOSING
    };

public:
    explicit Doors(QObject *parent = nullptr);

signals:
    void closed_doors();
    void opened_doors();
    void opening_doors();
    
public slots:
    void start_openning();
    void start_closing();
    void open();
    void close();

private:
    doors_state current_state;
    QTimer doors_open_timer;
    QTimer doors_close_timer;
    QTimer doors_stay_open_timer;
};

#endif