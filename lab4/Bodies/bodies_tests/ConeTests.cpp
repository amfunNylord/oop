#include "stdafx.h"
#include "../Cone.h"

struct Cone_
{
	const double expectedBaseRadius = 15.5;
	const double expectedHeight = 10.3;
	const double expectedVolume = 2591.36888;
	const double expectedDensity = 100;
	const std::string expectedType = "Cone";
	const CCone cone;
	Cone_()
		: cone(expectedDensity, expectedBaseRadius, expectedHeight)
	{}
};
// �����
BOOST_FIXTURE_TEST_SUITE(Cone, Cone_)
	// �������� �������� �����
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK(static_cast<const CBody*>(&cone));
	}
	// ����� ������ ���������
	BOOST_AUTO_TEST_CASE(has_a_height)
	{
		BOOST_CHECK_EQUAL(cone.GetHeight(), expectedHeight);
	}
	// ����� ������
	BOOST_AUTO_TEST_CASE(has_a_base_radius)
	{
		BOOST_CHECK_EQUAL(cone.GetBaseRadius(), expectedBaseRadius);
	}
	// ����� ���������
	BOOST_AUTO_TEST_CASE(has_a_density)
	{
		BOOST_CHECK_EQUAL(static_cast<const CBody&>(cone).GetDensity(), expectedDensity);
	}
	// ����� �����
	BOOST_AUTO_TEST_CASE(has_a_volume)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody&>(cone).GetVolume(), expectedVolume, 1e-7);
	}
	// ����� �����
	BOOST_AUTO_TEST_CASE(has_a_mass)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody&>(cone).GetMass(), expectedVolume * expectedDensity, 1e-7);
	}
	// ��������� ��� ����
	BOOST_AUTO_TEST_CASE(has_a_type)
	{
		BOOST_CHECK_EQUAL(cone.GetType(), expectedType);
	}
	// ����� ��������� �������������
	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = R"(Cone:
	density = 100
	volume = 2591.36888
	mass = 259136.888
	base radius = 15.5
	height = 10.3
)";
		BOOST_CHECK_EQUAL(static_cast<const CBody&>(cone).ToString(), expectedString);
	}
BOOST_AUTO_TEST_SUITE_END()