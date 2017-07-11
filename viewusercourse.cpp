#include "viewusercourse.h"

viewUserCourse::viewUserCourse(usrCourse *u, mainWidget*a):mainWidget(a), usr(u), definitionView(0), sourceView(0), userDataView(0)
{
    vLay = new QVBoxLayout;
    box = new QGroupBox;
    newNote = new QPushButton("Nuova nota");
    newDefinition = new QPushButton("Nuova Definizione");
    newSource = new QPushButton("Nuovo codice sorgente");
    selectNote = new QComboBox();
    noteTable = new QTableWidget;
    loadGraphic();
}

viewUserCourse::~viewUserCourse(){
    delete noteTable;
    delete newNote;
    delete newDefinition;
    delete newSource;
    delete selectNote;
    delete box;
    delete vLay;
    if(definitionView)
        delete definitionView;
    if(sourceView)
        delete sourceView;
    if(userDataView)
        delete userDataView;
}

void viewUserCourse::closeEvent(QCloseEvent* event){
    emit signalSave();
    emit signalLogout();
    event->accept();
}

void viewUserCourse::loadGraphic(){

    setWindowTitle("Gestione note");
    QVBoxLayout* boxL= new QVBoxLayout;
    QLabel* titleLabel = new QLabel("Gestione Note");

    QLabel* selectLabel = new QLabel("Visualizza");
    selectNote->addItem("Tutti");
    selectNote->addItem("Definizioni");
    selectNote->addItem("Sorgenti");
    selectNote->addItem("Preferiti");
    connect(selectNote,SIGNAL(currentIndexChanged(int)),SLOT(menuNote(int)));

    QPushButton* modUserButton = new QPushButton("Modifica account");
    QPushButton* logoutButton = new QPushButton("Logout");

    newNote->setCheckable(true);

    QStringList header;
    header<<"Cancella"<<"Modifica"<<"Preferito"<<"Titolo";
    noteTable->setColumnCount(5);
    noteTable->setColumnHidden(4,true);
    noteTable->setHorizontalHeaderLabels(header);
    noteTable->setAutoScroll(false);
    noteTable->setMinimumWidth(800);
    noteTable->setMinimumHeight(300);
    noteTable->setMaximumHeight(300);
    noteTable->setColumnWidth(0,90);
    noteTable->setColumnWidth(1,90);
    noteTable->setColumnWidth(2,90);
    noteTable->setColumnWidth(3,160);

    noteList(usr->getNote());
    connect(noteTable, SIGNAL(cellClicked(int,int)), this, SLOT(actionMenuNote(int,int)));

    boxL->addWidget(titleLabel);

    boxL->addWidget(selectLabel);
    boxL->addWidget(selectNote);
    boxL->addWidget(newNote);
    boxL->addWidget(newDefinition);
    boxL->addWidget(newSource);
    boxL->addWidget(noteTable);
    newDefinition->hide();
    newSource->hide();
    boxL->addWidget(modUserButton);
    boxL->addWidget(logoutButton);

    box->setLayout(boxL);
    vLay->addWidget(box);
    setLayout(vLay);
    connect(logoutButton,SIGNAL(clicked()),this,SLOT(logout()));
    connect(newNote,SIGNAL(clicked()),this,SLOT(showNote()));
    connect(modUserButton,SIGNAL(clicked()),this,SLOT(showUsrData()));
}

void viewUserCourse::noteList(const QVector<const note *> & notes){
    int row=0;
    int aux=notes.length();
    noteTable->setSortingEnabled(false);
    if(aux>0){
        for(QVector<const note*>::const_iterator it=notes.begin();it!=notes.end();++it){
            noteTable->setRowCount(row+1);
            QTableWidgetItem* id= new QTableWidgetItem(QString::number((*it)->getId()));
            QTableWidgetItem* cancel= new QTableWidgetItem();
            QTableWidgetItem* modify= new QTableWidgetItem();
            QTableWidgetItem* favourite= new QTableWidgetItem();
            QTableWidgetItem* title= new QTableWidgetItem((*it)->getTitle());
            id->setFlags(Qt::NoItemFlags);
            cancel->setFlags(Qt::NoItemFlags);
            modify->setFlags(Qt::NoItemFlags);
            favourite->setFlags(Qt::NoItemFlags);
            title->setFlags(Qt::NoItemFlags);

            cancel->setIcon(QIcon("../QPedia/icon/delete.png"));
            modify->setIcon(QIcon("../QPedia/icon/edit.png"));
            if((*it)->isFavourite())
                favourite->setIcon(QIcon("../QPedia/icon/favourite.jpg"));
            else
                favourite->setIcon(QIcon("../QPedia/icon/unfavourite.png"));

            noteTable->setItem(row,0,cancel);
            noteTable->setItem(row,1,modify);
            noteTable->setItem(row,2,favourite);
            noteTable->setItem(row,3,title);
            noteTable->setItem(row,4,id);

            row++;
        }
    }
    else{
        noteTable->setRowCount(row);
    }
    noteTable->setSortingEnabled(true);
    noteTable->sortItems(1, Qt::AscendingOrder);
}

void viewUserCourse::menuNote(int a){
    if(a==0) noteList(usr->getNote());
    else if(a==1) noteList(usr->getDefinition());
    else if(a==2) noteList(usr->getSource());
    else if(a==3) noteList(usr->getFavourites());
}

void viewUserCourse::logout(){
    emit signalSave();
    emit signalLogout();
}

void viewUserCourse::showUsrData(){
    if(userDataView==0){
        userDataView = new viewUserData(usr);
        userDataView->show();
        connect(userDataView,SIGNAL(signalSaveMod(const QString&)),this,SLOT(editUser(const QString&)));
        connect(userDataView,SIGNAL(signalCancelMod()),this,SLOT(closeUsrData()));
    }
}




void viewUserCourse::showNote(){
    newNote->setChecked(true);
    newDefinition->show();
    newSource->show();
    disconnect(newNote,SIGNAL(clicked()),this,SLOT(showNote()));
    connect(newNote,SIGNAL(clicked()),this,SLOT(hideNote()));
    connect(newDefinition,SIGNAL(clicked()),this,SLOT(showDefinition()));
    connect(newSource,SIGNAL(clicked()),this,SLOT(showSource()));
}

void viewUserCourse::hideNote(){
    newNote->setChecked(false);
    disconnect(newNote,SIGNAL(clicked()),this,SLOT(hideNote()));
    disconnect(newDefinition,SIGNAL(clicked()),this,SLOT(showDefinition()));
    disconnect(newSource,SIGNAL(clicked()),this,SLOT(showSource()));
    connect(newNote,SIGNAL(clicked()),this,SLOT(showNote()));
    newDefinition->hide();
    newSource->hide();
}

void viewUserCourse::showDefinition(){
    if(definitionView==0)
    {
        definitionView = new viewDefinition;
        definitionView->show();
        connect(definitionView,SIGNAL(signalWrite(const QString&, const QString&)),this,SLOT(writeDef(const QString&,const QString&)));
        connect(definitionView,SIGNAL(signalDelete()),this,SLOT(closeDefinition()));
    }
}

void viewUserCourse::showSource(){
    if(sourceView==0)
    {
        sourceView = new viewSource;
        sourceView->show();
        connect(sourceView,SIGNAL(signalWrite(const QString&, const QString&,const QString&)),this,SLOT(writeSour(const QString&,const QString&,const QString&)));
        connect(sourceView,SIGNAL(signalDelete()),this,SLOT(closeSource()));
    }
}

void viewUserCourse::actionMenuNote(int row, int col){
    int id = noteTable->item(row,4)->text().toInt();
    if(col==0){
        QMessageBox::StandardButton msg;
        msg=QMessageBox::question(this, "Eliminazione Nota" , "Confermi di voler eliminare questa Nota?", QMessageBox::Yes|QMessageBox::No);
        if (msg==QMessageBox::Yes)
        {
             noteTable->removeRow(row);
             emit signalClearNote(id);
             noteList(usr->getNote());
         }
    }
    else if(col==1){
        const note* aux= usr->searchNote(id);
        const definition* auxDef = dynamic_cast<const definition*>(aux);
        if(auxDef){
            definitionView = new viewDefinition(auxDef);
            definitionView->show();
            connect(definitionView,SIGNAL(signalEdit(const uint&,const QString&,const QString&)),this,SLOT(editDef(const uint&,const QString&,const QString&)));
            connect(definitionView,SIGNAL(signalDelete()),this,SLOT(closeDefinition()));
        }
        else{
            sourceView = new viewSource(dynamic_cast<const source*>(aux));
            sourceView->show();
            connect(sourceView,SIGNAL(signalEdit(const uint&,const QString&,const QString&,const QString&)),this,SLOT(editSour(const uint&,const QString&,const QString&,const QString&)));
            connect(sourceView,SIGNAL(signalDelete()),this,SLOT(closeSource()));
        }
    }
    else if(col==2){
        note* aux=const_cast <note*>(usr->searchNote(id));
        QMessageBox::StandardButton msg;
        if(aux->isFavourite()==0)
        {
            msg=QMessageBox::question(this, "Gestione preferiti" , "Confermi di voler aggiungere la nota ai preferiti?", QMessageBox::Yes|QMessageBox::No);
            if (msg==QMessageBox::Yes)
                aux->setFavourite(true);
        }
        else
        {
            msg=QMessageBox::question(this, "Gestione preferiti" , "Confermi di voler togliere la nota dai preferiti?", QMessageBox::Yes|QMessageBox::No);
            if (msg==QMessageBox::Yes)
                aux->setFavourite(false);
        }
        noteList(usr->getNote());
    }
}

void viewUserCourse::writeDef(const QString &t, const QString &d){
    emit signalWriteDef(t,d);
    noteList(usr->getNote());
    delete definitionView;
    definitionView=0;
}

void viewUserCourse::writeSour(const QString &t, const QString &l, const QString &b){
    emit signalWriteSour(t,l,b);
    noteList(usr->getNote());
    delete sourceView;
    sourceView=0;
}

void viewUserCourse::editDef(const unsigned int &id, const QString &t, const QString &d){
    emit signalEditDef(id,t,d);
    noteList(usr->getNote());
    delete definitionView;
    definitionView=0;
}
void viewUserCourse::editSour(const unsigned int &id, const QString &t, const QString &l, const QString &b){
    emit signalEditSour(id,t,l,b);
    noteList(usr->getNote());
    delete sourceView;
    sourceView=0;
}
void viewUserCourse::editUser(const QString&p){
    emit signalEditUsrData(p);
    delete userDataView;
    userDataView = 0;
}

void viewUserCourse::closeDefinition(){
    QMessageBox::StandardButton msg;
    msg=QMessageBox::question(this, "Salvataggio non effettuato" , "Attenzione! Le modifiche non salvate andranno perse! Uscire comunque?", QMessageBox::Yes|QMessageBox::No);
     if (msg==QMessageBox::Yes)
     {
         delete definitionView;
         definitionView=0;
     }
}

void viewUserCourse::closeSource(){
    QMessageBox::StandardButton msg;
    msg=QMessageBox::question(this, "Salvataggio non effettuato" , "Attenzione! Le modifiche non salvate andranno perse! Uscire comunque?", QMessageBox::Yes|QMessageBox::No);
     if (msg==QMessageBox::Yes)
     {
         delete sourceView;
         sourceView=0;
     }
}

void viewUserCourse::closeUsrData(){
    QMessageBox::StandardButton msg;
    msg=QMessageBox::question(this, "Salvataggio non effettuato" , "Attenzione! Le modifiche non salvate andranno perse! Uscire comunque?", QMessageBox::Yes|QMessageBox::No);
     if (msg==QMessageBox::Yes)
     {
         delete userDataView;
         userDataView=0;
     }
}

