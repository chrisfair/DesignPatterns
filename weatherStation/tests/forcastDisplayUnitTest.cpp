#include<iostream>


// Braket your tested classes with these defines / undefs
// if you want to test your protected and private methods
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

  const int averageTemperature = forcastDisplay->getAverage(forcastDisplay->historicalTemperatures);
  const int averageHumidities = forcastDisplay->getAverage(forcastDisplay->historicalHumidities);
  const int averagePressures = forcastDisplay->getAverage(forcastDisplay->historicalPressures);

  const bool thatAllAveragesAreThirty = ((averageTemperature == 30) &&
                                         (averageHumidities == 30) &&
                                         (averagePressures == 30));

  const bool numberOfTemperatures = forcastDisplay->historicalTemperatures.size() == 5;
  const bool numberOfHumidities = forcastDisplay->historicalHumidities.size() == 5;
  const bool numberOfPressures = forcastDisplay->historicalPressures.size() == 5;


  const bool thatThereAreFiveReadings = numberOfTemperatures &&
    numberOfHumidities &&
    numberOfPressures;

  REQUIRE( thatAllAveragesAreThirty ); // average should be thirty for all members
  REQUIRE( thatThereAreFiveReadings );  

  (void)forcastDisplay;
  delete forcastDisplay;
  delete weatherData;
}





