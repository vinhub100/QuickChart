#ifndef RECENT_H
#define RECENT_H

#include <QDebug>

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>

class Recent : public QWidget
{
    Q_OBJECT

    QBoxLayout *layout;
    QPushButton *btn;
    QString letr;

public:
    Recent(QString cha, QWidget *parent = nullptr);
public slots:
    void btnClicked();
signals:
    void onBtnClicked(QString letr);



//    ~Recent();
};

#endif // RECENT_H
