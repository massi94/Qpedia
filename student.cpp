#include "student.h"

student::student()
{

}

course* student::findCourse(setCourses& sc,QString n){
    return sc.searchCourse(n);

}

void student::addNote(course& c,note* n){
    c.addNote(n);
}
