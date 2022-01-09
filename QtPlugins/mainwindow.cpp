#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pluginManager = new PluginManager();
    m_pluginManager = m_pluginManager->getInstance();
    qDebug() << m_pluginManager->loadPlugin();
}

MainWindow::~MainWindow()
{
    delete ui;
}
 
void MainWindow::on_pushButton_clicked()
{
    ui->lineEditAnswer->clear();
    m_echoInterface = m_pluginManager->getPlugin("EchoPlugin");
    if(m_echoInterface){
        QString text = m_echoInterface->echo(ui->lineEditMessage->text());
        ui->lineEditAnswer->setText(text);
    }else{
        qWarning()<<"EchoPlugin error";
    }
}

void MainWindow::on_btnEchoSend_clicked()
{
    auto loader = m_pluginManager->getPlugin("EchoPlugin");
    if(loader){
        PluginMetaData m;
        m.from = "EchoPlugin";
        m.dest = "TestMsgPlugin";
        m.msg = "你好，测试消息！";
        emit loader->sendMsgToManager(m);
    }else{
        qWarning()<<"EchoPlugin Send error";
    }
}

void MainWindow::on_btnTestMsgSend_clicked()
{
    auto loader = m_pluginManager->getPlugin("TestMsgPlugin");
    if(loader){
        PluginMetaData m;
        m.from = "TestMsgPlugin";
        m.dest = "EchoPlugin";
        m.msg = "测试消息成功！";
        emit loader->sendMsgToManager(m);
    }else{
        qWarning()<<"TestMsgPlugin Send error";
    }
}
