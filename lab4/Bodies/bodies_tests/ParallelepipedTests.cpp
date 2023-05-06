#include "stdafx.h"
#include "../Parallelepiped.h"

struct Parallelepiped_
{
	const double expectedDensity = 50;
	const double expectedWidth = 100;
	const double expectedHeight = 150;
	const double expectedDepth = 100;
	const double expectedVolume = 1500000;
	const std::string expectedType = "Parallelepiped";
	const CParallelepiped parallelepiped;
	Parallelepiped_()
		: parallelepiped(expectedDensity, expectedWidth, expectedHeight, expectedDepth)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(Parallelepiped, Parallelepiped_)
	// является объемным телом
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK(static_cast<const CBody*>(&parallelepiped));
	}
	// имеет ширину
	BOOST_AUTO_TEST_CASE(has_a_width)
	{
		BOOST_CHECK_EQUAL(static_cast<const CParallelepiped&>(parallelepiped).GetWidth(), expectedWidth);
	}
	// имеет высоту
	BOOST_AUTO_TEST_CASE(has_a_height)
	{
		BOOST_CHECK_EQUAL(static_cast<const CParallelepiped&>(parallelepiped).GetHeight(), expectedHeight);
	}
	// имеет глубину
	BOOST_AUTO_TEST_CASE(has_a_depth)
	{
		BOOST_CHECK_EQUAL(static_cast<const CParallelepiped&>(parallelepiped).GetDepth(), expectedDepth);
	}
	// имеет плотность
	BOOST_AUTO_TEST_CASE(has_a_density)
	{
		BOOST_CHECK_EQUAL(static_cast<const CBody&>(parallelepiped).GetDensity(), expectedDensity);
	}
	// имеет объем
	BOOST_AUTO_TEST_CASE(has_a_volume)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody&>(parallelepiped).GetVolume(), expectedVolume, 1e-7);
	}
	// имеет массу
	BOOST_AUTO_TEST_CASE(has_a_mass)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody&>(parallelepiped).GetMass(), expectedVolume * expectedDensity, 1e-7);
	}
	// возвращет тип тела
	BOOST_AUTO_TEST_CASE(has_a_type)
	{
		BOOST_CHECK_EQUAL(parallelepiped.GetType(), expectedType);
	}
	// имеет строковое представление
	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = R"(Parallelepiped:
	density = 50
	volume = 1500000
	mass = 75000000
	width = 100
	height = 150
	depth = 100
)";
		BOOST_CHECK_EQUAL(static_cast<const CBody&>(parallelepiped).ToString(), expectedString);
	}
BOOST_AUTO_TEST_SUITE_END()