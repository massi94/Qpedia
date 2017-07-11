#ifndef VIEWDEFINITION_H
#define VIEWDEFINITION_H

#include <QLineEdit>
#include <QDateTimeEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QMessageBox>
#include <QString>
#include <QApplication>
#include <QCloseEvent>
#include <iostream>

#include "definition.h"
#include "mainwidget.h"

//componente grafica che permette la visualizzazione delle definizioni

class viewDefinition : public mainWidget
{
    Q_OBJECT
private:
    QLineEdit* editId;
    QLineEdit* editTitle;
    QDateTimeEdit* editCreationDate;
    QDateTimeEdit* editModifyDate;
    QTextEdit* editDescription;

    QPushButton* saveButton;

    QVBoxLayout* vLay;

    const definition* nDef;

public:
    viewDefinition(const definition* =0,mainWidget* =0);
    ~viewDefinition();

    void closeEvent(QCloseEvent*);

    virtual void loadGraphic();

public slots:
    void editDefinition();
    void writeDefinition();
    void deleteDefinition();
    void readOnlyDefinition();

signals:
    void signalWrite(const QString&, const QString&);
    void signalEdit(const unsigned int&, const QString&, const QString&);
    void signalDelete();
    void signalReadOnly();
};

#endif // VIEWDEFINITION_H
