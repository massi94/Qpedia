#include "source.h"

source::source(QString t,QString l,QString b)
{
    note::setTitle(t);
    language = l;
    body = b;
}

QString source::getLanguage()const{
    return language;
}

QString source::getBody()const{
    return body;
}

void source::setLanguage(const QString& l)
{
    language = l;
}

void source::setBody(const QString& b)
{
    body = b;
}

QString source::getType()const{
    return "codice";
}

void source::saveNote(QXmlStreamWriter& writer)const{
    dbNoteIO io;
    io.writeStart(writer,"source");
    io.writeNote(writer,(*this).getTitle(),"title");
    io.writeNote(writer,(*this).getLanguage(),"language");
    io.writeNote(writer,(*this).getBody(),"body");

    io.writeEnd(writer);
}
