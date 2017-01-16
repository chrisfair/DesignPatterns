#include "MallardDuck.h"

MallardDuck::MallardDuck()
{
    //quackBehavior = new Quack();
    //flyBehavior = new FlyWithWings();
}

MallardDuck::~MallardDuck()
{
}


bool MallardDuck::Display()
{
    std::cout<<"I am a happy mallard duck!"<<std::endl;
    return true;
}


