#pragma once
#include <iostream>
#include <optional>
//#include <new>

template <typename T>
struct Node
{
	std::optional<T> data;
	Node<T> *prev = nullptr, *next = nullptr;
	
	Node() = default;

	Node(const std::optional<T>& data)
		: data(data)
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
