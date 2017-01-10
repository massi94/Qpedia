#include "../view/mainview.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsView>

mainView::mainView()
{
    vLayMain = new QVBoxLayout();
}

mainView::~mainView(){}


void mainView::newCourse(){
    QWidget * nuovo = new QWidget();
    nuovo->show();
}


QHBoxLayout* mainView::createBody(){
    if(vLayMain->count()>2)
    {
        hLayBody->deleteLater();
    }

    hLayBody = new QHBoxLayout;

    QTableView *tab = new QTableView();
    QStandardItemModel *model = new QStandardItemModel( 5, 2);
    tab->verticalHeader()->hide();
    model->setHeaderData(1, Qt::Horizontal,"Titolo");
    model->setHeaderData(0, Qt::Horizontal,"Tipo");
    tab->setModel(model);
    tab->horizontalHeader()->setStretchLastSection(true);
    tab->setEditTriggers(QAbstractItemView::NoEditTriggers);


    QPushButton *vedi = new QPushButton("Vedi");



    hLayBody->addWidget(tab);
    hLayBody->addWidget(vedi);



    QLabel *courseName = new QLabel();
    courseName->setText("Nome del corso A.A 2016/2017");
    std::cout<<hLayBody->count()<<std::endl;
    std::cout<<vLayMain->count()<<std::endl;

    QObject::connect(vedi,SIGNAL(clicked()),this,SLOT(loadNote()));

    return hLayBody;
}

void mainView::loadBody(){
    vLayMain->addLayout(createBody());
}

void mainView::loadNote(){
    std::cout<<"HLAYBODY: "<<hLayBody->count()<<std::endl;

    if(hLayBody->count()>=2)
    {
        hLayBody->deleteLater();
    }
    QImage image("test.png");
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsView* view = new QGraphicsView(scene);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    hLayBody->addWidget(view);
}


void mainView::mainScreen(){
    QHBoxLayout *hLayMenu = new QHBoxLayout;
    QMenuBar *menu = new QMenuBar();
    QAction *note = menu->addAction("Nuovo Corso");
    QAction *quit = menu->addAction("Esci");
    hLayMenu->addWidget(menu);

    QHBoxLayout *hLaySelection = new QHBoxLayout;
    QLabel *cor = new QLabel();
    cor->setText("Corso:");
    QComboBox * box = new QComboBox();
        box->addItem("Prova1");
        box->addItem("Prova2");
    QPushButton *find = new QPushButton("Cerca");
    QLabel *crea = new QLabel();
    crea->setText("Crea:");
    QPushButton *sch = new QPushButton("Schema");
    QPushButton *def = new QPushButton("Definizione");
    QPushButton *cod = new QPushButton("Codice");
    hLaySelection->addWidget(cor);
    hLaySelection->addWidget(box);
    hLaySelection->addWidget(find);
    hLaySelection->addWidget(crea);
    hLaySelection->addWidget(sch);
    hLaySelection->addWidget(def);
    hLaySelection->addWidget(cod);


//costruzione schermata principale
    vLayMain->addLayout(hLayMenu);
    vLayMain->addLayout(hLaySelection);

    //vLayMain->addLayout(loadBody());

    QObject::connect(note,SIGNAL(triggered()),this,SLOT(newCourse()));

    QObject::connect(find,SIGNAL(clicked()),this,SLOT(loadBody()));


    QWidget *w = new QWidget();

    w->setLayout(vLayMain);
    w->show();

}
