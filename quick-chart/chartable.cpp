#include "chartable.h"

CharTable::CharTable(QString cha, QWidget *parent)
    : QWidget(parent),letr(cha)
{
    layout = new QGridLayout(this);

    btn = new QPushButton(letr,this);
    btn->setStyleSheet("font-size:50px;");
    btn->setGeometry(0,0,90,90);
    btn->setFixedSize(90,90);

    like_btn = new QPushButton("✅",this);
    if(fList.contains(letr)){
        this->isFav = true;
        like_btn->setStyleSheet("font-size:15px;border:0px none black;background-color:#00000000;color:#ff00ff00;");
    }
    else {
        like_btn->setStyleSheet("font-size:15px;border:0px none black;background-color:#00000000;color:#ff999999;");
        this->isFav = false;
    }

    like_btn->setFixedSize(16,16);
//    x_btn->setGeometry(75,10,12,12);// ✅

    connect(btn, SIGNAL(clicked()),this,SLOT(btnClicked()));
    connect(like_btn, SIGNAL(clicked()),this,SLOT(btnLikeClicked()));
    layout->addWidget(like_btn,1,1,Qt::AlignRight | Qt::AlignTop );
    layout->addWidget(btn,1,1,Qt::AlignCenter);
    setStyleSheet("border:1px solid #99999999;border-radius:1px;background-color:#55555555;color:gold;");
    setLayout(layout);
}

void CharTable::btnClicked(){
    emit onBtnClicked(this->letr);
}

void CharTable::btnLikeClicked(){
    if(this->isFav){
        fList.removeAll(this->letr);
        this->like_btn->setStyleSheet("font-size:15px;border:0px none black;background-color:#00000000;color:#ff999999;");
        this->isFav = false;
        saveStore("favourite");
    } else {
        fList.prepend(this->letr);
        this->like_btn->setStyleSheet("font-size:15px;border:0px none black;background-color:#00000000;color:#ff00ff00;");
        this->isFav = true;
        saveStore("favourite");
    }
}
