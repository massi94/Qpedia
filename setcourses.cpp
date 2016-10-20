#include "setcourses.h"

setCourses::setCourses()
{

}


void setCourses::addCourse(course* c){
    courses.push_back(c);
}


list<course *> setCourses::getCourses() const{
    return courses;
}
