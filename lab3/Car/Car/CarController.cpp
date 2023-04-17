#include "stdafx.h"
#include "CarController.h"
#include "Car.h"

CCarController::CCarController(CCar& car, std::istream& input, std::ostream& output)
		: m_car(car)
		, m_input(input)
		, m_output(output)
		, m_actionMap({ 
			{ "EngineOn", bind(&CCarController::EngineOn, this, std::placeholders::_1) },
			{ "EngineOff", bind(&CCarController::EngineOff, this, std::placeholders::_1) }, 
			{ "SetGear", bind(&CCarController::SetGear, this, std::placeholders::_1) }, 
			{ "SetSpeed", bind(&CCarController::SetSpeed, this, std::placeholders::_1) },
			{ "Info", bind(&CCarController::Info, this, std::placeholders::_1) }
		})
{
}

bool CCarController::HandleCommand()
{
	std::string commandLine;
	getline(m_input, commandLine);
	std::istringstream strm(commandLine);

	std::string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CCarController::Info(std::istream& args)
{
	std::string info = (m_car.IsSwitchedOnEngine())
		? "Engine is on\n"
		: "Engine is off\n";
	info += "Direction is ";
	switch (m_car.GetDirection())
	{
	case FORWARD:
		info += "forward\n";
		break;
	case BACKWARD:
		info += "backward\n";
		break;
	case STANDING:
		info += "still standing\n";
		break;
	}
	info += "Speed is " + std::to_string(m_car.GetSpeed()) + "\n";
	info += "Gear is " + std::to_string(m_car.GetGear()) + "\n";
	m_output << info;
	return true;
}

bool CCarController::EngineOn(std::istream& args)
{
	if (m_car.IsSwitchedOnEngine())
	{
		m_output << "Engine is already switched on" << std::endl;
		return true;
	}
	m_car.SwitchOnEngine();
	m_output << "Engine is switched on" << std::endl;
	return true;
}

bool CCarController::EngineOff(std::istream& args)
{
	if (!m_car.IsSwitchedOnEngine())
	{
		m_output << "Engine is already switched off" << std::endl;
		return true;
	}
	if (!m_car.SwitchOffEngine())
	{
		m_output << "Engine is switched off" << std::endl;
		return true;
	}
	m_output << "You can't switch engine of because the speed must be 0 and the gear must be neutral" << std::endl;
	return true;
}

bool CCarController::SetGear(std::istream& args)
{
	if (args.eof())
	{
		m_output << "Invalid using: SetGear <gear>" << std::endl;
		return true;
	}
	std::string gearStr;
	args >> gearStr;
	int gear;
	try
	{
		gear = stoi(gearStr);
	}
	catch (std::invalid_argument e)
	{
		m_output << "Gear must be integer value" << std::endl;
		return true;
	}
	if (gear < -1 || gear > 5)
	{
		m_output << "Gear must be from -1 to 5" << std::endl;
		return true;
	}
	if (m_car.SetGear(gear))
	{
		m_output << "Gear has been set" << std::endl;
	}
	return true;
}

bool CCarController::SetSpeed(std::istream& args)
{
	if (args.eof())
	{
		m_output << "Invalid using: SetSpeed <speed>" << std::endl;
		return true;
	}
	std::string speedStr;
	args >> speedStr;
	int speed;
	try
	{
		speed = stoi(speedStr);
	}
	catch (std::invalid_argument e)
	{
		m_output << "Speed must be integer value" << std::endl;
		return true;
	}
	if (m_car.SetSpeed(speed))
	{
		m_output << "Speed has been set" << std::endl;
	}
	else
	{
		if (!m_car.IsSwitchedOnEngine())
		{
			m_output << "You need to switch engine on" << std::endl;
			return true;
		}
		if (m_car.GetGear() == GEAR_N)
		{
			m_output << "You can only downgrade speed because you are on neutral gear" << std::endl;
			return true;
		}
		if (speed < GEAR_N_MIN_SPEED || speed > GEAR_N_MAX_SPEED)
		{
			m_output << "Speed value are higher or lower than car possible" << std::endl;
			return true;
		}
		else
		{
			m_output << "Speed value are higher or lower than gear possible" << std::endl;
			return true;
		}
	}
	return true;
}
