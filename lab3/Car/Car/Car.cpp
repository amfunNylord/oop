#include "stdafx.h"
#include "Car.h"

const std::map<int, std::pair<int, int>> gearSpeedRange = {
	{ GEAR_R, { GEAR_R_MIN_SPEED, GEAR_R_MAX_SPEED } },
	{ GEAR_N, { GEAR_N_MIN_SPEED, GEAR_N_MAX_SPEED } },
	{ GEAR_1, { GEAR_1_MIN_SPEED, GEAR_1_MAX_SPEED } },
	{ GEAR_2, { GEAR_2_MIN_SPEED, GEAR_2_MAX_SPEED } },
	{ GEAR_3, { GEAR_3_MIN_SPEED, GEAR_3_MAX_SPEED } },
	{ GEAR_4, { GEAR_4_MIN_SPEED, GEAR_4_MAX_SPEED } },
	{ GEAR_5, { GEAR_5_MIN_SPEED, GEAR_5_MAX_SPEED } }
};

bool CCar::IsSwitchedOnEngine() const
{
	return m_engineStatus;
}

Direction CCar::GetDirection() const
{
	if (m_speed > 0)
	{
		return FORWARD;
	}
	else if (m_speed == 0)
	{
		return STANDING;
	}
	else
	{
		return BACKWARD;
	}
}

int CCar::GetGear() const
{
	return m_gear;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

bool CCar::SwitchOnEngine()
{
	if (m_engineStatus == ENGINE_ON)
	{
		std::cout << "The car's engine is already switched on" << std::endl;
	}
	else
	{
		m_engineStatus = ENGINE_ON;
		m_gear = GEAR_N;
	}
	return m_engineStatus;
}

bool CCar::SwitchOffEngine()
{
	if (m_engineStatus != ENGINE_OFF)
	{
		if (m_speed == GEAR_N_MIN_SPEED && m_gear == GEAR_N)
		{
			m_engineStatus = ENGINE_OFF;
		} 
	}
	return m_engineStatus;
}

bool CCar::SetGear(int gear)
{
	if (m_engineStatus == ENGINE_OFF)
	{
		std::cout << "You can't set gear because your engine is off" << std::endl;
		return false;
	}
	if (gear == GEAR_R)
	{
		if (m_gear == gear)
		{
			return true;
		}
		if (m_speed != 0)
		{
			std::cout << "You can't set R gear because your speed isn't zero" << std::endl;
			return false;
		}
	}
	if (gear > GEAR_N && (m_gear == GEAR_R || m_gear == GEAR_N))
	{
		if (m_speed != 0)
		{
			std::cout << "You can set this gear after stopping" << std::endl;
			return false;
		}
	}
	if ((m_speed < 0 ? -m_speed : m_speed) >= gearSpeedRange.find(gear)->second.first && (m_speed < 0 ? -m_speed : m_speed) <= gearSpeedRange.find(gear)->second.second)
	{
		m_gear = gear;
		return true;
	}
	std::cout << "You don't have needed speed for this gear" << std::endl;
	return false;
}

bool CCar::SetSpeed(int speed)
{
	if (m_gear == GEAR_N)
	{
		if (speed > (m_speed < 0 ? -m_speed : m_speed))
		{
			return false;
		}
	}
	if (speed >= gearSpeedRange.find(m_gear)->second.first && speed <= gearSpeedRange.find(m_gear)->second.second)
	{
		if (m_gear == GEAR_R)
		{
			m_speed = -speed;
		}
		else
		{
			m_speed = speed;
		}
		return true;
	}
	return false;
}
