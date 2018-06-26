#ifndef SQLITEHELPER_H
#define SQLITEHELPER_H

#include <QObject>

class SqliteHelper : public QObject
{
    Q_OBJECT
public:
    explicit SqliteHelper(QObject *parent = nullptr);

    Q_INVOKABLE void loadSqliteDB();

signals:

public slots:
};

#endif // SQLITEHELPER_H
