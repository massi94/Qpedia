#include <QApplication>

#include "dbonxml.h"
#include "viewlogin.h"
#include "controllerlogin.h"

#include "iostream"

#include "viewcourselist.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dbOnXml db;
    /*
    std::cout<<"inizio";
    std::cout<<"ciao";
    std::cout<<((db.searchUser("fabio"))->getUsr()).toStdString();

    usrCourse * f = dynamic_cast<usrCourse*>(db.searchUser("fabio"));
    definition * d = new definition();
    source *s = new source();
    f->addNote(d);
    f->addNote(s);

    db.writeUser();
    db.writeNote();
*/
    viewLogin login;
    controllerLogin controller(&db,&login);

    return a.exec();
}
