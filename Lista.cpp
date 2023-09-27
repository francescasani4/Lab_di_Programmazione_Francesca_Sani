//
// Created by Francesca Sani
//

#include "Lista.h"

void Lista::aggiungiArticolo(Articolo& IDarticolo) {
    auto itr = listaArt.find(IDarticolo.getIDarticolo());

    if(itr != listaArt.end()) {
        itr -> second->setQt(itr -> second->getQt() + IDarticolo.getQt());
    } else {
        listaArt.insert(make_pair(IDarticolo.getIDarticolo(),make_shared<Articolo>(IDarticolo)));
    }

    notify();
}

bool Lista::rimuoviArticolo(const string &art) {
    auto itr = listaArt.find(art);

    if(itr != listaArt.end()) {
        listaArt.erase(itr);
        notify();
        return true;
    } else {
        return false;
    }
}

bool Lista::setComprato(const string &art) {
    auto itr = listaArt.find(art);

    if (itr != listaArt.end()) {
        bool acq = itr -> second->isAcquistato();

        if(acq)
            itr -> second->setAcquistato(false);
        else
            itr -> second->setAcquistato(true);

        notify();
        return true;
    } else {
        return false;
    }
}

int Lista::getNumeroArticoliNonComprati() {
    int r = 0;

    for(auto &itr: listaArt) {
        if(!itr.second->isAcquistato()) {
            r += itr.second->getQt();
        }
    }

    return r;
}

void Lista::stampaArticoliDaComprare() {
    cout << "Articoli da comprare nella lista " << IDlista << ": " << endl;

    for (auto &a : listaArt) {
        shared_ptr<Articolo>& articolo = a.second;
        if (!articolo->isAcquistato()) {
            cout << "Nome: " << a.second->getIDarticolo() << endl;
            cout << "Quantità: " << a.second->getQt() << endl;
            cout << "Categoria: " << a.second->getCat() << endl;
            cout << "**************************" << endl;
        }
    }
}

void Lista::subscribe(Observer *o) {
    observers.push_back(o);
}

void Lista::unsubscribe(Observer *o) {
    observers.remove(o);
}

void Lista::notify() {
    for(auto &itr : observers)
        itr -> update(IDlista);
}