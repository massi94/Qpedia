#ifndef COURSE_H
#define COURSE_H

#include <QString>

#include"../model/note.h"
#include"../model/definition.h"
#include"../model/schema.h"
#include"../model/source.h"
#include"../model/list.h"

class course
{
private:
    QString name;
    list<const note*> noteList;
public:
    course(QString);

    QString getMateria() const;
    list<const note*> getNotes() const;
    list<const note*> getDefinitions() const;
    list<const note*> getSchemas() const;
    list<const note*> getSources() const;

    void setName(const QString&);

    void outCourse() const;
    void addNote(const note* );
    const note* findNote(int) const;
    void deleteMemo(int);

};

#endif // COURSE_H
