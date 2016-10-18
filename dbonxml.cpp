#include "dbonxml.h"

dbOnXml::dbOnXml()
{

}

void dbOnXml::loadDB() const{}

void dbOnXml::writeDB(QString mat, const list<const note *> & l)
{
    QFile file("./materia/"+mat+".txt");

    if(!file.exists())
    {
        std::cout<<"file non presente";
    }
    else{

        file.open(QIODevice::WriteOnly);
        list<const note*>::iterator it;
        wr.setDevice(&file);

        wr.setAutoFormatting(true);
        wr.writeStartDocument();

        wr.writeStartElement("Note");

        for(it=l.begin(); it!=l.end();it++)
        {
            l[it]->saveNote(wr);
        }

        wr.writeEndElement();

        wr.writeEndDocument();
    }
}

