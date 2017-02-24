#ifndef OBSERVER_H
#define OBSERVER_H

namespace WeatherStation {
    class Observer {
      public:
          virtual ~Observer();
          Observer();
          virtual void update(float temp, float humidity, float pressure);

    };
}
#endif //OBSERVER_H
