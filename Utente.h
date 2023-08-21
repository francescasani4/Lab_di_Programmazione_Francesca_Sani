//
// Created by Francesca Sani
//

#ifndef LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_UTENTE_H
#define LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_UTENTE_H

#include "Observer.h"
#include "Lista.h"

#include <list>
#include <map>
#include <iostream>

using namespace std;

class Utente : public Observer {
public:
    Utente(const string& IDutente) : IDutente(IDutente) {}

    virtual ~Utente() {};

    const string &getIDutente() const {
        return IDutente;
    }

    void setIDutente(const string &iDutente) {
        IDutente = iDutente;
    }

    const vector<Lista *> &getListe() const {
        return liste;
    }

    void setListe(const vector<Lista *> &liste) {
        Utente::liste = liste;
    }


    void aggiungiLista(Lista* lista);
    void rimuoviLista(Lista* lista);

    void update(string& IDLista) override;

private:
    string IDutente;
    vector<Lista*> liste;
};


#endif //LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_UTENTE_H