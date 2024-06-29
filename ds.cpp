#include "ds.h"


Ds::Ds(QWidget *parent)
    : QLabel{parent} {
    dino.load(":/new/prefix1/bwl.png");
    dino2.load(":/new/prefix1/bwl2.png");
    dino3.load(":/new/prefix1/bwl3.png");
    dino4.load(":/new/prefix1/bwl4.png");
    dinosaur=new QLabel(parent);
    dinosaur->setPixmap(dino);
    dinoscale[0]=100;
    dinoscale[1]=108;
    edgepoint[0][0]=10;
    edgepoint[0][1]=15;
    edgepoint[1][0]=18;
    edgepoint[1][1]=80;
    edgepoint[2][0]=40;
    edgepoint[2][1]=10;
    edgepoint[3][0]=90;
    edgepoint[3][1]=40;
    edgepoint[4][0]=70;
    edgepoint[4][1]=100;
    edgepoint[5][0]=65;
    edgepoint[5][1]=50;
    edgepoint[6][0]=50;
    edgepoint[6][1]=40;
    edgepoint[7][0]=60;
    edgepoint[7][1]=70;

}


void Ds::red(){
    dino.load(":/new/prefix1/bwl.png");
    dino2.load(":/new/prefix1/bwl2.png");
    dino3.load(":/new/prefix1/bwl3.png");
    dino4.load(":/new/prefix1/bwl4.png");
    dinosaur->setPixmap(dino);
    dinoscale[0]=100;
    dinoscale[1]=108;
    edgepoint[0][0]=10;
    edgepoint[0][1]=15;
    edgepoint[1][0]=15;
    edgepoint[1][1]=100;
    edgepoint[2][0]=40;
    edgepoint[2][1]=10;
    edgepoint[3][0]=90;
    edgepoint[3][1]=40;
    edgepoint[4][0]=70;
    edgepoint[4][1]=100;
    edgepoint[5][0]=65;
    edgepoint[5][1]=50;
    edgepoint[6][0]=50;
    edgepoint[6][1]=40;
    edgepoint[7][0]=60;
    edgepoint[7][1]=70;
    damage=2;
    step=25;
}
void Ds::purple(){
    dino.load(":/new/prefix1/sjl.png");
    dino2.load(":/new/prefix1/sjl2.png");
    dino3.load(":/new/prefix1/sjl3.png");
    dino4.load(":/new/prefix1/sjl4.png");
    dinosaur->setPixmap(dino);
    dinoscale[0]=150;
    dinoscale[1]=72;
    edgepoint[0][0]=10;
    edgepoint[0][1]=36;
    edgepoint[1][0]=40;
    edgepoint[1][1]=10;
    edgepoint[2][0]=75;
    edgepoint[2][1]=15;
    edgepoint[3][0]=110;
    edgepoint[3][1]=30;
    edgepoint[4][0]=125;
    edgepoint[4][1]=40;
    edgepoint[5][0]=75;
    edgepoint[5][1]=72;
    edgepoint[6][0]=70;
    edgepoint[6][1]=70;
    edgepoint[7][0]=75;
    edgepoint[7][1]=40;
    damage=1;
    step=25;
}
Ds::~Ds(){
    delete dinosaur;
}

