#include "stopwatch.h"

stopwatch::stopwatch(QObject *parent)
    : QObject{parent}
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&stopwatch::TIMER));
}
stopwatch::~stopwatch()
{
    delete timer;
}
void stopwatch::ClickStart(){
    timer->start(100);
}
void stopwatch::ClickStop(){
    timer->stop();
}
void stopwatch::ClickCircl(){
    numb_circl++;
    emit sig_ClickCircl(QString("Круг "+ QString::number(numb_circl) + " время: " +QString::number(time_circl) + " сек"));
    time_circl=0;

}
void stopwatch::ClickClear(){
    numb_circl=0;
    time_circl=0;
    time_=0;
}

void stopwatch::TIMER(){
    time_+=0.1;
    time_circl+=0.1;
    qDebug()<<time_;
    SendTIMER();
}
void stopwatch::SendTIMER(){
    emit sig_sendTIMER(time_);
}
