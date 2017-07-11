#include "note.h"

note::note(unsigned int id, QString t, QDateTime cr, QDateTime mo, bool f, QString p): id(id), title(t), creationDate(cr), modifyDate(mo), favourite(f), parent(p) {}

note::~note(){}

//get variabili
unsigned int note::getId() const {return id;}

QString note::getTitle() const {return title;}

QDateTime note::getCreationDate() const {return creationDate;}

QDateTime note::getModifyDate() const {return modifyDate;}

QString note::getParent() const{return parent;}

bool note::isFavourite() const {return favourite;}

//set variabili
void note::setId(const unsigned int& newId){id=newId;}

void note::setTitle(const QString& newTitle){title=newTitle;}

void note::setCreationDate(const QDateTime& newCreaDate){creationDate=newCreaDate;}

void note::setModifyDate(const QDateTime& newModDate){modifyDate=newModDate;}

void note::setFavourite(const bool & newFav){favourite=newFav;}
