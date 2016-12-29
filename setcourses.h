#ifndef SETCOURSES_H
#define SETCOURSES_H

#include"list.h"
#include"course.h"
#include"dbio.h"

class setCourses
{
private:
    list<course *> courses;
public:
    setCourses();
    void addCourse(course *);

    list<course *> getCourses() const;
    course* searchCourse(QString c) const;

    void saveCourses(dbIO&);
    void loadCourses(dbIO&);
};

#endif // SETCOURSES_H
