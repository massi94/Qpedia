#include "controllerlogin.h"

controllerLogin::controllerLogin(dbOnXml* db,viewLogin* vL, controllerUsrCourse* cUC, QObject* w): QObject(w), usrDB(db),usrCourCont(cUC),loginView(vL)
{
    vL->show();
    connect(loginView,SIGNAL(signalLogin(const QString&, const QString&)),this,SLOT(checkData(const QString&,const QString&)));
    connect(loginView,SIGNAL(signalReg()),this,SLOT(openReg()));
}

void controllerLogin::checkData(const QString & usr, const QString & psw){
//controllo se esiste l'utente
    if(usrDB->searchUser(usr))
    {
        usrCourse* aux = dynamic_cast<usrCourse*>(usrDB->searchUser(usr));
        //controllo se l'utente è un Corso
        if(aux){
            if(aux->getPsw()==psw){
                usrCourCont = new controllerUsrCourse(usrDB,aux);
                connect(usrCourCont,SIGNAL(signalHome()),this,SLOT(openNote()));
                loginView->hide();
                usrCourCont->showUserCourseView();
            }
            else
            {
                QMessageBox msg;
                msg.setIcon(QMessageBox::Information);
                msg.setText("Password non corretta");
                msg.exec();
            }
        }
        //altrimenti l'utente è uno studente
        else{
            usrStudent * stud = dynamic_cast<usrStudent*>(usrDB->searchUser(usr));
            if(stud->getPsw()==psw){
                usrStudCont = new controllerUsrStudent(usrDB,stud);
                connect(usrStudCont,SIGNAL(signalHome()),this,SLOT(openNote()));
                loginView->hide();
                usrStudCont->showUserStudentView();
            }
            else
            {
                QMessageBox msg;
                msg.setIcon(QMessageBox::Information);
                msg.setText("Password non corretta");
                msg.exec();
            }
        }
    }
    else
    {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Information);
        msg.setText("Username non corretta");
        msg.exec();
    }
}

void controllerLogin::openReg()
{
    regView = new viewReg;
    loginView->hide();
    regView->show();
    connect(regView,SIGNAL(signalReg(const QString&,const QString&)),this,SLOT(writeUsrCourse(const QString&,const QString&)));
    connect(regView,SIGNAL(signalRegStud(const QString&,const QString&)),this,SLOT(writeUsrStudent(const QString&,const QString&)));
    connect(regView,SIGNAL(signalClose()),this,SLOT(closeReg()));
}

void controllerLogin::openNote()
{
    if(usrCourCont)
    {
        delete usrCourCont;
        usrCourCont=0;
        loginView->show();
    }
    else{
        delete usrStudCont;
        usrStudCont=0;
        loginView->show();
    }
}

void controllerLogin::writeUsrCourse(const QString& usr,const QString& psw)
{
    QMessageBox msg;
    msg.setIcon(QMessageBox::Information);
    if(!usrDB->searchUser(usr)){
        usrCourse* newUsrCour= new usrCourse(usr,psw);
        usrDB->addUser(newUsrCour);
        usrDB->writeUser();
        msg.setText("Registrazione corso effettuata con Successo");
        msg.exec();
        closeReg();
    }
    else
    {
        msg.setText("Username già presente");
        msg.exec();
    }
}

void controllerLogin::writeUsrStudent(const QString& usr,const QString& psw)
{
    QMessageBox msg;
    msg.setIcon(QMessageBox::Information);
    if(!usrDB->searchUser(usr)){
        usrStudent* newUsrCour= new usrStudent(usr,psw);
        usrDB->addUser(newUsrCour);
        usrDB->writeUser();
        msg.setText("Registrazione studente effettuata con Successo");
        msg.exec();
        closeReg();
    }
    else
    {
        msg.setText("Username già presente");
        msg.exec();
    }
}


void controllerLogin::closeReg()
{
    regView->hide();
    delete regView;
    loginView->show();
}
