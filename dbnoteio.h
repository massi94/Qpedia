#ifndef DBNOTEIO_H
#define DBNOTEIO_H
#include <QXmlStreamWriter>
#include <QString>

class dbNoteIO
{
public:
    dbNoteIO();
    void writeNote(QXmlStreamWriter&,const QString&,const QString&) const;
    void writeStart(QXmlStreamWriter&, const QString&) const;
    void writeEnd(QXmlStreamWriter&) const;

};

#endif // DBNOTEIO_H
