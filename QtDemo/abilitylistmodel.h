#ifndef ABILITYLISTMODEL_H
#define ABILITYLISTMODEL_H

#include <QObject>
#include <QSqlQueryModel>

class AbilityListModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit AbilityListModel();
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

signals:

public slots:
    void updateModel();
};

#endif // ABILITYLISTMODEL_H
