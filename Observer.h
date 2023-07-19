//
// Created by Francesca Sani on 11/07/23.
//

#ifndef LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_OBSERVER_H
#define LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_OBSERVER_H

/*using namespace std;*/

#include <string>

class Observer {
public:
    virtual ~Observer() = default; /*vedere cosa fa default */

    virtual void update() = 0; /*aggiungere eventuali parametri*/
};


#endif //LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_OBSERVER_H
