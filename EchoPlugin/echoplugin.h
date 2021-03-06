#ifndef ECHOPLUGIN_H
#define ECHOPLUGIN_H

#include <QObject>

#include "EchoPlugin_global.h"
#include "echointerface.h"

//继承实现接口的方法，对外导出生成的动态库，指定元数据使用的qt框架的那个插件
class ECHOPLUGIN_EXPORT EchoPlugin : public QObject, EchoInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Example.Plugin.EchoInterface")
    Q_INTERFACES(EchoInterface)

public:
    explicit EchoPlugin(QObject *parent = nullptr);
    ~EchoPlugin()override;
    QString echo(const QString & message)override;
    QString get_name() const override;

public slots:
    void recMsgFromManager(PluginMetaData metaData)override;//接收到来自创建管理器的消息

signals:
    void sendMsgToManager(PluginMetaData metaData)override;//给插件管理器发消息
};

#endif // ECHOPLUGIN_H
