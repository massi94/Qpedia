#include"view/mainwindow.h"
#include<QApplication>
#include"model/list.h"
#include"model/course.h"
#include"model/definition.h"
#include<iostream>
#include"model/setcourses.h"
#include"model/dbonxml.h"

#include"model/user.h"
#include"model/student.h"
#include"model/teacher.h"

#include"view/mainview.h"


int main(int argc, char *argv[])
{

    QApplication app (argc, argv);

    mainView p;
    p.mainScreen();





return app.exec();


/*
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


    dbOnXml sav;

    setCourses sc;

    student stud;
    teacher teach;

    sav.loadDB(sc);
/*
    teach.createCourse(sc,"PAO");
    teach.createCourse(sc,"TecWeb");
    teach.createCourse(sc,"P3");

    teach.addNote(*(sc.searchCourse("PAO")),new definition());
    teach.addNote(*(sc.searchCourse("PAO")),new source());
    teach.addNote(*(sc.searchCourse("PAO")),new definition());
    teach.addNote(*(sc.searchCourse("PAO")),new schema());


    teach.addNote(*(sc.searchCourse("TecWeb")),new source());
    teach.addNote(*(sc.searchCourse("TecWeb")),new source());
    teach.addNote(*(sc.searchCourse("TecWeb")),new definition());

    stud.addNote(*(sc.searchCourse("TecWeb")),new definition("daStudente"));
    stud.addNote(*(sc.searchCourse("PAO")),new schema("daStudente"));
*/

    sav.writeDB(sc);




}
