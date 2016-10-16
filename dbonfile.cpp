#include "dbonfile.h"

dbOnFile::dbOnFile()
{

}

void dbOnFile::setFile(QString f){
    out.setFileName(f);
}

bool dbOnFile::isValid() const{
    if((this->out).exists())
        return true;
    else
        return false;
}

void dbOnFile::openFile(){
    out.open(QIODevice::WriteOnly | QIODevice::Text);
}
