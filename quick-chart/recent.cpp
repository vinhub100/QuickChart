#include "recent.h"

Recent::Recent(QString cha, QWidget *parent)
    :QWidget (parent),letr(cha)
{
    layout = new QBoxLayout(QBoxLayout::TopToBottom,this);
    btn = new QPushButton(letr,this);
    btn->setStyleSheet("font-size:50px;color:gold;");
    btn->setGeometry(0,0,90,90);
    btn->setFixedSize(90,90);
    connect(btn, SIGNAL(clicked()),this,SLOT(btnClicked()));
    layout->addWidget(btn);
    setLayout(layout);
}

//Recent::~Recent()
//{

//}

void Recent::btnClicked(){
    emit onBtnClicked(this->letr);
}
