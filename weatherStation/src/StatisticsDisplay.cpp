#include "StatisticsDisplay.h"
#include <iostream>

namespace WeatherStation {

  StatisticDisplay::StatisticDisplay(Subject * weatherData) {
    this->weatherData = weatherData;
    weatherData->registerObserver(this);

  }


  StatisticDisplay::~StatisticDisplay()
  {


  }


  void StatisticDisplay::update(float temperature, float humidity, float pressure){

    historicalTemperatures.push_back(temperature);
    historicalHumidities.push_back(humidity);
    historicalPressures.push_back(pressure);

    display();

  }

  float StatisticDisplay::getAverage(std::vector<float> & vectorToAverage)
  {

    float sumOfValues = 0;
    float averageValue = 0; 

    for (auto& value : vectorToAverage)
    {
      sumOfValues += value;

    }

    if (vectorToAverage.size() > 0)
    {
      averageValue = sumOfValues / vectorToAverage.size();

    }

    return averageValue;
  }


  void StatisticDisplay::display(){

    std::cout<<"Current average conditions: " << getAverage(historicalTemperatures) 
      << "F degrees and "
      <<getAverage(historicalHumidities) 
      << "\% humidity "
      <<getAverage(historicalPressures)
      << " pressure "
      <<std::endl;

  }
}

