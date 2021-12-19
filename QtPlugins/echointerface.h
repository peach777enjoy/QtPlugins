#ifndef ECHOINTERFACE_H
#define ECHOINTERFACE_H

#include <QtPlugin>
#include <QString>

QT_BEGIN_NAMESPACE

class EchoInterface
{
public:
    virtual ~EchoInterface() = 0;
    virtual QString echo(const QString &message) = 0;
};

#define EchoInterface_lib "Example.Plugin.EchoInterface"

Q_DECLARE_INTERFACE(EchoInterface, EchoInterface_lib)
QT_END_NAMESPACE

#endif // ECHOINTERFACE_H
