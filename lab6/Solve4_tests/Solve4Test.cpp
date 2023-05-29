#include "stdafx.h"
#include "../Solve4/Solve4.h"

//template <typename Ex, typename Fn>
//void ExpectException(Fn&& fn, const std::string& expectedDescription)
//{
//	BOOST_CHECK_EXCEPTION(fn(), Ex, [&](const Ex& e) {
//		return e.what() == expectedDescription;
//	});	
//
//	try
//	{
//		fn();
//		BOOST_ERROR("No exception thrown");
//	}
//	catch (const Ex& e)
//	{
//		BOOST_CHECK_EQUAL(expectedDescription, e.what());
//	}
//	catch (...)
//	{
//		BOOST_ERROR("Unexpected exception");
//	}
//
//}

BOOST_AUTO_TEST_SUITE(Fourth_degree_equation)
	BOOST_AUTO_TEST_CASE(solves_standard_4th_degree_equation)
	{
		const double firstCoef = 1;
		const double secondCoef = 4;
		const double thirdCoef = -4;
		const double fourthCoef = -20;
		const double fifthCoef = -5;
		const double expectedRootCount = 4;
		const double expectedFirstRoot = 2.2361;
		const double expectedSecondRoot = -2.2361;
		const double expectedThirdRoot = -0.2679;
		const double expectedFourthRoot = -3.7321;
		EquationRoot4 result = Solve4(firstCoef, secondCoef, thirdCoef, fourthCoef, fifthCoef);
		BOOST_CHECK_EQUAL(result.numRoots, expectedRootCount);
		BOOST_CHECK_CLOSE_FRACTION(result.roots[0], expectedFirstRoot, 1e-7);
		BOOST_CHECK_CLOSE_FRACTION(result.roots[1], expectedSecondRoot, 1e-7);
		BOOST_CHECK_CLOSE_FRACTION(result.roots[2], expectedThirdRoot, 1e-7);
		BOOST_CHECK_CLOSE_FRACTION(result.roots[3], expectedFourthRoot, 1e-7);
	}
	BOOST_AUTO_TEST_CASE(throws_error_when_first_coefficient_is_zero)
	{
		const double firstCoef = 0;
		const double secondCoef = 4;
		const double thirdCoef = -4;
		const double fourthCoef = -20;
		const double fifthCoef = -5;
		BOOST_CHECK_THROW(Solve4(firstCoef, secondCoef, thirdCoef, fourthCoef, fifthCoef), std::invalid_argument);
		/*std::string error = "The coefficient at the variable to the fourth degree can't be zero";
		ExpectException([firstCoef, secondCoef, thirdCoef, fourthCoef, fifthCoef](){return Solve4(firstCoef, secondCoef, thirdCoef, fourthCoef, fifthCoef); }, error);
		ExpectException(Solve4(firstCoef, secondCoef, thirdCoef, fourthCoef, fifthCoef), error);*/
	}
	BOOST_AUTO_TEST_CASE(throws_error_when_one_of_others_coefficients_is_zero)
	{
		const double zeroCoef = 0;
		const double secondCoef = 4;
		const double thirdCoef = -4;
		const double fourthCoef = -20;
		const double fifthCoef = -5;
		BOOST_CHECK_THROW(Solve4(secondCoef, zeroCoef, thirdCoef, fourthCoef, fifthCoef), std::invalid_argument);
		BOOST_CHECK_THROW(Solve4(secondCoef, thirdCoef, zeroCoef, fourthCoef, fifthCoef), std::invalid_argument);
		BOOST_CHECK_THROW(Solve4(secondCoef, fourthCoef, thirdCoef, zeroCoef, fifthCoef), std::invalid_argument);
		BOOST_CHECK_THROW(Solve4(secondCoef, fifthCoef, thirdCoef, fourthCoef, zeroCoef), std::invalid_argument);
	}
	BOOST_AUTO_TEST_CASE(throws_error_when_some_roots_are_complex)
	{
		const double zeroCoef = 1;
		const double secondCoef = 3;
		const double thirdCoef = 3;
		const double fourthCoef = -1;
		const double fifthCoef = -6;
		BOOST_CHECK_THROW(Solve4(secondCoef, zeroCoef, thirdCoef, fourthCoef, fifthCoef), std::domain_error);
	}
	BOOST_AUTO_TEST_CASE(throws_error_when_no_roots)
	{
		const double zeroCoef = 5;
		const double secondCoef = 2;
		const double thirdCoef = 3;
		const double fourthCoef = 4;
		const double fifthCoef = 5;
		BOOST_CHECK_THROW(Solve4(secondCoef, zeroCoef, thirdCoef, fourthCoef, fifthCoef), std::domain_error);
	}
BOOST_AUTO_TEST_SUITE_END()