#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include <QFileDialog>

#include "SqliteDB/sqlitehelper.h"
#include "listmodel.h"
#include "unitlistmodel.h"
#include "abilitylistmodel.h"
#include "updateunitabilityhandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QScopedPointer<SqliteHelper> sqliteHelper(new SqliteHelper);
    QScopedPointer<ListModel> model(new ListModel);
    QScopedPointer<UnitListModel> unitModel(new UnitListModel);
    QScopedPointer<AbilityListModel> abilityModel(new AbilityListModel);

    QScopedPointer<UpdateUnitAbilityHandler> updateUnitAbilityHandler(new UpdateUnitAbilityHandler);
    updateUnitAbilityHandler->initialize(sqliteHelper.data());

    //sqliteHelper.data()->loadSqliteDB();

    engine.rootContext()->setContextProperty("sqlite", sqliteHelper.data());
    engine.rootContext()->setContextProperty("sqlModel", model.data());
    engine.rootContext()->setContextProperty("unitModel", unitModel.data());
    engine.rootContext()->setContextProperty("abilityModel", abilityModel.data());

    engine.rootContext()->setContextProperty("updateUnitAbilityHandler", updateUnitAbilityHandler.data());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
