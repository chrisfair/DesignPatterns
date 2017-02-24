#include "CurrentConditionsDisplay.h"
#include <iostream>

namespace WeatherStation {

  CurrentConditionsDisplay::CurrentConditionsDisplay(Subject * weatherData) {
    this->weatherData = weatherData;
    weatherData->registerObserver(this);

  }


  CurrentConditionsDisplay::~CurrentConditionsDisplay()
  {


  }


  void CurrentConditionsDisplay::update (float temperature, float humidity, float pressure){

    this->temperature = temperature;
    this->humidity = humidity;
    display();

  }

  void CurrentConditionsDisplay::display(){

    std::cout<<"Current conditions: " << temperature 
                                      << "F degrees and "
                                      <<humidity 
                                      << "% humidity"
                                      <<std::endl;

  }
}

