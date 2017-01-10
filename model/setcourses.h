#ifndef SETCOURSES_H
#define SETCOURSES_H

#include"../model/list.h"
#include"../model/course.h"

class setCourses
{
private:
    list<course *> courses;
public:
    setCourses();
    void addCourse(course *);

    list<course *> getCourses() const;
    course* searchCourse(QString c) const;

};

#endif // SETCOURSES_H
