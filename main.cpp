#include "widget.h"
#include "widget2.h"

#include <QApplication>
#include <QLabel>
#include <QPushButton>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;

    QLabel hello("hello",&w);
    hello.resize(75,35);
    QPushButton qquit("&QUIT",&w);
    qquit.setCheckable(true);
    qquit.move(10,40);
    qquit.resize(75,35);
    QObject::connect(&qquit, &QPushButton::clicked, &hello,[&](){hello.setText("changed text");});
    w.show();


    QPushButton quit("QUIT",nullptr);
    quit.resize(75,35);
    quit.move(50,70);
    quit.show();
    QObject::connect(&quit,SIGNAL(clicked(bool)),&a,SLOT(quit()));


    widget2 w2;
    w2.show();


    return a.exec();
}
