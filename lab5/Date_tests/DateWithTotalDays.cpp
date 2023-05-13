#include "stdafx.h"
#include "../Date/Date.h"

struct Date_
{
	const unsigned timestamp = 32;
	const unsigned expectedTimeDay = 2;
	const Month expectedTimeMonth = Month::FEBRUARY;
	const unsigned expectedTimeYear = 1970;
	CDate date;
	Date_()
		: date(timestamp)
	{}
};

BOOST_FIXTURE_TEST_SUITE(DateWithTotalDays, Date_)
	// ��������� ���� � �������������� ������������ �� ���������� ����
	BOOST_AUTO_TEST_CASE(creates_date_with_count_of_days)
	{
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp);
	}
	// ��������� ���������� ���� � ������� ���������� ����
	BOOST_AUTO_TEST_CASE(creates_correct_date_with_count_of_days)
	{
		BOOST_CHECK_EQUAL(date.GetDay(), expectedTimeDay);
		BOOST_CHECK(date.GetMonth() == expectedTimeMonth);
		BOOST_CHECK_EQUAL(date.GetYear(), expectedTimeYear);
	}
	// �������� ����������������� ���������� ����� ����������
	BOOST_AUTO_TEST_CASE(works_prefix_increment)
	{
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp);
		++date;
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp + 1);
	}
	// �������� ����������������� ����������� ����� ����������
	BOOST_AUTO_TEST_CASE(works_postfix_increment)
	{
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp);
		date++;
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp + 1);
	}
	// �������� ����������������� ���������� ����� ����������
	BOOST_AUTO_TEST_CASE(works_prefix_decrement)
	{
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp);
		--date;
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp - 1);
	}
	// �������� ����������������� ����������� ����� ����������
	BOOST_AUTO_TEST_CASE(works_postfix_decrement)
	{
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp);
		date--;
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp - 1);
	}
	// �������� ����������������� ��������� ��������
	BOOST_AUTO_TEST_CASE(works_plus_operator)
	{
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp);
		date = date + 5;
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp + 5);
	}
	// �������� ����������������� ��������� ��������� ���������� ����
	BOOST_AUTO_TEST_CASE(works_minus_operator_with_count_of_days)
	{
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp);
		date = date - 5;
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp - 5);
	}
	// �������� ����������������� ��������� ��������� ���
	BOOST_AUTO_TEST_CASE(works_minus_operator_with_two_dates)
	{
		const unsigned timestampSecondDate = 28;
		const int expectedDifference = 4;
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp);
		CDate date2(timestampSecondDate);
		BOOST_CHECK_EQUAL(date2.GetDays(), timestampSecondDate);
		int difference = date - date2;
		BOOST_CHECK_EQUAL(difference, expectedDifference);
	}
	// �������� ����������������� ��������� ����������� ��������
	BOOST_AUTO_TEST_CASE(works_assigning_plus_operator)
	{
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp);
		date += 5;
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp + 5);
	}
	// �������� ����������������� ��������� ����������� ��������
	BOOST_AUTO_TEST_CASE(works_assigning_minus_operator)
	{
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp);
		date -= 5;
		BOOST_CHECK_EQUAL(date.GetDays(), timestamp - 5);
	}
	// �������� ����������������� ��������� ����� � �����, ���� ������� ������ ����
	BOOST_AUTO_TEST_CASE(works_input_operator_with_valid_date)
	{
		std::istringstream input("12.12.2003");
		input >> date;
		CDate date2(12, Month::DECEMBER, 2003);
		BOOST_CHECK_EQUAL(date, date2);
	}
	// �������� ����������������� ��������� ������ � �����, ���� ������� ������ ����
	BOOST_AUTO_TEST_CASE(works_output_operator_with_valid_date)
	{
		std::ostringstream output("");
		output << date;
		BOOST_CHECK_EQUAL(output.str(), "2.2.1970\n");
	}
	// �������� ����������������� ��������� ������ � �����, ���� ������� �������� ����
	BOOST_AUTO_TEST_CASE(works_output_operator_with_invalid_date)
	{
		std::ostringstream output("");
		CDate date2(2932897);
		output << date2;
		BOOST_CHECK_EQUAL(output.str(), "INVALID\n");
	}
	// �������� ����������������� ��������� ���������
	BOOST_AUTO_TEST_CASE(works_equal_operator)
	{
		unsigned timestampSecondDate = 32;
		CDate date2(timestampSecondDate);
		BOOST_CHECK(date == date2);
	}
	// �������� ����������������� ��������� ��������� ���������
	BOOST_AUTO_TEST_CASE(works_unequal_operator)
	{
		unsigned timestampSecondDate = 33;
		CDate date2(timestampSecondDate);
		BOOST_CHECK(date != date2);
	}
	// �������� ����������������� ��������� ������ 
	BOOST_AUTO_TEST_CASE(works_comparison_operator_more)
	{
		unsigned timestampSecondDate = 33;
		CDate date2(timestampSecondDate);
		BOOST_CHECK(date2 > date);
	}
	// �������� ����������������� ��������� ������
	BOOST_AUTO_TEST_CASE(works_comparison_operator_less)
	{
		unsigned timestampSecondDate = 33;
		CDate date2(timestampSecondDate);
		BOOST_CHECK(date < date2);
	}
	// �������� ����������������� ��������� ������ ��� �����
	BOOST_AUTO_TEST_CASE(works_comparison_operator_more_or_equal)
	{
		unsigned timestampSecondDate = 32;
		CDate date2(timestampSecondDate);
		BOOST_CHECK(date2 >= date);
	}
	// �������� ����������������� ��������� ������ ��� �����
	BOOST_AUTO_TEST_CASE(works_comparison_operator_less_or_equal)
	{
		unsigned timestampSecondDate = 32;
		CDate date2(timestampSecondDate);
		BOOST_CHECK(date <= date2);
	}

BOOST_AUTO_TEST_SUITE_END()

struct Date__
{
	const unsigned timestamp = 2932896;
	const unsigned expectedTimeDay = 31;
	const Month expectedTimeMonth = Month::DECEMBER;
	const unsigned expectedTimeYear = 9999;
	const CDate date;
	Date__()
		: date(timestamp)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(DateWithTotalDays2, Date__)
	// ��������� ���������� ���� � ������� ���������� ���� 31 ������� 9999
	BOOST_AUTO_TEST_CASE(creates_correct_date_with_count_of_days_31_december_9999)
	{
		BOOST_CHECK_EQUAL(date.GetDay(), expectedTimeDay);
		BOOST_CHECK(date.GetMonth() == expectedTimeMonth);
		BOOST_CHECK_EQUAL(date.GetYear(), expectedTimeYear);
	}
BOOST_AUTO_TEST_SUITE_END()