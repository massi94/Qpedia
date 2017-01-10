#ifndef DBIO_H
#define DBIO_H

#include <QString>
#include <iostream>


#include "../model/setcourses.h"


class dbIO
{
public:
    dbIO();
    virtual void writeDB(const setCourses &) =0;
    virtual void loadDB(setCourses &) =0;
};

#endif // DBIO_H
