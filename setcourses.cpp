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


course* setCourses::searchCourse(QString c) const{
    list<course *>::iterator it;
    for(it=courses.begin();it!=courses.end();it++)
    {
        if(courses[it]->getMateria()==c)
            return courses[it];
    }

}

void setCourses::saveCourses(dbIO& save){
    save.writeCourse(courses);
}

void setCourses::loadCourses(dbIO&){

}
