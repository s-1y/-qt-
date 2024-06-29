#include "gamepage.h"
#include "ui_gamepage.h"
int distancedm(int x1,int y1,int x2,int y2){
    int a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return a;
}
GamePage::GamePage(QWidget *parent)
    : QWidget(parent), ui(new Ui::GamePage),tm(this),ds(this){
    ui->setupUi(this);
    ui->pushButton_3->hide();
    blood=100;
    level = new Lv1;
    wintitle = new QLabel(this);
    wintitle->setGeometry(420,150,200,100);
    wintitle->setText("你赢了");
    wintitle->hide();
    wintitle->setStyleSheet("font-size: 40pt; font-family: 微软雅黑; color: green;");
    losetitle = new QLabel(this);
    losetitle->setGeometry(420,150,200,100);
    losetitle->setText("你输了");
    losetitle->hide();
    losetitle->setStyleSheet("font-size: 40pt; font-family: 微软雅黑; color: red;");
    blood_bar=new QProgressBar(this);
    blood_bar->setGeometry(430,25,200,30);
    blood_bar->setRange(0,100);
    blood_bar->setValue(100);
    blood_bar->hide();
    blood_bar->setStyleSheet(
        "QProgressBar { ""border: 1px solid grey; "
        "border-radius: 5px; background: lightgrey; }"
        "QProgressBar::chunk { background: #ff0000; margin: 1px; }"
        "QProgressBar { height: 20px; }"
        "QProgressBar { text-align: center; }");
    ds.dinosaur->setGeometry(180,460,ds.dinoscale[0],ds.dinoscale[1]);
    location[0]=ds.dinosaur->pos().x();
    location[1]=ds.dinosaur->pos().y();
    ds.dinosaur->show();
    stop_button = new QLabel("按“空格”停止",this);
    stop_button->setGeometry(20,20,97,40);
    stop_button->hide();
    stop_button->setStyleSheet(
        "QLabel { background-color: rgba(255,255,255,0.5); "
        "border: 2px solid darkblue; "
        "border-radius: 5px; "
        "color: black; "
        "font-size: 15px; }"
        "QLabel { text-align: center; }");
    backcount = new QLabel("90",this);
    backcount->setGeometry(900,20,60,40);
    backcount->hide();
    backcount->setStyleSheet(
        "QLabel { background-color: rgba(255,255,255,0.5); "
        "border: 2px solid darkblue; "
        "border-radius: 5px; "
        "alignment: Center;"
        "color: black; "
        "font-size: 22px; }"
        "QLabel { text-align: center; }");
    connect(tm.movetimer_left, &QTimer::timeout, this, &GamePage::longPress_left);
    connect(tm.movetimer_right, &QTimer::timeout, this, &GamePage::longPress_right);
    connect(tm.maintimer,&QTimer::timeout,this,&GamePage::maintimer_react);
    connect(tm.meteorite_summon,&QTimer::timeout,this,&GamePage::meteorite_summon_react);
    connect(tm.fall,&QTimer::timeout,this,&GamePage::fall_react);
    connect(cl,&Cl::levelsignal,this,&GamePage::updatelvlnum);
    connect(tm.dcount,&QTimer::timeout,this,[&](){
        if(dinocount==3) {
            ds.dinosaur->setPixmap(ds.dino2);
            dinocount--;
        }
        else if(dinocount==2) {
            ds.dinosaur->setPixmap(ds.dino3);
            dinocount--;
        }
        else if(dinocount==1){
            ds.dinosaur->setPixmap(ds.dino);
            dinocount--;
        }
        else {
            tm.dcount->stop();
            dinocount=3;
        }
        deblooding=false;
    });
}
void GamePage::updatelvlnum(int lvnum){
    lvlnum=lvnum;
    if(lvlnum==1) level=new Lv1;
    if(lvlnum==2) level=new Lv2;
    if(lvlnum==3) level=new Lv3;
    if(lvlnum==4) {
        level=new Lv4;
        backcount->setText("1");
    }
    if(ds.damage==1){
        ds.dinosaur->setGeometry(180,490,ds.dinoscale[0],ds.dinoscale[1]);
        ds.dinosaur->setPixmap(ds.dino);
    }
    else{
        ds.dinosaur->setGeometry(180,460,ds.dinoscale[0],ds.dinoscale[1]);
        ds.dinosaur->setPixmap(ds.dino);
    }
}
bool GamePage::checkcollide(int x,int y){
    int d[8]={0};
    for(int i=0;i<8;i++){
        d[i]=distancedm(50*x+30,
                           level->stonelist[x][y][0]+55,
                           location[0]+ds.edgepoint[i][0],
                           location[1]+ds.edgepoint[i][1]);
    }
    for(int i=0;i<8;i++){
        if(d[i]<=20){
            boom[x][0][0]=level->stonelist[x][y][0];
            level->stonelist[x][y][0]=0;
            boom[x][1][0]=5;
            return true;
        }
    }
    return false;
}
bool GamePage::checkcollide2(int x,int y){
    int d[8]={0};
    for(int i=0;i<8;i++){
        d[i]=distancedm(50*x+30,
                          level->stonelist[x][y][1]+55,
                          location[0]+ds.edgepoint[i][0],
                          location[1]+ds.edgepoint[i][1]);
    }
    for(int i=0;i<8;i++){
        if(d[i]<=20){
            boom[x][0][1]=level->stonelist[x][y][1];
            level->stonelist[x][y][1]=0;
            boom[x][1][1]=5;
            return true;
        }
    }
    return false;
}
void GamePage::newstart(){
    for(int i=0;i<20;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<3;k++){
                level->stonelist[i][j][k]=0;
            }
        }
    }
    for(int i=0;i<20;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                boom[i][j][k]=0;
            }
        }
    }
    level->hard=1;
    backcountnum=90;
    backcount->setText("90");
    dinocount=3;
    blood=100;
    win=0;
    deblooding=0;
    counting=0;
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->label->show();
    ui->startGamebt->show();
    ui->startGamebt_2->show();
    ui->startGamebt_3->show();
    if(ds.damage==1){
        ds.dinosaur->setGeometry(180,490,ds.dinoscale[0],ds.dinoscale[1]);
    }
    else{
        ds.dinosaur->setGeometry(180,460,ds.dinoscale[0],ds.dinoscale[1]);
    }
    update();
    blood_bar->setValue(blood);
}
void GamePage::maintimer_react(){
    backcountnum-=level->dtime;
    if(!level->dtime) {
        level->hard++;
        if(level->hard%10==0){
            tm.meteorite_summon->stop();
            tm.meteorite_summon->setInterval(level->summon_interval());
            tm.meteorite_summon->start();
        }
    }
    if(backcountnum%10==0&&level->dtime) {
        level->hard++;
        tm.meteorite_summon->stop();
        tm.meteorite_summon->setInterval(level->summon_interval());
        tm.meteorite_summon->start();
    }
    if(!backcountnum){
        win=true;
        tm.maintimer->stop();
        tm.meteorite_summon->stop();
        tm.beforeend->singleShot(2000,this,&GamePage::gameover);
    }
    if(lvlnum!=4){
        QString s=QString::number(backcountnum);
        backcount->setText(s);
    }
    else{
        QString s=QString::number(level->hard);
        backcount->setText(s);
    }

}
void GamePage::meteorite_summon_react(){
    level->meteorite_summon_react_lv();
}
void GamePage::fall_react(){
    if(blood==0){
        tm.maintimer->stop();
        tm.meteorite_summon->stop();
        tm.beforeend->singleShot(2200,this,&GamePage::gameover);
        ds.dinosaur->setPixmap(ds.dino4);
    }
    for(int i=0;i<20;i++){
        if(boom[i][1][0]>1){
            boom[i][1][0]--;
        }
        if(boom[i][1][0]==1){
            boom[i][0][0]=0;
            boom[i][1][0]--;
        }
    }
    for(int i=0;i<20;i++){
        if(boom[i][1][1]>1){
            boom[i][1][1]--;
        }
        if(boom[i][1][1]==1){
            boom[i][0][1]=0;
            boom[i][1][1]--;
        }
    }

    location[0]=ds.dinosaur->pos().x();
    location[1]=ds.dinosaur->pos().y();
    level->fall_react_lv();
    for(int i=0;i<20;i++){
        for(int j=0;j<maxstonesperline;j++){
            if(level->stonelist[i][j][0]){
                bool check=checkcollide(i,j);
                if(check){
                    blood-=5*ds.damage;
                    if(blood<0){
                        blood=0;
                    }
                    if(deblooding==false){
                        switchdino_react();
                    }
                }
            }
            if(level->stonelist[i][j][1]){
                bool check=checkcollide2(i,j);
                if(check){
                    blood+=20*ds.damage;
                    if(blood>=100) {
                        blood=100;
                    }
                }
            }
        }
    }
    blood_bar->setValue(blood);
    update();
}
void GamePage::gameover(){
    counting=0;
    if(win){
        wintitle->show();
    }
    else{
        losetitle->show();
    }
    tm.fall->stop();
    ui->startGamebt->show();
    ui->label->show();
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->startGamebt_3->show();
}
void GamePage::switchdino_react(){
    deblooding=true;
    tm.dcount->start();
}
void GamePage::stopcounting(){
    if(counting==0){
        counting=1;
        stop_button->setText("按“空格”停止");
        tm.maintimer->start();
        tm.meteorite_summon->setInterval(level->summon_interval());
        tm.meteorite_summon->start();
        tm.fall->start(40);
        ui->pushButton_3->hide();
    }
    else{
        counting=0;
        stop_button->setText("按“空格”继续");
        tm.maintimer->stop();
        tm.meteorite_summon->stop();
        tm.fall->stop();
        ui->pushButton_3->show();
    }
}
void GamePage::on_startGamebt_clicked()
{
    level->hard=1;
    win=0;
    blood=100;
    backcountnum=90;
    blood_bar->setValue(blood);
    wintitle->hide();
    losetitle->hide();
    ui->pushButton->hide();
    ui->label->hide();
    ui->pushButton_2->hide();
    ui->startGamebt->hide();
    ui->startGamebt_2->hide();
    ui->startGamebt_3->hide();
    this->setFocus();
    stop_button->show();
    backcount->show();
    blood_bar->show();
    stopcounting();
}
void GamePage::paintEvent(QPaintEvent* event){
    QPainter painter(this);
    QPixmap sto(":/new/prefix1/R1.png");
    QPixmap hea(":/new/prefix1/R2.png");
    QPixmap boo(":/new/prefix1/bz.png");
    QPixmap gai(":/new/prefix1/tx.png");
    painter.drawPixmap(0,0,1000,600,level->bac);
    for(int i=0;i<20;i++){
        for(int j=0;j<maxstonesperline;j++){
            if(level->stonelist[i][j][0]){
                painter.drawPixmap(50*i,level->stonelist[i][j][0],60,80,sto);
            }
        }
    }
    for(int i=0;i<20;i++){
        for(int j=0;j<maxstonesperline;j++){
            if(level->stonelist[i][j][1]){
                painter.drawPixmap(50*i,level->stonelist[i][j][1],60,80,hea);
            }
        }
    }
    for(int i=0;i<20;i++){
        if(boom[i][1][0]){
            painter.drawPixmap(50*i-10,boom[i][0][0],80,80,boo);
        }
    }
    for(int i=0;i<20;i++){
        if(boom[i][1][1]){
            painter.drawPixmap(50*i-10,boom[i][0][1],80,80,gai);
        }
    }
    QWidget::paintEvent (event);
}
void GamePage::keyPressEvent(QKeyEvent *event){
    bool l=0,r=0;
    if(event->key() == Qt::Key_Right)
        r=1;
    if (event->key() == Qt::Key_Left)
        l=1;
    if(counting==0||(l==1&&r==1)){
        updateTimerStatus_l(0);
        updateTimerStatus_r(0);
    }
    else if(l==1)
        updateTimerStatus_l(1);
    else if(r==1)
        updateTimerStatus_r(1);
    QWidget::keyPressEvent(event);
    switch(event->key()){
    case Qt::Key_Space:
        stopcounting();
        break;
    }
}
void GamePage::longPress_left(){
    int x=ds.dinosaur->geometry().x();
    int y=ds.dinosaur->geometry().y();
    if(x>0)ds.dinosaur->move(x-ds.step,y);
    location[0]=ds.dinosaur->pos().x();
    location[1]=ds.dinosaur->pos().y();
}
void GamePage::longPress_right(){
    int x=ds.dinosaur->geometry().x();
    int y=ds.dinosaur->geometry().y();
    if(x<900)ds.dinosaur->move(x+ds.step,y);
    location[0]=ds.dinosaur->pos().x();
    location[1]=ds.dinosaur->pos().y();
}
void GamePage::updateTimerStatus_r(bool startTimer)
{
    if (startTimer)tm.movetimer_right->start();
    else tm.movetimer_right->stop();
}
void GamePage::updateTimerStatus_l(bool startTimer)
{
    if (startTimer)tm.movetimer_left->start();
    else tm.movetimer_left->stop();
}
void GamePage::keyReleaseEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Right)
        updateTimerStatus_r(0);
    if (event->key() == Qt::Key_Left)
        updateTimerStatus_l(0);
    QWidget::keyReleaseEvent(event);
}
GamePage::~GamePage(){
    delete ui;
}
void GamePage::on_pushButton_clicked()
{
    ds.red();
    ds.dinosaur->setGeometry(180,460,ds.dinoscale[0],ds.dinoscale[1]);
    ds.dinosaur->show();
}
void GamePage::on_pushButton_2_clicked()
{
    ds.purple();
    ds.dinosaur->setGeometry(180,490,ds.dinoscale[0],ds.dinoscale[1]);
    ds.dinosaur->show();
}
void GamePage::on_startGamebt_2_clicked()
{
    Dialog* dia= new Dialog(this);
    dia->show();
}
void GamePage::on_startGamebt_3_clicked()
{
    cl->show();
}
void GamePage::on_pushButton_3_clicked()
{
    newstart();
    ui->pushButton_3->hide();

}

