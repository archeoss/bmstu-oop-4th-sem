#ifndef BMSTU_OOP_4TH_SEM_LIFT_H
#define BMSTU_OOP_4TH_SEM_LIFT_H

#include <QObject>
#include <QTextEdit>

#include "cabin.h"
#include "controlpanel.h"
#include "constants.h"

class Lift : public QObject 
{
    Q_OBJECT

public:
    Lift();
    void click(int floor);

private:
    ControlPanel control_panel;
    Cabin cabin;
};

#endif
