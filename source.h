#ifndef SOURCE_H
#define SOURCE_H

#include"note.h"
#include"dbio.h"

class source : public note
{
private:
    QString language;
    QString body;
public:
    source(QString="noTitolo",QString="noLinguaggio",QString="noCorpo");
    QString getLanguage() const;
    QString getBody() const;

    void setLanguage(const QString&);
    void setBody(const QString&);

    QString getType() const;
    virtual void saveNote(QXmlStreamWriter&) const;
};

#endif // SOURCE_H
