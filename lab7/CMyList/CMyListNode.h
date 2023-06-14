#pragma once
#include <iostream>
#include <new>

template <typename T>
struct Node
{
	T data;
	Node<T> *prev, *next;

	Node(const T data, Node* prev, Node* next)
		: data(data)
		, prev(prev)
		, next(next)
	{
	}
};

//template <typename T>
//struct Node
//{
//	Node() = default;
//
//	Node(T data, Node* prev, Node* next)
//	{
//		new (buffer) T(std::move(data));
//	}
//	T* GetData()
//	{
//		return reinterpret_cast<T*>(&buffer[0]);
//	}
//	void Destroy()
//	{
//		GetData()->~T();
//	}
//	alignas(T) char buffer[sizeof(T)];
//	Node* prev = nullptr;
//	Node* next = nullptr;
//};
