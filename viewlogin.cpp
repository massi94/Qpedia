#include "viewlogin.h"

viewLogin::viewLogin(mainWidget* a): mainWidget(a)
{
    vLay = new QVBoxLayout;
    box = new QGroupBox;
    usrEdit = new QLineEdit;
    pswEdit = new QLineEdit;
    loadGraphic();
}

viewLogin::~viewLogin()
{
    delete usrEdit;
    delete pswEdit;
    delete box;
    delete vLay;
}

void viewLogin::loadGraphic(){
    setWindowTitle("Login");
    QVBoxLayout* nBox = new QVBoxLayout;

    QLabel* titleLabel = new QLabel;
    titleLabel->setText("QPedia");

    QLabel* usrLabel = new QLabel;
    usrLabel->setText("Username");

    QLabel* pswLabel = new QLabel;
    pswLabel->setText("Password");
    pswEdit->setEchoMode(QLineEdit::Password);

    QPushButton* loginButton = new QPushButton("Login");
    QPushButton* regButton = new QPushButton("Registrazione");

    QWidget::setFixedHeight(250);
    QWidget::setFixedWidth(300);

    nBox->addWidget(titleLabel);
    nBox->addWidget(usrLabel);
    nBox->addWidget(usrEdit);
    nBox->addWidget(pswLabel);
    nBox->addWidget(pswEdit);
    nBox->addWidget(loginButton);
    nBox->addWidget(regButton);
    box->setLayout(nBox);
    box->focusPolicy();
    vLay->addWidget(box);
    setLayout(vLay);
    connect(loginButton,SIGNAL(clicked()),this,SLOT(tryLogin()));
    connect(regButton,SIGNAL(clicked()),this,SLOT(openReg()));
}

void viewLogin::tryLogin(){
    emit signalLogin(usrEdit->text(),pswEdit->text());
}

void viewLogin::openReg(){
    emit signalReg();
}

