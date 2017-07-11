#include "viewreg.h"

viewReg::viewReg(mainWidget *a) : mainWidget(a)
{
    vLay = new QVBoxLayout;
    box = new QGroupBox;
    usrEdit = new QLineEdit;
    pswEdit = new QLineEdit;
    loadGraphic();
}


viewReg::~viewReg(){
    delete pswEdit;
    delete usrEdit;
    delete box;
    delete vLay;
}

void viewReg::closeEvent(QCloseEvent* event){
    emit signalClose();
    event->accept();
}


void viewReg::loadGraphic(){
    setWindowTitle("Registrazione");
    QVBoxLayout* nBox = new QVBoxLayout;

    QLabel* titleLabel = new QLabel;
    titleLabel->setText("QPedia");

    QLabel* usrLabel = new QLabel;
    usrLabel->setText("Username");

    QLabel* pswLabel = new QLabel;
    pswLabel->setText("Password");
    pswEdit->setEchoMode(QLineEdit::Password);

    QPushButton* backButton = new QPushButton("Indietro");
    QPushButton* regButton = new QPushButton("Registrazione Corso");
    QPushButton* regButtonStud = new QPushButton("Registrazione Studente");

    QWidget::setFixedHeight(300);
    QWidget::setFixedWidth(300);

    nBox->addWidget(titleLabel);
    nBox->addWidget(usrLabel);
    nBox->addWidget(usrEdit);
    nBox->addWidget(pswLabel);
    nBox->addWidget(pswEdit);
    nBox->addWidget(regButton);
    nBox->addWidget(regButtonStud);
    nBox->addWidget(backButton);
    box->setLayout(nBox);
    box->focusPolicy();
    vLay->addWidget(box);
    setLayout(vLay);
    connect(regButton,SIGNAL(clicked()),this,SLOT(reg()));
    connect(regButtonStud,SIGNAL(clicked()),this,SLOT(regStud()));
    connect(backButton,SIGNAL(clicked()),this,SLOT(delReg()));
}

void viewReg::reg(){
    if(usrEdit->text()==""||pswEdit->text()=="")
    {
        QMessageBox err;
        err.setText("Campi non compilati");
        err.exec();
    }
    else emit signalReg(usrEdit->text(),pswEdit->text());
}

void viewReg::regStud(){
    if(usrEdit->text()==""||pswEdit->text()=="")
    {
        QMessageBox err;
        err.setText("Campi non compilati");
        err.exec();
    }
    else emit signalRegStud(usrEdit->text(),pswEdit->text());
}

void viewReg::delReg(){
    emit signalClose();
}
