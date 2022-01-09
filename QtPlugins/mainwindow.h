#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "echointerface.h"
#include "PluginManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class EchoInterface;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_btnEchoSend_clicked();

    void on_btnTestMsgSend_clicked();

private:
    Ui::MainWindow *ui;
    EchoInterface * m_echoInterface;
    PluginManager * m_pluginManager;
};
#endif // MAINWINDOW_H
