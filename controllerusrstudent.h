#ifndef CONTROLLERUSRSTUDENT_H
#define CONTROLLERUSRSTUDENT_H

#include "viewuserstudent.h"
#include "usrstudent.h"
#include "dbonxml.h"

//controller usrStudent, esegue i controlli per la visualizzazione delle note, modifica utente, e le iscrizioni ai corsi

class controllerUsrStudent: public QObject{
    Q_OBJECT
private:
    dbOnXml* db;
    viewUserStudent * usrView;
    usrStudent* usr;
public:
    controllerUsrStudent(dbOnXml* =0, usrStudent* =0, QObject* =0);
    ~controllerUsrStudent();
    void showUserStudentView() const;
public slots:    
    void closeUserStudentView();
    void modifyUsrStudent(const QString&);

    void saveNote() const;

    void subscribe(user *);
    void unSubscribe(const QString&);
signals:
    void signalHome();
};

#endif // CONTROLLERUSRSTUDENT_H
