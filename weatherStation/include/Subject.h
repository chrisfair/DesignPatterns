#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

namespace WeatherStation {

    class Subject {

      public:
          Subject();
          virtual ~Subject(); 
          virtual void registerObserver(Observer *o);
          virtual void removeObserver(Observer *o);
          virtual void notifyObservers();

    };


}
#endif //SUBJECET_H
