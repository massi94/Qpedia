#ifndef DBIO_H
#define DBIO_H

#include <QString>
#include <iostream>

#include "course.h"
#include "note.h"
#include "list.h"

class dbIO
{
public:
    dbIO();
    virtual void writeDB(QString, const list<const note*>&) =0;
    virtual void loadDB() const =0;
};

#endif // DBIO_H
