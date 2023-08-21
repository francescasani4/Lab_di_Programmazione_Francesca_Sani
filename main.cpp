

#include <iostream>
#include "Utente.h" // Assumo che tu abbia definito la classe Utente
#include "Lista.h"  // Assumo che tu abbia definito la classe Lista

int main() {
    // Creazione di alcuni articoli
    Articolo articolo1("001", "Alimenti", 2);
    Articolo articolo2("002", "Abbigliamento", 1);
    Articolo articolo3("005", "Casa", 1);


    // Creazione di una lista della spesa
    Lista lista1((string &) "Lista1");
    Lista lista2((string&) "Lista2");

    // Creazione di un utente
    Utente utente1("Mario");
    Utente utente2("Paolo");

    // Iscrizione dell'utente alla lista
    utente1.aggiungiLista(&lista1);
    utente1.aggiungiLista(&lista2);
    utente2.aggiungiLista(&lista1);

    // Aggiunta di articoli alla lista
    lista1.aggiungiArticolo(articolo1);
    lista1.aggiungiArticolo(articolo2);
    lista1.aggiungiArticolo(articolo3);

    // Rimozione di un articolo dalla lista
    lista1.rimuoviArticolo(articolo1);

    // Stampa delle liste a cui l'utente è iscritto
    std::cout << "Liste partecipate da " << utente1.getIDutente() << ":" << std::endl;
    for (Lista* lista : utente1.getListe()) {
        std::cout << " - " << lista->getIDlista() << std::endl;
    }

    return 0;
}