#include "chartablewidget.h"

CharTableWidget::CharTableWidget(QWidget *parent)
    : QWidget (parent)
{
    layout = new QHBoxLayout();
    layout->setMargin(0);

    // LEFT PANE

    leftPane = new QWidget(this);
    leftPane->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    leftPane->setMinimumWidth(100);
    leftPane->setMaximumWidth(100);
    leftPaneLayout = new QVBoxLayout(this);


    for (int i = 1; i <= chartobject.length(); i++){

        QJsonObject obj = chartobject[QString::number(i)].toObject();
//        qDebug() << obj["title"].toString();
        LeftCharTableButton *btn = new LeftCharTableButton(obj["title"].toString(), QString::number(i), leftPane);
        connect(btn, &LeftCharTableButton::onBtnClicked,this,&CharTableWidget::leftPaneBtnClicked);
        leftPaneLayout->addWidget(btn,0,Qt::AlignTop);
    }

    leftPaneLayout->insertStretch(-1,1);
    leftPaneLayout->setContentsMargins(0,0,0,0);
    leftPane->setLayout(leftPaneLayout);

    leftscrollarea = new QScrollArea(this);
    leftscrollarea->setWidgetResizable(false);
    leftscrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    leftscrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    leftscrollarea->setWidget(leftPane);

    //  RIGHT PANE

    createRightPane(QString::number(1));

    //////

    rightscrollarea = new QScrollArea(this);
    rightscrollarea->setWidgetResizable(true);
    rightscrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    rightscrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    rightscrollarea->setWidget(rightPane);


    layout->addWidget(leftscrollarea,1);
    layout->addWidget(rightscrollarea,4);
    setStyleSheet("border: 0px solid #00000000");
    setFixedSize(600,450);
    setGeometry(0,50,600,450);
    setLayout(layout);
}


void CharTableWidget::leftPaneBtnClicked(QString key){
    rightscrollarea->takeWidget();
    delete rightPane;
    createRightPane(key);
    rightscrollarea->setWidget(rightPane);
}

void CharTableWidget::rightPaneBtnClicked(QString letr){
    qDebug() << letr << "Right Button";
    emit onChrTblBtnClicked(letr);
}

void CharTableWidget:: createRightPane(QString key){
    rightPane = new QWidget(this);
    rightPane->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    rightPane->move(100,0);
    rightPane->setMinimumSize(480,450);

    rightPaneLayout = new FlowLayout(rightPane);
    rightPaneLayout->setMargin(0);

    QJsonObject obj = chartobject[key].toObject();
    QJsonArray clist = obj["charlist"].toArray();
    int x = clist.count();
    for(int i = 1;i<x;i++){
        CharTable *btn = new CharTable(clist[i].toString(),rightPane);
        connect(btn, &CharTable::onBtnClicked,this,&CharTableWidget::rightPaneBtnClicked);
        rightPaneLayout->addWidget(btn);
    }
}
