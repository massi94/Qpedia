#ifndef USER_H
#define USER_H

#include <QString>
#include "course.h"
#include "note.h"
#include "setcourses.h"

class user
{
private:
    QString username;
    QString password;
public:
    user();
    void setUsername(QString&);
    void setPassword(QString&);
    bool login(QString&, QString&);

    virtual ~user();

};

#endif // USER_H
