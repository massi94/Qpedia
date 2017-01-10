#ifndef TEACHER_H
#define TEACHER_H

#include"../model/student.h"

class teacher:public student
{
public:
    teacher();
    void createCourse(setCourses&, QString);
};

#endif // TEACHER_H
