#include "abilitylistmodel.h"

AbilityListModel::AbilityListModel()
{

}

QVariant AbilityListModel::data(const QModelIndex &index, int role) const
{

    int columnId = role - Qt::UserRole - 1;

    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

QHash<int, QByteArray> AbilityListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole + 1] = "name";
    return roles;
}

void AbilityListModel::updateModel()
{
    this->setQuery("SELECT name FROM ability_metadata");
}
