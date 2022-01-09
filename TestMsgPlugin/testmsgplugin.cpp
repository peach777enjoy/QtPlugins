#include "testmsgplugin.h"

#include <QDebug>

TestMsgPlugin::TestMsgPlugin(QObject *parent) : QObject(parent)
{
}

TestMsgPlugin::~TestMsgPlugin()
{
    qDebug()<<"~TestMsgPlugin()";
}

QString TestMsgPlugin::echo(const QString &message)
{
    return message;
}

void TestMsgPlugin::recMsgFromManager(PluginMetaData metaData)
{
    qDebug()<<QString("插件%1接收到消息：%2").arg(this->metaObject()->className()).arg(metaData.msg);
}

QString TestMsgPlugin::get_name() const
{
     return this->metaObject()->className();
}
