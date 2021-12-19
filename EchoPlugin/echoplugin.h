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

};

#endif // ECHOPLUGIN_H
