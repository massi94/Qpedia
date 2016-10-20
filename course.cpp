#include "course.h"

course::course(QString n) : name(n){}

QString course::getMateria() const {
    return name;
}

list<const note*> course::getNotes() const {
    return noteList;
}

list<const note*> course::getDefinitions() const {
    list<const note*> ris;
    list<const note*>::iterator it;

    for(it=noteList.begin();it!=noteList.end();++it)
    {
        const definition * d=dynamic_cast<const definition*>(noteList[it]);
        if(d) ris.push_front(d);
    }
    return ris;
}

list<const note*> course::getSchemas() const {
    list<const note*> ris;
    list<const note*>::iterator it;

    for(it=noteList.begin();it!=noteList.end();++it)
    {
        const schema * d=dynamic_cast<const schema*>(noteList[it]);
        if(d) ris.push_front(d);
    }
    return ris;
}

list<const note*> course::getSources() const {
    list<const note*> ris;
    list<const note*>::iterator it;

    for(it=noteList.begin();it!=noteList.end();++it)
    {
        const source * d=dynamic_cast<const source*>(noteList[it]);
        if(d) ris.push_front(d);
    }
    return ris;
}

void course::setName(const QString & n){
    name=n;
}

void course::addNote(const note* app){
    noteList.push_back(app);
}


void course::saveNote(dbIO & save){
    save.writeDB(name,noteList);
}


void course::loadNote(dbIO &save){
    save.loadDB(name,noteList);
}
