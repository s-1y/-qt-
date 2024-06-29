#ifndef GAMEPAGE_H
#define GAMEPAGE_H
#include <QtMath>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QKeyEvent>
#include <qstring>
#include <QPaintEvent>
#include <QPainter>
#include <QProgressBar>
#include <QPixmap>
#include <ds.h>
#include <tm.h>
#include <dialog.h>
#include <lv.h>
#include <cl.h>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui {
class GamePage;
}
QT_END_NAMESPACE

class GamePage : public QWidget
{
    Q_OBJECT

public:
    GamePage(QWidget *parent = nullptr);
    ~GamePage();

private slots:
    void longPress_left();
    void longPress_right();
    void on_startGamebt_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_startGamebt_2_clicked();
    void on_startGamebt_3_clicked();

    void on_pushButton_3_clicked();

protected:
    void updateTimerStatus_r(bool startTimer);
    void updateTimerStatus_l(bool startTimer);
    void keyReleaseEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void maintimer_react();
    void meteorite_summon_react();
    void stopcounting();
    void fall_react();
    void newstart();
    bool checkcollide(int,int);
    bool checkcollide2(int,int);
    void switchdino_react();
    void gameover();
    void restart();
    void updatelvlnum(int lvnum);

private:
    Ui::GamePage *ui;
    bool deblooding=0;
    bool counting=0;
    bool win=0;
    int lvlnum=1;
    int backcountnum=90;
    int dinocount=3;
    int blood=100;
    int location[2];
    int boom[20][2][3]={{{0}}};
    QLabel *wintitle;
    QLabel *losetitle;
    QLabel *backcount;
    QLabel *stop_button;
    QPushButton *restart_button;
    QProgressBar *blood_bar;
    Tm tm;
    Ds ds;
    Lv* level;
    Cl* cl = new Cl(this);

};
#endif // GAMEPAGE_H
