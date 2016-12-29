#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"

class student : public user
{
public:
    student();
    virtual course* findCourse(setCourses&,QString&);

};

#endif // STUDENT_H
