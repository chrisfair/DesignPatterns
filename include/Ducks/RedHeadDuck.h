#ifndef READHEAD_DUCK_H
#define READHEAD_DUCK_H

#include "Duck.h"
#include "FlyWithWings.h"
#include "Quack.h"

class RedHeadDuck : public Duck
{
  public:
    RedHeadDuck();
    ~RedHeadDuck();
    virtual bool Display();     

};



#endif //READHEAD_DUCK_H

