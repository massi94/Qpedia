#ifndef NOTE_H
#define NOTE_H

#include<QString>
#include<QDateTime>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>

class note
{
private:
    int id;
    QString title;
    QDateTime creationDate;
    QDateTime modifyDate;
public:
    note(QString ="noTitolo");
    virtual ~note();

    QString getTitle() const;
    QString getCreationDate() const;
    QString getModifyDate() const;
    int getId() const;
    virtual QString getType() const =0;

    void setTitle(const QString&);
    void setCreationDate(const QDateTime&);
    void setModifyDate(const QDateTime&);
    void updateModifyDate();
    virtual void saveNote(QXmlStreamWriter&) const =0;
};

#endif // NOTE_H

//?????????    virtual void salvaMemo(QXmlStreamWriter& xmlWriter) const =0; // salvataggio del memo nel file xml
