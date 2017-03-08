// Typically there is no implementation in the main catch.hpp
// Unit test.   The #define CATCH_CONFIG_MAIN only needs to be
// in one file, so you only need to do something special here
// if you need a custom main function beyond the created one in
// catch.
#include<iostream>
#include "WeatherData.h"
#include "CurrentConditionsDisplay.h"
#include "StatisticsDisplay.h"
#include "ForcastDisplay.h"
#include "HeatIndexDisplay.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"



