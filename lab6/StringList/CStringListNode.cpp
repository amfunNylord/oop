#include "CStringListNode.h"

Node::Node(const std::string data, Node* prev, Node* next)
	: data(data)
	, prev(prev)
	, next(next)
{
}