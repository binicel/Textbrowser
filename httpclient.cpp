#include "httpclient.h"
#include <QDebug>
#include <QCoreApplication>

HttpClient::HttpClient(QObject *parent) : QObject(parent)
{
    unsigned short port = 80;
    m_socket = new QTcpSocket(this);

    // Signal ->  Slot-Verbindung
    connect(m_socket, &QTcpSocket::connected, this, &HttpClient::connected);
    connect(m_socket, &QTcpSocket::readyRead, this, &HttpClient::readyRead);

    m_socket->connectToHost(m_hostname, port); // TCP Connect
    if (!m_socket->waitForConnected(TIMEOUT)) {
        qDebug() << "Connect failed!";
        exit(1);
    }
}
void HttpClient::connected()
{
    // normgerechter HTTP Request zum Server
    m_socket->write("GET / HTTP/1.1\r\nHost:" + m_hostname + "\r\n\r\n");
}

void HttpClient::readyRead()
{
    // HTTP-Antwort vom Server
    qDebug() << m_socket->readAll();
    m_socket->disconnectFromHost();
    QCoreApplication::quit();
}
