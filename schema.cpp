#include "schema.h"

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

void schema::saveNote(dbOnXml& io)const{
    io.writeStart("schema");
    io.writeNote((*this).getTitle(),"title");
    io.writeNote((*this).getUrlImg(),"urlImg");
    io.writeEnd();
}
