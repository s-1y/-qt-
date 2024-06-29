#include "lv.h"

Lv::Lv() {}
Lv::~Lv(){};
Lv1::Lv1(){bac.load(":/new/prefix1/1.jpg");}
void Lv1::meteorite_summon_react_lv(){
    int stonenum=rand()%10;
    if(stonenum>=hard) stonenum=hard;
    if(hard-stonenum>2){
        stonenum=hard;
    }
    for(int i=0;i<stonenum;i++){
        int x=rand()%20;
        for(int j=0;j<maxstonesperline;j++){
            if(!stonelist[x][j][0]){
                stonelist[x][j][0]=1;
                break;
            }
        }
    }
}
void Lv1::fall_react_lv(){
    for(int i=0;i<20;i++){
        for(int j=0;j<maxstonesperline;j++){
            if(stonelist[i][j][0]) {
                stonelist[i][j][0]+=10+hard;
                if(stonelist[i][j][0]>600){
                    stonelist[i][j][0] = 0;
                }
            }
        }
    }
}
int Lv1::summon_interval(){
    return 2000-160*hard;
}
Lv1::~Lv1(){};

Lv2::Lv2(){bac.load(":/new/prefix1/2.jpg");}
void Lv2::meteorite_summon_react_lv(){
    int stonenum=1;
    if(hard>3&&hard<8) stonenum=2;
    if(hard>=8)stonenum=3;
    for(int i=0;i<stonenum;i++){
        int x=rand()%20;
        for(int j=0;j<5;j++){
            if(!stonelist[x][j][0]){
                stonelist[x][j][0]=1;
                break;
            }
        }
    }
}
void Lv2::fall_react_lv(){
    for(int i=0;i<20;i++){
        for(int j=0;j<5;j++){
            if(stonelist[i][j][0]) {
                stonelist[i][j][0]+=10+2*hard;
                if(stonelist[i][j][0]>600){
                    stonelist[i][j][0] = 0;
                }
            }
        }
    }
}
int Lv2::summon_interval(){
    if(hard>8)return 240;
    if(hard>4)return 270;
    return 300;
}
Lv2::~Lv2(){};

Lv3::Lv3(){bac.load(":/new/prefix1/3.jpg");}
void Lv3::meteorite_summon_react_lv(){
    int stonenum=6;
    if(hard>3) stonenum=10;
    if(hard>5) stonenum=12;
    if(hard>8) stonenum=14;
    for(int i=0;i<stonenum;i++){
        int x=rand()%20;
        if(x==16) x=17;
        for(int j=0;j<5;j++){
            if(!stonelist[x][j][0]){
                stonelist[x][j][0]=1;
                break;
            }
        }
    }
}
void Lv3::fall_react_lv(){
    for(int i=0;i<20;i++){
        for(int j=0;j<5;j++){
            if(stonelist[i][j][0]) {
                if(stonelist[i][j][0]<30){
                    stonelist[i][j][0]+=2;
                }
                else{
                    stonelist[i][j][0]+=50;
                }
                if(stonelist[i][j][0]>600){
                    stonelist[i][j][0] = 0;
                }
            }
        }
    }
}
int Lv3::summon_interval(){
    if(hard>5)return 800;
    if(hard>3)return 1200;
    return 1500;
}
Lv3::~Lv3(){};

Lv4::Lv4(){bac.load(":/new/prefix1/4.jpg");
    dtime=0;
}
void Lv4::meteorite_summon_react_lv(){
    if((hard/60)%2==0){
        if(hard>300){
            int stonenum=4+rand()%3+hard/200;
            for(int i=0;i<stonenum;i++){
                int x=rand()%20;
                for(int j=0;j<5;j++){
                    if(!stonelist[x][j][0]){
                        stonelist[x][j][0]=1;
                        break;
                    }
                }
            }
        }
        else{
            int stonenum=1;
            stonenum=hard/80+rand()%2+1;
            for(int i=0;i<stonenum;i++){
                int x=rand()%20;
                for(int j=0;j<5;j++){
                    if(!stonelist[x][j][0]){
                        stonelist[x][j][0]=1;
                        break;
                    }
                }
            }
        }
    }
    else {
        if(hard>300){
            int stonenum=2+rand()%2+hard/300;
            for(int i=0;i<stonenum;i++){
                int x=rand()%20;
                for(int j=0;j<5;j++){
                    if(!stonelist[x][j][0]){
                        stonelist[x][j][0]=1;
                        break;
                    }
                }
            }
        }
        else{
            int stonenum=hard/150+1;
            for(int i=0;i<stonenum;i++){
                int x=rand()%20;
                for(int j=0;j<5;j++){
                    if(!stonelist[x][j][0]){
                        stonelist[x][j][0]=1;
                        break;
                    }
                }
            }
        }
    }
    int ifheal=rand()%30;
    if(ifheal==1){
        int x=rand()%20;
        for(int j=0;j<5;j++){
            if(!stonelist[x][j][1]){
                stonelist[x][j][1]=1;
                break;
            }
        }
    }
}
void Lv4::fall_react_lv(){
    for(int i=0;i<20;i++){
        for(int j=0;j<5;j++){
            if(stonelist[i][j][0]) {
                stonelist[i][j][0]+=10+hard/100;
                if(stonelist[i][j][0]>600){
                    stonelist[i][j][0] = 0;
                }
            }
        }
    }
    for(int i=0;i<20;i++){
        for(int j=0;j<5;j++){
            if(stonelist[i][j][1]) {
                stonelist[i][j][1]+=10+hard/100;
                if(stonelist[i][j][1]>600){
                    stonelist[i][j][1] = 0;
                }
            }
        }
    }
}
int Lv4::summon_interval(){
    if((hard/60)%2==0){
        if(hard>300){
            return 660-0.1*hard;
        }
        return 1200-2*hard;
    }
    else {
        if(hard>300){
            return 265-0.05*hard;
        }
        return 550-hard;
    }
}
Lv4::~Lv4(){};

