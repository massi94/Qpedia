#include "course.h"

course::course(QString n) : name(n){}

QString course::getMateria() const {return name;}

QVector<const note*> course::getNotes() const {return noteList;}

QVector<const note*> course::getDefinitions() const {
    QVector<const note*> ris;
    QVector<const note*>::const_iterator it;

    for(it=noteList.begin();it!=noteList.end();++it)
    {
        const definition * d=dynamic_cast<const definition*>(*it);
        if(d) ris.push_front(d);
    }
    return ris;
}

QVector<const note*> course::getSchemas() const {
    QVector<const note*> ris;
    QVector<const note*>::const_iterator it;

    for(it=noteList.begin();it!=noteList.end();++it)
    {
        const schema * d=dynamic_cast<const schema*>(*it);
        if(d) ris.push_front(d);
    }
    return ris;
}

QVector<const note*> course::getSources() const {
    QVector<const note*> ris;
    QVector<const note*>::const_iterator it;

    for(it=noteList.begin();it!=noteList.end();++it)
    {
        const source * d=dynamic_cast<const source*>(*it);
        if(d) ris.push_front(d);
    }
    return ris;
}

void course::setName(const QString & n){name=n;}

