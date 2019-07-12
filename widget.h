#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>

namespace Ui {
class widget;
}

class widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    ~widget();

    void changeMoney(int n);
    int money ={0};


private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb500_clicked();

    void on_pbCoffee_clicked();

    void on_pbMilk_clicked();

    void on_pbIcetea_clicked();

    void on_pbChange_clicked();

private:
    Ui::widget *ui;
};

#endif // WIDGET_H
