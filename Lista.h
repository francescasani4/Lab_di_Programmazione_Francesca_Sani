//
// Created by Francesca Sani
//

#ifndef LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_LISTA_H
#define LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_LISTA_H

#include "Subject.h"
#include "Observer.h"
#include "Articolo.h"

#include <list>
#include <map>
#include <iostream>

using namespace std;

class Lista : public Subject {
public:
    Lista(const string& IDlista) : IDlista(IDlista) {}

    virtual ~Lista() {};

    const string &getIDlista() const {
        return IDlista;
    }

    void setIDlista(const string &iDlista) {
        IDlista = iDlista;
    }

    const map<string, Articolo *> &getListaArt() const {
        return listaArt;
    }

    void setListaArt(const map<string, Articolo *> &listaArt) {
        Lista::listaArt = listaArt;
    }

    const list<Observer *> &getObservers() const {
        return observers;
    }

    void setObservers(const list<Observer *> &observers) {
        Lista::observers = observers;
    }

    void aggiungiArticolo(Articolo* IDarticolo);
    void rimuoviArticolo(const string& art);
    void setComprato(const string& art);
    int setNonComprato();
    void stampaArticoliDaComprare();

    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify() override;

private:
    string IDlista;
    list<Observer*> observers;
    map<string, Articolo*> listaArt;

};


#endif //LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_LISTA_H
