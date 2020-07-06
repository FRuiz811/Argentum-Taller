#ifndef ARGENTUM_TALLER_SUBJECT_H
#define ARGENTUM_TALLER_SUBJECT_H


#include <vector>
#include "Observer.h"

class Subject {
private:
    std::vector<Observer> observers;
public:
    Subject();

    virtual void Attach(Observer* observer) = 0;

    virtual void Detach(Observer* observer) = 0;

    virtual void Notify() = 0;

    virtual ~Subject();

};


#endif //ARGENTUM_TALLER_SUBJECT_H
