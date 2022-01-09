#include "PluginManager.h"
#include <QDir>
#include <QPluginLoader>
#include <QDebug>

PluginManager::PluginManager(QObject *parent) : QObject(parent)
{

}

PluginManager* PluginManager::m_instance = nullptr;
PluginManager* PluginManager::getInstance()
{
  if(m_instance == nullptr){
      m_instance = new PluginManager();
  }
  return m_instance;
}

//插件管理器--加载插件
bool PluginManager::loadPlugin()
{
    QDir pluginsDir(".");
    //这里我新建了plugins文件夹，把上面生成的dll文件放到此文件夹下
    pluginsDir.cd("plugins");
    //加载当前文件夹下的库文件
    foreach(QString fileName, pluginsDir.entryList(QStringList() << "*.dll", QDir::Files)) {
       qDebug() << fileName << "   " <<pluginsDir.absoluteFilePath(fileName);
       QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
       bool isLoad = pluginLoader.isLoaded();
       QString info = pluginLoader.errorString();
       QObject *plugin = pluginLoader.instance();
       if (plugin) {
           //插件名称
           QString pluginName = plugin->metaObject()->className();
           qDebug()<<"插件名称："<<pluginName;
           m_pluginList << qobject_cast<EchoInterface *>(plugin);
           connect(plugin,SIGNAL(sendMsgToManager(PluginMetaData)),this,SLOT(recMsgFromManager(PluginMetaData)));
        }
    }
    if(!m_pluginList.empty()){
        qDebug()<<"size:"<<m_pluginList.size();
        return true;
    }

    return false;
}

EchoInterface *PluginManager::getPlugin(QString name)
{
    EchoInterface *result = nullptr;
    foreach(EchoInterface* e, m_pluginList){
        if(name == e->get_name()){
            result = e;
            break;
        }
    }
    return result;
}

void PluginManager::recMsgFromManager(PluginMetaData metaData)
{
    auto loader = getPlugin(metaData.dest);
    if(loader){
        loader->recMsgFromManager(metaData);
    }
}


