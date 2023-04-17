#pragma once
#include <map>

const int GEAR_R = -1;
const int GEAR_N = 0;
const int GEAR_1 = 1;
const int GEAR_2 = 2;
const int GEAR_3 = 3;
const int GEAR_4 = 4;
const int GEAR_5 = 5;

const int GEAR_R_MIN_SPEED = 0;
const int GEAR_R_MAX_SPEED = 20;
const int GEAR_N_MIN_SPEED = 0;
const int GEAR_N_MAX_SPEED = 150;
const int GEAR_1_MIN_SPEED = 0;
const int GEAR_1_MAX_SPEED = 30;
const int GEAR_2_MIN_SPEED = 20;
const int GEAR_2_MAX_SPEED = 50;
const int GEAR_3_MIN_SPEED = 30;
const int GEAR_3_MAX_SPEED = 60;
const int GEAR_4_MIN_SPEED = 40;
const int GEAR_4_MAX_SPEED = 90;
const int GEAR_5_MIN_SPEED = 50;
const int GEAR_5_MAX_SPEED = 150;

enum Direction
{
	BACKWARD = -1,
	STANDING,
	FORWARD
};

const bool ENGINE_ON = true;
const bool ENGINE_OFF = false;

class CCar
{
public:
	bool IsSwitchedOnEngine() const;
	Direction GetDirection() const;
	int GetGear() const;
	int GetSpeed() const;
	bool SwitchOnEngine();
	bool SwitchOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	bool m_engineStatus = ENGINE_OFF;
	int m_speed = GEAR_N_MIN_SPEED;
	int m_gear = GEAR_N;
};
