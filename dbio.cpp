#include "dbio.h"

dbIO::dbIO()
{

}

void dbIO::writeDB(const QString& mat, const list<const note*>& l) const
{
    QFile file("./materia/"+mat+".txt");

    if(!file.exists())
    {
        std::cout<<"file non presente";
    }
    else{
        list<const note*>::iterator it;
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QXmlStreamWriter stream(&file);

        stream.setAutoFormatting(true);
        stream.writeStartDocument();
        for(it=l.begin();it!=l.end();it++)
        {
                l[it]->saveNote(stream);
        }
        stream.writeEndDocument();
    }
}

