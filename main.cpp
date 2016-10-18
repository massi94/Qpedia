#include "mainwindow.h"
#include <QApplication>
#include "list.h"
#include "course.h"
#include "definition.h"
#include <iostream>
#include "dbonxml.h"

int main(int argc, char *argv[])
{
/*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
*/

    list<const note*> prova;
    list<const note*>::iterator it;

    definition b;
    b.setTitle("titolo");
    b.setDescription("prova");

    definition f;

    source d;

    schema s;

    course prog("PAO");
    prog.addNote(&b);
    prog.addNote(&d);
    prog.addNote(&s);
    prog.addNote(&f);


    for(it=prog.getNotes().begin();it!=prog.getNotes().end();it++)
    {
        std::cout<<prog.getNotes()[it]->getType().toStdString()<<std::endl;
    }


    dbOnXml asd;
    asd.writeDB(prog.getMateria(),prog.getNotes());
}
