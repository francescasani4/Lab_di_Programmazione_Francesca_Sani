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
#include "Articolo.h"

using namespace std;

class Lista : public Subject {
public:
    Lista(string& IDlista) : IDlista(IDlista) {}

    virtual ~Lista() {};

    const string &getIDlista() const {
        return IDlista;
    }

    void setIDlista(const string &iDlista) {
        IDlista = iDlista;
    }

    /* Da implementare */
    void aggiungiArticolo(Articolo& IDarticolo);
    void rimuoviArticolo(Articolo& IDarticolo);
    bool cercaArticolo(Articolo& IDarticolo);
    void setComprato(Articolo& IDarticolo);

    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify() override;

private:
    string IDlista; /* Nome Lista */
    list<Observer*> observers;
    map<string, Articolo> articoli;
    /* aggiungere attributi */
};


#endif //LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_LISTA_H
