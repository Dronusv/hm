#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->rBut1->setText("Mode1");
    ui->rBut2->setText("Mode2");

    for(int i=1;i<=10;++i){
        ui->cBox_listcolor->addItem(QString("Цвет %1").arg(i));
    }

    ui->pBut_count->setText("+10");
    ui->pBut_count->setCheckable(true);

    ui->pBar->setValue(0);
    ui->pBar->setMinimum(0);
    ui->pBar->setMaximum(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pBut_count_clicked()
{
    if(ui->pBar->value()==10){
        ui->pBar->setValue(0);
    }else{
        ui->pBar->setValue(ui->pBar->value()+1);
    }

}


void MainWindow::on_rBut2_clicked()
{
    ui->pBar->setFormat("%p%");
}


void MainWindow::on_rBut1_clicked()
{
     ui->pBar->setFormat("%v steps");
}


void MainWindow::on_cBox_listcolor_activated(int index)
{
    switch(index){
        case 0:
        ui->pBar->setStyleSheet("QProgressBar::chunk {background-color: red;}");
            break;
        case 1:
            ui->pBar->setStyleSheet("QProgressBar::chunk {background-color: green;}");
            break;
        case 2:
            ui->pBar->setStyleSheet("QProgressBar::chunk {background-color: black;}");
            break;
        case 3:
            ui->pBar->setStyleSheet("QProgressBar::chunk {background-color: white;}");
            break;
        case 4:
            ui->pBar->setStyleSheet("QProgressBar::chunk {background-color: purple;}");
            break;
        case 5:
            ui->pBar->setStyleSheet("QProgressBar::chunk {background-color: blue;}");
            break;
        case 6:
            ui->pBar->setStyleSheet("QProgressBar::chunk {background-color: orange;}");
            break;
        case 7:
            ui->pBar->setStyleSheet("QProgressBar::chunk {background-color: yellow;}");
            break;
        case 8:
            ui->pBar->setStyleSheet("QProgressBar::chunk {background-color: gray;}");
            break;
        case 9:
            ui->pBar->setStyleSheet("QProgressBar::chunk {background-color: pink;}");
            break;
    }
}

