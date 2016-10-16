#include "dbio.h"

dbIO::dbIO()
{

}

void dbIO::writeDB(const QString& mat, const list<const note*>& l)
{
    file.setFile("./materia/"+mat+".txt");

    if(!file.isValid())
    {
        std::cout<<"file non presente";
    }
    else{
        list<const note*>::iterator it;
        file.openFile();
        file.setStream();
        file.initialzeFile();

        for(it=l.begin();it!=l.end();it++)
        {
                l[it]->saveNote((*this).file);
        }

        file.endFile();
    }
}
