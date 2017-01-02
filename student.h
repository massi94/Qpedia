#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"

class student : public user
{
public:
    student();
    const course* findCourse(setCourses&,QString) const;
    void addNote(course&,note*);

};

#endif // STUDENT_H
