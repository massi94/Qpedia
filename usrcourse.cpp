#include "usrcourse.h"

usrCourse::usrCourse(QString u,QString p):user(u,p){}

QVector<const note*> usrCourse::getNote() const{return dbNote;}

QVector<const note*> usrCourse::getDefinition() const{
    QVector<const note*> aux;
    for(QVector<const note*>::const_iterator it=dbNote.begin();it!=dbNote.end();it++)
    {
        const definition* d=dynamic_cast<const definition*>(*it);
        if(d){
            aux.push_back(d);
        }
    }
    return aux;
}

QVector<const note*> usrCourse::getSource() const{
    QVector<const note*> aux;
    for(QVector<const note*>::const_iterator it=dbNote.begin();it!=dbNote.end();it++)
    {
        const source* d=dynamic_cast<const source*>(*it);
        if(d){
            aux.push_back(d);
        }
    }
    return aux;
}

QVector<const note*> usrCourse::getFavourites() const{
    QVector<const note*> aux;
    for(QVector<const note*>::const_iterator it=dbNote.begin();it!=dbNote.end();it++)
    {
        const note* a=(*it);
        if(a->isFavourite())
            aux.push_back(a);
    }
    return aux;
}


void usrCourse::saveUser(QXmlStreamWriter& wr) const{
    wr.writeStartElement("usrCourse");
    wr.writeTextElement("username",getUsr().toUtf8().constData());
    wr.writeTextElement("password",getPsw().toUtf8().constData());
    wr.writeEndElement();
}

void usrCourse::writeOnDb(QXmlStreamWriter & wr) const
{
    wr.writeStartElement("usrCourse");
    wr.writeAttribute("name",this->getUsr());
    if(!dbNote.isEmpty())
        for(QVector<const note*>::const_iterator it=dbNote.begin(); it!=dbNote.end(); ++it)
           (*it)->saveNote(wr);
    wr.writeEndElement();
}

void usrCourse::resetNote()
{
    while(!dbNote.isEmpty())
        dbNote.pop_front();
}

void usrCourse::addNote(const note* n)
{
    dbNote.push_back(n);
}

void usrCourse::editDefinition(const unsigned int& id, const QString& t, const QString& d)
{
    definition* oldDef=const_cast<definition*>(dynamic_cast<const definition*>(searchNote(id)));
    oldDef->setTitle(t);
    oldDef->setDescription(d);
    oldDef->setModifyDate(QDateTime::currentDateTime());
}

void usrCourse::editSource(const unsigned int &id, const QString &t, const QString &l, const QString &b)
{
    source* oldSour=const_cast<source*>(dynamic_cast<const source*>(searchNote(id)));
    oldSour->setTitle(t);
    oldSour->setLanguage(l);
    oldSour->setBody(b);
    oldSour->setModifyDate(QDateTime::currentDateTime());
}

const note* usrCourse::searchNote(const unsigned int& id) const
{
    if(!dbNote.isEmpty())
    {
        for(QVector<const note*>::const_iterator it=dbNote.begin();it!=dbNote.end();it++)
            if((*it)->getId()==id)
                return dynamic_cast<const note*>(*it);
    }
    return 0;
}

void usrCourse::clearNote(const unsigned int& id)
{
    if(!dbNote.isEmpty())
    {
        for(QVector<const note*>::iterator it=dbNote.begin();it!=dbNote.end();it++)
            if((*it)->getId()==id){
                delete (*it);
                it = dbNote.erase(it);
                --it;
            }
    }
}

