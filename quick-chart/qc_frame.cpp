#include "qc_frame.h"

QC_Frame::QC_Frame(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
        setWindowOpacity(0.9);
        setStyleSheet("background-color: #222222;color:#999999;padding:0px;margin:0px;");

        QDesktopWidget *desktop = QApplication::desktop();
        int windowWidth = 600;
        int windowHeight = 500;
        int screenWidth = desktop->width();
        int screenHeight = desktop->height();
        setGeometry((screenWidth/2)-(windowWidth/2),
                    (screenHeight/2)-(windowHeight/2),
                    windowWidth,
                    windowHeight);


        QC_layout = new QVBoxLayout(this);
//        QC_layout->setSizeConstraint(QLayout::SetMinimumSize);

        button_container = new QWidget(this);
        button_container->setFixedHeight(40);
//        button_container->setFixedSize(600,50);

        button_container->setGeometry(0,0,600,50);

        top_btn_layout = new QHBoxLayout(button_container);

//        top_btn_layout->setSizeConstraint(QLayout::SetFixedSize);

        recent = new QPushButton("RECENT",button_container);
        recent->setFixedHeight(30);
        recent->setStyleSheet("color:skyblue;");
//        recent->setStyleSheet("color:#aaaaaa;");
        top_btn_layout->addWidget(recent);

        favourite = new QPushButton("FAVOURITE",button_container);
        favourite->setFixedHeight(30);
        top_btn_layout->addWidget(favourite);

        char_table = new QPushButton("CHART",button_container);
        char_table->setFixedHeight(30);
        top_btn_layout->addWidget(char_table);

        top_btn_grp = new QButtonGroup(this);
//        top_btn_grp->setExclusive(true);
        top_btn_grp->addButton(recent, 1);
        recent->setChecked(true);
        top_btn_grp->addButton(favourite, 2);
        top_btn_grp->addButton(char_table, 3);

        connect(top_btn_grp, SIGNAL(buttonClicked(int)), this, SLOT(btnClicked(int)));

        button_container->setLayout(top_btn_layout);

        QC_layout->addWidget(button_container);

        setLayout(QC_layout);

        this->showRecentPane();
        this->prev_action_pane_no = 1;
}



void QC_Frame::btnClicked(int id){
//    this->hide();

    if(this->prev_action_pane_no == 2){
        QC_layout->removeWidget(scrollarea);
        delete scrollarea;
        favourite->setStyleSheet("color:#aaaaaa;");
    } else if (this->prev_action_pane_no == 3) {
        QC_layout->removeWidget(charTableWidget);
        delete charTableWidget;
        char_table->setStyleSheet("color:#aaaaaa;");
    } else if(this->prev_action_pane_no == 1) {
        QC_layout->removeWidget(action_plane_container);
        delete action_plane_container;
        recent->setStyleSheet("color:#aaaaaa;");
    } else {}


    if(id == 2){
        favourite->setStyleSheet("color:skyblue;");
        this->showFavouritePane();
    } else if (id == 3) {
        char_table->setStyleSheet("color:skyblue;");
        this->showCharTablePane();
    } else {
        recent->setStyleSheet("color:skyblue;");
        this->showRecentPane();
    }

    this->prev_action_pane_no = id;
}

//void QC_Frame::createActionPaneContainer(){
//    action_plane_container = new QWidget(this);
//    action_plane_container->setFixedSize(600,450);
//    action_plane_container->setGeometry(0,50,600,450);
//    QC_layout->addWidget(action_plane_container);
//}

//void QC_Frame::removeActionPaneContainer(){
//    QC_layout->removeWidget(action_plane_container);
//    delete action_plane_container;
//}

void QC_Frame::recentBtnClicked(QString letr){
    this->hide();
    if(rList.contains(letr)){
        rList.removeAll(letr);
    }
    rList.prepend(letr);
    saveStore("recent");
    QC_layout->removeWidget(action_plane_container);
    delete action_plane_container;
    this->showRecentPane();
    cb->setText(letr,QClipboard::Clipboard);
    emit sendCtlVsignal();

}

void QC_Frame::favouriteBtnClicked(QString letr){
    this->hide();
    saveRecent(letr);
//    if(rList.contains(letr)){
//        rList.removeAll(letr);
//    }
//    rList.prepend(letr);
//    saveStore("recent");
    cb->setText(letr,QClipboard::Clipboard);
    emit sendCtlVsignal();
//    qDebug() << letr << "Fav Clicked" ;
//    qDebug() << "Call DBus to uinput Crl + v" ;
}

void QC_Frame::favouriteXBtnClicked(QString letr){
    fList.removeAll(letr);
    saveStore("favourite");
    QC_layout->removeWidget(scrollarea);
    delete scrollarea;
    this->showFavouritePane();
//    qDebug() << letr << " Fav X Clicked" ;
}

void QC_Frame::showRecentPane(){

    action_plane_container = new QWidget(this);
    action_plane_container->setFixedSize(600,450);
    action_plane_container->setGeometry(0,50,600,450);
    QC_layout->addWidget(action_plane_container);

    flow_action_plane = new FlowLayout(action_plane_container);


    for (int i =0;i < rList.length();i++) {
        recentBtn = new Recent(rList[i],this);
        connect(recentBtn,&Recent::onBtnClicked,this,&QC_Frame::recentBtnClicked);
        flow_action_plane->addWidget(recentBtn);
    }

    action_plane_container->setLayout(flow_action_plane);
}

void QC_Frame::showFavouritePane(){
    action_plane_container = new QWidget(this);

    flow_action_plane = new FlowLayout(action_plane_container);


    for (int i =0;i < fList.length();i++) {
        favBtn = new Favourite(fList[i],this);
        connect(favBtn,&Favourite::onBtnClicked,this,&QC_Frame::favouriteBtnClicked);
        connect(favBtn,&Favourite::onXBtnClicked,this,&QC_Frame::favouriteXBtnClicked);
        flow_action_plane->addWidget(favBtn);
    }

//    b1 = new QPushButton("⚽",action_plane_container);
//    b1->setFixedSize(100,100);
//    b1->setStyleSheet("font-size:60px;");
//    action_plane->addWidget(b1,1,1,Qt::AlignTop);

    action_plane_container->setLayout(flow_action_plane);
    scrollarea = new QScrollArea(this);
//    scrollarea->setStyleSheet("border: 1px solid #000000ff");
    scrollarea->setWidget(action_plane_container);
    scrollarea->setWidgetResizable(true);
    scrollarea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollarea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QC_layout->addWidget(scrollarea);
}

void QC_Frame::showCharTablePane(){


    charTableWidget = new CharTableWidget(this);
    // This is connected to favouriteBtnClicked because it does
    // same job for both Char Table Widget and Fav Widget
    connect(charTableWidget,&CharTableWidget::onChrTblBtnClicked,this,&QC_Frame::favouriteBtnClicked);

    QC_layout->addWidget(charTableWidget);
}

