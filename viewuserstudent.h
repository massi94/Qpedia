#ifndef VIEWUSERSTUDENT_H
#define VIEWUSERSTUDENT_H

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

#include "usrcourse.h"
#include "usrstudent.h"
#include "note.h"
#include "mainwidget.h"
#include "viewdefinition.h"
#include "viewsource.h"
#include "viewuserdata.h"
#include "viewcourselist.h"

//componente grafica che permette la visualizzazione di note per l'utente Studente, e l'iscrizione ai corsi


class viewUserStudent : public mainWidget
{
    Q_OBJECT
private:
    dbOnXml* db;
    usrStudent *usr;
    viewDefinition* definitionView;
    viewSource* sourceView;
    viewUserData* userDataView;
    viewCourseList* courseListView;


    QVBoxLayout* vLay;
    QGroupBox* box;
    QTableWidget* noteTable;
    QComboBox* selectNote;

public:
    viewUserStudent(dbOnXml* =0, usrStudent* =0, mainWidget* =0);
    ~viewUserStudent();

    void closeEvent(QCloseEvent*);

    virtual void loadGraphic();

    void noteList(const QVector<const note*>&);

public slots:
    void menuNote(int);

    void logout();

    void showUsrData();

    void actionMenuNote(int,int);

    void editUser(const QString&);

    void closeUsrData();
    void closeDefinition();
    void closeSource();

    void openListCourse();
    void closeListCourse();

    void subscription(user *);

signals:
    void signalSave();
    void signalLogout();
    void signalEditUsrData(const QString&);
    void signalSubscription(user *);
    void signalUnSubscription(const QString&);

};

#endif // VIEWUSERSTUDENT_H
