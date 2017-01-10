#ifndef MAINVIEW_H
#define MAINVIEW_H

#include<iostream>

#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QProgressBar>
#include <QSlider>
#include <QToolBar>
#include <QComboBox>
#include <QBoxLayout>
#include <QLabel>
#include <QTableWidget>

#include <QStandardItemModel>
#include <QStringList>
#include <QHeaderView>
#include <QTextEdit>
#include <QWidget>
#include <QDialog>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QBoxLayout>
#include <QLayoutItem>
#include <QObject>
#include <QLayout>

class mainView : public QMainWindow{
    Q_OBJECT
private:
    QVBoxLayout *vLayMain;
    QHBoxLayout *hLayBody;
public:
    mainView();
    ~mainView();
    void mainScreen();
    QHBoxLayout* createBody();

public slots:
    void newCourse();
    void loadBody();
    void loadNote();


};

#endif // MAINVIEW_H
