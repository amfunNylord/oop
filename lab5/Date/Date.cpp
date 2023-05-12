#include "Date.h"

const std::map<Month, bool> monthAndDaysCount = {
	{ Month::JANUARY, 1 },
	{ Month::FEBRUARY, 0},
	{ Month::MARCH, 1 },
	{ Month::APRIL, 0 },
	{ Month::MAY, 1 },
	{ Month::JUNE, 0 },
	{ Month::JULY, 1 },
	{ Month::AUGUST, 1 },
	{ Month::SEPTEMBER, 0 },
	{ Month::OCTOBER, 1 },
	{ Month::NOVEMBER, 0 },
	{ Month::DECEMBER, 1 }
};

CDate::CDate(unsigned day, Month month, unsigned year)
{
	m_days = 0;
	bool leapYear = 0;
	unsigned countYearDays = 365;
	unsigned currentYear = 1970;
	while (currentYear != year)
	{
		m_days += (leapYear) ? 366 : 365;
		currentYear++;
		if (currentYear % 400 == 0)
		{
			leapYear = 1;
			countYearDays = 366;
		}
		else
		{
			if (currentYear % 100 == 0)
			{
				leapYear = 0;
				countYearDays = 365;
			}
			else
			{
				if (currentYear % 4 == 0)
				{
					leapYear = 1;
					countYearDays = 366;
				}
				else
				{
					leapYear = 0;
					countYearDays = 365;
				}
			}
		}
	}
	Month currentMonth = Month::JANUARY;
	unsigned currentMonthUnsigned = static_cast<unsigned>(Month::JANUARY);
	while (currentMonth != month)
	{
		if (monthAndDaysCount.find(static_cast<Month>(currentMonthUnsigned))->second)
		{
			m_days += 31;
		}
		else
		{
			if (currentMonth == Month::FEBRUARY)
			{
				if (leapYear)
				{
					m_days += 29;
				}
				else
				{
					m_days += 28;
				}
			}
			else
			{
				m_days += 30;
			}
		}
		currentMonthUnsigned++;
		currentMonth = static_cast<Month>(currentMonthUnsigned);
	}
	m_days += day - 1;
}

CDate::CDate(unsigned timestamp)
	: m_days(timestamp)
{
}

unsigned CDate::GetDay() const
{
	bool leapYear = 0;
	unsigned countYearDays = 365;
	unsigned currentYear = 1970;
	unsigned days = m_days;
	while (days / countYearDays > 0)
	{
		days -= (leapYear) ? 366 : 365;
		currentYear++;
		if (currentYear % 400 == 0)
		{
			leapYear = 1;
			countYearDays = 366;
		}
		else
		{
			if (currentYear % 100 == 0)
			{
				leapYear = 0;
				countYearDays = 365;
			}
			else
			{
				if (currentYear % 4 == 0)
				{
					leapYear = 1;
					countYearDays = 366;
				}
				else
				{
					leapYear = 0;
					countYearDays = 365;
				}
			}
		}
	}
	Month currentMonth = Month::JANUARY;
	unsigned currentMonthUnsigned = static_cast<unsigned>(Month::JANUARY);
	while (days / 28 > 0 && currentMonth != Month::DECEMBER)
	{
		if (monthAndDaysCount.find(static_cast<Month>(currentMonthUnsigned))->second)
		{
			days -= 31;
		}
		else
		{
			if (currentMonth == Month::FEBRUARY)
			{
				if (leapYear)
				{
					days -= 29;
				}
				else
				{
					days -= 28;
				}
			} 
			else
			{
				days -= 30;
			}
		}
		currentMonthUnsigned++;
		currentMonth = static_cast<Month>(currentMonthUnsigned);
	}
	unsigned currentDay = 1;
	currentDay += days;
	return currentDay;
}

Month CDate::GetMonth() const
{
	bool leapYear = 0;
	unsigned countYearDays = 365;
	unsigned currentYear = 1970;
	unsigned days = m_days;
	while (days / countYearDays > 0)
	{
		days -= (leapYear) ? 366 : 365;
		currentYear++;
		if (currentYear % 400 == 0)
		{
			leapYear = 1;
			countYearDays = 366;
		}
		else
		{
			if (currentYear % 100 == 0)
			{
				leapYear = 0;
				countYearDays = 365;
			}
			else
			{
				if (currentYear % 4 == 0)
				{
					leapYear = 1;
					countYearDays = 366;
				}
				else
				{
					leapYear = 0;
					countYearDays = 365;
				}
			}
		}
	}
	Month currentMonth = Month::JANUARY;
	unsigned currentMonthUnsigned = static_cast<unsigned>(Month::JANUARY);
	while (days / 28 > 0 && currentMonth != Month::DECEMBER)
	{
		if (monthAndDaysCount.find(static_cast<Month>(currentMonthUnsigned))->second)
		{
			days -= 31;
		}
		else
		{
			if (currentMonth == Month::FEBRUARY)
			{
				if (leapYear)
				{
					days -= 29;
				}
				else
				{
					days -= 28;
				}
			}
			else
			{
				days -= 30;
			}
		}
		currentMonthUnsigned++;
		currentMonth = static_cast<Month>(currentMonthUnsigned);
	}
	return currentMonth;
}

unsigned CDate::GetYear() const
{
	bool leapYear = 0;
	unsigned countYearDays = 365;
	unsigned currentYear = 1970;
	unsigned days = m_days;
	while (days / countYearDays > 0)
	{
		days -= (leapYear) ? 366 : 365; 
		currentYear++;
		if (currentYear % 400 == 0)
		{
			leapYear = 1;
			countYearDays = 366;
		}
		else
		{
			if (currentYear % 100 == 0)
			{
				leapYear = 0;
				countYearDays = 365;
			}
			else
			{
				if (currentYear % 4 == 0)
				{
					leapYear = 1;
					countYearDays = 366;
				}
				else
				{
					leapYear = 0;
					countYearDays = 365;
				}
			}
		}
	}
	return currentYear;
}

WeekDay CDate::GetWeekDay() const
{
	WeekDay startDay = WeekDay::THURSDAY;
	return static_cast<WeekDay>(m_days % 7 + static_cast<int>(startDay));
}

unsigned CDate::GetDays() const
{
	return m_days;
}

bool CDate::IsValid() const
{
	if (m_days < 0 || m_days > 2932896)
	{
		return false;
	}
	return true;
}

CDate::~CDate()
{
}

CDate& CDate::operator++()
{
	++m_days;
	return *this;
}

CDate CDate::operator++(int)
{
	CDate tmpCopy(*this);
	++*this;
	return tmpCopy;
}

CDate& CDate::operator--()
{
	--m_days;
	return *this;
}

CDate CDate::operator--(int)
{
	CDate tmpCopy(*this);
	--*this;
	return tmpCopy;
}

CDate CDate::operator+(int days) const
{
	return CDate(m_days + days);
}

CDate CDate::operator-(int days) const
{
	return CDate(m_days - days);
}

CDate& CDate::operator+=(int days)
{
	m_days += days;
	return *this;
}

CDate& CDate::operator-=(int days)
{
	m_days -= days;
	return *this;
}

bool CDate::operator==(CDate const& other) const
{
	return (m_days == other.m_days);
}

bool CDate::operator!=(CDate const& other) const
{
	return !(m_days == other.m_days);
}

int operator-(CDate const& firstDate, CDate const& secondDate)
{
	return firstDate.GetDays() - secondDate.GetDays();
}

bool operator>(CDate const& firstDate, CDate const& secondDate)
{
	return firstDate.m_days > secondDate.m_days;
}

bool operator<(CDate const& firstDate, CDate const& secondDate)
{
	return firstDate.m_days < secondDate.m_days;
}

bool operator>=(CDate const& firstDate, CDate const& secondDate)
{
	return !(firstDate.m_days < secondDate.m_days);
}

bool operator<=(CDate const& firstDate, CDate const& secondDate)
{
	return !(firstDate.m_days > secondDate.m_days);
}

std::ostream& operator<<(std::ostream& stream, CDate const& date)
{
	if (date.IsValid())
	{
		stream << date.GetDay() << '.' << static_cast<int>(date.GetMonth()) << '.' << date.GetYear() << std::endl;
	}
	else
	{
		stream << "INVALID" << std::endl;
	}
	return stream;
}

std::istream& operator>>(std::istream& stream, CDate& date)
{
	unsigned day;
	unsigned monthUnsigned;
	unsigned year;
	unsigned daysCountInMonth;
	bool leapYear;
	if ((stream >> day) && (stream.get() == '.') && (stream >> monthUnsigned) && (stream.get() == '.') && (stream >> year))
	{
		if (year % 400 == 0)
		{
			leapYear = 1;
		}
		else
		{
			if (year % 100 == 0)
			{
				leapYear = 0;
			}
			else
			{
				if (year % 4 == 0)
				{
					leapYear = 1;
				}
				else
				{
					leapYear = 0;
				}
			}
		}
		if (monthAndDaysCount.find(static_cast<Month>(monthUnsigned))->second)
		{
			daysCountInMonth = 31;
		}
		else
		{
			if (static_cast<Month>(monthUnsigned) == Month::FEBRUARY)
			{
				if (leapYear)
				{
					daysCountInMonth = 29;
				}
				else
				{
					daysCountInMonth = 28;
				}
			}
			else
			{
				daysCountInMonth = 30;
			}
		}
		if (day > daysCountInMonth || monthUnsigned > 12 || year > 9999)
		{
			stream.setstate(std::ios_base::failbit | stream.rdstate());
			std::cout << "INVALID" << std::endl;
		}
		else
		{
			Month month = static_cast<Month>(monthUnsigned);
			date = CDate(day, month, year);
		}
	}
	else
	{
		stream.setstate(std::ios_base::failbit | stream.rdstate());
		std::cout << "INVALID" << std::endl;
	}
	return stream;
}

