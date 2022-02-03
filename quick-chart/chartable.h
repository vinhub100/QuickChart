#ifndef CHARTABLE_H
#define CHARTABLE_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include "common.h"

class CharTable : public QWidget
{
    Q_OBJECT
    QGridLayout *layout;
    QPushButton *btn, *like_btn;
    QString letr;
    bool isFav;

public:
    CharTable(QString cha, QWidget *parent = nullptr);

signals:
    void onBtnClicked(QString letr);

public slots:
    void btnClicked();
    void btnLikeClicked();
};

#endif // CHARTABLE_H
