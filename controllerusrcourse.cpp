#include "controllerusrcourse.h"

controllerUsrCourse::controllerUsrCourse(dbOnXml * d, usrCourse * u, QObject *aux): QObject(aux), db(d),usr(u){
    usrView = new viewUserCourse(u);
    connect(usrView,SIGNAL(signalSave()),this,SLOT(saveNote()));
    connect(usrView,SIGNAL(signalLogout()),this,SLOT(closeUserCourseView()));
    connect(usrView,SIGNAL(signalWriteDef(const QString&,const QString&)),this,SLOT(writeDefinition(const QString&,const QString&)));
    connect(usrView,SIGNAL(signalEditDef(const uint&,const QString&,const QString&)),this,SLOT(editDefinition(const uint&,const QString&,const QString&)));
    connect(usrView,SIGNAL(signalWriteSour(const QString&,const QString&,const QString&)),this,SLOT(writeSource(const QString&,const QString&,const QString&)));
    connect(usrView,SIGNAL(signalEditSour(const uint&,const QString&,const QString&,const QString&)),this,SLOT(editSource(const uint&,const QString&,const QString&,const QString&)));
    connect(usrView,SIGNAL(signalClearNote(const uint&)),this,SLOT(clearNote(const uint&)));
    connect(usrView,SIGNAL(signalEditUsrData(const QString&)),this,SLOT(modifyUsrCourse(const QString&)));
}

controllerUsrCourse::~controllerUsrCourse(){
    delete usrView;
}

void controllerUsrCourse::showUserCourseView() const{
    usrView->show();
}

void controllerUsrCourse::closeUserCourseView(){
    emit signalHome();
}

void controllerUsrCourse::modifyUsrCourse(const QString & p){
    QMessageBox msg;
    msg.setIcon(QMessageBox::Information);
    usr->setPsw(p);
    db->writeUser();
    msg.setText("Modifiche effettuate");
    msg.exec();
}

void controllerUsrCourse::saveNote()const{
    db->writeNote();
}

void controllerUsrCourse::clearNote(const unsigned int& id){
    usr->clearNote(id);
}

void controllerUsrCourse::writeDefinition(const QString &t, const QString &d){
    definition* nDef = new definition(db->getCurrentId(),t,QDateTime::currentDateTime(),QDateTime::currentDateTime(),false,usr->getUsr(),d);
    usr->addNote(nDef);
}

void controllerUsrCourse::writeSource(const QString& t, const QString& l, const QString& b){
    source* nSour = new source(db->getCurrentId(),t,QDateTime::currentDateTime(),QDateTime::currentDateTime(),false,usr->getUsr(),l,b);
    usr->addNote(nSour);
}

void controllerUsrCourse::editDefinition(const unsigned int& id, const QString& t, const QString& d){
    usr->editDefinition(id,t,d);
}

void controllerUsrCourse::editSource(const unsigned int& id, const QString& t, const QString& l,const  QString& b){
    usr->editSource(id,t,l,b);
}


