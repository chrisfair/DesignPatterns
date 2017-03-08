#pragma once

#include "Beverage.h"

public class CondimentDecorator:public Beverage {

  virtual std::string getDescription()=0;

}

