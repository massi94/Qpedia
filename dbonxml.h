#ifndef DBONXML_H
#define DBONXML_H

#include<QXmlStreamWriter>
#include<QFile>

#include"dbio.h"
#include"note.h"
#include"definition.h"
#include"schema.h"
#include"source.h"



class dbOnXml: public dbIO
{
private:
    QXmlStreamWriter wr;
    QXmlStreamReader re;
public:
    dbOnXml();

    virtual void writeDB(QString, const list<const note*>&);
    virtual void loadDB(QString, list<const note*>&);

    virtual void writeCourse(const list<course*>&);
};

#endif // DBONXML_H
