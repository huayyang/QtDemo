#include "sqlitehelper.h"

#include <QDebug>
#include <QDir>

#define DATABASE_HOSTNAME "localhost"
#define DATABASE_PATH "/Users/huayuyang/Projects/DreamCraft/QtDemo/QtDemo/DemoDB.db"

SqliteHelper::SqliteHelper(QObject *parent) : QObject(parent)
{

}

bool SqliteHelper::loadSqliteDB()
{
    qDebug() << "loadSqliteDB" << endl;
    if (!QFile(DATABASE_PATH).exists()) {
        qDebug() << "Failed to load DB" << endl;
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



