#include "updateunitabilityhandler.h"

#include <QDebug>
#include <QQmlContext>
#include "unitlistmodel.h"

UpdateUnitAbilityHandler::UpdateUnitAbilityHandler(QObject *parent)
{

}

UpdateUnitAbilityHandler::UpdateUnitAbilityHandler(QQmlApplicationEngine *engine)
{
    engine_ = engine;
}

void UpdateUnitAbilityHandler::updateUnitAbility()
{
    qDebug() << "UpdateUnitAbility" << endl;
    QVariant unitModelData = engine_->rootContext()->contextProperty("unitModel");
    UnitListModel* unitModel = unitModelData.value<UnitListModel*>();
    qDebug() << unitModel->data(QModelIndex()) << endl;
}
