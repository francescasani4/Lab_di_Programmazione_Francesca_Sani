//
// Created by Francesca Sani
//

#include "Lista.h"

void Lista::aggiungiArticolo(Articolo &IDarticolo) {
    auto itr = articoli.find(IDarticolo.getIDarticolo());

    if(itr != articoli.end()) {
        itr -> second.setQt(itr->second.getQt() + IDarticolo.getQt());
    }
    else {
        articoli.emplace(IDarticolo.getIDarticolo(), IDarticolo);
    }

    notify();
}

void Lista::rimuoviArticolo(Articolo &IDarticolo) {
    bool result = cercaArticolo((IDarticolo));
    if(result) {
        articoli.erase(IDarticolo.getIDarticolo());
        notify();
    }
    else {
        cout << "Articolo non trovato!" << endl;
    }
}

bool Lista::cercaArticolo(Articolo &IDarticolo) {
    auto itr = articoli.find(IDarticolo.getIDarticolo());

    if(itr == articoli.end()) {
        return false;
    }
    else {
        return true;
    }
}

void Lista::setComprato(Articolo &IDarticolo) {

}

void Lista::subscribe(Observer *o) {
    observers.push_back(o);
}

void Lista::unsubscribe(Observer *o) {
    observers.remove(o);
}

void Lista::notify() {
    for(auto &itr : observers)
        itr -> update(IDlista); /*si passa il nome della lista*/
}
