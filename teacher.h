#ifndef TEACHER_H
#define TEACHER_H

#include "tutor.h"

class teacher:public tutor
{
public:
    teacher();
    virtual void createCourse(setCourses&, QString&);
};

#endif // TEACHER_H
