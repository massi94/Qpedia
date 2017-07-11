#ifndef VIEWCOURSELIST_H
#define VIEWCOURSELIST_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QString>
#include <QIcon>
#include <QMessageBox>
#include <QComboBox>
#include <QVector>
#include <QLabel>
#include <QHeaderView>
#include <QCloseEvent>

#include "mainwidget.h"
#include "usrstudent.h"

//componente grafica che si occupa di visualizzare i corsi disponibili all'utente Studente, permettendone l'iscrizione

class viewCourseList : public mainWidget
{
    Q_OBJECT
private:
    QVBoxLayout* vLay;
    QGroupBox* box;
    QTableWidget* courTable;

    dbOnXml* db;

    const usrStudent* uStud;
public:
    viewCourseList(dbOnXml* =0, usrStudent* =0,mainWidget* =0);
    ~viewCourseList();

    virtual void loadGraphic();

    void closeEvent(QCloseEvent*);

    void courseList(const QVector<const usrCourse*>&);

public slots:
    void actionMenuCourse(int,int);
    void back();

signals:
    void signalBack();
    void signalSubscribe(user*);

};


#endif // VIEWCOURSELIST_H
