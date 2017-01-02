#ifndef DBIO_H
#define DBIO_H

#include <QString>
#include <iostream>


#include "setcourses.h"


class dbIO
{
public:
    dbIO();
    virtual void writeDB(const setCourses &) =0;
    //virtual void loadDB(QString, setCourses &) =0;
};

#endif // DBIO_H
