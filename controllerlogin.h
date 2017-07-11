#ifndef CONTROLLERLOGIN_H
#define CONTROLLERLOGIN_H

#include <QObject>
#include <QMessageBox>

#include "dbonxml.h"
#include "viewlogin.h"
#include "viewreg.h"
#include "controllerusrcourse.h"
#include "controllerusrstudent.h"

//Controller login, esegui i controlli per verificare che l'utente inserito è corso o studente

class controllerLogin: public QObject{
    Q_OBJECT
private:
    dbOnXml* usrDB;
    controllerUsrCourse* usrCourCont;
    controllerUsrStudent* usrStudCont;
    viewLogin* loginView;
    viewReg* regView;
public:
    controllerLogin(dbOnXml*,viewLogin* =0, controllerUsrCourse* =0, QObject* =0);
public slots:
    void checkData(const QString&, const QString&);
    void openReg();
    void openNote();
    void writeUsrCourse(const QString&, const QString&);
    void writeUsrStudent(const QString&, const QString&);
    void closeReg();
};

#endif // CONTROLLERLOGIN_H
