#include "stdafx.h"
#include "../StringList/CStringList.h"

struct EmptyStringList
{
	CStringList list;
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
			CStringList list2 = CStringList(list);
			BOOST_CHECK_EQUAL(list2.GetSize(), list.GetSize());
		}
		BOOST_AUTO_TEST_CASE(same_as_the_original_by_moving_constructor)
		{
			std::string insertingWord = "first";
			list.InsertBack(insertingWord);
			CStringList list2 = CStringList(std::move(list));
			BOOST_CHECK_EQUAL(list2.GetSize(), 1);
			BOOST_CHECK_EQUAL(list.GetSize(), 0);
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
			CStringList list2 = list;
			BOOST_CHECK_EQUAL(list.GetSize(), list2.GetSize());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(moving_assignment)
		BOOST_AUTO_TEST_CASE(the_same_as_the_original)
		{
			list.InsertBack("first");
			list.InsertBack("second");
			size_t listSize = list.GetSize();
			CStringList list2 = std::move(list);
			BOOST_CHECK_EQUAL(list2.GetSize(), listSize);
			BOOST_CHECK_EQUAL(list.GetSize(), 0);
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

			auto constIter = list.cbegin();
			BOOST_CHECK_EQUAL(*constIter, "first");

			constIter = list.cend();
			BOOST_CHECK_EQUAL(*--constIter, "third");

			iter = list.begin();
			BOOST_CHECK_EQUAL(*iter, "first");

			iter = list.end();
			BOOST_CHECK_EQUAL(*--iter, "third");

			auto reverseIter = list.rbegin();
			BOOST_CHECK_EQUAL(*++reverseIter, "third");

			reverseIter = list.rend();
			BOOST_CHECK_EQUAL(*reverseIter, "first");

			auto constReverseIter = list.crbegin();
			BOOST_CHECK_EQUAL(*++constReverseIter, "third");

			constReverseIter = list.crend();
			BOOST_CHECK_EQUAL(*constReverseIter, "first");
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()