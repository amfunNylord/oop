#pragma once
#include <string>

class CCar
{
public:
	bool IsTurnedOn() const;
	std::string GetDirection() const;
	int GetGear() const;
	int GetSpeed() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
};
