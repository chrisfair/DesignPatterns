#ifndef SQUEAK_H
#define SQUEAK_H

#include <iostream>
#include "QuackBehavior.h"

class Squeak: public QuackBehavior
{
  public:
      virtual bool Quack();
};



#endif // SQUEAK_H
