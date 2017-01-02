#ifndef DBONXML_H
#define DBONXML_H

#include<QXmlStreamWriter>
#include<QFile>
#include<iostream>

#include"dbio.h"
#include "list.h"
#include"note.h"
#include"definition.h"
#include"schema.h"
#include"source.h"
#include "setcourses.h"



class dbOnXml: public dbIO
{
private:
    QXmlStreamWriter wr;
    QXmlStreamReader re;
public:
    dbOnXml();

    virtual void writeDB(const setCourses &);
    virtual void loadDB(setCourses &);
};

#endif // DBONXML_H
