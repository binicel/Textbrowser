#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QAbstractSocket>
#include <QTcpSocket>

const int TIMEOUT = 5000;

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = nullptr);
    void scan(QString& host);

signals:
    void ScanFinished(bool status);

public slots:
    void connected();
    void readyRead();

private:
    QTcpSocket *m_socket;
    QByteArray m_hostname;

};

#endif // HTTPCLIENT_H
