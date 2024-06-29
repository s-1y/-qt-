#ifndef GAMETIMER_H
#define GAMETIMER_H
#include <QWidget>
#include <QTimer>
#include <mylabel.h>

class gametimer : public QWidget
{
    Q_OBJECT
public:
    explicit gametimer(QWidget *parent = nullptr);
private:
    int rate=100;
    int meteorite_num=3;
    void callmeteorite();
signals:


};

#endif // GAMETIMER_H
