#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtNetwork/QHostAddress>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db;
    QHostAddress QHA;
    return a.exec();
}
