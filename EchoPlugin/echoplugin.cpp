#include "echoplugin.h"

#include <QDebug>

EchoPlugin::EchoPlugin(QObject *parent) : QObject(parent)
{
}

EchoPlugin::~EchoPlugin()
{
     qDebug()<<"~EchoPlugin()";
}

QString EchoPlugin::echo(const QString &message)
{
    return message;
}

void EchoPlugin::recMsgFromManager(PluginMetaData metaData)
{
     qDebug()<<QString("插件%1接收到消息：%2").arg(this->metaObject()->className()).arg(metaData.msg);
}

QString EchoPlugin::get_name() const
{
    return this->metaObject()->className();
}
