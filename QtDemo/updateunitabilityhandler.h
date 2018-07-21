#ifndef UPDATEUNITABILITYHANDLER_H
#define UPDATEUNITABILITYHANDLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlEngine>

class UpdateUnitAbilityHandler: public QObject
{
Q_OBJECT
public:
   explicit  UpdateUnitAbilityHandler(QObject *parent = nullptr);
   explicit  UpdateUnitAbilityHandler(QQmlApplicationEngine *engine);

signals:

public slots:
    void updateUnitAbility();

private:
    QQmlApplicationEngine* engine_;
};

#endif // UPDATEUNITABILITYHANDLER_H
