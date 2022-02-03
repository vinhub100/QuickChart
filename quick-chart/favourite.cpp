#include "favourite.h"

Favourite::Favourite(QString cha, QWidget *parent)
    : QWidget(parent),letr(cha)
{
    layout = new QGridLayout(this);

    btn = new QPushButton(letr,this);
    btn->setStyleSheet("font-size:50px;color:gold;");
    btn->setGeometry(0,0,90,90);
    btn->setFixedSize(90,90);

    x_btn = new QPushButton("❌",this);
    x_btn->setStyleSheet("font-size:10px;border:0px solid black;background-color:#00000000;");
    x_btn->setFixedSize(15,15);
//    x_btn->setGeometry(75,10,12,12);

    connect(btn, SIGNAL(clicked()),this,SLOT(btnClicked()));
    connect(x_btn, SIGNAL(clicked()),this,SLOT(btnXClicked()));
    layout->addWidget(x_btn,1,1,Qt::AlignRight | Qt::AlignTop );
    layout->addWidget(btn,1,1,Qt::AlignCenter);
    setLayout(layout);
}

//Favourite::~Favourite(){

//}

void Favourite::btnClicked(){
    emit onBtnClicked(this->letr);
}

void Favourite::btnXClicked(){
    emit onXBtnClicked(this->letr);
}
