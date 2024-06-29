#include "tm.h"

Tm::Tm(QWidget *parent)
    : QTimer{parent}{
    dcount = new QTimer(parent);
    movetimer_left = new QTimer(parent);
    movetimer_right = new QTimer(parent);
    maintimer = new QTimer(parent);
    meteorite_summon = new QTimer(parent);
    fall = new QTimer(parent);
    beforeend= new QTimer(parent);
    dcount->setInterval(100);
    movetimer_left->setInterval(TIMEOUT);
    movetimer_right->setInterval(TIMEOUT);
    maintimer->setInterval(1000);
    beforeend->setInterval(2000);
}
