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

    virtual ~Utente() {
        for(auto &itr : liste) {
            itr.second ->unsubscribe(this);
        }
    };

    const string &getIDutente() const {
        return IDutente;
    }

    void setIDutente(const string &iDutente) {
        IDutente = iDutente;
    }

    const map<string, Lista*> &getListe() const {
        return liste;
    }

    void aggiungiLista(Lista* lista);
    void rimuoviLista(const string& lista);

    void update(const string& IDLista) override;

private:
    string IDutente;
    map<string, Lista*> liste;
};


#endif //LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_UTENTE_H