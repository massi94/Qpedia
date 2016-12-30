#ifndef TUTOR_H
#define TUTOR_H

#include"student.h"

class tutor: public student
{
public:
    tutor();
    virtual void addNote(course&,note&);
};

#endif // TUTOR_H
