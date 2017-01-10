#include "../model/note.h"


note::note(QString t): title(t), creationDate(QDateTime::currentDateTime()), modifyDate(QDateTime::currentDateTime()){}

note::~note(){};


void note::setTitle(const QString& t){
    title = t;
}

QString note::getTitle() const{
    return title;
}
