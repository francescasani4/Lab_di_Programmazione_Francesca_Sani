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
#include <memory>

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

    const map<string, shared_ptr<Articolo>> &getListaArt() const {
        return listaArt;
    }

    const list<Observer *> &getObservers() const {
        return observers;
    }

    void aggiungiArticolo(Articolo& IDarticolo);
    bool rimuoviArticolo(const string& art);
    bool setComprato(const string& art);
    int getNumeroArticoliNonComprati();
    void stampaArticoliDaComprare();

    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify() override;

private:
    string IDlista;
    list<Observer*> observers;
    map<string, shared_ptr<Articolo>> listaArt;

};


#endif //LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_LISTA_H
