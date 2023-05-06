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
// Конус
BOOST_FIXTURE_TEST_SUITE(Cone, Cone_)
	// является объемным телом
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK(static_cast<const CBody*>(&cone));
	}
	// имеет радиус основания
	BOOST_AUTO_TEST_CASE(has_a_height)
	{
		BOOST_CHECK_EQUAL(cone.GetHeight(), expectedHeight);
	}
	// имеет высоту
	BOOST_AUTO_TEST_CASE(has_a_base_radius)
	{
		BOOST_CHECK_EQUAL(cone.GetBaseRadius(), expectedBaseRadius);
	}
	// имеет плотность
	BOOST_AUTO_TEST_CASE(has_a_density)
	{
		BOOST_CHECK_EQUAL(static_cast<const CBody&>(cone).GetDensity(), expectedDensity);
	}
	// имеет объем
	BOOST_AUTO_TEST_CASE(has_a_volume)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody&>(cone).GetVolume(), expectedVolume, 1e-7);
	}
	// имеет массу
	BOOST_AUTO_TEST_CASE(has_a_mass)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody&>(cone).GetMass(), expectedVolume * expectedDensity, 1e-7);
	}
	// возвращет тип тела
	BOOST_AUTO_TEST_CASE(has_a_type)
	{
		BOOST_CHECK_EQUAL(cone.GetType(), expectedType);
	}
	// имеет строковое представление
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