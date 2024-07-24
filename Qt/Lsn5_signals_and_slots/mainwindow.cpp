#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDebug"
#include "QTimer"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sWatch = new stopwatch(this);

    //sWatch->setObjectName("sWatch");
    QObject::connect(sWatch, &stopwatch::sig_ClickStart,this, &MainWindow::pb_Start_clicked);
    QObject::connect(sWatch, &stopwatch::sig_ClickStop,this, &MainWindow::pb_Stop_clicked);
    QObject::connect(sWatch, &stopwatch::sig_ClickCircl,this, &MainWindow::Circl);
    QObject::connect(sWatch, &stopwatch::sig_ClickClear,this, &MainWindow::Clear);
    QObject::connect(sWatch, &stopwatch::sig_sendTIMER,this, &MainWindow::lb_txt);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sWatch;
}

void MainWindow::pb_Start_clicked()
{
    ui->pb_start->setText("Стоп");
    ui->pb_circle->setEnabled(true);
}
void MainWindow::pb_Stop_clicked()
{
    ui->pb_start->setText("Старт");
     ui->pb_circle->setEnabled(false);
}
void MainWindow::lb_txt(double t){
    ui->label_time->setText(QString::number(t));
}
void MainWindow::Circl(QString str){

    ui->tBrow_menu->append(str);

}
void MainWindow::Clear(){

}

void MainWindow::on_pb_start_clicked()
{
    if(ui->pb_start->text()=="Старт"){
        sWatch->ClickStart();
    }else if(ui->pb_start->text()=="Стоп"){
        sWatch->ClickStop();
    }

}

void MainWindow::on_pb_clear_clicked()
{
    sWatch->ClickClear();
}

void MainWindow::on_pb_circle_clicked()
{
    sWatch->ClickCircl();
}

