#include "viewuserdata.h"

viewUserData::viewUserData(const user* u, mainWidget* w): mainWidget(w), usrData(u)
{
    usrEdit = new QLineEdit(u->getUsr());
    usrEdit->setReadOnly(true);
    pswEdit = new QLineEdit(u->getPsw());
    vLay = new QVBoxLayout;
    loadGraphic();
}

viewUserData::~viewUserData(){
    delete usrEdit;
    delete pswEdit;
    delete vLay;
}

void viewUserData::loadGraphic(){
    setWindowTitle("Modifica account");
    QLabel* usr= new QLabel("Username");
    QLabel* psw= new QLabel("Password");
    QPushButton* saveModButton = new QPushButton("Salva");
    QPushButton* cancelModButton = new QPushButton("Annulla");

    vLay->addWidget(usr);
    vLay->addWidget(usrEdit);
    vLay->addWidget(psw);
    vLay->addWidget(pswEdit);
    vLay->addWidget(saveModButton);
    vLay->addWidget(cancelModButton);
    setLayout(vLay);

    connect(saveModButton,SIGNAL(clicked()),this,SLOT(saveMod()));
    connect(cancelModButton,SIGNAL(clicked()),this,SLOT(cancelMod()));
}

void viewUserData::saveMod()
{
    emit signalSaveMod(pswEdit->text());
}

void viewUserData::cancelMod(){emit signalCancelMod();}

void viewUserData::closeEvent(QCloseEvent* event){
    emit signalCancelMod();
    event->accept();
}
