#ifndef DBIO_H
#define DBIO_H

#include <QFile>
#include <QString>
#include <iostream>

#include "course.h"
#include "note.h"
#include "list.h"
#include "dbonxml.h"

class dbIO
{
private:
    dbOnXml file;
public:
    dbIO();
    void writeDB(const QString&, const list<const note*>&);
    list<const note*> loadDB(const QString&) const;
};

#endif // DBIO_H
