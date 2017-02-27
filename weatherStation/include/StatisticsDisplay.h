
#ifndef STATISTICS_STATION_H
#define STATISTICS_STATION_H

#include "DisplayElement.h"
#include "Observer.h"
#include "Subject.h"
#include <vector>


namespace WeatherStation {


  class StatisticDisplay : public Observer,  public DisplayElement {



    public:
      StatisticDisplay(Subject * weatherData);
      virtual ~StatisticDisplay();
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




#endif // STATISTICS_STATION_H



