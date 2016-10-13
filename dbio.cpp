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
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QXmlStreamWriter stream(&file);
        stream.setAutoFormatting(true);
        stream.writeStartDocument();
        stream.writeStartElement("bookmark");
        stream.writeAttribute("href", "http://qt.nokia.com/");
        stream.writeTextElement("title", "Qt Home");
        stream.writeEndElement(); // bookmark
        stream.writeEndDocument();
    }

}
