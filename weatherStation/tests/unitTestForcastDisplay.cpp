#include<iostream>

#define protected public
#define private public
#include "ForcastDisplay.h"
#include "WeatherData.h"
#undef protected
#undef private 

#include "catch.hpp"


TEST_CASE ( "Forcast Display Unit Tests", "[forcastDisplay]" ) {
  WeatherStation::WeatherData * weatherData = new WeatherStation::WeatherData();
  WeatherStation::ForcastDisplay * forcastDisplay = new WeatherStation::ForcastDisplay(weatherData);

  weatherData->setMeasurements(10, 10, 10.0f);
  weatherData->setMeasurements(20, 20, 20.0f);
  weatherData->setMeasurements(30, 30, 30.0f);
  weatherData->setMeasurements(40, 40, 40.0f);
  weatherData->setMeasurements(50, 50, 50.0f);

  const int getAverageTemperature = forcastDisplay->getAverage(forcastDisplay->historicalTemperatures);

  REQUIRE( getAverageTemperature == 30 ); 

  (void)forcastDisplay;
  delete forcastDisplay;
  delete weatherData;


}





