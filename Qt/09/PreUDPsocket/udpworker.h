#ifndef UDPWORKER_H
#define UDPWORKER_H

#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QNetworkDatagram>
#include <QDateTime>


#define BIND_PORT 12345

class UDPworker : public QObject
{
    Q_OBJECT
public:
    explicit UDPworker(QObject *parent = nullptr);
    void InitSocket( void );
    void ReadDatagram( QNetworkDatagram datagram);
    void ReadDatagramSecSock( QNetworkDatagram datagram);
    void SendDatagram(QByteArray data );
    void SendDatagramSecSock(QByteArray data );


private slots:
    void readPendingDatagrams(void);

private:
    QUdpSocket* serviceUdpSocket;
    QUdpSocket* DataUdpSocket;

signals:
    void sig_sendDataToGUI(QHostAddress Qha,int size);
    void sig_sendTimeToGUI(QDateTime data);

};

#endif // UDPWORKER_H
