#ifndef FLY_WITH_WINGS_H
#define FLY_WITH_WINGS_H

#include <iostream>
#include "FlyBehavior.h"

class FlyWithWings: public FlyBehavior
{
  public:
      virtual ~FlyWithWings();
      virtual bool fly();
};



#endif //FLY_WITH_WINGS_H
