#include "mainwidget.h"

mainWidget::mainWidget(QWidget* a) : QWidget(a){this->center();}

mainWidget::~mainWidget(){}

void mainWidget::center(){
    int w=frameGeometry().width();
    int h=frameGeometry().height()+150;
    QDesktopWidget window;
    int sW=window.screen()->width();
    int sH=window.screen()->height();
    int x=((sW-w)/2);
    int y=((sH-h)/2);
    move(x,y);
}

