#include<iostream>
#include"Duck.h"
#include"MallardDuck.h"
#include "RedHeadDuck.h"
#include "RubberDucky.h"
#include "ModelDuck.h"
#include "FlyRocketPowered.h"
#include "GreenDuck.h"

int main(int argc, char ** argv)
{

  Duck myDuck;
  MallardDuck myMallardDuck;
  RedHeadDuck myRedHeadDuck;
  RubberDucky myRubberDucky;
  ModelDuck myModelDuck;
  GreenDuck myGreenDuck;


  std::cout<<"Hello Ducks!"<<std::endl;
  myDuck.PerformQuack();
  myDuck.PerformFly();
  myDuck.Swim();
  myDuck.Display();
  std::cout<<std::endl;

  std::cout<<"Using the myMallardDuck object"<<std::endl;
  myMallardDuck.Display();
  myMallardDuck.PerformFly();
  myMallardDuck.PerformQuack();
  std::cout<<std::endl;

  std::cout<<"Using the myRedHeadDuck object"<<std::endl;
  myRedHeadDuck.Display();
  myRedHeadDuck.PerformFly();
  myRedHeadDuck.PerformQuack();
  std::cout<<std::endl;

  std::cout<<"Using the myRubberDucky object"<<std::endl;
  myRubberDucky.Display();
  myRubberDucky.PerformFly();
  myRubberDucky.PerformQuack();
  std::cout<<std::endl;

  std::cout<<"Using the GreenDuck object"<<std::endl;
  myGreenDuck.Display();
  myGreenDuck.PerformFly();
  myGreenDuck.PerformQuack();
  std::cout<<std::endl;

  std::cout<<"Using the myModelDuck object"<<std::endl;
  myModelDuck.Display();
  myModelDuck.PerformFly();
  myModelDuck.PerformQuack();
  std::cout<<"Change my fly skill to rocket powered!"<<std::endl;
  myModelDuck.SetFlyBehavior(new FlyRocketPowered);
  myModelDuck.PerformFly();

  std::cout<<std::endl;



  return 0;



}

