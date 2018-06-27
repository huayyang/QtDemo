#include "listmodel.h"
#include "SqliteDB/sqlitehelper.h"

ListModel::ListModel(QObject *parent) :
    QSqlQueryModel(parent)
{
    updateModel();
}

QHash<int, QByteArray> ListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[DefaultNameRole] = "default_name";
    roles[UnityPrefabRole] = "unity_prefab_path";
    return roles;
}

QVariant ListModel::data(const QModelIndex & index, int role) const {

    // Define the column number, on the role of number
    int columnId = role - Qt::UserRole - 1;
    // Create the index using a column ID
    QModelIndex modelIndex = this->index(index.row(), columnId);

    return QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
}

void ListModel::updateModel()
{
    qDebug() << "updateModel" << endl;
    // The update is performed SQL-queries to the database
    this->setQuery("SELECT * FROM unit_metadata");
}
