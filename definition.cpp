#include "definition.h"

definition::definition(unsigned int id, QString t, QDateTime cr, QDateTime mo, bool f, QString p, QString d):note(id,t,cr,mo,f,p),description(d){}


QString definition::getDescription() const{
    return description;
}

void definition::setDescription(const QString& d){
    description = d;
}

void definition::saveNote(QXmlStreamWriter & wr)const{
    wr.writeStartElement("definition");
    wr.writeTextElement("id",QString::number(getId()));
    wr.writeTextElement("title",getTitle().toUtf8().constData());
    wr.writeTextElement("description",getDescription().toUtf8().constData());
    wr.writeTextElement("creationDate",getCreationDate().toString("yyyy:MM:dd HH:mm:ss"));
    wr.writeTextElement("modifyDate",getModifyDate().toString("yyyy:MM:dd HH:mm:ss"));
    wr.writeTextElement("favourite",QString::number(isFavourite()));
    wr.writeTextElement("parent",getParent().toUtf8().constData());
    wr.writeEndElement();
}
