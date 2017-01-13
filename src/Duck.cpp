#include "Duck.h"

Duck::Duck()
{
}

Duck::~Duck()
{

}
      
bool Duck::Quack()
{
    std::cout<<"Quack!\n"<<std::endl;
    return true;

}

bool Duck::Swim()
{
    std::cout<<"Splish Splash!\n"<<std::endl;
    return true;
}

bool Duck::Fly()
{
    std::cout<<"The Duck is flapping furiously to climb into the sky!"<<std::endl;
    return true;
}

}


bool Duck::Display()
{

    std::cout<<"I am a nondescript duck!"<<std::endl;
    return true;
}



