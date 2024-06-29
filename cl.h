#ifndef CL_H
#define CL_H

#include <QDialog>

namespace Ui {
class Cl;
}

class Cl : public QDialog
{
    Q_OBJECT

public:
    explicit Cl(QWidget *parent = nullptr);
    ~Cl();

private slots:
    void on_pushButto_clicked();
    void on_pushButto_2_clicked();
    void on_pushButto_3_clicked();
    void on_pushButto_4_clicked();
signals:
    void levelsignal(int lvsignal);
private:
    Ui::Cl *ui;
};

#endif // CL_H
