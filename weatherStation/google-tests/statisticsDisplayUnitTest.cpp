// Bracket your tested classes with these defines / undefs
// if you want to test your protected and private methods
#define protected public
#define private public
#include "StatisticsDisplay.h"
#include "WeatherData.h"
#undef protected
#undef private 

#include "gtest/gtest.h"

TEST(StatisticsDisplayUnitTests, Examples) {
   WeatherStation::WeatherData * weatherData = new WeatherStation::WeatherData();
   WeatherStation::StatisticsDisplay * statisticsDisplay = new WeatherStation::StatisticsDisplay(weatherData);


   weatherData->setMeasurements(10, 10, 10.0f);
   weatherData->setMeasurements(20, 20, 20.0f);
   weatherData->setMeasurements(30, 30, 30.0f);
   weatherData->setMeasurements(40, 40, 40.0f);
   weatherData->setMeasurements(50, 50, 50.0f);

   const int averageTemperature = statisticsDisplay->getAverage(statisticsDisplay->historicalTemperatures);
   const int averageHumidities = statisticsDisplay->getAverage(statisticsDisplay->historicalHumidities);
   const int averagePressures = statisticsDisplay->getAverage(statisticsDisplay->historicalPressures);

   const bool thatAllAveragesAreThirty = ((averageTemperature == 30) &&
                                          (averageHumidities == 30) &&
                                          (averagePressures == 30));

   const bool numberOfTemperatures = statisticsDisplay->historicalTemperatures.size() == 5;
   const bool numberOfHumidities = statisticsDisplay->historicalHumidities.size() == 5;
   const bool numberOfPressures = statisticsDisplay->historicalPressures.size() == 5;


   const bool thatThereAreFiveReadings = numberOfTemperatures &&
      numberOfHumidities &&
      numberOfPressures;

   // These are the actual unit tests the rest is really set up

   ASSERT_TRUE( thatAllAveragesAreThirty );
   ASSERT_TRUE( thatThereAreFiveReadings );  

   (void)statisticsDisplay;
   delete statisticsDisplay;
   delete weatherData;

}

