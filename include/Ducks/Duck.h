#ifndef DUCK_H
#define DUCK_H

#include <iostream>
#include "FlyBehavior.h"
#include "QuackBehavior.h"

class Duck
{


  public:
      Duck();
      virtual ~Duck();
      virtual bool PerformQuack();
      bool Swim();
      virtual bool PerformFly();
      virtual bool Display();
      void SetFlyBehavior(FlyBehavior *flyingBehavior);
      void SetQuackBehavior(QuackBehavior *quackingBehavior);

  protected:
      FlyBehavior *flyBehavior;
      QuackBehavior *quackBehavior;

};


#endif //DUCK_H
