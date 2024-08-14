#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include "QTimer"
#include "QDebug"

class stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit stopwatch(QObject *parent = nullptr);
    ~stopwatch();
    void ClickStart(void);
    void ClickStop(void);
    void ClickCircl(void);
    void ClickClear(void);
    void SendTIMER(void);
private:
    double time_=0;
    double time_circl=0;
    int numb_circl=0;
    QTimer *timer;
signals:
    void sig_ClickCircl(QString str);
    void sig_sendTIMER(double t);
public slots:
    void TIMER();
};

#endif // STOPWATCH_H
