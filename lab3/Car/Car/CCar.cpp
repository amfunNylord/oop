#include "CCar.h"

bool CCar::IsTurnedOn() const
{
	return false;
}

std::string CCar::GetDirection() const
{
	return "STOPPED";
}

int CCar::GetGear() const
{
	return 0;
}

int CCar::GetSpeed() const
{
	return 0;
}

bool CCar::TurnOnEngine()
{
	return false;
}

bool CCar::TurnOffEngine()
{
	return false;
}

bool CCar::SetGear(int gear)
{
	return false;
}

bool CCar::SetSpeed(int speed)
{
	return false;
}
