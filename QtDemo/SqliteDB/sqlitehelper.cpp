#include "sqlitehelper.h"

#include <QDebug>
#include <sqlite3.h>

SqliteHelper::SqliteHelper(QObject *parent) : QObject(parent)
{

}

void SqliteHelper::loadSqliteDB()
{
    qDebug() << "loadSqliteDB" << endl;
}


