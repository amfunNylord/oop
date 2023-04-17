#pragma once
#include "stdafx.h"

class CBody
{
public:
	CBody(const std::string& type, double density);

	double GetDensity() const;
	virtual double GetVolume() const = 0;
	double GetMass() const;
	std::string ToString() const;
	virtual ~CBody();

private:
	virtual void AppendProperties(std::ostream& strm) const = 0;
	double m_density; // плотность
	std::string m_type;
};