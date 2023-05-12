#include "stdafx.h"
#include "BodyController.h"
#include "Body.h"
#include "Cone.h"
#include "Cylinder.h"
#include "Parallelepiped.h"
#include "Sphere.h"

const double PHYSICAL_GRANDEUR_G = 9.81;
const double WATER_DENSITY = 1000.0;
const int CONE_TYPE = 1;
const int CYLINDER_TYPE = 2;
const int PARALLELEPIPED_TYPE = 3;
const int SPHERE_TYPE = 4;
const std::string ERROR_NO_BODIES_ENTERED = "No bodies entered";

// добавить поддержку Compound
// добавить валидацию параметров тел

CBodyController::CBodyController(std::istream& input, std::ostream& output, std::vector<std::shared_ptr<CBody>>& bodiesVector)
	: m_input(input)
	, m_output(output)
	, m_bodiesVector(bodiesVector)
	, m_actionMap({ 
		{ "Info", bind(&CBodyController::InfoAboutAllBodies, this, std::placeholders::_1) },
		{ "AddBody", bind(&CBodyController::AddBody, this, std::placeholders::_1) },
		{ "GetBodyWithBiggestMass", std::bind(&CBodyController::GetBodyWithBiggestMass, this) },
		{ "GetLightestBodyInWater", std::bind(&CBodyController::GetLightestBodyInWater, this) }
	})
{
}

bool CBodyController::HandleCommand()
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

CBodyController::~CBodyController()
{
}

bool CBodyController::InfoAboutAllBodies(std::istream& args)
{
	if (m_bodiesVector.size() == 0)
	{
		m_output << ERROR_NO_BODIES_ENTERED << std::endl;
		return true;
	}
	for (size_t i = 0; i < m_bodiesVector.size(); i++)
	{
		m_output << m_bodiesVector[i]->ToString();
	}
	return true;
}

bool CBodyController::AddBody(std::istream& args)
{
	if (args.eof())
	{
		m_output << "Invalid using: AddBody <body_type>" << std::endl;
		return true;
	}

	std::string bodyTypeStr;
	args >> bodyTypeStr;
	int bodyType;
	try
	{
		bodyType = stoi(bodyTypeStr);
	}
	catch (std::invalid_argument e)
	{
		m_output << "Body type must be integer value" << std::endl;
		return true;
	}
	std::string densityStr;
	args >> densityStr;
	double density;
	try
	{
		density = stod(densityStr);
	}
	catch (std::invalid_argument e)
	{
		m_output << "Density must be double value" << std::endl;
		return true;
	}
	switch (bodyType)
	{
		case CONE_TYPE:
		{
			double baseRadius, height;
			args >> baseRadius >> height;
			std::shared_ptr<CCone> cone = std::make_shared<CCone>(density, baseRadius, height);
			m_bodiesVector.emplace_back(cone);
			break;
		}
		case CYLINDER_TYPE:
		{
			double baseRadius, height;
			args >> baseRadius >> height;
			std::shared_ptr<CCylinder> cylinder = std::make_shared<CCylinder>(density, baseRadius, height);
			m_bodiesVector.emplace_back(cylinder);
			break;
		}
		case PARALLELEPIPED_TYPE: 
		{
			double width, height, depth;
			args >> width >> height >> depth;
			std::shared_ptr<CParallelepiped> parallelepiped = std::make_shared<CParallelepiped>(density, width, height, depth);
			m_bodiesVector.emplace_back(parallelepiped);
			break;
		}
		case SPHERE_TYPE: 
		{
			double radius;
			args >> radius;
			std::shared_ptr<CSphere> sphere = std::make_shared<CSphere>(density, radius);
			m_bodiesVector.emplace_back(sphere);
			break;
		}
		default:
		{
			m_output << "Invalid <body_type>" << std::endl;
		}
	}
	return true;
}

bool CBodyController::GetBodyWithBiggestMass()
{
	if (m_bodiesVector.size() == 0)
	{
			m_output << ERROR_NO_BODIES_ENTERED << std::endl;
			return true;
	}
	double maxMass = m_bodiesVector[0]->GetMass();
	std::shared_ptr<CBody> maxMassBody = m_bodiesVector[0];
	size_t vectorSize = m_bodiesVector.size();
	for (size_t i = 1; i < vectorSize; i++)
	{
			double possibleMaxMass = m_bodiesVector[i]->GetMass();
			if (possibleMaxMass > maxMass)
			{
				maxMass = possibleMaxMass;
				maxMassBody = m_bodiesVector[i];
			}
	}
	m_output << "The body with biggest mass is " << maxMassBody->ToString() << std::endl;
	return true;
}

bool CBodyController::GetLightestBodyInWater()
{
	if (m_bodiesVector.size() == 0)
	{
			m_output << ERROR_NO_BODIES_ENTERED << std::endl;
			return true;
	}
	double minWeight = (m_bodiesVector[0]->GetDensity()) * PHYSICAL_GRANDEUR_G * m_bodiesVector[0]->GetVolume();
	std::shared_ptr<CBody> minWeightBody = m_bodiesVector[0];
	size_t vectorSize = m_bodiesVector.size();
	for (size_t i = 1; i < vectorSize; i++)
	{
			double possibleMinWeight = (m_bodiesVector[i]->GetDensity() - WATER_DENSITY) * PHYSICAL_GRANDEUR_G * m_bodiesVector[0]->GetVolume();
			if (possibleMinWeight < minWeight)
			{
				minWeight = possibleMinWeight;
				minWeightBody = m_bodiesVector[i];
			}
	}
	m_output << "The lightest body in water is " << minWeightBody->ToString() << std::endl;
	return true;
}

