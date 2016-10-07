#ifndef DEFINITION_H
#define DEFINITION_H

#include"note.h"
#include"dbio.h"

class definition : public note
{
private:
    QString description;
public:
    definition(QString="noTitolo",QString="noDescrizione");

    QString getDescription() const;

    void setDescription(const QString&);

    QString getType() const;
    virtual void saveNote() const;

};

#endif // DEFINITION_H
