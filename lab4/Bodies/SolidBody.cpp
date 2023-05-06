#include "stdafx.h"
#include "SolidBody.h"

CSolidBody::CSolidBody(double density, double baseRadius, double height)
	: CBody(density)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
}

double CSolidBody::GetBaseRadius() const
{
	return m_baseRadius;
}

double CSolidBody::GetHeight() const
{
	return m_height;
}

CSolidBody::~CSolidBody()
{
}

void CSolidBody::AppendProperties(std::ostream& strm) const
{
	strm << "\tbase radius = " << GetBaseRadius() << std::endl
		 << "\theight = " << GetHeight() << std::endl;
}
