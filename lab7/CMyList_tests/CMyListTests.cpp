#include "stdafx.h"
#include "../CMyList/CMyList.h"

struct EmptyStringList
{
	CMyList<std::string> list;
};

BOOST_FIXTURE_TEST_SUITE(String_list, EmptyStringList)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(is_empty)
		{
			BOOST_CHECK_EQUAL(list.GetSize(), 0u);
		}
		BOOST_AUTO_TEST_CASE(same_as_the_original_by_copying_constructor)
		{
			std::string insertingWord = "first";
			list.InsertBack(insertingWord);
			CMyList<std::string> list2 = CMyList<std::string>(list);
			BOOST_CHECK_EQUAL(list2.GetSize(), list.GetSize());
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(insert_methods)
		BOOST_AUTO_TEST_CASE(insert_back)
		{
			list.InsertBack("first");
			list.InsertBack("second");
			list.InsertBack("third");
			BOOST_CHECK_EQUAL(list.GetSize(), 3);
		}
		BOOST_AUTO_TEST_CASE(insert_front)
		{
			list.InsertFront("first");
			list.InsertFront("second");
			list.InsertFront("third");
			BOOST_CHECK_EQUAL(list.GetSize(), 3);
		}
		BOOST_AUTO_TEST_CASE(insert_in_the_beginning_of_empty_list)
		{
			std::string insertingWord = "first";
			list.Insert(list.begin(), insertingWord);

			BOOST_CHECK_EQUAL(*list.begin(), insertingWord);
			BOOST_CHECK_EQUAL(list.GetSize(), 1);
		}
		BOOST_AUTO_TEST_CASE(insert_in_the_beginning_of_non_empty_list)
		{
			std::string insertingWord = "first";
			list.InsertBack("second");
			list.Insert(list.begin(), insertingWord);

			BOOST_CHECK_EQUAL(*list.begin(), insertingWord);
			BOOST_CHECK_EQUAL(list.GetSize(), 2);
		}
		BOOST_AUTO_TEST_CASE(insert_in_the_end_of_empty_list)
		{
			std::string insertingWord = "first";
			list.Insert(list.end(), insertingWord);

			BOOST_CHECK_EQUAL(*--list.end(), insertingWord);
			BOOST_CHECK_EQUAL(list.GetSize(), 1);
		}
		BOOST_AUTO_TEST_CASE(insert_in_the_end_of_non_empty_list)
		{
			std::string insertingWord = "first";
			list.InsertBack("zero");
			list.Insert(list.end(), insertingWord);

			BOOST_CHECK_EQUAL(*--list.end(), insertingWord);
			BOOST_CHECK_EQUAL(list.GetSize(), 2);
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(erase_method)
		BOOST_AUTO_TEST_CASE(erase_empty_list)
		{
			BOOST_CHECK_THROW(list.Erase(list.begin()), std::logic_error);
		}
		BOOST_AUTO_TEST_CASE(erase_existing_element)
		{
			list.InsertBack("first");
			BOOST_CHECK_EQUAL(list.GetSize(), 1);
			list.Erase(list.begin());
			BOOST_CHECK_EQUAL(list.GetSize(), 0);
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(clear_method)
		BOOST_AUTO_TEST_CASE(clear_list)
		{
			list.InsertBack("first");
			list.InsertBack("second");
			list.InsertBack("third");
			BOOST_CHECK_EQUAL(list.GetSize(), 3);
			list.Clear();
			BOOST_CHECK_EQUAL(list.GetSize(), 0);
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(copy_assignment)
		BOOST_AUTO_TEST_CASE(the_same_as_the_original)
		{
			list.InsertBack("first");
			list.InsertBack("second");
			CMyList<std::string> list2 = list;
			BOOST_CHECK_EQUAL(list.GetSize(), list2.GetSize());
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(range_based_for)
		BOOST_AUTO_TEST_CASE(works)
		{
			list.InsertBack("first");
			list.InsertBack("second");
			list.InsertBack("third");
			std::ostringstream output;

			for (auto& el : list)
			{
				output << el;
			}

			BOOST_CHECK_EQUAL(output.str(), "firstsecondthird");
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(iterator)
		BOOST_AUTO_TEST_CASE(works)
		{
			list.InsertBack("first");
			list.InsertBack("second");
			list.InsertBack("third");

			auto iter = list.begin();
			BOOST_CHECK_EQUAL(*iter, "first");
			iter++;
			BOOST_CHECK_EQUAL(*iter, "second");
			++iter;
			BOOST_CHECK_EQUAL(*iter, "third");
			--iter;
			BOOST_CHECK_EQUAL(*iter, "second");
			iter--;
			BOOST_CHECK_EQUAL(*iter, "first");

			iter = list.begin();
			BOOST_CHECK_EQUAL(*iter, "first");

			iter = list.end();
			BOOST_CHECK_EQUAL(*--iter, "third");

			auto reverseIter = list.rbegin();
			BOOST_CHECK_EQUAL(*++reverseIter, "third");

			reverseIter = list.rend();
			BOOST_CHECK_EQUAL(*reverseIter, "first");
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()


struct EmptyIntList
{
	CMyList<int> intList;
};

BOOST_FIXTURE_TEST_SUITE(Int_list, EmptyIntList)
	BOOST_AUTO_TEST_SUITE(is_ok)
		BOOST_AUTO_TEST_CASE(insert_front_method)
		{
			int num1 = 10;
			intList.InsertFront(num1);
			BOOST_CHECK_EQUAL(intList.GetSize(), 1);
		}
		BOOST_AUTO_TEST_CASE(insert_back_method)
		{
			int num1 = 10;
			intList.InsertBack(num1);
			BOOST_CHECK_EQUAL(intList.GetSize(), 1);
		}
		BOOST_AUTO_TEST_CASE(insert_method)
		{
			int num1 = 10;
			int num2 = 5;
			intList.InsertFront(num1);
			intList.InsertFront(num1);
			auto iter = intList.begin();
			iter++;
			intList.Insert(iter, num2);
			BOOST_CHECK_EQUAL(intList.GetSize(), 3);
			iter = intList.begin();
			iter++;
			BOOST_CHECK_EQUAL(*iter, num2);
		}
	
		BOOST_AUTO_TEST_CASE(range_based_for_works)
		{
			intList.InsertBack(2);
			intList.InsertBack(3);
			intList.InsertBack(4);
			std::ostringstream output;

			for (auto& el : intList)
			{
				output << el;
			}

			BOOST_CHECK_EQUAL(output.str(), "234");
		}

		BOOST_AUTO_TEST_CASE(erase_method)
		{
			intList.InsertBack(2);
			intList.InsertBack(3);
			intList.InsertBack(4);
			intList.Erase(intList.begin());
			BOOST_CHECK_EQUAL(intList.GetSize(), 2);
			BOOST_CHECK_EQUAL(*intList.begin(), 3);
		}

		BOOST_AUTO_TEST_CASE(clear_method)
		{
			BOOST_CHECK(intList.IsEmpty());
			intList.InsertBack(2);
			intList.InsertBack(3);
			intList.InsertBack(4);
			BOOST_CHECK_EQUAL(intList.GetSize(), 3);
			intList.Clear();
			BOOST_CHECK_EQUAL(intList.GetSize(), 0);
		}

		BOOST_AUTO_TEST_CASE(copy_constructor)
		{
			intList.InsertBack(2);
			CMyList<int> intList2(intList);
			BOOST_CHECK_EQUAL(intList.GetSize(), intList2.GetSize());
		}
	
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()