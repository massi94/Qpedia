#include "viewsource.h"

viewSource::viewSource(const source *s, mainWidget *w):mainWidget(w),nSour(s)
{
    if(nSour) editId = new QLineEdit(QString::number(nSour->getId()));
    else editId = new QLineEdit();
    if(nSour){
        editTitle = new QLineEdit();
        editTitle->setText(nSour->getTitle());
    }
    else editTitle = new QLineEdit();
    if(nSour) editCreationDate = new QDateTimeEdit(nSour->getCreationDate());
    else editCreationDate = new QDateTimeEdit(QDateTime::currentDateTime());
    if(nSour) editModifyDate = new QDateTimeEdit(nSour->getModifyDate());
    else editModifyDate = new QDateTimeEdit(QDateTime::currentDateTime());
    if(nSour){
        editLanguage = new QLineEdit();
        editLanguage->setText(nSour->getLanguage());
    }
    else editLanguage = new QLineEdit();
    if(nSour){
        editBody = new QTextEdit();
        editBody->setText(nSour->getBody());
    }
    else editBody = new QTextEdit;

    editCreationDate->setReadOnly(true);
    editModifyDate->setReadOnly(true);
    editId->setReadOnly(true);

    vLay = new QVBoxLayout;
    loadGraphic();
}


viewSource::~viewSource(){
    delete editId;
    delete editTitle;
    delete editCreationDate;
    delete editModifyDate;
    delete editLanguage;
    delete editBody;
    delete vLay;
}


void viewSource::closeEvent(QCloseEvent* event){
    emit signalDelete();
    event->accept();
}


void viewSource::loadGraphic(){
    setWindowTitle("Gestione Codice Sorgente");
    QLabel* id= new QLabel("Codice:");
    QLabel* title= new QLabel("Titolo:");
    QLabel* creationDate= new QLabel("Data di creazione:");
    QLabel* modifyDate= new QLabel("Data ultima moddifica:");
    QLabel* language= new QLabel("Linguaggio:");
    QLabel* body= new QLabel("Corpo:");

    saveButton = new QPushButton("Salva");
    QPushButton* deleteButton = new QPushButton("Annulla");

    QWidget::setFixedWidth(350);

    if(nSour){
    vLay->addWidget(id);
    vLay->addWidget(editId);
    }
    vLay->addWidget(title);
    vLay->addWidget(editTitle);
    vLay->addWidget(creationDate);
    vLay->addWidget(editCreationDate);
    vLay->addWidget(modifyDate);
    vLay->addWidget(editModifyDate);
    vLay->addWidget(language);
    vLay->addWidget(editLanguage);
    vLay->addWidget(body);
    vLay->addWidget(editBody);
    vLay->addWidget(saveButton);
    vLay->addWidget(deleteButton);
    setLayout(vLay);

    if(nSour)
        connect(saveButton,SIGNAL(clicked()),this,SLOT(editSource()));
    else
        connect(saveButton,SIGNAL(clicked()),this,SLOT(writeSource()));
    connect(deleteButton,SIGNAL(clicked()),this,SLOT(deleteSource()));
}

void viewSource::editSource()
{
    emit signalEdit((editId->text()).toInt(),editTitle->text(),editLanguage->text(),editBody->toPlainText());
}

void viewSource::writeSource()
{
    emit signalWrite(editTitle->text(),editLanguage->text(),editBody->toPlainText());
}

void viewSource::deleteSource(){emit signalDelete();}

void viewSource::readOnlySource(){
    editId->setReadOnly(true);
    editTitle->setReadOnly(true);
    editCreationDate->setReadOnly(true);
    editModifyDate->setReadOnly(true);
    editLanguage->setReadOnly(true);
    editBody->setReadOnly(true);
    saveButton->hide();
}
