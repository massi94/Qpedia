#include "definition.h"
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

void definition::saveNote(QXmlStreamWriter& writer)const{
    dbNoteIO io;
    io.writeStart(writer,"definition");
    io.writeNote(writer,(*this).getTitle(),"title");
    io.writeNote(writer,(*this).getDescription(),"descriprion");
    io.writeEnd(writer);
}
