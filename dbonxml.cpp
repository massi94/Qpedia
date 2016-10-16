#include "dbonxml.h"

dbOnXml::dbOnXml()
{

}

void dbOnXml::setStream(){
    wr.setDevice(&out);
}

void dbOnXml::initialzeFile(){
    wr.setAutoFormatting(true);
    wr.writeStartDocument();
}

void dbOnXml::endFile(){
    wr.writeEndDocument();
}

void dbOnXml::writeNote(const QString& l,const QString& label){
    wr.writeTextElement(label,l);
}
void dbOnXml::writeStart(const QString& l){
    wr.writeStartElement(l);
}
void dbOnXml::writeEnd(){
    wr.writeEndElement();
}

void dbOnXml::setFile(QString f){
    out.setFileName(f);
}

bool dbOnXml::isValid() const{
    if((this->out).exists())
        return true;
    else
        return false;
}

void dbOnXml::openFile(){
    out.open(QIODevice::WriteOnly | QIODevice::Text);
}
