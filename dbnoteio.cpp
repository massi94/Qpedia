#include "dbnoteio.h"

dbNoteIO::dbNoteIO()
{

}

void dbNoteIO::writeNote(QXmlStreamWriter& writer,const QString& l,const QString& label) const{
    writer.writeTextElement(label,l);
}

void dbNoteIO::writeStart(QXmlStreamWriter& writer, const QString& l) const{
    writer.writeStartElement(l);
}

void dbNoteIO::writeEnd(QXmlStreamWriter& writer) const{
    writer.writeEndElement();
}
