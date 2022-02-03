#include "frontend.h"

#include <chrono>

using namespace std::chrono;

FrontEnd::FrontEnd(QObject *parent) : QObject(parent)
{
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon("../data/qwerty.png"));
    trayIconMenu = new QMenu();
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->show();
    actionGroup = new QActionGroup(this);

    createTrayMenu();

    QC = new QC_Frame();
    connect(QC,&QC_Frame::sendCtlVsignal,this,&FrontEnd::callCtrlV);

    process = new QProcess(this);

    setSudoKbCharMap();


    serviceDemon = new in::kanet::kbdemon::Service("in.kanet.kbdemon","/Service",QDBusConnection::systemBus(),this);
}

FrontEnd::~FrontEnd(){
    delete QC;
}

void FrontEnd::createTrayMenu(void){

    QAction *toggleAction = new QAction("Show &QuickChart");
    connect(toggleAction, &QAction::triggered, this, &FrontEnd::toggleqcview);
    trayIconMenu->addAction(toggleAction);
}

void FrontEnd::toggleQCView(void){
    toggleqcview();
}

void FrontEnd::setSudoKbCharMap(){
    process->start("/bin/bash -c \"xinput list --id-only 'kanet Psudo Keyboard'\"");
    process->waitForFinished();
    QString dId = process->readAllStandardOutput();
    dId = dId.remove("\n");
    process->start("/bin/bash -c \"setxkbmap -device "+ dId +" -model evdev vitanive_vndr/in\"");
    process->waitForFinished();
//    qDebug() << "Data: " << dId;
}



void FrontEnd::toggleqcview(void){
        if(!QC->isVisible()){
            QC->show();
        } else {
            QC->hide();
            QC->setFocusPolicy(Qt::ClickFocus);
        }
}


void FrontEnd::callCtrlV(void){
//    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    serviceDemon->callCtrlV(400);
//    qDebug() << "Ctrl - V";
}


