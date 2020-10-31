#include "byteconverter.h"

ByteConverter::ByteConverter(QObject *parent) : QObject(parent)
{

}

void ByteConverter::setDec(const QString &newValue)
{
    bool ok;
    long long num = newValue.toLongLong(&ok);
    if(ok) {
        emit hexChanged(QString::number(num, 16));
        emit binChanged(QString::number(num, 2));
    } else {
        emit hexChanged("");
        emit binChanged("");
    }
}

void ByteConverter::setHex(const QString &newValue)
{
    bool ok;
    long long num = newValue.toLongLong(&ok, 16);
    if(ok) {
        emit decChanged(QString::number(num));
        emit binChanged(QString::number(num, 2));
    } else {
        emit decChanged("");
        emit binChanged("");
    }

}

void ByteConverter::setBin(const QString &newValue)
{
    bool ok;
    long long num = newValue.toLongLong((&ok), 2);
    if(ok) {
        emit decChanged(QString::number(num));
        emit hexChanged(QString::number(num, 16));
    } else {
        emit decChanged("");
        emit hexChanged("");
    }
}
