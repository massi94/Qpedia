#include "viewuserstudent.h"

viewUserStudent::viewUserStudent(dbOnXml* d,usrStudent* u, mainWidget* w):mainWidget(w),db(d), usr(u), definitionView(0), sourceView(0), userDataView(0)
{
    vLay = new QVBoxLayout;
    box = new QGroupBox;
    selectNote = new QComboBox();
    noteTable = new QTableWidget;
    loadGraphic();
    courseListView=0;
}

viewUserStudent::~viewUserStudent(){
    delete noteTable;
    delete selectNote;
    delete box;
    delete vLay;
    if(definitionView)
        delete definitionView;
    if(sourceView)
        delete sourceView;
    if(userDataView)
        delete userDataView;
    if(courseListView)
        delete courseListView;
}

void viewUserStudent::closeEvent(QCloseEvent* event){
    emit signalSave();
    emit signalLogout();
    event->accept();
}

void viewUserStudent::loadGraphic(){

    setWindowTitle("Gestione note");
    QVBoxLayout* boxL= new QVBoxLayout;
    QLabel* titleLabel = new QLabel("Gestione Note");

    QLabel* courseSelectLabel = new QLabel("Selezione corsi");
    QPushButton* courseSelectButton = new QPushButton("Corsi");
    connect(courseSelectButton,SIGNAL(clicked()),this,SLOT(openListCourse()));

    QLabel* selectLabel = new QLabel("Visualizza");
    selectNote->addItem("Tutti");
    selectNote->addItem("Definizioni");
    selectNote->addItem("Sorgenti");
    selectNote->addItem("Preferiti");
    connect(selectNote,SIGNAL(currentIndexChanged(int)),this,SLOT(menuNote(int)));

    QPushButton* modUserButton = new QPushButton("Modifica account");
    QPushButton* logoutButton = new QPushButton("Logout");

    QStringList header;
    header<<""<<"Titolo"<<"Corso";
    noteTable->setColumnCount(4);
    noteTable->setColumnHidden(3,true);
    noteTable->setHorizontalHeaderLabels(header);
    noteTable->setAutoScroll(false);
    noteTable->setMinimumWidth(450);
    noteTable->setMinimumHeight(500);
    noteTable->setMaximumHeight(500);
    noteTable->setColumnWidth(0,30);
    noteTable->setColumnWidth(1,200);
    noteTable->setColumnWidth(2,199);

    noteList(usr->getAllNotes());
    connect(noteTable, SIGNAL(cellClicked(int,int)), this, SLOT(actionMenuNote(int,int)));

    QWidget::setFixedHeight(750);
    QWidget::setFixedWidth(500);

    boxL->addWidget(courseSelectLabel);
    boxL->addWidget(courseSelectButton);
    boxL->addWidget(titleLabel);
    boxL->addWidget(selectLabel);
    boxL->addWidget(selectNote);
    boxL->addWidget(noteTable);
    box->setLayout(boxL);
    vLay->addWidget(box);
    vLay->addWidget(modUserButton);
    vLay->addWidget(logoutButton);


    setLayout(vLay);
    connect(logoutButton,SIGNAL(clicked()),this,SLOT(logout()));
    connect(modUserButton,SIGNAL(clicked()),this,SLOT(showUsrData()));
}

void viewUserStudent::noteList(const QVector<const note *> & notes){
    int row=0;
    int aux=notes.length();
    noteTable->setSortingEnabled(false);
    if(aux>0){
        for(QVector<const note*>::const_iterator it=notes.begin();it!=notes.end();++it){
            noteTable->setRowCount(row+1);
            QTableWidgetItem* view= new QTableWidgetItem();
            QTableWidgetItem* title= new QTableWidgetItem((*it)->getTitle());
            QTableWidgetItem* cour= new QTableWidgetItem((*it)->getParent());
            QTableWidgetItem* id= new QTableWidgetItem(QString::number((*it)->getId()));
            view->setFlags(Qt::NoItemFlags);
            title->setFlags(Qt::NoItemFlags);
            id->setFlags(Qt::NoItemFlags);
            cour->setFlags(Qt::NoItemFlags);

            view->setIcon(QIcon("../QPedia/icon/view.png"));

            noteTable->setItem(row,0,view);
            noteTable->setItem(row,1,title);
            noteTable->setItem(row,2,cour);
            noteTable->setItem(row,3,id);
            row++;
        }
    }
    else{
        noteTable->setRowCount(row);
    }
    noteTable->setSortingEnabled(true);
    noteTable->sortItems(1, Qt::AscendingOrder);
}


void viewUserStudent::menuNote(int a){
    if(a==0) noteList(usr->getAllNotes());
    else if(a==1) noteList(usr->getAllDefinitions());
    else if(a==2) noteList(usr->getAllSources());
    else if(a==3) noteList(usr->getAllFavourites());
}

void viewUserStudent::logout(){
    emit signalSave();
    emit signalLogout();
}

void viewUserStudent::showUsrData(){
    if(userDataView==0){
        userDataView = new viewUserData(usr);
        userDataView->show();
        connect(userDataView,SIGNAL(signalSaveMod(const QString&)),this,SLOT(editUser(const QString&)));
        connect(userDataView,SIGNAL(signalCancelMod()),this,SLOT(closeUsrData()));
    }
}




void viewUserStudent::actionMenuNote(int row, int col){
    int id = noteTable->item(row,3)->text().toInt();
    if(col==0){
        const note* aux= usr->searchNote(id);
        const definition* auxDef = dynamic_cast<const definition*>(aux);
        if(auxDef){
            definitionView = new viewDefinition(auxDef);
            definitionView->readOnlyDefinition();
            definitionView->show();
            connect(definitionView,SIGNAL(signalDelete()),this,SLOT(closeDefinition()));
        }
        else{
            sourceView = new viewSource(dynamic_cast<const source*>(aux));
            sourceView->readOnlySource();
            sourceView->show();
            connect(sourceView,SIGNAL(signalDelete()),this,SLOT(closeSource()));
        }
    }
}

void viewUserStudent::editUser(const QString&p){
    emit signalEditUsrData(p);
    delete userDataView;
    userDataView = 0;
}

void viewUserStudent::closeUsrData(){
    QMessageBox::StandardButton msg;
    msg=QMessageBox::question(this, "Salvataggio non effettuato" , "Attenzione! Le modifiche non salvate andranno perse! Uscire comunque?", QMessageBox::Yes|QMessageBox::No);
     if (msg==QMessageBox::Yes)
     {
         delete userDataView;
         userDataView=0;
     }
}

void viewUserStudent::closeDefinition(){
         delete definitionView;
         definitionView=0;
}

void viewUserStudent::closeSource(){
         delete sourceView;
         sourceView=0;
}


void viewUserStudent::openListCourse(){

    if(courseListView){
        delete courseListView;
    }
    courseListView = new viewCourseList(db,usr);
    courseListView->show();
    connect(courseListView,SIGNAL(signalSubscribe(user*)),this,SLOT(subscription(user *)));
    connect(courseListView,SIGNAL(signalBack()),this,SLOT(closeListCourse()));

}

void viewUserStudent::closeListCourse(){
    std::cout<<" chiudo ";
    delete courseListView;
    courseListView=0;
}

void viewUserStudent::subscription(user * u){
    QMessageBox::StandardButton msg;
    if(usr->isSubscribed(u->getUsr()) == 0)
    {
        msg=QMessageBox::question(this, "Gestione iscrizioni" , "Confermi di voler iscriverti al corso?", QMessageBox::Yes|QMessageBox::No);
        if (msg==QMessageBox::Yes){
            emit signalSubscription(u);
        }
    }
    else{
        msg=QMessageBox::question(this, "Gestione iscrizioni" , "Confermi di voler cancellare la tua iscrizione?", QMessageBox::Yes|QMessageBox::No);
        if (msg==QMessageBox::Yes){
            emit signalUnSubscription(u->getUsr());
        }
    }
    selectNote->setCurrentIndex(0);
    noteList(usr->getAllNotes());
}
