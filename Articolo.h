//
// Created by Francesca Sani
//

#ifndef LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_ARTICOLO_H
#define LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_ARTICOLO_H

#include <string>
#include <stdexcept>

using namespace std;

class Articolo {
public:
    Articolo(const string& IDarticolo,const string& cat, int qt): IDarticolo(IDarticolo), cat(cat) {
        if(qt > 0)
            this -> qt = qt;
        else
            throw invalid_argument("La quantità inserita deve avere valore positivo!");

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
        if(qt > 0)
            Articolo::qt = qt;
        else
            throw invalid_argument("La quantità inserita deve avere valore positivo!");
    }

    bool isAcquistato() const {
        return acquistato;
    }

    void setAcquistato(bool acquistato) {
        Articolo::acquistato = acquistato;
    }

private:
    string IDarticolo;
    string cat;
    int qt;
    bool acquistato;
};


#endif //LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_ARTICOLO_H
