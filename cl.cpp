#include "cl.h"
#include "ui_cl.h"

Cl::Cl(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Cl)
{
    ui->setupUi(this);
}

Cl::~Cl()
{
    delete ui;
}

void Cl::on_pushButto_clicked()
{
    this->close();
    emit levelsignal(1);
}


void Cl::on_pushButto_2_clicked()
{
    this->close();
    emit levelsignal(2);
}


void Cl::on_pushButto_3_clicked()
{
    this->close();
    emit levelsignal(3);
}


void Cl::on_pushButto_4_clicked()
{
    this->close();
    emit levelsignal(4);
}

