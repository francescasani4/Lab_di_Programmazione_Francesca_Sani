//
// Created by Francesca Sani
//

#ifndef LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_OBSERVER_H
#define LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_OBSERVER_H

#include <string>

using namespace std;

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update(const string& IDlista) = 0;
};


#endif //LAB_DI_PROGRAMMAZIONE_FRANCESCA_SANI_OBSERVER_H
