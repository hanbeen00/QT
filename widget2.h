#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>


class widget2 : public QWidget
{
    Q_OBJECT
    QTimer *timer;
public:
    widget2(QWidget *parent = nullptr);
    ~widget2();
};

#endif // WIDGET2_H
