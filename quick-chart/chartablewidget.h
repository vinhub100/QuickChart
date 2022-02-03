#ifndef CHARTABLEWIDGET_H
#define CHARTABLEWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QScrollArea>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "common.h"
#include "chartable.h"
#include "leftchartablebutton.h"
#include "flowlayout.h"

class CharTableWidget : public QWidget
{
    Q_OBJECT

    QHBoxLayout *layout;
    QVBoxLayout *leftPaneLayout;
    FlowLayout *rightPaneLayout;
    QScrollArea *leftscrollarea,*rightscrollarea;
//    QMenu *menu;
    QWidget *leftPane, *rightPane;

public:
    CharTableWidget(QWidget *parent = nullptr);
    void createRightPane(QString key);

public slots:
    void leftPaneBtnClicked(QString str);
    void rightPaneBtnClicked(QString letr);

signals:
    void onChrTblBtnClicked(QString letr);

};

#endif // CHARTABLEWIDGET_H
