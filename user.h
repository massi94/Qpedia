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

    virtual course* findCourse(setCourses&,QString&) =0;
    virtual void addNote(course&, note&) =0;
    virtual void createCourse(setCourses&, QString &) =0;

};

#endif // USER_H
