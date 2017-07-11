#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QDesktopWidget>

//classe grafica madre, utilizzata come base per le operazioni di centramento dei vari widget utilizzati

class mainWidget : public QWidget {
    Q_OBJECT
private:
    void center();
public:
    mainWidget(QWidget* =0);
    virtual ~mainWidget();
    virtual void loadGraphic() =0;
};

#endif // MAINWIDGET_H
