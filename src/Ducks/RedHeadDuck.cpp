#include "RedHeadDuck.h"


RedHeadDuck::RedHeadDuck()
{

    quackBehavior = new Quack();
    flyBehavior = new FlyWithWings();



}




RedHeadDuck::~RedHeadDuck()
{


}

bool RedHeadDuck::Display()
{
    std::cout<<"I am a depressed redhead duck!"<<std::endl;
    return true;
}


