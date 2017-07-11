#include "dbonxml.h"

dbOnXml::dbOnXml()
{
    readUser();
    readNote();
}

dbOnXml::~dbOnXml(){
    writeUser();

    while (!allUser.isEmpty())
    {
        allUser.pop_front();
    }

}

void dbOnXml::addUser(const user* u){
    allUser.push_back(u);
}

user *dbOnXml::searchUser(const QString & us) const
{
    for(QVector<const user*>::const_iterator it=allUser.begin(); it!=allUser.end(); ++it)
       if((*it)->getUsr()==us) return const_cast<user*>(*it);
    return 0;
}

void dbOnXml::readUser()
{
    QString usr;
    QString psw;
    QFile file("../QPedia/db/userDB.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text)) std::cout<<"DataBase non trovato"<<std::endl;
    QXmlStreamReader re(&file);
    re.readNext();


    while(!re.atEnd())
    {
        if(re.isStartElement())
        {
            if(re.name()=="users" || re.name()=="usrCourse"|| re.name()=="usrStudent")
                re.readNext();
            else if(re.name()=="username")
                usr=re.readElementText();
            else if(re.name()=="password")
                psw=re.readElementText();
        }
        else if(re.isEndElement() && re.name()=="usrCourse")
        {
                usrCourse* newUsrCour=new usrCourse(usr,psw);
                allUser.push_back(newUsrCour);
                re.readNext();
        }
        else if(re.isEndElement() && re.name()=="usrStudent")
        {
                usrStudent* newUsrStud=new usrStudent(usr,psw);
                allUser.push_back(newUsrStud);
                re.readNext();
        }
        else re.readNext();
    }
    file.close();
}

void dbOnXml::writeUser() const
{
    QFile file("../QPedia/db/userDB.xml");
    if(!file.open(QIODevice::WriteOnly)) std::cout<<"DataBase non presente"<<std::endl;
    QXmlStreamWriter wr(&file);
    wr.setAutoFormatting(true);
    wr.writeStartDocument();
    wr.writeStartElement("users");
    if(!allUser.isEmpty())
        for(QVector<const user*>::const_iterator it=allUser.begin(); it!=allUser.end(); ++it)
            (*it)->saveUser(wr);
    wr.writeEndDocument();
    file.close();
}

void dbOnXml::readNote(){
    unsigned int id;
    QString title;
    QDateTime creationDate;
    QDateTime modifyDate;
    bool favourite;
    QString description;
    QString language;
    QString body;
    QString course;
    QString student;
    QString subscription;
    QString parent;

    bool isStudent = false;
    bool isCourse = false;

    QFile file("../QPedia/db/notes.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text)) std::cout<<"DB non trovato"<<std::endl;
    QXmlStreamReader re(&file);
    re.readNext();
    while(!re.atEnd())
    {
        if(re.isStartElement())
        {
            if(re.name()=="notes"||re.name()=="definition"||re.name()=="source")
                re.readNext();
            else if(re.name()=="usrCourse")
            {
                isCourse=true;
                course=re.attributes().begin()->value().toString();
            }
            else if(re.name()=="usrStudent")
            {
                isStudent=true;
                student=re.attributes().begin()->value().toString();
            }
            else if(re.name()=="course" && isStudent)
            {
                subscription=re.readElementText();
                usrStudent* us = (dynamic_cast<usrStudent*>(searchUser(student)));
                us->subscribeCourse(dynamic_cast<usrCourse*>(searchUser(subscription)));
            }
            else if(re.name()=="id" && isCourse)
                id=re.readElementText().toInt();
            else if(re.name()=="title" && isCourse)
                title=re.readElementText();
            else if(re.name()=="creationDate" && isCourse)
                creationDate=QDateTime::fromString(re.readElementText().toUtf8().constData(),"yyyy:MM:dd HH:mm:ss");
            else if(re.name()=="modifyDate" && isCourse)
                modifyDate=QDateTime::fromString(re.readElementText().toUtf8().constData(),"yyyy:MM:dd HH:mm:ss");
            else if(re.name()=="favourite" && isCourse)
                favourite= re.readElementText().toInt();
            else if(re.name()=="description" && isCourse)
                description=re.readElementText();
            else if(re.name()=="language" && isCourse)
                language=re.readElementText();
            else if(re.name()=="body" && isCourse)
                body=re.readElementText();
            else if(re.name()=="parent")
                parent=re.readElementText();
        }
        else if(re.isEndElement() && re.name()=="definition" && isCourse)
        {
            definition* newDef=new definition(id,title,creationDate,modifyDate,favourite,parent,description);
            usrCourse* uc = (dynamic_cast<usrCourse*>(searchUser(course)));
            uc->addNote(newDef);
            re.readNext();
        }
        else if(re.isEndElement() && re.name()=="source" && isCourse)
        {
            source* newSour=new source(id,title,creationDate,modifyDate,favourite,parent,language,body);
            usrCourse* uc = (dynamic_cast<usrCourse*>(searchUser(course)));
            uc->addNote(newSour);
            re.readNext();
        }
        else if(re.isEndElement() && re.name()=="usrCourse" && isCourse)
        {
            isCourse=false;
        }
        else if(re.isEndElement() && re.name()=="usrStident" && isStudent)
        {
            isStudent=false;
        }
        re.readNext();
    }
    file.close();
}

void dbOnXml::writeNote() const{
    QFile file("../QPedia/db/notes.xml");
    if(!file.open(QIODevice::WriteOnly))
        std::cout<<"DB non trovato"<<std::endl;
    QXmlStreamWriter wr(&file);
    wr.setAutoFormatting(true);
    wr.writeStartDocument();
    wr.writeStartElement("notes");
    if(allUser.size()!=0)
        for(QVector<const user*>::const_iterator it=allUser.begin(); it!=allUser.end(); ++it)
        {

            (*it)->writeOnDb(wr);

        }
    wr.writeEndElement();
    wr.writeEndDocument();
    file.close();
}

QVector<const usrCourse *> dbOnXml::getUsrCourse() const{
    QVector<const usrCourse*> aux;
    for(QVector<const user*>::const_iterator it=allUser.begin(); it!=allUser.end(); ++it){
        const usrCourse* c =dynamic_cast<const usrCourse*>(*it);
        if(c)
            aux.push_back(c);
    }
    return aux;

}

int dbOnXml::getCurrentId() const{
    unsigned int id=0;
    for(QVector<const user*>::const_iterator it=allUser.begin(); it!=allUser.end(); ++it){
        const usrCourse* c =dynamic_cast<const usrCourse*>(*it);
        if(c){
            QVector<const note*> a = c->getNote();
            for(QVector<const note*>::const_iterator itt=a.begin();itt!=a.end();itt++)
            {
                if((*itt)->getId() > id)
                    id = (*itt)->getId();
            }
        }
    }
    return id+1;
}

