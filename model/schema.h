#ifndef SCHEMA_H
#define SCHEMA_H

#include"../model/note.h"

class schema : public note
{
private:
    QString urlImg;
public:
    schema(QString="noTitle",QString="noImage");
    QString getUrlImg() const;

    void setUrlImg(const QString&);

    QString getType() const;
    virtual void saveNote(QXmlStreamWriter&) const;

};

#endif // SCHEMA_H
