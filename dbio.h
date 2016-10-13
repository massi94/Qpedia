#ifndef DBIO_H
#define DBIO_H

#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QString>
#include <iostream>

#include "course.h"
#include "note.h"
#include "list.h"

class dbIO
{
public:
    dbIO();
    void writeDB(const QString&, const list<const note*>&) const;
    list<const note*> loadDB(const QString&) const;



};

#endif // DBIO_H
