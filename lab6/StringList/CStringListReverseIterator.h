#pragma once
#include "CStringListNode.h"

class CStringListReverseIterator
{
	friend class CStringList;

public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = std::string;
	using pointer = value_type*;
	using reference = value_type&;

	CStringListReverseIterator(Node* node);
	reference operator*() const;
	pointer operator->() const;

	CStringListReverseIterator& operator++();
	CStringListReverseIterator operator++(int);

	CStringListReverseIterator& operator--();
	CStringListReverseIterator operator--(int);

	bool operator==(CStringListReverseIterator const& other) const;
	bool operator!=(CStringListReverseIterator const& other) const;

private:
	Node* m_node;
};
