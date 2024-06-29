#include "gamepage.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GamePage w;
    w.show();
    return a.exec();
}
