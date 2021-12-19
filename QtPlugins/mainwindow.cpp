#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QPluginLoader>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"load"<<loadPlugin();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::loadPlugin()
{
    QDir pluginsDir(qApp->applicationDirPath());
    //这里我新建了plugins文件夹，把上面生成的dll文件放到此文件夹下
    pluginsDir.cd("plugins");
    //加载当前文件夹下的库文件
    foreach(QString fileName, pluginsDir.entryList(QStringList() << "*.dll", QDir::Files)) {
       qDebug() << fileName << "   " <<pluginsDir.absoluteFilePath(fileName);
       QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
       bool isLoad = pluginLoader.isLoaded();
       QString info = pluginLoader.errorString();
       qDebug()<<isLoad<<info;
       QObject *plugin = pluginLoader.instance();
       if (plugin) {
           qDebug()<<"222";
           //插件名称
           QString pluginName = plugin->metaObject()->className();
           if(pluginName == "EchoPlugin") {
               qDebug() << "enter here"<<pluginName;
               m_echoInterface = qobject_cast<EchoInterface *>(plugin);
               if (m_echoInterface){
                   return true;
               }
           }
       }
    }
    return false;
}


void MainWindow::on_pushButton_clicked()
{
    ui->lineEditAnswer->clear();
    QString text = m_echoInterface->echo(ui->lineEditMessage->text());
    ui->lineEditAnswer->setText(text);
}
