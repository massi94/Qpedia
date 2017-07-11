#ifndef SOURCE_H
#define SOURCE_H

#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QString>
#include <iostream>

#include "note.h"

//codice sorgente caratterizzato da un campo body e uno di definizione del linguaggio

class source:public note
{
private:
    QString language;
    QString body;
public:
    source(unsigned int=1, QString ="noTitolo", QDateTime=QDateTime::currentDateTime(), QDateTime=QDateTime::currentDateTime(), bool=false, QString = "noParent", QString ="noLinguaggio",QString = "noBody");

    QString getLanguage() const;
    QString getBody() const;

    void setLanguage(const QString&);
    void setBody(const QString&);

    virtual void saveNote(QXmlStreamWriter&) const;
};

#endif // SOURCE_H
