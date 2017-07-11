#include "usrstudent.h"

usrStudent::usrStudent(QString u, QString p):user(u,p){}

void usrStudent::subscribeCourse(const usrCourse* c){
    course.push_back(c);
}

void usrStudent::unSubscribeCourse(const QString& n){
    for(QVector<const usrCourse*>::iterator it=course.begin();it!=course.end();++it){
        if((*it)->getUsr()==n){
                it = course.erase(it);
                --it;
    }}
}

QVector<const usrCourse*> usrStudent::getCourses() const{
    return course;
}


QVector<const note*> usrStudent::usrStudent::getAllNotes()const{
    QVector<const note*> aux;
    for(QVector<const usrCourse*>::const_iterator it=course.begin();it!=course.end();it++){
        QVector<const note*> a = (*it)->getNote();
        for(QVector<const note*>::const_iterator itt=a.begin();itt!=a.end();itt++)
        {
            aux.push_back(*itt);
        }
    }
    return aux;

}
QVector<const note*> usrStudent::usrStudent::getAllDefinitions()const{
    QVector<const note*> aux;
    for(QVector<const usrCourse*>::const_iterator it=course.begin();it!=course.end();it++){
        QVector<const note*> a = (*it)->getDefinition();
        for(QVector<const note*>::const_iterator itt=a.begin();itt!=a.end();itt++)
        {
            aux.push_back(*itt);
        }
    }
    return aux;
}
QVector<const note*> usrStudent::usrStudent::getAllSources()const{
    QVector<const note*> aux;
    for(QVector<const usrCourse*>::const_iterator it=course.begin();it!=course.end();it++){
        QVector<const note*> a = (*it)->getSource();
        for(QVector<const note*>::const_iterator itt=a.begin();itt!=a.end();itt++)
        {
            aux.push_back(*itt);
        }
    }
    return aux;
}

QVector<const note*> usrStudent::usrStudent::getAllFavourites()const{
    QVector<const note*> aux;
    for(QVector<const usrCourse*>::const_iterator it=course.begin();it!=course.end();it++){
        QVector<const note*> a = (*it)->getNote();
        for(QVector<const note*>::const_iterator itt=a.begin();itt!=a.end();itt++)
        {
            if((*itt)->isFavourite())
                aux.push_back(*itt);
        }
    }
    return aux;

}



void usrStudent::saveUser(QXmlStreamWriter& wr) const{
    wr.writeStartElement("usrStudent");
    wr.writeTextElement("username",getUsr().toUtf8().constData());
    wr.writeTextElement("password",getPsw().toUtf8().constData());
    wr.writeEndElement();
}

void usrStudent::writeOnDb(QXmlStreamWriter & wr) const{
    wr.writeStartElement("usrStudent");
    wr.writeAttribute("name",this->getUsr());
    if(!course.isEmpty())
        for(QVector<const usrCourse*>::const_iterator it=course.begin();it!=course.end();++it)
        {
            wr.writeTextElement("course",(*it)->getUsr().toUtf8().constData());
        }
    wr.writeEndElement();
}

const note* usrStudent::searchNote(const unsigned int& id) const
{
    QVector<const note*> tmp = getAllNotes();
    if(!tmp.isEmpty())
    {
        for(QVector<const note*>::const_iterator it=tmp.begin();it!=tmp.end();it++)
            if((*it)->getId()==id)
                return dynamic_cast<const note*>(*it);
    }
    return 0;
}

bool usrStudent::isSubscribed(const QString & c) const{
    if(!course.isEmpty())
        for(QVector<const usrCourse*>::const_iterator it=course.begin();it!=course.end();++it)
        {
            if((*it)->getUsr()==c)
                return true;
        }
    return false;
}

