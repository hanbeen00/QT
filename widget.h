#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QRadioButton;
class QButtonGroup;
class QCheckBox;
class QLabel;

class Widget : public QWidget
{
    Q_OBJECT
    QRadioButton * radioButton[4];
    QButtonGroup * buttonGroup;

    QCheckBox * checkBox[4];
    QButtonGroup * buttonGroup2;
    QLabel * label;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void slotQuit();
    void realQuit();
    void selectButton(int id);

signals:
    void dd();
};

#endif // WIDGET_H
