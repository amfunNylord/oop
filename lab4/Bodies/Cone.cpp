#include "stdafx.h"
#include "Cone.h"

CCone::CCone(double density, double baseRadius, double height)
	: CSolidBody(density, baseRadius, height)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
}

double CCone::GetBaseRadius() const
{
	return m_baseRadius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return M_PI * m_height / 3 * pow(m_baseRadius, 2);
}

std::string CCone::GetType() const
{
	return "Cone";
}

CCone::~CCone()
{
}

void CCone::AppendProperties(std::ostream& strm) const
{
	strm << "\tbase radius = " << GetBaseRadius() << std::endl
		 << "\theight = " << GetHeight() << std::endl;
}
