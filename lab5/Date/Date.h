#pragma once
#include "stdafx.h"

// �����
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

// ���� ������
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

// ���� � ������� ����-�����-���. ��� � ��������� �� 1970 �� 9999
class CDate
{
public:
	// �������������� ���� ��������� ����, ������� � �����.
	// ����������: ��� >= 1970
	CDate(unsigned day, Month month, unsigned year);

	// �������������� ���� ����������� ����, ��������� ����� 1 ������ 1970 ����
	// ��������, 2 = 3 ������ 1970, 32 = 2 ������� 1970 ���� � �.�.
	CDate(unsigned timestamp = 0);

	// ���������� ���� ������ (�� 1 �� 31)
	unsigned GetDay() const;

	// ���������� �����
	Month GetMonth() const;

	// ���������� ���
	unsigned GetYear() const;

	// ���������� ���� ������
	WeekDay GetWeekDay() const;

	unsigned GetDays() const;

	// ���������� ���������� � ������������ �������� ����.
	// ��������, ����� ������ CDate date(99, static_cast<Month>(99), 10983);
	// ��� �����:
	//	CDate date(1, January, 1970); --date;
	// ����� date.IsValid() ������ ������� false;
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