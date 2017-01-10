#ifndef DBONXML_H
#define DBONXML_H

#include<QXmlStreamWriter>
#include<QFile>
#include<iostream>

#include"../model/dbio.h"
#include"../model/list.h"
#include"../model/note.h"
#include"../model/definition.h"
#include"../model/schema.h"
#include"../model/source.h"
#include"../model/setcourses.h"



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
