#ifndef DEFINITION_H
#define DEFINITION_H

#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QString>
#include <iostream>

#include "note.h"

//definizione caratterizzata da un campo descrizione

class definition: public note
{
private:
    QString description;
public:
    definition(unsigned int=1, QString ="noTitolo", QDateTime=QDateTime::currentDateTime(), QDateTime=QDateTime::currentDateTime(), bool=false,QString = "noParent", QString ="noDescrizione");

    QString getDescription() const;

    void setDescription(const QString&);

    void saveNote(QXmlStreamWriter&) const;
};

#endif // DEFINITION_H
