#ifndef LV_H
#define LV_H
#define maxstonesperline 3
#include <QtMath>
#include <QPixMap>

class Lv{
public:
    Lv();
    QPixmap bac;
    int dtime=1;
    int hard=1;
    int stonelist[20][20][3]={{{0}}};
    virtual void meteorite_summon_react_lv() = 0;
    virtual void fall_react_lv()=0;
    virtual int summon_interval()=0;
    virtual ~Lv();
};

class Lv1:public Lv{
public:
    Lv1();
    void meteorite_summon_react_lv();
    void fall_react_lv();
    int summon_interval();
    ~Lv1();
};

class Lv2:public Lv{
public:
    Lv2();
    void meteorite_summon_react_lv();
    void fall_react_lv();
    int summon_interval();
    ~Lv2();
};

class Lv3:public Lv{
public:
    Lv3();
    void meteorite_summon_react_lv();
    void fall_react_lv();
    int summon_interval();
    ~Lv3();
};

class Lv4:public Lv{
public:
    Lv4();
    void meteorite_summon_react_lv();
    void fall_react_lv();
    int summon_interval();
    ~Lv4();
};

#endif // LV_H
