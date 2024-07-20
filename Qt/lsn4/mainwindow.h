#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:
    void on_pBut_count_clicked();

    void on_rBut2_clicked();

    void on_rBut1_clicked();

    void on_cBox_listcolor_activated(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
