#include "dbonxml.h"

dbOnXml::dbOnXml()
{

}

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
    file.close();
}

void dbOnXml::loadDB(QString mat, list<const note *> & l){

    QString title;
    QString description;
    QString urlImg;
    QString language;
    QString body;

    QFile file("./materia/"+mat+".txt");
    if(!file.exists())
    {
        std::cout<<"file non presente";
    }
    else{
        file.open(QIODevice::ReadOnly);
        re.setDevice(&file);
        //definition *a=new definition("titoljoi","definizione");
        //l.push_back(a);
        while(!re.atEnd())
        {
            if(re.isStartElement())
            {
                if(re.name()=="Definition" ||
                   re.name()=="Schema"||
                   re.name()=="Source")
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
                definition *a=new definition(title,description);
                l.push_back(a);
                re.readNext();
            }
            else if(re.isEndElement() && re.name()=="Schema")
            {
                schema *b=new schema(title,urlImg);
                l.push_back(b);
                re.readNext();
            }
            else if(re.isEndElement() && re.name()=="Source")
            {
                source *c=new source(title,language,body);
                l.push_back(c);
                re.readNext();
            }
            re.readNext();
        }
    }
    file.close();
}


