#include "viewdefinition.h"

viewDefinition::viewDefinition(const definition * d, mainWidget* w):mainWidget(w),nDef(d)
{
    if(nDef) editId = new QLineEdit(QString::number(nDef->getId()));
    else{ editId = new QLineEdit();}
    if(nDef){
        editTitle = new QLineEdit();
        editTitle->setText(nDef->getTitle());
    }
    else editTitle = new QLineEdit();
    if(nDef) editCreationDate = new QDateTimeEdit(nDef->getCreationDate());
    else editCreationDate = new QDateTimeEdit(QDateTime::currentDateTime());
    if(nDef) editModifyDate = new QDateTimeEdit(nDef->getModifyDate());
    else editModifyDate = new QDateTimeEdit(QDateTime::currentDateTime());
    if(nDef) {
        editDescription = new QTextEdit();
        editDescription->setText((nDef->getDescription()));
    }
    else editDescription = new QTextEdit;

    editCreationDate->setReadOnly(true);
    editModifyDate->setReadOnly(true);
    editId->setReadOnly(true);
    vLay = new QVBoxLayout;
    loadGraphic();
}


viewDefinition::~viewDefinition(){
    delete editId;
    delete editTitle;
    delete editCreationDate;
    delete editModifyDate;
    delete editDescription;
    delete saveButton;
    delete vLay;
}

void viewDefinition::closeEvent(QCloseEvent* event){
    emit signalDelete();
    event->accept();
}


void viewDefinition::loadGraphic(){
    setWindowTitle("Gestione Definizioni");
    QLabel* id= new QLabel("Codice:");
    QLabel* title= new QLabel("Titolo:");
    QLabel* creationDate= new QLabel("Data di creazione:");
    QLabel* modifyDate= new QLabel("Data ultima moddifica:");
    QLabel* definition= new QLabel("Definizione:");

    saveButton = new QPushButton("Salva");
    QPushButton* deleteButton = new QPushButton("Annulla");

    QWidget::setFixedWidth(350);

    if(nDef){
        vLay->addWidget(id);
        vLay->addWidget(editId);
    }
    vLay->addWidget(title);
    vLay->addWidget(editTitle);
    vLay->addWidget(creationDate);
    vLay->addWidget(editCreationDate);
    vLay->addWidget(modifyDate);
    vLay->addWidget(editModifyDate);
    vLay->addWidget(definition);
    vLay->addWidget(editDescription);
    vLay->addWidget(saveButton);
    vLay->addWidget(deleteButton);
    setLayout(vLay);

    if(nDef)
        connect(saveButton,SIGNAL(clicked()),this,SLOT(editDefinition()));
    else
        connect(saveButton,SIGNAL(clicked()),this,SLOT(writeDefinition()));
    connect(deleteButton,SIGNAL(clicked()),this,SLOT(deleteDefinition()));
}


void viewDefinition::editDefinition()
{
    emit signalEdit((editId->text()).toInt(),editTitle->text(),editDescription->toPlainText());
}

void viewDefinition::writeDefinition()
{
    emit signalWrite(editTitle->text(),editDescription->toPlainText());
}

void viewDefinition::deleteDefinition(){emit signalDelete();}

void viewDefinition::readOnlyDefinition(){
    editId->setReadOnly(true);
    editTitle->setReadOnly(true);
    editCreationDate->setReadOnly(true);
    editModifyDate->setReadOnly(true);
    editDescription->setReadOnly(true);
    saveButton->hide();
}
