#ifndef DS_H
#define DS_H
#include <QLabel>
#include <QWidget>

class Ds : public QLabel
{
    Q_OBJECT
public:
    explicit Ds(QWidget *parent = nullptr);
    Ds();
    void red();
    void purple();
    QPixmap dino;
    QPixmap dino2;
    QPixmap dino3;
    QPixmap dino4;
    QLabel *dinosaur;
    int dinoscale[2]={0};
    int edgepoint[8][2]={{0}};
    int damage=2;
    int step=15;
    ~Ds();
signals:
};

#endif // DS_H
