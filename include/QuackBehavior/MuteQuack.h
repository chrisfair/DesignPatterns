#ifndef MUTE_QUACK_H
#define MUTE_QUACK_H

#include <iostream>
#include "QuackBehavior.h"

class MuteQuack: public Quack
{
  public:
      virtual bool Quack();
};



#endif //MUTE_QUACK_H
