#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>


widget::widget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbMilk->setEnabled(false);
    ui->pbIcetea->setEnabled(false);
}

widget::~widget()
{
    delete ui;
}
void widget::changeMoney(int n){

    money += n;
    ui->lcdNumber->display(QString::number(money));
    if(money<100){
        ui->pbCoffee->setEnabled(false);
        ui->pbMilk->setEnabled(false);
        ui->pbIcetea->setEnabled(false);
    }
    else if (money>=100&&money<200) {
        ui->pbCoffee->setEnabled(true);
        ui->pbMilk->setEnabled(false);
        ui->pbIcetea->setEnabled(false);
    }
    else if (money>=200&&money<300) {
        ui->pbCoffee->setEnabled(true);
        ui->pbMilk->setEnabled(true);
        ui->pbIcetea->setEnabled(false);
    }
    else{
        ui->pbCoffee->setEnabled(true);
        ui->pbMilk->setEnabled(true);
        ui->pbIcetea->setEnabled(true);
    }
    //if (money<100)
    //ui->pbCoffee->setEnabled(false);

}

void widget::on_pb10_clicked()
{
    changeMoney(10);

}

void widget::on_pb50_clicked()
{
    changeMoney(50);
}

void widget::on_pb100_clicked()
{
    changeMoney(100);
}



void widget::on_pb500_clicked()
{
   changeMoney(500);

}

void widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void widget::on_pbIcetea_clicked()
{
    changeMoney(-300);
}

void widget::on_pbChange_clicked()
{
    int change_500=0;
    int change_100=0;
    int change_50 =0;
    int change_10=0;
    int temp=0;

    change_500 = money/500;
    temp = money%500;
    change_100 = temp/100;
    temp = temp%100;
    change_50 = temp/50;
    temp = temp%50;
    change_10 = temp/10;

    QMessageBox msg;
    if(money){
        msg.information(nullptr,"change","500원 "+QString::number(change_500) + "개 100원" + QString::number(change_100) + "개 50원" + QString::number(change_50)  + "개 10원" + QString::number(change_10) + "개 남았습니다.");
        changeMoney(-money);
    }

    else {
        msg.information(nullptr,"change","거스름돈이 없습니다!");
    }

}
