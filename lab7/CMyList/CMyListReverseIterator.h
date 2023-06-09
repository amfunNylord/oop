#pragma once
#include "CMyListNode.h"

template <typename T>
class CMyListReverseIterator
{
	friend class CMyList<T>;

public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = T;
	using pointer = value_type*;
	using reference = value_type&;

	CMyListReverseIterator(Node<T>* node)
		: m_node(node)
	{
	}
	reference operator*() const
	{
		return m_node->data;
	}
	pointer operator->() const
	{
		return &m_node->data;
	}

	CMyListReverseIterator& operator++()
	{
		m_node = m_node->prev;
		return *this;
	}
	CMyListReverseIterator operator++(int)
	{
		CMyListReverseIterator tmpCopy(*this);
		++*this;
		return tmpCopy;
	}

	CMyListReverseIterator& operator--()
	{
		m_node = m_node->next;
		return *this;
	}
	CMyListReverseIterator operator--(int)
	{
		CMyListReverseIterator tmpCopy(*this);
		--*this;
		return tmpCopy;
	}

	bool operator==(CMyListReverseIterator const& other) const
	{
		return (m_node == other.m_node);
	}
	bool operator!=(CMyListReverseIterator const& other) const
	{
		return !(m_node == other.m_node);
	}

private:
	Node<T>* m_node;
};