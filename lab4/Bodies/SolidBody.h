#pragma once
#include "Body.h"

class CSolidBody : public CBody
{
public:
	CSolidBody(double density, double baseRadius, double height);

	double GetBaseRadius() const;
	double GetHeight() const;

	~CSolidBody();

private:
	void AppendProperties(std::ostream& strm) const override;
	double m_height;
	double m_baseRadius;
};
