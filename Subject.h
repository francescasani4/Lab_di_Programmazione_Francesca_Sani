//
// Created by Francesca Sani on 11/07/23.
//

#ifndef LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_SUBJECT_H
#define LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_SUBJECT_H

/*using namespace std;*/

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;

    virtual void subscribe(Observer* o) = 0;
    virtual void unsubscribe(Observer* o) = 0;
    virtual void notify() = 0;
};


#endif //LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_SUBJECT_H
