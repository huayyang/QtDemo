#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDateTime>
#include <QDebug>
#include <QTcpSocket>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    displayUnityScene();

    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));

    QHostAddress address;
    address.setAddress("127.0.0.1");
    if(!server->listen(address, 8888)) {
        qDebug() << "Listen failed" << endl;
    };

}

MainWindow::~MainWindow()
{
    if(unityClient != NULL) {
        unityClient->close();
    }
    delete ui;
}

void MainWindow::newConnection()
{
    unityClient = server->nextPendingConnection();
    unityClient->write("Hello Unity");
    unityClient->flush();

    unityClient->waitForBytesWritten(3000);
}

BOOL CALLBACK  MainWindow::EnumChildProc(HWND hwnd, LPARAM lParam)
{
    SendMessage(hwnd, WM_ACTIVATE, WA_ACTIVE, lParam);
    return TRUE;
}

void MainWindow::sendMessageToUnity()
{
    unityClient->write("hello client\r\n");
    unityClient->flush();
    unityClient->waitForBytesWritten(3000);
}

void MainWindow::displayUnityScene()
{

    QString fileName = QFileDialog::getOpenFileName(this,
             tr("Open Unity Build"), "D:/Projects/Qt/QtUnity/Unity", tr("Unity Build (*.exe)"));

    //QString fileName = "D:\\Projects\\Qt\\QtUnity\\Unity\\Child.exe";

    // PASS ARGS
    QString _args = QString("-parentHWND %1").arg(ui->unityWidget->winId());

    qDebug() << _args <<endl;

    PROCESS_INFORMATION procInfo;
    STARTUPINFO startupInfo;

    ZeroMemory( &startupInfo, sizeof(startupInfo) );
    startupInfo.cb = sizeof(startupInfo);
    ZeroMemory( &procInfo, sizeof(procInfo) );

    startupInfo.dwFlags = STARTF_USESTDHANDLES;
    startupInfo.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
    startupInfo.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    startupInfo.hStdError = GetStdHandle(STD_ERROR_HANDLE);

    unityHWND = (HWND) ui->unityWidget->winId();
    LPCWSTR cmd = (LPCWSTR)fileName.utf16();
    LPWSTR args = (LPWSTR)_args.utf16();

    BOOL bProcessStarted = CreateProcess(
                cmd,
                args,
                nullptr,
                nullptr,
                TRUE,
                CREATE_NO_WINDOW,
                nullptr,
                nullptr,
                &startupInfo,
                &procInfo);

    if(!bProcessStarted){
        qDebug() << GetLastError() << endl;
        return;
    }

    //WAIT FOR START
    qint64 before = QDateTime::currentMSecsSinceEpoch();
    Sleep(100);
    WaitForInputIdle(procInfo.hProcess, INFINITE);
    qint64 after = QDateTime::currentMSecsSinceEpoch();
    qDebug() << "Waited " << (after-before);

    //GET UNITY WINDOW HANDLE
    EnumChildWindows(unityHWND, MainWindow::EnumChildProc, 0);

    // Close process and thread handles.
    CloseHandle( procInfo.hProcess );
    CloseHandle( procInfo.hThread );
    qDebug() << "Exit" << endl;
}

void MainWindow::on_testButton_clicked()
{
    unityClient->write("send from server");
    unityClient->flush();

    unityClient->waitForBytesWritten(3000);
    qDebug() << "Send Message" << endl;
}
