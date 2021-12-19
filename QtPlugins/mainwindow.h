#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include "echointerface.h"

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

    bool loadPlugin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    EchoInterface * m_echoInterface;
};
#endif // MAINWINDOW_H
