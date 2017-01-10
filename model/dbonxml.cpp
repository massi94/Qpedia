#include "dbonxml.h"

dbOnXml::dbOnXml()
{

}

void dbOnXml::writeDB(const setCourses & l)
{
    QFile file("./materia/db.txt");

    file.open(QIODevice::WriteOnly);

    list<course *> corsi = l.getCourses();
    list<course *>::iterator itCour;


    wr.setDevice(&file);

    wr.setAutoFormatting(true);
    wr.writeStartDocument();
wr.writeStartElement("Corsi");
    for(itCour=corsi.begin(); itCour!=corsi.end(); ++itCour)
    {
        wr.writeStartElement("Materia");
wr.writeAttribute("name",corsi[itCour]->getMateria());
            list<const note*> appunti = corsi[itCour]->getNotes();
            list<const note*>::iterator it;

            wr.writeStartElement("Note");

            for(it=appunti.begin(); it!=appunti.end();it++)
            {
                appunti[it]->saveNote(wr);
            }

            wr.writeEndElement();

        wr.writeEndElement();
    }
    wr.writeEndElement();

    wr.writeEndDocument();

    file.close();
}


void dbOnXml::loadDB(setCourses & cour){

    QString subj;
    QString title;
    QString description;
    QString urlImg;
    QString language;
    QString body;

    QFile file("./materia/db.txt");
    if(!file.exists())
    {
        std::cout<<"file non presente";
    }
    else{
        file.open(QIODevice::ReadOnly);
        re.setDevice(&file);

        while(!re.atEnd())
        {
            if(re.isStartElement())
            {
                if(re.name()=="Materia")
                {
                   subj = re.attributes().begin()->value().toString();
                   cour.addCourse(new course(subj));
                }
                else if(re.name()=="Definition" ||
                   re.name()=="Schema"||
                   re.name()=="Source"||re.name()=="Note")
                    re.readNext();
                else if(re.name()=="Title")
                    title=re.readElementText();
                else if(re.name()=="Description")
                    description=re.readElementText();
                else if(re.name()=="UrlImg")
                    urlImg=re.readElementText();
                else if(re.name()=="Language")
                    language=re.readElementText();
                else if(re.name()=="Body")
                    body=re.readElementText();
            }
            else if(re.isEndElement() && re.name()=="Definition")
            {
                cour.searchCourse(subj)->addNote(new definition(title,description));
                re.readNext();
            }
            else if(re.isEndElement() && re.name()=="Schema")
            {
                cour.searchCourse(subj)->addNote(new schema(title,urlImg));
                re.readNext();
            }
            else if(re.isEndElement() && re.name()=="Source")
            {
                cour.searchCourse(subj)->addNote(new source(title,language,body));
                re.readNext();
            }
            re.readNext();
        }
    }
    file.close();
}



