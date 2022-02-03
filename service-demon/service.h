#ifndef SERVICE_H
#define SERVICE_H

#include <QtDBus>
#include <QObject>
#include <QDebug>
#include "servicedemon_adaptor.h"
#include "common.h"




class Service : public QObject
{
    Q_OBJECT

public:
    explicit Service(QObject *parent = nullptr);
    ~Service();
signals:

public slots:
    void callCtrlV(int msec);

};


#endif // SERVICE_H
