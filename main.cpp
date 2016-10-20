#include "mainwindow.h"
#include <QApplication>
#include "list.h"
#include "course.h"
#include "definition.h"
#include <iostream>
#include "setcourses.h"

int main(int argc, char *argv[])
{
/*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
*/
    list<const note*>::iterator it;
    setCourses aa16;
    course prog("PAO");

    aa16.addCourse(&prog);

    prog.loadNote();
    std::cout<<"ciao";
    for(it=prog.getNotes().begin(); it!=prog.getNotes().end(); it++)
    {
        std::cout<<prog.getNotes()[it]->getTitle().toStdString()<<std::endl;
    }
    prog.saveNote();
}
