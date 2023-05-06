#include "stdafx.h"
#include "../Cylinder.h"

struct Cylinder_
{
	const double expectedBaseRadius = 15.5;
	const double expectedHeight = 10.3;
	const double expectedVolume = 7774.106641;
	const double expectedDensity = 100;
	const std::string expectedType = "Cylinder";
	const CCylinder cylinder;
	Cylinder_()
		: cylinder(expectedDensity, expectedBaseRadius, expectedHeight)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Cylinder, Cylinder_)
	// является объемным телом
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK(static_cast<const CBody*>(&cylinder));
	}
	// имеет радиус основания
	BOOST_AUTO_TEST_CASE(has_a_base_radius)
	{
		BOOST_CHECK_EQUAL(cylinder.GetBaseRadius(), expectedBaseRadius);
	}
	// имеет высоту
	BOOST_AUTO_TEST_CASE(has_a_height)
	{
		BOOST_CHECK_EQUAL(cylinder.GetHeight(), expectedHeight);
	}
	// имеет плотность
	BOOST_AUTO_TEST_CASE(has_a_density)
	{
		BOOST_CHECK_EQUAL(static_cast<const CBody&>(cylinder).GetDensity(), expectedDensity);
	}
	// имеет объем
	BOOST_AUTO_TEST_CASE(has_a_volume)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody&>(cylinder).GetVolume(), expectedVolume, 1e-7);
	}
	// имеет массу
	BOOST_AUTO_TEST_CASE(has_a_mass)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody&>(cylinder).GetMass(), expectedVolume * expectedDensity, 1e-7);
	}
	// возвращет тип тела
	BOOST_AUTO_TEST_CASE(has_a_type)
	{
		BOOST_CHECK_EQUAL(cylinder.GetType(), expectedType);
	}
	// имеет строковое представление
	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = R"(Cylinder:
	density = 100
	volume = 7774.106641
	mass = 777410.6641
	base radius = 15.5
	height = 10.3
)";
		BOOST_CHECK_EQUAL(static_cast<const CBody&>(cylinder).ToString(), expectedString);
	}
BOOST_AUTO_TEST_SUITE_END()
