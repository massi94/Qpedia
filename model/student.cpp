#include "../model/student.h"

student::student()
{

}

const course* student::findCourse(setCourses& sc,QString n) const{
    return sc.searchCourse(n);

}

void student::addNote(course& c,note* n){
    c.addNote(n);
}
