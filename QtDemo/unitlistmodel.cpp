#include "unitlistmodel.h"

#include <QDebug>

const char* UnitListModel::SQL_SELECT = "SELECT name FROM unit_metadata";

UnitListModel::UnitListModel(QObject *parent)
{

}

void UnitListModel::updateModel()
{
    this->setQuery(SQL_SELECT);
}

QVariant UnitListModel::data(const QModelIndex &index, int role) const
{
    int columnId = role - Qt::UserRole - 1;

    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

QHash<int, QByteArray> UnitListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::UserRole + 1] = "name";
    return roles;
}
