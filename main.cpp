#include "mainwindow.h"
#include <QApplication>
#include "list.h"
#include "course.h"
#include "definition.h"
#include <iostream>
#include "setcourses.h"
#include "dbonxml.h"

int main(int argc, char *argv[])
{
/*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
*/
    dbOnXml sav;
    setCourses aa16;
    list<course*>::iterator it;
    list<const note*>::iterator it2;

    course prog("PAO");
    definition d;
    schema s;
    source b;
    definition g;

    prog.addNote(&d);
    prog.addNote(&s);
    prog.addNote(&b);
    prog.addNote(&g);

    aa16.addCourse(&prog);

    //prog.loadNote(sav);

    course* r=aa16.searchCourse("PAO");
    std::cout<<"Risultato: "<<r->getMateria().toStdString()<<std::endl;

    definition p("Agggounta dopo","descirizione dopo");
    definition k("Agggounta","descirizione");
    prog.addNote(&k);
    r->addNote(&p);

    prog.saveNote(sav);
}
