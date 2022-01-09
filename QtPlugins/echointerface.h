#ifndef ECHOINTERFACE_H
#define ECHOINTERFACE_H

#include <QtPlugin>
#include <QString>
#include <QJsonObject>

QT_BEGIN_NAMESPACE

struct PluginMetaData
{
    QString from;//消息来源
    QString dest;//消息目的地
    QString msg;

    QObject *object = nullptr;
    QJsonObject info = QJsonObject();
};
Q_DECLARE_METATYPE(PluginMetaData);//确保类型可以通过信号槽传递

//声明一个抽象类即接口，注册进qt框架，以名字区分注册的qt插件
class EchoInterface
{
public:
    virtual ~EchoInterface(){};
    virtual QString echo(const QString &message) = 0;
    virtual QString get_name() const = 0;

public slots:
    virtual void recMsgFromManager(PluginMetaData metaData) = 0;//接收到来自创建管理器的消息

signals:
    virtual void sendMsgToManager(PluginMetaData metaData) = 0;//给插件管理器发消息

};

#define EchoInterface_lib "Example.Plugin.EchoInterface"
Q_DECLARE_INTERFACE(EchoInterface, EchoInterface_lib)

QT_END_NAMESPACE

#endif // ECHOINTERFACE_H
