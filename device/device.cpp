#include "device.h"

Device::Device(QString COM, int baudrate, QString confirm_cmd, QString rev_msg, bool is_open, QObject *parent) : QObject(parent),
    serialPortName(COM), baudrate(baudrate), confirmRequest(confirm_cmd), confirmResponse(rev_msg)
{

    jsonObject["device"] = "device";

    if (is_open == true) {
        Run();
    }
}

Device::~Device()
{
    delete serialPort;
}

void Device::Connect()
{
    if (serialPort->isOpen())
        return;

    if (serialPortName.toLower() == "auto" && confirmRequest != "")
    {
        QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();

        for (int i = 0; i < availablePorts.size(); ++i)
        {
            serialPort->setPortName(availablePorts.at(i).portName());
            serialPort->setBaudRate(baudrate);

            if (serialPort->open(QIODevice::ReadWrite)) {
                serialPort->blockSignals(true);
                serialPort->write((confirmRequest + "\n").toLocal8Bit());
                serialPort->waitForReadyRead(500);
                QString response = QString(serialPort->readLine());
                if (response.indexOf(confirmResponse) > -1) {
                    qDebug() << availablePorts.at(i).portName() << "is connected";
                    readDataConnection = connect(serialPort, SIGNAL(readyRead()), this, SLOT(ReadData()));
                    serialPort->blockSignals(false);
                    break;
                }
                else {
                    serialPort->close();
                }
            }
        }
    }

    if (serialPortName.toLower() != "auto")
    {
        serialPort->setPortName(serialPortName);
        serialPort->setBaudRate(baudrate);

        if (serialPort->open(QIODevice::ReadWrite))
        {
            qDebug() << serialPortName << "is connected";
            readDataConnection = connect(serialPort, SIGNAL(readyRead()), this, SLOT(ReadData()));
        }
        else
        {
            qDebug() << serialPortName << "is not connected";
        }
    }

    jsonObject["id"] = id;
    jsonObject["state"] = (serialPort->isOpen())?"open":"close";
    jsonObject["com_name"] = serialPort->portName();
    jsonObject["baudrate"] = serialPort->baudRate();

    QJsonDocument jsonDocument;
    jsonDocument.setObject(jsonObject);
    QString jsonString = jsonDocument.toJson(QJsonDocument::Indented);
    emit infoReady(jsonString);

}

void Device::Disconnect()
{
    if (serialPort->isOpen())
    {
        serialPort->close();
        jsonObject["state"] = "close";

        QJsonDocument jsonDocument;
        jsonDocument.setObject(jsonObject);
        QString jsonString = jsonDocument.toJson(QJsonDocument::Indented);
        emit infoReady(jsonString);
    }
}

void Device::Delay(int msec) {
    QEventLoop loop;
    QTimer::singleShot(msec, &loop, SLOT(quit()));
    loop.exec();
}

QString Device::GetResponse(int timeout_ms) {
    QElapsedTimer timer;
    timer.start();
    while (timer.elapsed() < timeout_ms) {
        serialPort->waitForReadyRead(1);
        if (serialPort->canReadLine() == true) {
            break;
        }
    }

    return ReadLine();
}

void Device::WriteData(QString data)
{
    if (!data.endsWith("\n"))
        data.append("\n");

    if (this->serialPort->isOpen())
        this->serialPort->write(data.toLocal8Bit());
}

void Device::ReadData()
{
    if (serialPort->canReadLine())
    {
        ReadLine();
    }
}

QString Device::ReadLine(){
    QString data = QString(serialPort->readLine());

    emit receivedMsg(id, data);

    return data;
}

QString Device::GetSerialPortName()
{
    return serialPortName;
}

int Device::GetSerialPortBaudrate()
{
    return baudrate;
}

bool Device::IsOpen()
{
    return serialPort->isOpen();
}

QString Device::ID()
{
    return this->id;
}

void Device::SetID(QString id)
{
    this->id = id;
}

void Device::Run()
{
    qDebug() << "Device run";
    serialPort = new QSerialPort();

    feedback  = "";
}
