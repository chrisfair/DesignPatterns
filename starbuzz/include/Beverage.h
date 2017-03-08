#pragma once

#include <string>

public class Beverage {

  public:
    virtual std::string getDescription();
    virtual double cost()=0;
  protected:
    std::string description;

};

