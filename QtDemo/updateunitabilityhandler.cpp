#include "updateunitabilityhandler.h"

#include <QDebug>
#include <QQmlContext>

UpdateUnitAbilityHandler::UpdateUnitAbilityHandler(QObject *parent)
{

}

void UpdateUnitAbilityHandler::initialize(SqliteHelper *sqliteHelper)
{
    sqliteHelper_.reset(sqliteHelper);
}

void UpdateUnitAbilityHandler::updateUnitAbility(QString unitName, QString abilityName)
{
    qDebug() << "Update: " + unitName + ", with ability: "+ abilityName << endl;
    if(unitName.isEmpty() || abilityName.isEmpty()) {
        qDebug() << "updateUnitAbility failed" << endl;
        return;
    }

    QString unitId = sqliteHelper_->getUnitIdWithDefaultName(unitName);
    QString abilityId = sqliteHelper_->getAbilityIdWithAbilityName(abilityName);

    if(unitId.isEmpty() || abilityId.isEmpty()) {
        qDebug() << "updateUnitAbility failed" << endl;
        return;
    }

    sqliteHelper_->updateUnitAbility(unitId, abilityId);

}
