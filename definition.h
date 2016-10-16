#ifndef DEFINITION_H
#define DEFINITION_H

#include"note.h"
#include"dbio.h"
#include"dbnoteio.h"

class definition : public note
{
private:
    QString description;
public:
    definition(QString="noTitolo",QString="noDescrizione");

    QString getDescription() const;

    void setDescription(const QString&);

    QString getType() const;
    virtual void saveNote(dbOnXml&) const;

};

#endif // DEFINITION_H

