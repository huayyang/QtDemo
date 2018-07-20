#ifndef UNITLISTMODEL_H
#define UNITLISTMODEL_H

#include <QObject>
#include <QSqlQueryModel>

class UnitListModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit UnitListModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

signals:

public slots:
    void updateModel();

private:
    const static char* SQL_SELECT;
};

#endif // UNITLISTMODEL_H
