#ifndef NOTE_H
#define NOTE_H
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QString>
#include <QFile>
#include <iostream>
#include <QDateTime>

//classe base per le note, caratterizzata da id, titolo, data di creazione, data di modifica, preferito(per il corso), genitore(per identificare chi ha scritto la nota)

class note
{
private:
    unsigned int id;
    QString title;
    QDateTime creationDate;
    QDateTime modifyDate;
    bool favourite;
    QString parent;
public:
    note(unsigned int=1, QString ="noTitolo", QDateTime=QDateTime::currentDateTime(), QDateTime=QDateTime::currentDateTime(), bool=false, QString = "noParent");
    virtual ~note();

//get variabili
    unsigned int getId() const;
    QString getTitle() const;
    QDateTime getCreationDate() const;
    QDateTime getModifyDate() const;
    QString getParent() const;
    bool isFavourite() const;

//set variabili
    void setId(const unsigned int&);
    void setTitle(const QString&);
    void setCreationDate(const QDateTime&);
    void setModifyDate(const QDateTime&);
    void setFavourite(const bool &);

//stampa
    virtual void saveNote(QXmlStreamWriter&) const =0;
};

#endif // NOTE_H
