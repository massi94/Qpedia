#ifndef DBIO_H
#define DBIO_H

#include <QString>
#include <iostream>

#include "note.h"
#include "list.h"

class course;

class dbIO
{
public:
    dbIO();
    virtual void writeDB(QString, const list<const note*>&) =0;
    virtual void loadDB(QString, list<const note*>&) =0;

    virtual void writeCourse(const list<course*>&) =0;

};

#endif // DBIO_H
