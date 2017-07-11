#ifndef USRCOURSE_H
#define USRCOURSE_H


#include<QDateTime>

#include "user.h"
#include"note.h"
#include "source.h"
#include "definition.h"

//utente che ha la possibilità di creare nuove note, modificarle, o eliminarle, marcandole, volendo, come preferite

class usrCourse: public user
{
private:
    QVector<const note*> dbNote;
public:
    usrCourse(QString,QString);

    QVector<const note*> getNote() const;
    QVector<const note*> getDefinition() const;
    QVector<const note*> getSource() const;
    QVector<const note*> getFavourites() const;

    virtual void saveUser(QXmlStreamWriter&) const;
    virtual void writeOnDb(QXmlStreamWriter &) const;

    void resetNote();

    void addNote(const note*);

    void editDefinition(const unsigned int&, const QString&, const QString&);
    void editSource(const unsigned int&, const QString&, const QString&,const QString&);

    virtual const note* searchNote(const unsigned int&) const;

    void clearNote(const unsigned int&);
};

#endif // USRCOURSE_H
