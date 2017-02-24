#ifndef CURRENT_CONDITIONS_ELEMENT_H
#define CURRENT_CONDITIONS_ELEMENT_H

#include "DisplayElement.h"
#include "Observer.h"
#include "Subject.h"

namespace WeatherStation {


  class CurrentConditionsDisplay : public Observer,  public DisplayElement {



    public:
      CurrentConditionsDisplay(Subject * weatherData);
      virtual ~CurrentConditionsDisplay();
      virtual void update (float temperature, float humidity, float pressure);
      virtual void display();
      

    private:
      float temperature;
      float humidity;
      Subject * weatherData;

  };
}




#endif // CURRENT_CONDITIONS_ELEMENT_H



