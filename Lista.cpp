//
// Created by Francesca Sani
//

#include "Lista.h"

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
