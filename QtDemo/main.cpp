#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "SqliteDB/sqlitehelper.h"
#include "listmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QScopedPointer<SqliteHelper> sqliteHelper(new SqliteHelper);
    QScopedPointer<ListModel> model(new ListModel);

    sqliteHelper.data()->loadSqliteDB();

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("sqlite", sqliteHelper.data());
    engine.rootContext()->setContextProperty("sqlModel", model.data());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
