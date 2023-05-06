#pragma once
#include "SolidBody.h"

class CCone final : public CSolidBody
{
public:
	CCone(double density, double baseRadius, double height);

	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override;
	std::string GetType() const override;

	~CCone();

private:
	void AppendProperties(std::ostream& strm) const override;
	double m_height;
	double m_baseRadius;
};