#include "mainwindow.h"
#include <QApplication>
#include "list.h"
#include "course.h"
#include "definition.h"
#include <iostream>
#include "setcourses.h"
#include "dbonxml.h"

#include"user.h"
#include"student.h"
#include"teacher.h"

#include "mainview.h"


int main(int argc, char *argv[])
{
/*
    QApplication app (argc, argv);

    mainView p;
    p.mainScreen();

return app.exec();



    // Create a container window

    QWidget window;
    window.setFixedSize(1000, 800);

    QMenuBar *menu = new QMenuBar(&window);
    QMenu *note;
    QMenu *subAdd;
    QAction *quit;

    note = menu->addMenu("Nota");
    subAdd = note->addMenu("Aggiungi");
    QAction* def = subAdd->addAction("Definizione");
    QAction* sch = subAdd->addAction("Schema");
    QAction* sou = subAdd->addAction("Codice");

    quit = menu->addAction("Esci");

    QPushButton *a = new QPushButton(&window);

    QWidget* prova = new QWidget(&window);

    QComboBox * box = new QComboBox(prova);
    box->setFixedSize(150,20);

    box->addItem("Prova1");
    box->addItem("Prova2");

    QPushButton * p = new QPushButton();

    window.show();
    return app.exec();
*/

/*

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
    */

    dbOnXml sav;

    course prog("PAO");
    prog.loadNote(sav);

    setCourses sof;
    sof.addCourse(&prog);

    std::cout<<prog.getMateria().toStdString();

    student stud;
    teacher teach;

    list<const note*> ll;
    list<const note*>::iterator it2;

    course* prova;
    prova = stud.findCourse(sof,"PAO");
    stud.addNote(*prova,new definition("DaUser","DaUtente"));

    teach.createCourse(sof,"SWE");

    ll=prova->getNotes();
    std::cout<<"adesso";
    for(it2=ll.begin();it2!=ll.end();++it2)
    {
        std::cout<<ll[it2]->getTitle().toStdString()<<std::endl;
    }

    list<course*> cc;
    list<course*>::iterator it3;

    cc=sof.getCourses();

    for(it3=cc.begin();it3!=cc.end();++it3)
    {
        std::cout<<cc[it3]->getMateria().toStdString()<<std::endl;
    }

    //prog.saveNote(sav);


}
