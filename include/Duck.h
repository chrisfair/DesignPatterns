#ifndef DUCK_H
#define DUCK_H

#include <iostream>

class Duck
{
  public:
      Duck();
      virtual ~Duck();
      bool Quack();
      bool Swim();
      bool Fly();
      virtual bool Display();

};



#endif //DUCK_H
