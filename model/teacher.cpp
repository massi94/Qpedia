#include "../model/teacher.h"

teacher::teacher()
{

}

void teacher::createCourse(setCourses& cour,QString name){
    cour.addCourse(new course(name));
}
