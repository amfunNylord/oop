#pragma once
#include "SolidBody.h"

class CCylinder final : public CSolidBody
{
public:
	CCylinder(double density, double baseRadius, double height);

	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override; // вы€снить и доложить про override
	std::string GetType() const override;

	~CCylinder();

private:
	void AppendProperties(std::ostream& strm) const override;
	double m_height;
	double m_baseRadius;
};