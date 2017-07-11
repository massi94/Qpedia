#ifndef VIEWSOURCE_H
#define VIEWSOURCE_H

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
#include <iostream>
#include <QCloseEvent>

#include "source.h"
#include "mainwidget.h"

//componente grafica che permette la visualizzazione dei codici sorgente


class viewSource: public mainWidget
{
    Q_OBJECT
private:
    QLineEdit* editId;
    QLineEdit* editTitle;
    QDateTimeEdit* editCreationDate;
    QDateTimeEdit* editModifyDate;
    QLineEdit* editLanguage;
    QTextEdit* editBody;

    QPushButton* saveButton;

    QVBoxLayout* vLay;

    const source* nSour;
public:
    viewSource(const source* =0,mainWidget* =0);
    ~viewSource();

    void closeEvent(QCloseEvent*);

    virtual void loadGraphic();

public slots:
    void editSource();
    void writeSource();
    void deleteSource();
    void readOnlySource();
signals:
    void signalWrite(const QString&, const QString&,const QString&);
    void signalEdit(const unsigned int&, const QString&,const QString&,const QString&);
    void signalDelete();
};

#endif // VIEWSOURCE_H
