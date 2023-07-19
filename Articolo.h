//
// Created by Francesca Sani
//

#ifndef LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_ARTICOLO_H
#define LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_ARTICOLO_H

#include <string>

using namespace std;

class Articolo {
public:
    Articolo(string IDarticolo, string cat, int qt): IDarticolo(IDarticolo), cat(cat) {
        if(qt > 0)
            qt = qt;
        else
            /* stampare errore */

        acquistato = false;
    }

    virtual ~Articolo() {};

    const string &getIDarticolo() const {
        return IDarticolo;
    }

    void setIDarticolo(const string &iDarticolo) {
        IDarticolo = iDarticolo;
    }

    const string &getCat() const {
        return cat;
    }

    void setCat(const string &cat) {
        Articolo::cat = cat;
    }

    int getQt() const {
        return qt;
    }

    void setQt(int qt) {
        Articolo::qt = qt; /* fare controllo se valore valido */
    }

    bool isAcquistato() const {
        return acquistato;
    }

    void setAcquistato(bool acquistato) {
        Articolo::acquistato = acquistato;
    }

private:
    string IDarticolo; /* Nome articolo */
    string cat; /* Categoria */
    int qt; /* Quantità */
    bool acquistato; /* Indica se l'atricolo è stato acquistato o meno */
};


#endif //LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_ARTICOLO_H
