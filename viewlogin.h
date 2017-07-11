#ifndef VIEWLOGIN_H
#define VIEWLOGIN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QLineEdit>

#include "dbonxml.h"
#include "mainwidget.h"

//componente grafica che permette l'inserimento delle credenziali per il login, o l'accesso nella sezione di registrazione

class viewLogin: public mainWidget{
    Q_OBJECT
private:
    QVBoxLayout* vLay;
    QGroupBox* box;
    QLineEdit* usrEdit;
    QLineEdit* pswEdit;
public:
    viewLogin(mainWidget* =0);
    ~viewLogin();
    virtual void loadGraphic();

public slots:
    void tryLogin();
    void openReg();
signals:
    void signalLogin(const QString&,const QString&);
    void signalReg();
};

#endif // VIEWLOGIN_H
