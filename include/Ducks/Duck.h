#ifndef DUCK_H
#define DUCK_H

#include <iostream>
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class Duck
{


  public:
      FlyBehavior *flyBehavior;
      QuackBehavior *quackBehavior;
      Duck();
      virtual ~Duck();
      virtual bool PerformQuack();
      bool Swim();
      virtual bool PerformFly();
      virtual bool Display();
};


#endif //DUCK_H
