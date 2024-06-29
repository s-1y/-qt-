#include "gametimer.h"
#include "QWidget"
#include "QTimer"




gametimer::gametimer(QWidget *parent): QWidget{parent}{
    callmeteorite();
}
void gametimer::callmeteorite(){
    int tmp=rand()%100+1;
    if(tmp>rate) return;
    int stones[4]={0};
    for(int i=0;i<meteorite_num;i++){
        stones[i]=rand()%950;
    }
    for(int i=0;i<4;i++){
        if(!stones[i])continue;
        MovingObject *mete_label=new MovingObject(0,stones[i]);
    }
}
