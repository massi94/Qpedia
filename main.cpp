#include "mainwindow.h"
#include <QApplication>
#include "list.h"
#include "course.h"
#include "definition.h"
#include <iostream>
#include "dbio.h"

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
    //prova.push_back(&b);.

    definition f;

    source d;
    //prova.push_back(&d);

    schema s;
    //prova.push_back(&s);

    for(it=prova.begin(); it!=prova.end(); it++)
    {
        std::cout<<(prova[it]->getType()).toStdString()<<std::endl ;
    }

    std::cout<<prova.getSize();

    course prog("PAO");
    prog.addNote(&b);
    prog.addNote(&d);
    prog.addNote(&s);
    prog.addNote(&f);

    prova=prog.getDefinitions();

    for(it=prova.begin(); it!=prova.end(); it++)
    {
        std::cout<<(prova[it]->getType()).toStdString()<<std::endl ;
        std::cout<<(prova[it]->getTitle()).toStdString()<<std::endl ;
    }

    std::cout<<(prog.getDefinitions()).getSize();

    dbIO asd;
    asd.writeDB(prog.getMateria(),prova);

}
