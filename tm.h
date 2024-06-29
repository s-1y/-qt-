#ifndef TM_H
#define TM_H
#include <QWidget>
#include <QTimer>
#define TIMEOUT 25

class Tm : public QTimer
{
    Q_OBJECT
public:
    explicit Tm(QWidget *parent = nullptr);
    QTimer* dcount;
    QTimer* movetimer_left;
    QTimer* movetimer_right;
    QTimer* maintimer;
    QTimer* meteorite_summon;
    QTimer* fall;
    QTimer* beforeend;

signals:
};

#endif // TM_H
