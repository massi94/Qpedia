#ifndef USER_H
#define USER_H

#include <QString>
#include"../model/course.h"
#include"../model/note.h"
#include"../model/setcourses.h"

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
