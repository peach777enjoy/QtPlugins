#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QObject>
#include "echointerface.h"

class PluginManager : public QObject
{
    Q_OBJECT

public:
    PluginManager(QObject *parent = nullptr);
    static PluginManager* getInstance();
    bool loadPlugin();
    EchoInterface *getPlugin(QString name);

public slots:
    void recMsgFromManager(PluginMetaData metaData);

public:
    QList<EchoInterface*> m_pluginList;
    static PluginManager* m_instance;
};

#endif // PLUGINMANAGER_H
