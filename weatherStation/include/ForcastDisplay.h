#ifndef FORCAST_DISPLAY_H
#define FORCAST_DISPLAY_H

#include <string>
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
      float getSum(std::vector<float> & vectorToAverage);

      std::vector<float> historicalTemperatures;
      std::vector<float> historicalHumidities;
      std::vector<float> historicalPressures;
      std::vector<float> historicalOrdinal;
      float getSumOfTwoMultipliedTogetherVectors(std::vector<float> & firstVector, std::vector<float> & secondVector);
      std::string getForcast();
      float getSlopeOfLine(std::vector<float> & firstVector, std::vector<float> & secondVector);

      Subject * weatherData;

  };
}




#endif // FORCAST_DISPLAY_H



