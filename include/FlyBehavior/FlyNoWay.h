#ifndef FLY_NO_WAY_H
#define FLY_NO_WAY_H

#include <iostream>
#include "FlyBehavior.h"

class FlyNoWay: public FlyBehavior
{
  public:
      virtual ~FlyNoWay();
      virtual bool fly();
};



#endif //FLY_NO_WAY_H
