#ifndef WEATHER_DATA_H
#define WEATHER_DATA_H

#include <iostream>
#include <vector>
#include "Subject.h"
#include "Observer.h"
#include <list>
#include <vector>

namespace WeatherStation {

  class WeatherData : public Subject {

    public:
      WeatherData();
      virtual ~WeatherData();
      float getTemperature();
      float getHumidity();
      float getPressure();
      std::vector<Observer *> observers;
      virtual void registerObserver(Observer *o);
      virtual void removeObserver(Observer *o);
      virtual void notifyObservers();
      void measurementsChanged() { notifyObservers(); };
      void setMeasurements(float temperature, float humidity, float pressure);
  
    private:
      typedef std::vector<Observer *>::const_iterator const_it;
      float temperature;
      float humidity;
      float pressure;
 
    protected:

 };
}

#endif //WEATHER_DATA_H

