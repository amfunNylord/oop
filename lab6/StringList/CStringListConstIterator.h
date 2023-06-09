#pragma once
#include "CStringListNode.h"

class CStringListConstIterator
{
	friend class CStringList;

public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const std::string;
	using pointer = const value_type*;
	using reference = const value_type&;

	CStringListConstIterator(Node* node);
	reference operator*() const;
    pointer operator->() const;

	CStringListConstIterator& operator++();
	CStringListConstIterator operator++(int);

	CStringListConstIterator& operator--();
	CStringListConstIterator operator--(int);

	bool operator==(CStringListConstIterator const& other) const;
	bool operator!=(CStringListConstIterator const& other) const;

private:
	Node* m_node;
};