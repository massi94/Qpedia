#ifndef LIST_H
#define LIST_H

#include<iostream>

template<class T>

class list
{
    friend class iterator;
private:
    int nodi;
    class Nodo;

    class Smartp
    {
    public:
        Nodo* punt;

        Smartp(Nodo* n=0) : punt(n){
            if(punt!=0)
                punt->rif++;
        }

        Smartp(const Smartp& s) :punt(s.punt) {
            if(punt!=0)
                punt->rif++;
        }

        ~Smartp() {
            if(punt!=0){
                punt->rif--;
                if(punt->rif==0)
                    delete punt;
            }
        }

        Smartp& operator= (const Smartp& s){
            if(this!= &s)
            {
                Nodo* aux=punt;
                punt=s.punt;
                if(punt!=0) punt->rif++;
                if(aux)
                {
                    aux->rif--;
                    if(aux->rif==0)
                        delete aux;
                }
            }
            return *this;
         }


        bool operator==(const Smartp& s) const {
            return punt==s.punt;
        }

        bool operator!=(const Smartp& s) const {
            return punt!=s.punt;
        }

        Nodo& operator*() const {
            return *punt;
        }

        Nodo* operator->() const {
            return punt;
        }
    };

    class Nodo{
    public:
        Nodo(T t, const Smartp& s=0) : info(t), next(s), rif(0) {}
        T info;
        Smartp next;
        int rif;
    };

    Smartp first;

public:
    class iterator
    {
        friend class list;
    private:
        list::Smartp punt;
    public:
        iterator& operator++(){
            if(punt!=0) punt=punt->next;
            return *this;
        }

        iterator operator++(int){
            iterator aux=*this;
            if(punt!=0) punt=punt->next;
            return aux;
        }


        T* operator*() const{
            return punt->info;
        }

        bool operator==(const iterator& i) const{
            return punt==i.punt;
        }

        bool operator!=(const iterator& i) const{
            return punt!=i.punt;
        }

    };

    list() : nodi(0),first(0){}

    list(const list& l) : nodi(l.nodi),first(l.first){}

    list& operator=(const list& l){
        if(this!=&l){
            first=l.first;
        }
        return *this;
    }

    int getSize() const {
        return nodi;
    }

    void push_front(const T& t){
        first=new Nodo(t,first);
        nodi++;
    }

    void push_back(const T& t){
        if(first==0) first=new Nodo(t,0);
        else{
            Smartp aux=first;
            while(aux->next != 0)
                aux=aux->next;
            aux->next=new Nodo(t,0);
        }
        nodi++;
    }

    void pop_front(){
        if(first!=0){
            first=first->next;
            nodi--;
        }
    }

    void pop_back(){
        if(first!=0){
            if(first->next!=0){
                Smartp prec=first;
                Smartp aux=first->next;
                while(aux->next != 0) {prec=prec->next; aux=aux->next;}
                prec->next=0;
            }
            else first=0;

            nodi--;
        }
    }


    iterator begin() const {
        iterator start;
        start.punt=first;
        return start;

    }

    iterator end() const{
        iterator fine;
        fine.punt=0;
        return fine;
    }

    T& operator[](const iterator& it) const{
        return (it.punt)->info;
    }

};

#endif // LIST_H
