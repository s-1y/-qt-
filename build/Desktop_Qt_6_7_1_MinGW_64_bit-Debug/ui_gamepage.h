/********************************************************************************
** Form generated from reading UI file 'gamepage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPAGE_H
#define UI_GAMEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GamePage
{
public:
    QPushButton *startGamebt;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QPushButton *startGamebt_2;
    QPushButton *startGamebt_3;
    QPushButton *pushButton_3;

    void setupUi(QWidget *GamePage)
    {
        if (GamePage->objectName().isEmpty())
            GamePage->setObjectName("GamePage");
        GamePage->resize(1000, 600);
        GamePage->setMinimumSize(QSize(1000, 600));
        GamePage->setMaximumSize(QSize(1000, 600));
        startGamebt = new QPushButton(GamePage);
        startGamebt->setObjectName("startGamebt");
        startGamebt->setGeometry(QRect(440, 470, 121, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setBold(true);
        startGamebt->setFont(font);
        startGamebt->setStyleSheet(QString::fromUtf8("    font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    font-size: 16px;\n"
"    color: black;\n"
"    font-weight: bold;\n"
"    text-align: left center;\n"
"    padding-left: 25px;\n"
"    padding-top: 0px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    border-color: #900000;\n"
"    border-radius: 20px;\n"
"    background-color: rgba(0,0,0,0);\n"
""));
        pushButton = new QPushButton(GamePage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(280, 240, 161, 121));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255,255,255,0.5);\n"
" color: white; \n"
"border: 3px solid #bb0003;\n"
" border-radius: 10px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/bwl.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/new/prefix1/bwl2.png"), QSize(), QIcon::Active, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(100, 108));
        pushButton_2 = new QPushButton(GamePage);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(560, 240, 161, 121));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgba(0255,255,0255,0.5); color: white; border: 3px solid purple;\n"
"border-radius: 10px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/sjl.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/sjl2.png"), QSize(), QIcon::Active, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/new/prefix1/sjl2.png"), QSize(), QIcon::Active, QIcon::On);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(150, 72));
        label = new QLabel(GamePage);
        label->setObjectName("label");
        label->setGeometry(QRect(440, 130, 121, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        label->setFont(font1);
        startGamebt_2 = new QPushButton(GamePage);
        startGamebt_2->setObjectName("startGamebt_2");
        startGamebt_2->setGeometry(QRect(290, 470, 121, 41));
        startGamebt_2->setFont(font);
        startGamebt_2->setStyleSheet(QString::fromUtf8("    font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    font-size: 16px;\n"
"    color: black;\n"
"    font-weight: bold;\n"
"    text-align: left center;\n"
"    padding-left: 25px;\n"
"    padding-top: 0px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    border-color: #900000;\n"
"    border-radius: 20px;\n"
"    background-color: rgba(0,0,0,0);\n"
""));
        startGamebt_3 = new QPushButton(GamePage);
        startGamebt_3->setObjectName("startGamebt_3");
        startGamebt_3->setGeometry(QRect(590, 470, 121, 41));
        startGamebt_3->setStyleSheet(QString::fromUtf8("    font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    font-size: 16px;\n"
"    color: black;\n"
"    font-weight: bold;\n"
"    text-align: left center;\n"
"    padding-left: 25px;\n"
"    padding-top: 0px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    border-color: #900000;\n"
"    border-radius: 20px;\n"
"    background-color: rgba(0,0,0,0);\n"
""));
        pushButton_3 = new QPushButton(GamePage);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 90, 101, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgba(0255,255,0255,0.5); color: white; border: 3px solid black;\n"
"border-radius: 10px;\n"
"font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    font-size: 16px;\n"
"    color: black;\n"
"    font-weight: bold;"));
        pushButton_3->setIconSize(QSize(150, 72));

        retranslateUi(GamePage);

        QMetaObject::connectSlotsByName(GamePage);
    } // setupUi

    void retranslateUi(QWidget *GamePage)
    {
        GamePage->setWindowTitle(QCoreApplication::translate("GamePage", "GamePage", nullptr));
        startGamebt->setText(QCoreApplication::translate("GamePage", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        label->setText(QCoreApplication::translate("GamePage", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700; color:#000000;\">\351\200\211\346\213\251\344\275\240\347\232\204\350\247\222\350\211\262</span></p></body></html>", nullptr));
        startGamebt_2->setText(QCoreApplication::translate("GamePage", "\346\270\270\346\210\217\350\257\264\346\230\216", nullptr));
        startGamebt_3->setText(QCoreApplication::translate("GamePage", "\345\205\263\345\215\241\351\200\211\346\213\251", nullptr));
        pushButton_3->setText(QCoreApplication::translate("GamePage", "\350\277\224\345\233\236\344\270\273\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GamePage: public Ui_GamePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAGE_H
