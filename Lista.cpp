//
// Created by Francesca Sani
//

#include "Lista.h"

void Lista::aggiungiArticolo(Articolo &IDarticolo) {
    auto itr = listaArt.find(IDarticolo.getIDarticolo());

    if(itr != listaArt.end()) {
        itr -> second->setQt(itr -> second->getQt() + IDarticolo.getQt());
    } else {
        listaArt.insert(make_pair(IDarticolo.getIDarticolo(),&IDarticolo));
    }

    notify();
}

void Lista::rimuoviArticolo(string &art) {
    auto itr = listaArt.find(art);

    if(itr != listaArt.end()) {
        listaArt.erase(itr);
        notify();
    } else {
        cout << "ERRORE!" << endl;
    }
}

void Lista::setComprato(string &art) {
    auto itr = listaArt.find(art);

    if (itr != listaArt.end()) {
        bool acq = itr -> second -> isAcquistato();

        if(acq)
            itr -> second -> setAcquistato(false);
        else
            itr -> second ->setAcquistato(true);

        notify();
    } else {
        cout << "ERRORE!" << endl;
    }
}

int Lista::setNonComprato() {
    int r = 0;

    for(auto &itr: listaArt) {
        if(!itr.second -> isAcquistato()) {
            r += itr.second->getQt();
        }
    }

    return r;
}

void Lista::stampaArticoliDaComprare() {
    int r = 0;
    cout << "Articoli da comprare nella lista " << IDlista << ": " << endl;

    for (const auto& a : listaArt) {
        const Articolo* articolo = a.second;
        if (!articolo->isAcquistato()) {
            std::cout << "Nome: " << articolo->getIDarticolo() << std::endl;
            std::cout << "Quantità: " << articolo->getQt() << std::endl;
            std::cout << "-------------------" << std::endl;
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