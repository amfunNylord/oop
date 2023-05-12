#pragma once
#include "stdafx.h"

// ћес€ц
enum class Month
{
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

// ƒень недели
enum class WeekDay
{
	SUNDAY = 0,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
};

// ƒата в формате день-мес€ц-год. √од в диапазоне от 1970 до 9999
class CDate
{
public:
	// инициализируем дату заданными днем, мес€цем и годом.
	// примечание: год >= 1970
	CDate(unsigned day, Month month, unsigned year);

	// инициализируем дату количеством дней, прошедших после 1 €нвар€ 1970 года
	// например, 2 = 3 €нвар€ 1970, 32 = 2 феврал€ 1970 года и т.д.
	CDate(unsigned timestamp = 0);

	// возвращает день мес€ца (от 1 до 31)
	unsigned GetDay() const;

	// возвращает мес€ц
	Month GetMonth() const;

	// возвращает год
	unsigned GetYear() const;

	// возвращает день недели
	WeekDay GetWeekDay() const;

	unsigned GetDays() const;

	// возвращает информацию о корректности хранимой даты.
	// Ќапример, после вызова CDate date(99, static_cast<Month>(99), 10983);
	// или после:
	//	CDate date(1, January, 1970); --date;
	// метод date.IsValid() должен вернуть false;
	bool IsValid() const;

	virtual ~CDate();

	CDate& operator++();
	CDate operator++(int);
	CDate& operator--();
	CDate operator--(int);
	CDate operator+(int days) const;
	CDate operator-(int days) const;
	int friend operator-(CDate const& firstDate, CDate const& secondDate);
	CDate& operator+=(int days);
	CDate& operator-=(int days);
	bool operator==(CDate const& other) const;
	bool operator!=(CDate const& other) const;
	bool friend operator>(CDate const& firstDate, CDate const& secondDate);
	bool friend operator<(CDate const& firstDate, CDate const& secondDate);
	bool friend operator>=(CDate const& firstDate, CDate const& secondDate);
	bool friend operator<=(CDate const& firstDate, CDate const& secondDate);

private:
	unsigned m_days;
};

std::ostream& operator<<(std::ostream& stream, CDate const& date);
std::istream& operator>>(std::istream& stream, CDate& date);