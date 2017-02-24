#include<iostream>
#include "WeatherData.h"
#include "CurrentConditionsDisplay.h"
#include "StatisticsDisplay.h"
#include "expat.h"
#include <curlpp/curlpp>

  int main(int argc, char ** argv)
  {

    WeatherStation::WeatherData * weatherData = new WeatherStation::WeatherData();
    WeatherStation::CurrentConditionsDisplay * currentDisplay = new WeatherStation::CurrentConditionsDisplay(weatherData);
    WeatherStation::StatisticDisplay * statisticsDisplay = new WeatherStation::StatisticDisplay(weatherData);

    (void)currentDisplay; // I am suppressing unused function warning
    (void)statisticsDisplay;

    weatherData->setMeasurements(90, 64, 30);
    weatherData->setMeasurements(95, 60, 33);
    weatherData->setMeasurements(80, 0, 20);

    return 0;

  }



