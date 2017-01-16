#include "Duck.h"

Duck::Duck()
{
    quackBehavior = new QuackBehavior;
    flyBehavior = new FlyBehavior;
}

Duck::~Duck()
{
    delete quackBehavior;
    delete flyBehavior;
}

bool Duck::PerformQuack()
{
    quackBehavior->quack();
    return true;
}

bool Duck::PerformFly()
{
    flyBehavior->fly();
    return true;
}


bool Duck::Swim()
{
    std::cout<<"Splish Splash!"<<std::endl;
    return true;
}

bool Duck::Display()
{
    std::cout<<"I am a nondescript duck!"<<std::endl;
    return true;
}

void Duck::SetFlyBehavior(FlyBehavior *flyingBehavior)
{
    flyBehavior = flyingBehavior;

}

void Duck::SetQuackBehavior(QuackBehavior *quackingBehavior)
{

    quackBehavior = quackingBehavior;

}


