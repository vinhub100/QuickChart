#ifndef FAVOURITE_H
#define FAVOURITE_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class Favourite : public QWidget
{
    Q_OBJECT

    QGridLayout *layout;
    QPushButton *btn, *x_btn;
    QString letr;



public:
    Favourite(QString cha, QWidget *parent = nullptr);
//    ~Favourite();

signals:
    void onBtnClicked(QString letr);
    void onXBtnClicked(QString letr);
public slots:
    void btnClicked();
    void btnXClicked();
};

#endif // FAVOURITE_H
