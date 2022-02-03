#include "leftchartablebutton.h"

LeftCharTableButton::LeftCharTableButton(QString text, QString id, QWidget *parent)
    : QWidget(parent),text(text),id(id)
{
    btn = new QPushButton(text,this);
    layout = new QBoxLayout(QBoxLayout::TopToBottom);
    layout->setContentsMargins(0,0,0,0);
    btn->setGeometry(0,0,100,25);
    btn->setFixedSize(100,25);
    btn->setStyleSheet("font-size:15px;");
    connect(btn,&QPushButton::clicked,this,&LeftCharTableButton::btnClicked);
    layout->addWidget(btn);
    setLayout(layout);
}

void LeftCharTableButton::btnClicked(){
    emit onBtnClicked(this->id);
}
