#include "user.h"

user::user(QString u, QString p):usr(u),psw(p)
{

}

user::~user(){}

QString user::getUsr() const{
    return usr;
}

QString user::getPsw() const{
    return psw;
}

void user::setUsr(const QString& u){
    usr=u;
}

void user::setPsw(const QString& p){
    psw=p;
}

