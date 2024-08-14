#include "udpworker.h"

UDPworker::UDPworker(QObject *parent) : QObject(parent)
{



}


/*!
 * @brief Метод инициализирует UDP сервер
 */
void UDPworker::InitSocket()
{

    serviceUdpSocket = new QUdpSocket(this);
    DataUdpSocket = new QUdpSocket(this);
    /*
     * Соединяем присваиваем адрес и порт серверу и соединяем функцию
     * обраотчик принятых пакетов с сокетом
     */
    serviceUdpSocket->bind(QHostAddress::LocalHost, BIND_PORT);
    DataUdpSocket->bind(QHostAddress::LocalHost,22334);

    connect(serviceUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::readPendingDatagrams);
    connect(DataUdpSocket, &QUdpSocket::readyRead, this, &UDPworker::readPendingDatagrams);

}

/*!
 * @brief Метод осуществляет обработку принятой датаграммы
 */
void UDPworker::ReadDatagram(QNetworkDatagram datagram)
{

    QByteArray data;
    data = datagram.data();


    QDataStream inStr(&data, QIODevice::ReadOnly);
    QDateTime dateTime;
    inStr >> dateTime;

    emit sig_sendTimeToGUI(dateTime);
}
void UDPworker::ReadDatagramSecSock(QNetworkDatagram datagram)
{

    QByteArray data;
    data = datagram.data();

    //QDataStream inStr(&data, QIODevice::ReadOnly);
    //QDateTime dateTime;
    //inStr >> dateTime;  

    emit sig_sendDataToGUI(datagram.destinationAddress(),data.size());
}


/*!
 * @brief Метод осуществляет опередачу датаграммы
 */
void UDPworker::SendDatagram(QByteArray data)
{
    /*
     *  Отправляем данные на localhost и задефайненный порт
     */
    serviceUdpSocket->writeDatagram(data, QHostAddress::LocalHost, BIND_PORT);

}
void UDPworker::SendDatagramSecSock(QByteArray data)
{
    /*
     *  Отправляем данные на localhost и задефайненный порт
     */
    DataUdpSocket->writeDatagram(data, QHostAddress::LocalHost, 22334);

}



/*!
 * @brief Метод осуществляет чтение датаграм из сокета
 */
void UDPworker::readPendingDatagrams( void )
{
    /*
     *  Производим чтение принятых датаграмм
     */
    while(DataUdpSocket->hasPendingDatagrams()){
        QNetworkDatagram datagram = DataUdpSocket->receiveDatagram();
        ReadDatagramSecSock(datagram);
    }
    while(serviceUdpSocket->hasPendingDatagrams()){
            QNetworkDatagram datagram = serviceUdpSocket->receiveDatagram();
            ReadDatagram(datagram);
    }

}


