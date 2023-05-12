#include "stdafx.h"
#include "../Date/Date.h"

struct Date_
{
	const unsigned expectedDays = 32;
	const unsigned day = 2;
	const Month month = Month::FEBRUARY;
	const unsigned year = 1970;
	const CDate date;
	Date_()
		: date(day, month, year)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(DateWithFullDate, Date_)
	// создается дата с использованием конструктора из дня, месяца и года
	BOOST_AUTO_TEST_CASE(creates_date_from_full_date)
	{
		BOOST_CHECK_EQUAL(date.GetDays(), expectedDays);
	}
BOOST_AUTO_TEST_SUITE_END()

struct Date__
{
	const unsigned expectedDays = 2932896;
	const unsigned day = 31;
	const Month month = Month::DECEMBER;
	const unsigned year = 9999;
	const CDate date;
	Date__()
		: date(day, month, year)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(DateWithFullDate2, Date__)
	// создается дата с использованием конструктора из дня, месяца и года, 31 декабря 9999 года
	BOOST_AUTO_TEST_CASE(creates_date_from_full_date_31_december_9999)
	{
		BOOST_CHECK_EQUAL(date.GetDays(), expectedDays);
	}
BOOST_AUTO_TEST_SUITE_END()