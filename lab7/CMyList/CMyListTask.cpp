#include <iostream>
#include "CMyList.h"

int main()
{
	CMyList<int> list;
	list.InsertFront(1);
	list.InsertBack(2);
	auto iter = list.begin();
	list.Insert(iter, 0);
	list.Erase(list.end());
	for (auto& el : list)
	{
		std::cout << el << ' ';
	}
	std::cout << std::endl;
	list.Clear();
	list.Insert(list.end(), 5);
	std::cout << "Is list clear? - " << list.IsEmpty();
	
}