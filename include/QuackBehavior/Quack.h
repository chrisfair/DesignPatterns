#ifndef QUACK_H
#define QUACK_H

#include <iostream>
#include "QuackBehavior.h"

class Quack: public QuackBehavior
{
  public:
      virtual bool Quack();
};



#endif // QUACK_H
