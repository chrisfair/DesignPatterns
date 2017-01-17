#ifndef QUACK_H
#define QUACK_H

#include <iostream>
#include "QuackBehavior.h"

class Quack: public QuackBehavior
{
  public:
      ~Quack();      
      bool quack();
};



#endif // QUACK_H
