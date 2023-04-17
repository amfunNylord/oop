#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../Car/Car.h"

SCENARIO("Test starting values of car")
{
	WHEN("Car is only created")
	{
		CCar car;
		THEN("Engine is switched off, speed is zero and gear is zero too")
		{
			REQUIRE(car.IsSwitchedOnEngine() == ENGINE_OFF);
			REQUIRE(car.GetGear() == GEAR_N);
			REQUIRE(car.GetSpeed() == GEAR_N_MIN_SPEED);
			REQUIRE(car.GetDirection() == STANDING);
		}
	}
}

SCENARIO("Switching on engine")
{
	WHEN("We want to switch on engine")
	{
		CCar car;
		car.SwitchOnEngine();
		THEN("Engine is switching on")
		{
			REQUIRE(car.IsSwitchedOnEngine() == ENGINE_ON);
			REQUIRE(car.GetGear() == GEAR_N);
			REQUIRE(car.GetDirection() == STANDING);
		}
	}
}

SCENARIO("Switching off engine")
{
	CCar car;
	car.SwitchOnEngine();
	WHEN("We want to switch off engine, when gear is neutral and speed is 0")
	{
		REQUIRE(car.GetSpeed() == GEAR_N_MIN_SPEED);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SwitchOffEngine();
		THEN("Engine is switching off")
		{
			REQUIRE(car.IsSwitchedOnEngine() == ENGINE_OFF);
		}
	}
	WHEN("We want to switch off engine, when gear isn't neutral and speed isn't 0")
	{
		car.SetGear(GEAR_1);
		car.SetSpeed(GEAR_1_MAX_SPEED);
		REQUIRE(car.GetGear() == GEAR_1);
		REQUIRE(car.GetSpeed() == GEAR_1_MAX_SPEED);
		car.SwitchOffEngine();
		THEN("Engine isn't switching off")
		{
			REQUIRE(car.IsSwitchedOnEngine() != ENGINE_OFF);
		}
	}
}

SCENARIO("Setting Gear")
{
	CCar car;
	WHEN("We want to change to 1 gear with the engine off")
	{
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_OFF);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_1);
		THEN("The gear remains neutral")
		{
			REQUIRE(car.GetGear() == GEAR_N);
		}
	}
	WHEN("We want to change to 2 gear with the engine off")
	{
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_OFF);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_2);
		THEN("The gear remains neutral")
		{
			REQUIRE(car.GetGear() == GEAR_N);
		}
	}
	WHEN("We want to change to 3 gear with the engine off")
	{
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_OFF);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_3);
		THEN("The gear remains neutral")
		{
			REQUIRE(car.GetGear() == GEAR_N);
		}
	}
	WHEN("We want to change to 4 gear with the engine off")
	{
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_OFF);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_4);
		THEN("The gear remains neutral")
		{
			REQUIRE(car.GetGear() == GEAR_N);
		}
	}
	WHEN("We want to change to 5 gear with the engine off")
	{
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_OFF);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_5);
		THEN("The gear remains neutral")
		{
			REQUIRE(car.GetGear() == GEAR_N);
		}
	}
	WHEN("We want to change to R gear with the engine off")
	{
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_OFF);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_R);
		THEN("The gear remains neutral")
		{
			REQUIRE(car.GetGear() == GEAR_N);
		}
	}
	WHEN("We want to change to 1 gear from neutral with the engine on")
	{
		car.SwitchOnEngine();
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_ON);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_1);
		THEN("The gear is 1 gear")
		{
			REQUIRE(car.GetGear() == GEAR_1);
		}
	}
	WHEN("We want to change to 2 gear from neutral with the engine on")
	{
		car.SwitchOnEngine();
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_ON);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_2);
		THEN("The gear remains neutral")
		{
			REQUIRE(car.GetGear() == GEAR_N);
		}
	}
	WHEN("We want to change to 3 gear from neutral with the engine on")
	{
		car.SwitchOnEngine();
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_ON);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_3);
		THEN("The gear remains neutral")
		{
			REQUIRE(car.GetGear() == GEAR_N);
		}
	}
	WHEN("We want to change to R gear from neutral with the engine on and speed is 0")
	{
		car.SwitchOnEngine();
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_ON);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_R);
		THEN("The gear is R")
		{
			REQUIRE(car.GetGear() == GEAR_R);
		}
	}
	WHEN("We want to change to R gear from neutral with the engine on and speed isn't 0 and direction is backward")
	{
		car.SwitchOnEngine();
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_ON);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_R);
		car.SetSpeed(GEAR_R_MAX_SPEED);
		car.SetGear(GEAR_N);
		REQUIRE(car.GetSpeed() == -GEAR_R_MAX_SPEED);
		REQUIRE(car.GetDirection() == BACKWARD);
		car.SetGear(GEAR_R);
		THEN("The gear remains neutral")
		{
			REQUIRE(car.GetGear() == GEAR_N);
		}
	}
	WHEN("We want to change to R gear from neutral with the engine on and speed isn't 0 and direction is forward")
	{
		car.SwitchOnEngine();
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_ON);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_1);
		REQUIRE(car.GetGear() == GEAR_1);
		car.SetSpeed(GEAR_1_MAX_SPEED);
		REQUIRE(car.GetSpeed() == GEAR_1_MAX_SPEED);
		car.SetGear(GEAR_N);
		REQUIRE(car.GetGear() == GEAR_N);
		REQUIRE(car.GetDirection() == FORWARD);
		car.SetGear(GEAR_R);
		THEN("The gear remains neutral")
		{
			REQUIRE(car.GetGear() == GEAR_N);
		}
	}
	WHEN("We want to change to 1 gear from R with the engine on and speed isn't 0")
	{
		car.SwitchOnEngine();
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_ON);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_R);
		REQUIRE(car.GetGear() == GEAR_R);
		car.SetSpeed(GEAR_R_MAX_SPEED);
		REQUIRE(car.GetSpeed() == -GEAR_R_MAX_SPEED);
		car.SetGear(GEAR_1);
		THEN("The gear remains R")
		{
			REQUIRE(car.GetGear() == GEAR_R);
		}
	}
	WHEN("We want to change to 1 gear from R with the engine on and speed is 0")
	{
		car.SwitchOnEngine();
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_ON);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_R);
		REQUIRE(car.GetGear() == GEAR_R);
		car.SetGear(GEAR_1);
		THEN("The gear is 1")
		{
			REQUIRE(car.GetGear() == GEAR_1);
		}
	}
	WHEN("We want to change to 1 gear from neutral after switching from R and direction isn't still standing")
	{
		car.SwitchOnEngine();
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_ON);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_R);
		REQUIRE(car.GetGear() == GEAR_R);
		car.SetSpeed(GEAR_R_MAX_SPEED);
		REQUIRE(car.GetSpeed() == -GEAR_R_MAX_SPEED);
		car.SetGear(GEAR_N);
		REQUIRE(car.GetGear() == GEAR_N);
		REQUIRE(car.GetDirection() != STANDING);
		car.SetGear(GEAR_1);
		THEN("The gear remains neutral")
		{
			REQUIRE(car.GetGear() == GEAR_N);
		}
	}
	WHEN("We want to change to 1 gear from neutral after switching from R and direction is still standing")
	{
		car.SwitchOnEngine();
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_ON);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_R);
		REQUIRE(car.GetGear() == GEAR_R);
		car.SetSpeed(GEAR_R_MAX_SPEED);
		REQUIRE(car.GetSpeed() == -GEAR_R_MAX_SPEED);
		car.SetGear(GEAR_N);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetSpeed(GEAR_N_MIN_SPEED);
		REQUIRE(car.GetDirection() == STANDING);
		car.SetGear(GEAR_1);
		THEN("The gear is 1")
		{
			REQUIRE(car.GetGear() == GEAR_1);
		}
	}
	WHEN("We want to change to other forward gear from R")
	{
		car.SwitchOnEngine();
		REQUIRE(car.IsSwitchedOnEngine() == ENGINE_ON);
		REQUIRE(car.GetGear() == GEAR_N);
		car.SetGear(GEAR_R);
		REQUIRE(car.GetGear() == GEAR_R);
		car.SetSpeed(GEAR_R_MAX_SPEED);
		REQUIRE(car.GetSpeed() == -GEAR_R_MAX_SPEED);
		car.SetGear(GEAR_2);
		THEN("The gear is remain R")
		{
			REQUIRE(car.GetGear() == GEAR_R);
		}
	}
}

SCENARIO("Setting speed")
{
	CCar car;
	WHEN("We want to set some speed with the engine off")
	{
		REQUIRE(!car.IsSwitchedOnEngine());
		car.SetSpeed(60);
		THEN("Speed remains 0")
		{
			REQUIRE(car.GetSpeed() == GEAR_N_MIN_SPEED);
		}
	}
	WHEN("We want to set some speed with the engine on without setting gear")
	{
		car.SwitchOnEngine();
		REQUIRE(car.IsSwitchedOnEngine());
		car.SetSpeed(60);
		THEN("Speed remains 0")
		{
			REQUIRE(car.GetSpeed() == GEAR_N_MIN_SPEED);
		}
	}
	WHEN("We want to set speed which is in interval of current gear, engine on")
	{
		car.SwitchOnEngine();
		REQUIRE(car.IsSwitchedOnEngine());
		car.SetGear(GEAR_1);
		REQUIRE(car.GetGear() == GEAR_1);
		car.SetSpeed(GEAR_1_MAX_SPEED);
		THEN("Speed is set speed")
		{
			REQUIRE(car.GetSpeed() == GEAR_1_MAX_SPEED);
		}
	}
	WHEN("We want to set speed which isn't in interval of current gear, engine on")
	{
		car.SwitchOnEngine();
		REQUIRE(car.IsSwitchedOnEngine());
		car.SetGear(GEAR_1);
		REQUIRE(car.GetGear() == GEAR_1);
		car.SetSpeed(GEAR_2_MAX_SPEED);
		THEN("Speed remains 0")
		{
			REQUIRE(car.GetSpeed() == GEAR_N_MIN_SPEED);
		}
	}
	WHEN("We are going back and trying to set the same speed as we already have")
	{
		car.SwitchOnEngine();
		REQUIRE(car.IsSwitchedOnEngine());
		car.SetGear(GEAR_R);
		REQUIRE(car.GetGear() == GEAR_R);
		car.SetSpeed(GEAR_R_MAX_SPEED);
		REQUIRE(car.GetSpeed() == -GEAR_R_MAX_SPEED);
		Direction directionBefore = car.GetDirection();
		car.SetSpeed(GEAR_R_MAX_SPEED);
		REQUIRE(car.GetSpeed() == -GEAR_R_MAX_SPEED);
		THEN("Direction haven't to change")
		{
			Direction directionAfter = car.GetDirection();
			REQUIRE(directionBefore == directionAfter);
		}
	}
}