#pragma once
#include "Body.h"

class CSphere final : public CBody
{
public:
	CSphere(double density, double radius);

	double GetRadius() const;
	double GetVolume() const;
	std::string GetType() const override;

	~CSphere();

private:
	void AppendProperties(std::ostream& strm) const override;
	double m_radius;
};
