#include "mainwindow.h"

#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtNetwork/QHostAddress>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QSqlDatabase db;
    QHostAddress QHA;
    return a.exec();
}
