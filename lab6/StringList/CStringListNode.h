#pragma once
#include <iostream>

struct Node
{
public:
	std::string data;
	Node *prev, *next;

public:
	Node(const std::string data, Node* prev, Node* next);
};
