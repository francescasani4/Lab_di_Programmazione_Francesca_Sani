//
// Created by Francesca Sani
//

#ifndef LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_SUBJECT_H
#define LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_SUBJECT_H

#include "Observer.h"

using namespace std;

class Subject {
public:
    virtual ~Subject() = default;

    virtual void subscribe(Observer* o) = 0;
    virtual void unsubscribe(Observer* o) = 0;
    virtual void notify() = 0;
};


#endif //LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_SUBJECT_H
