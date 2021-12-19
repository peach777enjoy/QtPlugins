#include "echoplugin.h"

#include <QDebug>

EchoPlugin::EchoPlugin(QObject *parent) : QObject(parent)
{
}

EchoPlugin::~EchoPlugin()
{

}

QString EchoPlugin::echo(const QString &message)
{
    return message;
}
