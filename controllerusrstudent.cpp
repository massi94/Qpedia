#include "controllerusrstudent.h"

controllerUsrStudent::controllerUsrStudent(dbOnXml * d, usrStudent * u, QObject * w):QObject(w),db(d),usr(u)
{
    usrView = new viewUserStudent(d,u);
    connect(usrView,SIGNAL(signalSave()),this,SLOT(saveNote()));
    connect(usrView,SIGNAL(signalLogout()),this,SLOT(closeUserStudentView()));
    connect(usrView,SIGNAL(signalEditUsrData(const QString&)),this,SLOT(modifyUsrStudent(const QString&)));
    connect(usrView,SIGNAL(signalSubscription(user*)),this,SLOT(subscribe(user*)));
    connect(usrView,SIGNAL(signalUnSubscription(const QString&)),this,SLOT(unSubscribe(const QString&)));
}

controllerUsrStudent::~controllerUsrStudent(){
    delete usrView;
}

void controllerUsrStudent::showUserStudentView() const{
    usrView->show();
}

void controllerUsrStudent::closeUserStudentView(){
    emit signalHome();
}

void controllerUsrStudent::modifyUsrStudent(const QString& p){
    QMessageBox msg;
    msg.setIcon(QMessageBox::Information);
    usr->setPsw(p);
    db->writeUser();
    msg.setText("Modifiche effettuate");
    msg.exec();
}

void controllerUsrStudent::saveNote() const{
    db->writeNote();
}

void controllerUsrStudent::subscribe(user * u){
    usr->subscribeCourse(dynamic_cast<usrCourse*>(u));
}

void controllerUsrStudent::unSubscribe(const QString& u){
    usr->unSubscribeCourse(u);
}
