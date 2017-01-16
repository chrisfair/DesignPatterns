#ifndef SQUEAK_H
#define SQUEAK_H

#include <iostream>
#include "QuackBehavior.h"

class Squeak: public QuackBehavior
{
  public:
      
      virtual ~Squeak();
      virtual bool quack();
      
};



#endif // SQUEAK_H
