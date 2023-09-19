#include <iostream>
#include "Lista.h"
#include "Utente.h"
#include <string>
using namespace std;

int main() {

    cout << endl;
    cout << "BENVENUTO/A!" << "\n"
    << "Questo è un programma dove vengono create delle liste, degli utenti e degli articoli \n"
    << "per simulare il comportamento di un'applicazione che permette di scriversi le proprie liste della spesa." << endl;
    cout << endl;
    cout << "__________________________________________________" << endl;

    /*Creazione di 5 liste*/
    Lista* lista1 = new Lista("Casa");
    Lista* lista2 = new Lista("Lavoro");
    Lista* lista3 = new Lista("Cibo");
    Lista* lista4 = new Lista("Animali");
    Lista* lista5 = new Lista("Scuola");

    cout << endl;
    cout << "Sono state create le seguenti liste:" << "\n";
    cout << lista1->getIDlista() << ", " << lista2->getIDlista() << ", " << lista3->getIDlista() << ", "
    << lista4->getIDlista() << ", " << lista5->getIDlista() << endl;
    cout << endl;
    cout << "__________________________________________________" << endl;

    /*Creazione di 3 utenti*/
    Utente* utente1 = new Utente("Francesca");
    Utente* utente2 = new Utente("Alessia");
    Utente* utente3 = new Utente("Salvatore");

    cout << endl;
    cout << "Sono state creati i seguenti utenti:" << "\n";
    cout << utente1->getIDutente() << ", " << utente2->getIDutente() << ", " << utente3->getIDutente() << endl;
    cout << endl;
    cout << "__________________________________________________" << endl;

    /*Creazione di 10 articoli*/
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

    cout << endl;
    cout << "Sono state creati i seguenti articoli:" << "\n";
    cout << articolo1->getIDarticolo() << ", " << articolo2->getIDarticolo() << ", " << articolo3->getIDarticolo() << ", "
    << articolo4->getIDarticolo() << ", " << articolo5->getIDarticolo() << ", " << articolo6->getIDarticolo() << ", "
    << articolo7->getIDarticolo() << ", " << articolo8->getIDarticolo() << ", " << articolo9->getIDarticolo() << ", "
    << articolo10->getIDarticolo() << endl;
    cout << endl;
    cout << "__________________________________________________" << endl;

    /*Si associa ogni utente a delle liste*/
    utente1->aggiungiLista(lista1);
    utente2->aggiungiLista(lista1);
    utente3->aggiungiLista(lista1);
    utente2->aggiungiLista(lista2);
    utente3->aggiungiLista(lista2);
    utente1->aggiungiLista(lista3);
    utente1->aggiungiLista(lista4);
    utente1->aggiungiLista(lista5);

    /*Stampa le liste di utente1*/
    cout << endl;
    cout << "Liste di " << utente1->getIDutente() << ":" << endl;
    map<string, Lista*> liste;
    liste = utente1->getListe();
    for(auto itr:liste) {
        cout << itr.second->getIDlista() << endl;
    }
    cout <<endl;
    cout << "__________________________________________________" << endl;

    /*Rimuove lista "Casa" a utente1 e stampa le sue liste*/
    utente1->rimuoviLista("Casa");

    cout << endl;
    cout << "Liste di " << utente1->getIDutente() << ":" << endl;
    liste = utente1->getListe();
    for(auto itr:liste) {
        cout << itr.second->getIDlista() << endl;
    }
    cout <<endl;
    cout << "__________________________________________________" << endl;

    /*Stampa chi partecipa alla lista2*/
    cout <<endl;
    cout << "Partecipanti della lista " << lista2->getIDlista() << ":" << endl;
    list<Observer *> o = lista2->getObservers();
    for (auto itr : o) {
        if(itr == utente1) {
            cout << utente1->getIDutente() << endl;
        } else if(itr == utente2) {
            cout << utente2->getIDutente() << endl;
        } else {
            cout << utente3->getIDutente() << endl;
        }
    }
    cout <<endl;
    cout << "__________________________________________________" << endl;

    /*Aggiunge gli articoli alle liste*/
    cout <<endl;
    lista1->aggiungiArticolo(articolo3);
    lista1->aggiungiArticolo(articolo7);
    lista2->aggiungiArticolo(articolo2);
    lista2->aggiungiArticolo(articolo9);
    lista3->aggiungiArticolo(articolo1);
    lista3->aggiungiArticolo(articolo6);
    lista4->aggiungiArticolo(articolo4);
    lista4->aggiungiArticolo(articolo10);
    lista5->aggiungiArticolo(articolo5);
    lista5->aggiungiArticolo(articolo8);
    cout <<endl;
    cout << "__________________________________________________" << endl;

    /*Stampa gli articoli nella lista5 prima e dopo aver aggiunto e rimosso degli articoli*/
    cout << endl;
    cout << "Articoli presenti nella lista " << lista5->getIDlista() << ": " << endl;
    map<string, Articolo *> articoli;
    articoli = lista5->getListaArt();
    for(auto itr : articoli) {
        cout << itr.second->getIDarticolo() << endl;
    }
    cout << endl;
    cout << "__________________________________________________" << endl;
    cout << endl;
    lista5->aggiungiArticolo(new Articolo("Gomma", "Cancelleria", 2));
    cout << endl;
    cout << "Articoli presenti nella lista " << lista5->getIDlista() << ": " << endl;
    articoli = lista5->getListaArt();
    for(auto itr : articoli) {
        cout << itr.second->getIDarticolo() << endl;
    }
    cout << endl;
    cout << "__________________________________________________" << endl;
    cout << endl;
    lista5->rimuoviArticolo("Astuccio");
    cout << endl;
    cout << "Articoli presenti nella lista " << lista5->getIDlista() << ": " << endl;
    articoli = lista5->getListaArt();
    for(auto itr : articoli) {
        cout << itr.second->getIDarticolo() << endl;
    }
    cout << endl;
    cout << "__________________________________________________" << endl;
    cout << endl;
    lista5->rimuoviArticolo("Diario");
    cout << endl;
    cout << "Articoli presenti nella lista " << lista5->getIDlista() << ": " << endl;
    articoli = lista5->getListaArt();
    for(auto itr : articoli) {
        cout << itr.second->getIDarticolo() << endl;
    }
    cout << endl;
    cout << "__________________________________________________" << endl;

    /*Imposta un articolo come comprato*/
    cout << endl;
    cout << "L'articolo PASTA è stato acquistato" << endl;
    cout << endl;
    lista3->setComprato("Pasta");
    cout << endl;
    cout << "__________________________________________________" << endl;



    return 0;
}