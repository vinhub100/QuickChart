#ifndef LEFTCHARTABLEBUTTON_H
#define LEFTCHARTABLEBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>

class LeftCharTableButton : public QWidget
{
    Q_OBJECT
    QPushButton *btn;
    QBoxLayout *layout;
    QString text,id;
public:
    explicit LeftCharTableButton(QString text, QString id, QWidget *parent = nullptr);

signals:
    void onBtnClicked(QString id);

public slots:
    void btnClicked();
};

#endif // LEFTCHARTABLEBUTTON_H
