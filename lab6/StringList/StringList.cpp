#include <iostream>
#include <list>
#include "CStringList.h"

int main()
{
	CStringList list;

	list.InsertBack("first");
	list.InsertBack("second");
	list.InsertBack("third");
	list.InsertBack("fourth");
	list.InsertBack("fifth");
	auto iter = list.begin();
	iter++;

	list.Erase(iter);

	iter = list.begin();
	iter++;

	list.Erase(iter);


	for (auto el : list)
		std::cout << el << ' ';

	return 0;
}