#ifndef COURSE_H
#define COURSE_H

#include <QString>

#include"dbio.h"
#include"note.h"
#include"definition.h"
#include"schema.h"
#include"source.h"
#include"list.h"


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
    void loadNote();
    void saveNote();
    void addNote(const note* );
    const note* findNote(int) const;
    void deleteMemo(int);

};

#endif // COURSE_H
