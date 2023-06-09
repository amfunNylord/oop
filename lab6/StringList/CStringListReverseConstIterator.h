#pragma once
#include "CStringListNode.h"

class CStringListReverseConstIterator
{
	friend class CStringList;

public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const std::string;
	using pointer = const value_type*;
	using reference = const value_type&;

	CStringListReverseConstIterator(Node* node);
	reference operator*() const;
	pointer operator->() const;

	CStringListReverseConstIterator& operator++();
	CStringListReverseConstIterator operator++(int);

	CStringListReverseConstIterator& operator--();
	CStringListReverseConstIterator operator--(int);

	bool operator==(CStringListReverseConstIterator const& other) const;
	bool operator!=(CStringListReverseConstIterator const& other) const;

private:
	Node* m_node;
};
