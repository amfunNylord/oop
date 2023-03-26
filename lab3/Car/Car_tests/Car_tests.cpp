#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../Car/CCar.h"

SCENARIO("Test starting values of car")
{
	WHEN("Car is only created")
	{
		CCar car;
		THEN("Engine is turned off, speed is zero and gear is zero too")
		{
			REQUIRE(car.IsTurnedOn() == false);
			REQUIRE(car.GetGear() == 0);
			REQUIRE(car.GetSpeed() == 0);
			REQUIRE(car.GetDirection() == "STOPPED");
		}
	}
}