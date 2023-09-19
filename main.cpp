#include <iostream>
#include "Lista.h"
#include "Utente.h"
#include <string>
using namespace std;

int main() {
    /*creare 5 liste*/
    Lista* lista1 = new Lista("Casa");
    Lista* lista2 = new Lista("Lavoro");
    Lista* lista3 = new Lista("Cibo");
    Lista* lista4 = new Lista("Animali");
    Lista* lista5 = new Lista("Scuola");

    /*creare 3 utenti*/
    Utente* utente1 = new Utente("Francesca");
    Utente* utente2 = new Utente("Alessia");
    Utente* utente3 = new Utente("Salvatore");

    /*creare 10 articolo*/
    Articolo* articolo1 = new Articolo("Pasta", "Cibo", 3);
    Articolo* articolo2 = new Articolo("Agenda", "Cartoleria", 1);
    Articolo* articolo3 = new Articolo("Sapone", "Pulizia", 2);
    Articolo* articolo4 = new Articolo("Croccantini", "Cane", 1);
    Articolo* articolo5 = new Articolo("Penne", "Cartoleria", 5);
    Articolo* articolo6 = new Articolo("Pollo", "Cibo", 2);
    Articolo* articolo7 = new Articolo("Detersivo", "Pulizia", 1);
    Articolo* articolo8 = new Articolo("Astuccio", "Cartoleria", 1);
    Articolo* articolo9 = new Articolo("Caricabatteria", "Tecnologia", 2);
    Articolo* articolo10 = new Articolo("Pallina", "Gioco", 1);

    /*associa gli utenti alle liste*/
    utente1->aggiungiLista(lista1);
    utente2->aggiungiLista(lista1);
    utente3->aggiungiLista(lista1);
    utente2->aggiungiLista(lista2);
    utente3->aggiungiLista(lista2);
    utente1->aggiungiLista(lista3);
    utente1->aggiungiLista(lista4);
    utente1->aggiungiLista(lista5);

    /*aggiungere gli articoli alle liste*/
    /*lista1->aggiungiArticolo(articolo3);
    lista1->aggiungiArticolo(articolo7);
    lista2->aggiungiArticolo(articolo2);
    lista2->aggiungiArticolo(articolo9);*/
    lista3->aggiungiArticolo(articolo1);
    lista3->aggiungiArticolo(articolo6);
    /*lista4->aggiungiArticolo(articolo4);
    lista4->aggiungiArticolo(articolo10);*/
    lista5->aggiungiArticolo(articolo5);
    lista5->aggiungiArticolo(articolo8);

    cout << "__________________________________________________" << endl;

    /*stampa chi partecipa alla lista1*/
    cout << "Partecipanti della lista " << lista1->getIDlista() << endl;
    list<Observer *> o = lista1->getObservers();
    for (auto itr : o) {
        if(itr == utente1) {
            cout << utente1->getIDutente() << endl;
        } else if(itr == utente2) {
            cout << utente2->getIDutente() << endl;
        } else {
            cout << utente3->getIDutente() << endl;
        }
    }

    cout << "__________________________________________________" << endl;

    /*stampa articoli nella lista5 prima e dopo aver aggiunto e rimosso degli articoli*/
    cout << "Articoli presenti nella lista " << lista5->getIDlista() << endl;
    map<string, Articolo *> articoli;
    articoli = lista5->getListaArt();
    for(auto itr : articoli) {
        cout << itr.second->getIDarticolo() << endl;
    }
    cout << "__________________________________________________" << endl;
    lista5->aggiungiArticolo(new Articolo("Gomma", "Cancelleria", 2));
    cout << "Articoli presenti nella lista " << lista5->getIDlista() << endl;
    articoli = lista5->getListaArt();
    for(auto itr : articoli) {
        cout << itr.second->getIDarticolo() << endl;
    }
    cout << "__________________________________________________" << endl;
    lista5->rimuoviArticolo("Astuccio");
    cout << "Articoli presenti nella lista " << lista5->getIDlista() << endl;
    articoli = lista5->getListaArt();
    for(auto itr : articoli) {
        cout << itr.second->getIDarticolo() << endl;
    }

    cout << "__________________________________________________" << endl;

    /*impostare un articolo come comprato*/
    cout << "L'articolo PASTA è stato acquistato" << endl;
    lista3->setComprato("Pasta");

    cout << "__________________________________________________" << endl;

    /*stampare liste di utente1*/
    cout << "Liste di " << utente1->getIDutente() << ":" << endl;
    map<string, Lista*> liste;
    liste = utente1->getListe();
    for(auto itr:liste) {
        cout << itr.second->getIDlista() << endl;
    }

    cout << "__________________________________________________" << endl;

    /*rimuovere lista "Casa" a utente1 e stampare le sue liste*/
    utente1->rimuoviLista("Casa");
    cout << "Liste di " << utente1->getIDutente() << ":" << endl;
    liste = utente1->getListe();
    for(auto itr:liste) {
        cout << itr.second->getIDlista() << endl;
    }

    return 0;
}