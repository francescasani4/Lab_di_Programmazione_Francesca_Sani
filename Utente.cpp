//
// Created by Francesca Sani
//

#include "Utente.h"
void Utente::aggiungiLista(Lista* lista) {
    liste.push_back(lista);
    lista -> subscribe(this);
}

void Utente::rimuoviLista(Lista* lista) {
    liste.erase(remove(liste.begin(), liste.end(), lista), liste.end());
    lista -> unsubscribe(this);
}

void Utente::update(string& IDLista) {
    cout << "NOTIFICA!" << endl;
    cout << IDutente << endl;
    cout << "La lista " << IDLista << "è stata aggiornata." << endl;
}
