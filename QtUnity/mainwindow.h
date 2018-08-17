#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qt_windows.h>
#include <QMainWindow>

#include <QTcpServer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void newConnection();

private slots:
    void sendMessageToUnity();
    void on_testButton_clicked();

private:
    Ui::MainWindow *ui;
    HWND unityHWND;
    void displayUnityScene();
    static BOOL CALLBACK EnumChildProc(HWND hwndChild, LPARAM lParamChild);

    QTcpServer *server;
    QTcpSocket *unityClient;
};

#endif // MAINWINDOW_H
