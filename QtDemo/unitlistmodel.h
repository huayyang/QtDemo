#ifndef UNITLISTMODEL_H
#define UNITLISTMODEL_H

#include <QObject>
#include <QStringListModel>

class UnitListModel : public QStringListModel
{
    Q_OBJECT
public:
    UnitListModel();
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QList<QString> unitNames;

signals:

public slots:
};

#endif // UNITLISTMODEL_H
