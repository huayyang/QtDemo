#include "sqlitehelper.h"

#include <QDebug>
#include <QDir>
#include <QSqlRecord>

#define DATABASE_HOSTNAME "localhost"
#if defined(Q_OS_IOS)
#define DATABASE_PATH "/Users/yanghuay/Projects/Playground/QtDemo/QtDemo/DemoDB.db"
#elif defined(Q_OS_WIN)
#define DATABASE_PATH "D:\\Projects\\QtUnityDemo\\QtUnityDemo\\Assets\\StreamingAssets\\Metadata\\DemoDb.db"
#endif

SqliteHelper::SqliteHelper(QObject *parent) : QObject(parent)
{

}

bool SqliteHelper::loadSqliteDB()
{
    qDebug() << "loadSqliteDB" << endl;
    if (!QFile(DATABASE_PATH).exists()) {
        qDebug() << "Failed to load DB" << endl;
        qDebug() << DATABASE_PATH << endl;
        return false;
    }

    if (sqliteDb.isOpen()) {
        return true;
    }

    sqliteDb = QSqlDatabase::addDatabase("QSQLITE");
    sqliteDb.setHostName(DATABASE_HOSTNAME);
    sqliteDb.setDatabaseName(DATABASE_PATH);
    if(sqliteDb.open()){
        qDebug() << "DB open" << endl;
        return true;
    } else {
        return false;
    }
}


void SqliteHelper::closeSqliteDB()
{
    sqliteDb.close();
}

QString SqliteHelper::getUnitIdWithDefaultName(QString defaultName)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM unit_metadata WHERE name = (:name)");
    query.bindValue(":name", defaultName);

    if(!query.exec()) {
        return "";
    }

    query.next();

    return query.value(0).toString();
}

QString SqliteHelper::getAbilityIdWithAbilityName(QString abilityName)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM ability_metadata WHERE name = (:abilityName)");
    query.bindValue(":abilityName", abilityName);

    if(!query.exec()) {
        return "";
    }

    query.next();

    return query.value(0).toString();
}

void SqliteHelper::updateUnitAbility(QString unitId, QString abilityId)
{
    QSqlQuery query;
    query.prepare("INSERT OR REPLACE INTO unit_editable(id, ability_id) values (:unitId, :abilityId)");
    query.bindValue(":unitId", unitId);
    query.bindValue(":abilityId", abilityId);

    if(!query.exec()) {
        qDebug() << "Failed to update unit ability" << endl;
    }
}




