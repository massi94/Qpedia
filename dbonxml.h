#ifndef DBONXML_H
#define DBONXML_H

#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QString>
#include <iostream>
#include <QVector>

#include "user.h"
#include "note.h"
#include "usrcourse.h"
#include "usrstudent.h"

//si occupa del salvataggio su file degli utenti e delle note

class dbOnXml
{
private:
    QVector<const user*> allUser;
public:
    dbOnXml();
    ~dbOnXml();

    void addUser(const user*);
    user* searchUser(const QString &) const;

    void readUser();
    void writeUser()const;

    void readNote();
    void writeNote() const;

    QVector<const usrCourse*> getUsrCourse() const;

    int getCurrentId() const;

};

#endif // DBONXML_H
