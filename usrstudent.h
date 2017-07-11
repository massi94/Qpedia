#ifndef USRSTUDENT_H
#define USRSTUDENT_H

#include "user.h"
#include "usrcourse.h"
#include "note.h"
#include "source.h"
#include "definition.h"
#include "dbonxml.h"

//utente che ha la possibilità di visionare le note inserite dai vari corsi, potendo gestire la visione di queli corsi seguire

class usrStudent: public user
{
private:
    QVector<const usrCourse*> course;

public:
    usrStudent(QString,QString);

    void subscribeCourse(const usrCourse*);
    void unSubscribeCourse(const QString&);

    QVector<const usrCourse*> getCourses() const;

    QVector<const note*> getAllNotes()const;
    QVector<const note*> getAllDefinitions()const;
    QVector<const note*> getAllSources()const;
    QVector<const note*> getAllFavourites()const;



    virtual void saveUser(QXmlStreamWriter&) const;
    virtual void writeOnDb(QXmlStreamWriter &) const;

    virtual const note* searchNote(const unsigned int&) const;

    bool isSubscribed(const QString &) const;
};

#endif // USRSTUDENT_H
