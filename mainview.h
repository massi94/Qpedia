#ifndef MAINVIEW_H
#define MAINVIEW_H

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
    void clearLayout(QLayout*, bool deleteWidgets);

public slots:
    void newCourse();
    void loadBody();


};

#endif // MAINVIEW_H
