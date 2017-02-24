#include "WeatherData.h"
#include "Subject.h"
#include "Observer.h"
#include <algorithm>
#include <vector>
#include <list>
namespace WeatherStation {

  WeatherData::WeatherData() 
  {


  }

  WeatherData::~WeatherData() 
  {


  }


  void WeatherData::registerObserver(Observer *o) 
  {
    observers.push_back(o);
  }


  void WeatherData::removeObserver(Observer *o)
  {



    const std::ptrdiff_t locationOfObserver = std::find(observers.begin(),
                                                       observers.end(),
                                                       o) - observers.begin();


    const bool theObserverWasFound = locationOfObserver != (observers.end() - observers.begin());

    if (theObserverWasFound) 
    {

      const int indexOfElement = static_cast<int>(locationOfObserver);

      observers.erase(indexOfElement + observers.begin());
    }


  }

  void WeatherData::notifyObservers()

  {
    const_it it = observers.begin(), it_end = observers.end();

    for(; it!=it_end; ++it)
    {

      (*it)->update(temperature, humidity, pressure);
    }


  }

  void WeatherData::setMeasurements(float temperature, float humidity, float pressure){

    this->temperature = temperature;
    this->humidity = humidity;
    this->pressure = pressure;
    measurementsChanged();
  }



}


