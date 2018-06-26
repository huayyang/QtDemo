#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "SqliteDB/sqlitehelper.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QScopedPointer<SqliteHelper> sqliteHelper(new SqliteHelper);
    engine.rootContext()->setContextProperty("sqlite", sqliteHelper.data());

    return app.exec();
}
