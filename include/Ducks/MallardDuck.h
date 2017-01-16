#ifndef MALLARD_DUCK_H 
#define MALLARD_DUCK_H 
#include "Duck.h"
#include "FlyWithWings.h"
#include "Quack.h"

class MallardDuck : public Duck
{
  public: 
    MallardDuck();
    ~MallardDuck();
    virtual bool Display();     

};



#endif //MALLARD_DUCK_H

