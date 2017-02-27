#ifndef FORCAST_DISPLAY_H
#define FORCAST_DISPLAY_H

#include "DisplayElement.h"
#include "Observer.h"
#include "Subject.h"
#include <vector>


namespace WeatherStation {


  class ForcastDisplay : public Observer,  public DisplayElement {



    public:
      ForcastDisplay(Subject * weatherData);
      virtual ~ForcastDisplay();
      virtual void update (float temperature, float humidity, float pressure);
      virtual void display();
      

    private:
      float getAverage(std::vector<float> & vectorToAverage);

      std::vector<float> historicalTemperatures;
      std::vector<float> historicalHumidities;
      std::vector<float> historicalPressures;
   
      Subject * weatherData;

  };
}




#endif // FORCAST_DISPLAY_H



