
#include "service.h"


Service::Service(QObject *parent) : QObject(parent)
{
    initCtrlV();

    new ServiceAdaptor(this);
    QDBusConnection con = QDBusConnection::systemBus();
    con.registerService("in.kanet.kbdemon");
    con.registerObject("/Service", this);

}

Service::~Service(){

    closeCtrlV();

}

void Service::callCtrlV(int msec){
    CtrlV(msec);
}


