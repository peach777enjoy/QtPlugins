#ifndef TESTMSGPLUGIN_H
#define TESTMSGPLUGIN_H

#include <QObject>

#include "TestMsgPlugin_global.h"
#include "echointerface.h"

class TESTMSGPLUGIN_EXPORT TestMsgPlugin : public QObject, EchoInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Example.Plugin.EchoInterface")
    Q_INTERFACES(EchoInterface)

public:
    TestMsgPlugin(QObject *parent = nullptr);
    ~TestMsgPlugin()override;
    QString echo(const QString & message)override;
    QString get_name() const override;

public slots:
    void recMsgFromManager(PluginMetaData metaData)override;//接收到来自创建管理器的消息

signals:
    void sendMsgToManager(PluginMetaData metaData)override;//给插件管理器发消息
};

#endif // TESTMSGPLUGIN_H
