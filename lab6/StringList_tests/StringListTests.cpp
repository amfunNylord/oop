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
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(after_appeding_a_string)
		BOOST_AUTO_TEST_CASE(increases_its_size_by_1)
		{
			auto oldSize = list.GetSize();
			list.InsertBack("hello");
			BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 1);
			list.InsertBack("hello");
			BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 2);
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(when_we_want_to_use_insert_in_not_empty_list)
		BOOST_AUTO_TEST_CASE(insert_new_string_on_the_second_place)
		{
			list.InsertBack("first");
			list.InsertBack("second");
			auto oldSize = list.GetSize();
			auto iter = list.begin();
			++iter;
			list.Insert(iter, "third");
			BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 1);
			iter = list.begin();
			++iter;
			BOOST_CHECK_EQUAL(*iter, "third");
			++iter;
			BOOST_CHECK_EQUAL(*iter, "second");
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(iterator)
		BOOST_AUTO_TEST_CASE(can_be_increnenting)
		{
			list.InsertBack("first");
			list.InsertBack("second");
			auto iter = list.begin();
			BOOST_CHECK_EQUAL(*iter, "first");
			++iter;
			BOOST_CHECK_EQUAL(*iter, "second");
		}
		BOOST_AUTO_TEST_CASE(can_be_reversing)
		{
			list.InsertBack("first");
			list.InsertBack("second");
			auto iter = list.rbegin();
			BOOST_CHECK_EQUAL(*iter, "second");
			iter++;
			BOOST_CHECK_EQUAL(*iter, "first");
		}
		BOOST_AUTO_TEST_CASE(can_be_const)
		{
			list.InsertBack("first");
			list.InsertBack("second");
			auto iter = list.cbegin();
			*iter = "third";
			BOOST_CHECK_EQUAL(*iter, "first");
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()