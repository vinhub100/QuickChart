#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>

#include <QIcon>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QRect>
#include <QButtonGroup>
#include <QPushButton>
#include <iostream>
#include <QSizePolicy>

#include <QMenu>
#include <QScrollArea>
#include <QClipboard>

#include "recent.h"
#include "favourite.h"
#include "chartable.h"
#include "chartablewidget.h"
#include "flowlayout.h"
#include "common.h"

using namespace std;

class QC_Frame : public QWidget
{
    Q_OBJECT

    int prev_action_pane_no;

    QVBoxLayout *QC_layout;
    QHBoxLayout *top_btn_layout;
    QGridLayout *action_plane;
    FlowLayout *flow_action_plane;
    QWidget *button_container, *action_plane_container;
    QButtonGroup *top_btn_grp;
    QPushButton *recent, *favourite, *char_table;
    QPushButton *b1,*b2,*b3,*b4,*b5,*b41,*b21,*b31,*b51;
    Recent *recentBtn;
    Favourite *favBtn;
    CharTableWidget *charTableWidget;
    QScrollArea *scrollarea;



public:
    QClipboard *cb;

    QC_Frame(QWidget *parent = nullptr);
    void showRecentPane();
    void showFavouritePane();
    void showCharTablePane();
    void createActionPaneContainer();
    void removeActionPaneContainer();
public slots:
    void btnClicked(int id);
    void recentBtnClicked(QString letr);
    void favouriteBtnClicked(QString letr);
    void favouriteXBtnClicked(QString letr);

signals:
    void sendCtlVsignal(void);

};

#endif // WIDGET_H


//🐈🐜🐒🐞🐇🐄🏡⛄🍌🎶🚂∫₹

