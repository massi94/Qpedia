#ifndef TUTOR_H
#define TUTOR_H

#include"student.h"

class tutor: public user
{
public:
    tutor();
    virtual void addNote(course&,note&);
};

#endif // TUTOR_H
