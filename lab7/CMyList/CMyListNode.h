#pragma once
#include <iostream>

template <typename T>
struct Node
{
public:
	T data;
	Node<T> *prev, *next;

public:
	Node(const T data, Node* prev, Node* next)
		: data(data)
		, prev(prev)
		, next(next)
	{
	}
};
