#include "ForcastDisplay.h"
#include <iostream>

namespace WeatherStation {

  ForcastDisplay::ForcastDisplay(Subject * weatherData) 
  {
    this->weatherData = weatherData;
    weatherData->registerObserver(this);

  }

  ForcastDisplay::~ForcastDisplay()
  {


  }

  void ForcastDisplay::update(float temperature, float humidity, float pressure)
  {
    historicalTemperatures.push_back(temperature);
    historicalHumidities.push_back(humidity);
    historicalPressures.push_back(pressure);
    float lengthOfPressureVector = static_cast<float>(this->historicalPressures.size());
    historicalOrdinal.push_back(lengthOfPressureVector);
    display();
  }

  float ForcastDisplay::getAverage(std::vector<float> & vectorToAverage)
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

  float ForcastDisplay::getSum(std::vector<float> & vectorToSum)
  {

    float sumOfValues = 0;

    for (auto& value : vectorToSum)
    {
      sumOfValues += value;
    }

    return sumOfValues;
  }

  float ForcastDisplay::getSlopeOfLine(std::vector<float> & firstVector,
                                       std::vector<float> & secondVector)
  {

    float slope = 0;
    float A = getSum(firstVector);
    float B = getSum(secondVector);
    float C = getSumOfTwoMultipliedTogetherVectors(firstVector, firstVector);
    float D = getSumOfTwoMultipliedTogetherVectors(firstVector, secondVector);

    float n = static_cast<float>(firstVector.size());

    slope = (n*D-A*B) / (n*C-A*A);

    return slope;

  }

  std::string ForcastDisplay::getForcast()
  {

    std::string returnedString = "Not enough data for a trend yet.";


    std::vector<float> subsetOfHistoricalOrdinal; 
    std::vector<float> subsetOfHistoricalPressures;

    if (historicalOrdinal.size()>2)

    {


      float forcastFromData = getSlopeOfLine(historicalOrdinal, historicalPressures);
      const bool historicalPressureHasMoreThanOneElement = historicalPressures.size() > 1; 
      std::cout<<"slope is "<<forcastFromData<<std::endl; 
      if (historicalPressureHasMoreThanOneElement
          &&  (forcastFromData < -1))
      {
        returnedString = "Watch out for cooler, rainy weather";

      }
      else if (historicalPressureHasMoreThanOneElement
               && (forcastFromData > 1))
      {

        returnedString = "Improving weather on the way!";

      }
      else
      {
        returnedString  = "More of the same!";

      }

    }

    return returnedString;
  }



  float ForcastDisplay::getSumOfTwoMultipliedTogetherVectors(std::vector<float> & firstVector,
                                                             std::vector<float> & secondVector)
  {

    float sumOfValues = 0;

    if (firstVector.size() == secondVector.size())
    {

      for (int i =0; i < firstVector.size(); i++)
      {
        sumOfValues += (firstVector[i] * secondVector[i]);
      }
    }

    return sumOfValues;
  }


  void ForcastDisplay::display(){

    std::cout<<getForcast()<<std::endl;
  }
}

