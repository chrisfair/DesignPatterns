#include<iostream>
#include "WeatherData.h"
#include "CurrentConditionsDisplay.h"
#include "StatisticsDisplay.h"
#include "ForcastDisplay.h"
#include "HeatIndexDisplay.h"


  int main(int argc, char ** argv)
  {

    WeatherStation::WeatherData * weatherData = new WeatherStation::WeatherData();
    WeatherStation::CurrentConditionsDisplay * currentDisplay = new WeatherStation::CurrentConditionsDisplay(weatherData);
    WeatherStation::StatisticDisplay * statisticsDisplay = new WeatherStation::StatisticDisplay(weatherData);
    WeatherStation::ForcastDisplay * forcastDisplay = new WeatherStation::ForcastDisplay(weatherData);
    WeatherStation::HeatIndexDisplay * heatIndexDisplay  = new WeatherStation::HeatIndexDisplay(weatherData);

    (void)currentDisplay; // I am suppressing unused function warning
    (void)statisticsDisplay;
    (void)forcastDisplay;
    (void)heatIndexDisplay;

    weatherData->setMeasurements(80, 65, 10.4f);
    weatherData->setMeasurements(92, 70, 50.4f);
    weatherData->setMeasurements(78, 90, 30.4f);
    weatherData->setMeasurements(78, 90, 20.4f);
    weatherData->setMeasurements(78, 90, 4.4f);

    delete weatherData;
    delete currentDisplay;
    delete statisticsDisplay;
    delete forcastDisplay;
    delete heatIndexDisplay;

    return 0;

  }




