#include "mainview.h"

mainView::mainView()
{
    vLayMain = new QVBoxLayout();
}

mainView::~mainView(){}


void mainView::newCourse(){
    QWidget * nuovo = new QWidget();
    nuovo->show();
}

void clearLayout(QLayout* layout, bool deleteWidgets = true)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        QWidget* widget;
        if ((deleteWidgets) && (widget = item->widget())) {
            delete widget;
        }
        if (QLayout* childLayout = item->layout()) {
            clearLayout(childLayout, deleteWidgets);
        }
        delete item;
    }
}

QHBoxLayout* mainView::createBody(){
    if(hLayBody)
    {
        while (QLayoutItem* item = hLayBody->takeAt(0))
        {
            QWidget* widget;
            if ((widget = item->widget())) {
                delete widget;
            }

        }
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

    QTextEdit *space = new QTextEdit();
    space->setReadOnly(true);
    hLayBody->addWidget(tab);
    hLayBody->addWidget(space);


    QLabel *courseName = new QLabel();
    courseName->setText("Nome del corso A.A 2016/2017");

    return hLayBody;
}

void mainView::loadBody(){
    vLayMain->addLayout(createBody());
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
