//
// Created by Francesca Sani
//

#include "Utente.h"
void Utente::aggiungiLista(Lista* lista) {
    liste.insert(make_pair(lista->getIDlista(), lista));
    lista->subscribe(this);
}

void Utente::rimuoviLista(const string& lista) {
    auto itr = liste.find(lista);

    if(itr != liste.end()) {
        itr -> second ->unsubscribe(this);
        liste.erase(lista);
    }
}

void Utente::update(const string& IDLista) {
    auto itr = liste.find(IDLista);

    cout << "La lista " << IDLista << " è stata AGGIORNATA!" << endl;
    itr -> second -> stampaArticoliDaComprare();
}