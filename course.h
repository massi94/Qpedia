#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include <QVector>

#include"dbio.h"
#include"note.h"
#include"definition.h"
#include"schema.h"
#include"source.h"


class course
{
private:
    QString name;
    QVector<const note*> noteList;
public:
    course(QString);

    QString getMateria() const;
    QVector<const note*> getNotes() const;
    QVector<const note*> getDefinitions() const;
    QVector<const note*> getSchemas() const;
    QVector<const note*> getSources() const;

    void setName(const QString&);

    void outCourse() const;
    void loadNote();
    void saveNote();
    void addNote(const note* );
    const note* findNote(int) const;
    void deleteMemo(int);

};

#endif // COURSE_H
