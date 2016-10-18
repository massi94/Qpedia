#ifndef DBONXML_H
#define DBONXML_H

#include<QXmlStreamWriter>
#include<QFile>

#include"dbio.h"

class dbOnXml: public dbIO
{
private:
    QXmlStreamWriter wr;
public:
    dbOnXml();

    virtual void writeDB(QString, const list<const note*>&);
    virtual void loadDB() const;
};

#endif // DBONXML_H
