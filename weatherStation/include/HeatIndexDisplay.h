#ifndef HEAT_INDEX_ELEMENT_H
#define HEAT_INDEX_ELEMENT_H

#include "DisplayElement.h"
#include "Observer.h"
#include "Subject.h"

namespace WeatherStation {


  class HeatIndexDisplay : public Observer,  public DisplayElement {



    public:
      HeatIndexDisplay(Subject * weatherData);
      virtual ~HeatIndexDisplay();
      virtual void update (float temperature, float humidity, float pressure);
      virtual void display();
      

    private:
      float temperature; 
      float humidity;
      float pressure;
      Subject * weatherData;
      float computeHeatIndex(float t, float rh);

  };
}




#endif // HEAT_INDEX_ELEMENT_H



