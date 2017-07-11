#ifndef USER_H
#define USER_H

#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QString>
#include <QVector>
#include <iostream>
#include <note.h>

//classe base per gli utenti, caratterizzati da username e password

class user
{
private:
    QString usr;
    QString psw;
public:
    user(QString,QString);
    virtual ~user();

    QString getUsr() const;
    QString getPsw() const;

    void setUsr(const QString&);
    void setPsw(const QString&);

    virtual void saveUser(QXmlStreamWriter&) const =0;
    virtual void writeOnDb(QXmlStreamWriter &) const =0;
    virtual const note* searchNote(const unsigned int&) const =0;

};

#endif // USER_H
