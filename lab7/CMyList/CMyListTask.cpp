#include <iostream>
#include "CMyList.h"

int main()
{
	CMyList<int> list;
	list.InsertBack(1);
	list.InsertBack(1);
	auto iter = list.begin();
	++iter;
	++iter;
	++iter;
}