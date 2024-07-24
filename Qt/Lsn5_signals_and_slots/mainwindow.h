#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
   void pb_Start_clicked();
   void pb_Stop_clicked();
   void lb_txt(double t);
   void Circl(QString str);
   void Clear();

private slots:

    void on_pb_start_clicked();

    void on_pb_clear_clicked();

    void on_pb_circle_clicked();

private:
    Ui::MainWindow *ui;
    stopwatch *sWatch;
};
#endif // MAINWINDOW_H
