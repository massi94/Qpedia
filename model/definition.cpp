#include "../model/definition.h"
#include <iostream>
definition::definition(QString t,QString s){
    note::setTitle(t);
    description = s;
}

QString definition::getDescription() const{
    return description;
}

void definition::setDescription(const QString& d){
    description = d;
}

QString definition::getType()const{
    return "Definizione";
}

void definition::saveNote(QXmlStreamWriter & wr)const{
    wr.writeStartElement("Definition");
    wr.writeTextElement("Title",getTitle());
    wr.writeTextElement("Description",getDescription());
    wr.writeEndElement();
}
