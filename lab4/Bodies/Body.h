#pragma once
class CBody
{
public:
	CBody(double density);

	double GetDensity() const;
	virtual double GetVolume() const = 0;
	double GetMass() const;
	std::string ToString() const;
	virtual std::string GetType() const = 0;

	// прочитать чек лист гитхаб по слову деструктор 
	virtual ~CBody();

private:
	virtual void AppendProperties(std::ostream& strm) const = 0;
	double m_density;
};
