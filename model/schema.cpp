#include "../model/schema.h"

schema::schema(QString t,QString i)
{
    note::setTitle(t);
    urlImg = i;
}

QString schema::getUrlImg() const{
    return urlImg;
}

void schema::setUrlImg(const QString& i){
    urlImg = i;
}

QString schema::getType()const{
    return "immagine";
}

void schema::saveNote(QXmlStreamWriter & wr)const{
    wr.writeStartElement("Schema");
    wr.writeTextElement("Title",getTitle());
    wr.writeTextElement("UrlImg",getUrlImg());
    wr.writeEndElement();
}
