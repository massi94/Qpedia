#include "tutor.h"

tutor::tutor()
{

}


void tutor::addNote(course& c,note& n){
    c.addNote(&n);
}
