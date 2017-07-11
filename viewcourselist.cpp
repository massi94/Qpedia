#include "viewcourselist.h"

viewCourseList::viewCourseList(dbOnXml * d, usrStudent * us, mainWidget* w):mainWidget(w),db(d),uStud(us){
    vLay = new QVBoxLayout;
    box = new QGroupBox;
    courTable = new QTableWidget;
    loadGraphic();
}

viewCourseList::~viewCourseList(){
    delete courTable;
    delete box;
    delete vLay;
}

void viewCourseList::loadGraphic(){
    setWindowTitle("Gestione iscrizioni");
    QVBoxLayout* boxL= new QVBoxLayout;
    QLabel* tiLabel = new QLabel("Gestione Note");


    QStringList header;
    header<<""<<"Corso"<<"Numero note";
    courTable->setColumnCount(3);
    courTable->setHorizontalHeaderLabels(header);
    courTable->setAutoScroll(false);
    courTable->setMinimumWidth(350);
    courTable->setMinimumHeight(280);
    courTable->setMaximumHeight(300);
    courTable->setColumnWidth(0,30);
    courTable->setColumnWidth(1,200);
    courTable->setColumnWidth(2,99);

    QWidget::setFixedHeight(400);
    QWidget::setFixedWidth(400);

    courseList(db->getUsrCourse());
    connect(courTable, SIGNAL(cellClicked(int,int)), this, SLOT(actionMenuCourse(int,int)));

    QPushButton* backButton = new QPushButton("Indietro");


    vLay->addWidget(tiLabel);
    boxL->addWidget(courTable);
    box->setLayout(boxL);
    vLay->addWidget(box);
    vLay->addWidget(backButton);
    setLayout(vLay);

    connect(backButton,SIGNAL(clicked()),this,SLOT(back()));

}

void viewCourseList::closeEvent(QCloseEvent* event){
    emit signalBack();
    event->accept();
}

void viewCourseList::courseList(const QVector<const usrCourse *> &courses){
    int row=0;
    int aux=courses.length();
    courTable->setSortingEnabled(false);
    if(aux>0){
        for(QVector<const usrCourse*>::const_iterator it=courses.begin();it!=courses.end();++it){
            courTable->setRowCount(row+1);
            QTableWidgetItem* subscribe= new QTableWidgetItem();
            QTableWidgetItem* course= new QTableWidgetItem((*it)->getUsr());
            QTableWidgetItem* nNote= new QTableWidgetItem(QString::number(((*it)->getNote()).length()));
            subscribe->setFlags(Qt::NoItemFlags);
            course->setFlags(Qt::NoItemFlags);
            nNote->setFlags(Qt::NoItemFlags);

            if(uStud->isSubscribed((*it)->getUsr()))
                subscribe->setIcon(QIcon("../QPedia/icon/remove.png"));
            else
                subscribe->setIcon(QIcon("../QPedia/icon/add.png"));

            courTable->setItem(row,0,subscribe);
            courTable->setItem(row,1,course);
            courTable->setItem(row,2,nNote);
            row++;
        }
    }
    else{
        courTable->setRowCount(row);
    }
    courTable->setSortingEnabled(true);
    courTable->sortItems(1, Qt::AscendingOrder);


    }

void viewCourseList::actionMenuCourse(int row,int col){
    const QString cour = courTable->item(row,1)->text();
    if(col==0){
        emit signalSubscribe(db->searchUser(cour));
        this->hide();
    }
}

void viewCourseList::back(){
    emit signalBack();
}

