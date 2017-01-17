#ifndef FLY_ROCKET_POWERED_H
#define FLY_ROCKET_POWERED_H

#include <iostream>
#include "FlyBehavior.h"

class FlyRocketPowered: public FlyBehavior
{
  public:
      virtual ~FlyRocketPowered();
      virtual bool fly();
};



#endif //FLY_ROCKET_POWERED_H
