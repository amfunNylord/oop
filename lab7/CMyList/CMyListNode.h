#pragma once
#include <iostream>
#include <optional>

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