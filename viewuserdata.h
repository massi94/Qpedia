#ifndef VIEWUSERDATA_H
#define VIEWUSERDATA_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QCloseEvent>

#include "user.h"
#include "mainwidget.h"

//componente grafica che permette la modifica della password dell'utente

class viewUserData : public mainWidget{
    Q_OBJECT
private:
    QLineEdit* usrEdit;
    QLineEdit* pswEdit;
    const user* usrData;
    QVBoxLayout* vLay;
public:
    viewUserData(const user* =0, mainWidget* =0);
    ~viewUserData();

    virtual void loadGraphic();
public slots:
    void saveMod();
    void cancelMod();
    void closeEvent(QCloseEvent*);
signals:
    void signalSaveMod(const QString&);
    void signalCancelMod();
};

#endif // VIEWUSERDATA_H
