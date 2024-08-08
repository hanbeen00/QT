#include "widget2.h"
#include <QLCDNumber>
#include <QProgressBar>
#include <QTimer>


widget2::widget2(QWidget *parent)
    : QWidget{parent}
{

    QLCDNumber *lcd = new QLCDNumber(this);
    lcd->setBinMode();
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->display(15);

    QProgressBar * progBar = new QProgressBar(this);
    progBar->move(10,40);
    //progBar->setValue(20);
    //progBar->setInvertedAppearance(true);

    timer = new QTimer(this);
    static int n=0;
    connect(timer,&QTimer::timeout,[=](){progBar->setValue(n++%101);});
    timer->start(100);

}

widget2::~widget2() {}
