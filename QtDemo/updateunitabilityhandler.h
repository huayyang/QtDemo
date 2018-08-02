#ifndef UPDATEUNITABILITYHANDLER_H
#define UPDATEUNITABILITYHANDLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlEngine>

#include "SqliteDB/sqlitehelper.h"
#include "unitlistmodel.h"

class UpdateUnitAbilityHandler: public QObject
{
Q_OBJECT
public:
   explicit  UpdateUnitAbilityHandler(QObject *parent = nullptr);
   void  initialize(SqliteHelper* sqliteHelper);

signals:

public slots:
    void updateUnitAbility(QString unitName, QString abilityName);

private:
    QScopedPointer<SqliteHelper> sqliteHelper_;
};

#endif // UPDATEUNITABILITYHANDLER_H
