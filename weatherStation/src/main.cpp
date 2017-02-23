#include<iostream>
#include "WeatherData.h"
#include "CurrentConditionDisplay.h"

namespace WeatherStation {


  int main(int argc, char ** argv)
  {

    WeatherData weatherData = new WeatherData();
    std::cout<<"Hello Weather Station!"<<std::endl;

    return 0;

  }

}


