#ifndef SQLITEHELPER_H
#define SQLITEHELPER_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

class SqliteHelper : public QObject
{
    Q_OBJECT
public:
    explicit SqliteHelper(QObject *parent = nullptr);

    Q_INVOKABLE bool loadSqliteDB();
    Q_INVOKABLE void closeSqliteDB();



private:
    QSqlDatabase sqliteDb;

signals:

public slots:
};

#endif // SQLITEHELPER_H
