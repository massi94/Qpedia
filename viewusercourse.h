#ifndef VIEWUSERCOURSE_H
#define VIEWUSERCOURSE_H

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
#include <QCloseEvent>

#include "usrcourse.h"
#include "note.h"
#include "mainwidget.h"
#include "viewdefinition.h"
#include "viewsource.h"
#include "viewuserdata.h"

//componente grafica che permette la visualizzazione e l'inserimento di note per l'utente corso

class viewUserCourse : public mainWidget
{
    Q_OBJECT
private:
    usrCourse* usr;
    viewDefinition* definitionView;
    viewSource* sourceView;
    viewUserData* userDataView;

    QVBoxLayout* vLay;
    QGroupBox* box;
    QTableWidget* noteTable;
    QPushButton* newNote;
    QPushButton* newDefinition;
    QPushButton* newSource;
    QComboBox* selectNote;

public:
    viewUserCourse(usrCourse* =0, mainWidget* =0);
    ~viewUserCourse();

    void closeEvent(QCloseEvent*);

    virtual void loadGraphic();

    void noteList(const QVector<const note*>& );

public slots:
    void menuNote(int);

    void logout();

    void showUsrData();

    void showNote();
    void hideNote();

    void showDefinition();
    void showSource();

    void actionMenuNote(int,int);

    void writeDef(const QString&, const QString&);
    void writeSour(const QString&, const QString&, const QString&);

    void editDef(const unsigned int&, const QString&, const QString&);
    void editSour(const unsigned int&, const QString&, const QString&, const QString&);
    void editUser(const QString&);

    void closeDefinition();
    void closeSource();
    void closeUsrData();

signals:
    void signalSave();
    void signalLogout();
    void signalEditUsrData(const QString&);
    void signalWriteDef(const QString&, const QString&);
    void signalEditDef(const unsigned int&, const QString&, const QString&);
    void signalWriteSour(const QString&, const QString&,const QString&);
    void signalEditSour(const unsigned int&, const QString&, const QString&,const QString&);
    void signalClearNote(const unsigned int&);
};

#endif // VIEWUSERCOURSE_H
