#pragma once
#include "CStringListNode.h"

class CStringListIterator
{
	friend class CStringList;

public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = std::string;
	using pointer = value_type*;
	using reference = value_type&;

	CStringListIterator(Node* node);
	CStringListIterator(const CStringListIterator& iter);
	CStringListIterator() = default;
	reference operator*() const;
	pointer operator->() const;

	CStringListIterator& operator++();
	CStringListIterator operator++(int);

	CStringListIterator& operator--();
	CStringListIterator operator--(int);

	bool operator==(CStringListIterator const& other) const;
	bool operator!=(CStringListIterator const& other) const;

private:
	Node* m_node = nullptr;
};
