#include "source.h"

source::source(unsigned int id, QString t, QDateTime cr, QDateTime mo, bool f, QString p, QString l, QString b):note(id,t,cr,mo,f,p),language(l),body(b){}

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

void source::saveNote(QXmlStreamWriter & wr)const{
    wr.writeStartElement("source");
    wr.writeTextElement("id",QString::number(getId()));
    wr.writeTextElement("title",getTitle().toUtf8().constData());
    wr.writeTextElement("language",getLanguage().toUtf8().constData());
    wr.writeTextElement("body",getBody().toUtf8().constData());
    wr.writeTextElement("creationDate",getCreationDate().toString("yyyy:MM:dd HH:mm:ss"));
    wr.writeTextElement("modifyDate",getModifyDate().toString("yyyy:MM:dd HH:mm:ss"));
    wr.writeTextElement("favourite",QString::number(isFavourite()));
    wr.writeTextElement("parent",getParent().toUtf8().constData());
    wr.writeEndElement();
}
