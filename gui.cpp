#include "gui.h"

Gui::Gui(QWidget *parent) : QWidget(parent), m_client()
{
    setupUi(this);
    connect(&m_client, &HttpClient::ScanFinished, this, &Gui::ShowResult);
}

void Gui::on_goButton_clicked()
{
    QString host = hostEntry->text();
    //m_client.HttpClient(host);
}
void Gui::ShowResult(bool status)
{
    qDebug() << status;
    QString host = hostEntry->text();
    QString msg = (status == true) ? "open" : "closed";
    QString result = host + msg;
    resultBrowser->append(result);
}
