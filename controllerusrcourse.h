#ifndef CONTROLLERUSRCOURSE_H
#define CONTROLLERUSRCOURSE_H

#include"viewusercourse.h"
#include"usrcourse.h"
#include"dbonxml.h"

//controller UsrCourse, esegue i controlli per le operazioni di: visualizzazione, aggiunta, modifica, eliminazione di note, modifica utente
//si occupa di far eseguire le componenti grafiche

class controllerUsrCourse: public QObject{
    Q_OBJECT
private:
    dbOnXml* db;
    usrCourse* usr;
    viewUserCourse* usrView;
public:
    controllerUsrCourse(dbOnXml*, usrCourse*, QObject* =0);
    ~controllerUsrCourse();
    void showUserCourseView() const;
public slots:
    void closeUserCourseView();
    void modifyUsrCourse(const QString&);

    void saveNote() const;
    void clearNote(const unsigned int&);

    void writeDefinition(const QString&, const QString&);
    void writeSource(const QString&,const QString&, const QString&);

    void editDefinition(const unsigned int&, const QString&, const QString&);
    void editSource(const unsigned int&, const QString&, const QString&, const QString&);
signals:
    void signalHome();
};

#endif // CONTROLLERUSRCOURSE_H
