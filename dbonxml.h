#ifndef DBONXML_H
#define DBONXML_H

#include<QXmlStreamWriter>
#include<QFile>

class dbOnXml
{
private:
    QXmlStreamWriter wr;
    QFile out;
public:
    dbOnXml();
    void setStream();
    void initialzeFile();
    void endFile();
    void writeNote(const QString&,const QString&);
    void writeStart(const QString&);
    void writeEnd();

    void setFile(QString);
    void openFile();
    bool isValid() const;
};

#endif // DBONXML_H
