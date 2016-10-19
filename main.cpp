#include "mainwindow.h"
#include <QApplication>
#include "list.h"
#include "course.h"
#include "definition.h"
#include <iostream>

int main(int argc, char *argv[])
{
/*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
*/
    list<const note*>::iterator it;

    course prog("PAO");

    prog.loadNote();


    /*definition d("titolo1","Descrizione");
    schema s("titolo2","imgUrl");
    definition f("titolo3","Descrizione");
    definition h("titolo4","Descrizione");

    prog.addNote(&d);
    prog.addNote(&s);
    prog.addNote(&f);
    prog.addNote(&h);

    list<const note*> provalista;

    provalista = prog.getNotes();

    for(it=provalista.begin();it!=provalista.end();it++){
        std::cout<<provalista[it]->getTitle().toStdString()<<std::endl;
    }
    std::cout<<std::endl;
    for(it=prog.getNotes().begin(); it!=prog.getNotes().end(); it++)
    {
        std::cout<<prog.getNotes()[it]->getTitle().toStdString()<<std::endl;
    }

    prog.saveNote();
    std::cout<<"fine";*/

    for(it=prog.getNotes().begin(); it!=prog.getNotes().end(); it++)
    {
        std::cout<<prog.getNotes()[it]->getTitle().toStdString()<<std::endl;
    }
    prog.saveNote();
}
