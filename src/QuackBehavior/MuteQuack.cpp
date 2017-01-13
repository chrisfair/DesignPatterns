#include "MuteQuack.h"

bool MuteQuack: public QuackBehavior
{
    std::cout<<"I cannot quack...it is sad!"::endl;
    return true;
}


