#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"

class student : public user
{
public:
    student();
    course* findCourse(setCourses&,QString);
    void addNote(course&,note*);

};

#endif // STUDENT_H
