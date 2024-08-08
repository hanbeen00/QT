#include "widget.h"
#include <QPushButton>
#include <QApplication>
#include <QButtonGroup>
#include <QRadioButton>
#include <QCheckBox>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton("QUIT",this);
    quit->resize(75,35);
    quit->move(10,70);



    //connect(quit,SIGNAL(clicked(bool)),this,SLOT(slotQuit()));
    //connect(quit,&QPushButton::clicked,this,[](){qDebug("slot Quit"); qApp->quit();});

    // QPushButton의 clicked 시그널을 Widget의 slotQuit 슬롯에 연결
    connect(quit,SIGNAL(clicked()),this,SLOT(slotQuit()));

    // Widget의 dd 시그널을 Widget의 realQuit 슬롯에 연결
    connect(this,SIGNAL(dd()),this,SLOT(realQuit()));

    buttonGroup = new QButtonGroup(this);
    for(int i =0;i<4;i++){
        QString str = QString("RadioButton%1").arg(i+1);
        radioButton[i] = new QRadioButton(str, this);
        radioButton[i]->move(10,120+20*i);
        buttonGroup->addButton(radioButton[i]);
    }

    buttonGroup2 = new QButtonGroup(this);
    for(int i =0;i<4;i++){
        QString str = QString("CheckBox%1").arg(i+1);
        checkBox[i] = new QCheckBox(str, this);
        checkBox[i]->move(10,200+20*i);
        buttonGroup2->addButton(checkBox[i]);
    }
    buttonGroup2->setExclusive(false);
    connect(buttonGroup2,SIGNAL(idClicked(int)),this,SLOT(selectButton(int)));

    label = new QLabel("hello",this);
    label->resize(75,35);
    label->move(0,300);
}

Widget::~Widget() {}


void Widget::slotQuit(){
    qDebug("slot Quit");

    // dd 시그널 방출 - 연결된 realQuit 슬롯을 호출
    emit dd();
}

void Widget::realQuit(){
    qDebug("real Quit");
    qApp->quit();
}

void Widget::selectButton(int id){
    QButtonGroup *buttonGroup = (QButtonGroup*)sender();
    QCheckBox * button = (QCheckBox *)buttonGroup->button(id);
    qDebug("CheckBox%d is selected(%s)",-(id+1),(button->isChecked())?"On":"Off");
    label->setText(QString::number(-(id + 1)));
}
