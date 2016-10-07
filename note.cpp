#include "note.h"


note::note(QString t): title(t), creationDate(QDateTime::currentDateTime()), modifyDate(QDateTime::currentDateTime()){}

note::~note(){};
