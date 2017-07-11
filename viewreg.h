#ifndef VIEWREG_H
#define VIEWREG_H


#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QLineEdit>
#include <QMessageBox>
#include <iostream>
#include <QCloseEvent>

#include "mainwidget.h"

//componente grafica che permette la registrazione dell'utente come studente o come corso

class viewReg : public mainWidget {
    Q_OBJECT
private:
    QVBoxLayout* vLay;
    QGroupBox* box;
    QLineEdit* usrEdit;
    QLineEdit* pswEdit;
public:
    viewReg(mainWidget* =0);
    ~viewReg();
    void closeEvent(QCloseEvent*);
    virtual void loadGraphic();
public slots:
    void reg();
    void regStud();
    void delReg();
signals:
    void signalReg(const QString&, const QString&);
    void signalRegStud(const QString&, const QString&);
    void signalClose();
};

#endif // VIEWREG_H
