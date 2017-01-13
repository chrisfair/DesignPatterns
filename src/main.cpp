#include<iostream>
#include"Duck.h"
#include"MallardDuck.h"
#include "RedHeadDuck.h"
int main(int argc, char ** argv)
{

  Duck myDuck;
  MallardDuck myMallardDuck;
  RedHeadDuck myRedHeadDuck;

  std::cout<<"Hello Ducks!\n"<<std::endl;
  myDuck.Quack();
  myDuck.Swim();
  myDuck.Display();

  std::cout<<"Using the myMallardDuck object"<<std::endl;
  myMallardDuck.Display();

  std::cout<<"Using the myRedHeadDuck object"<<std::endl;
  myRedHeadDuck.Display();



  return 0;



}

