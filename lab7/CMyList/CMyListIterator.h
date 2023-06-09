#pragma once
#include "CMyListNode.h"

template <typename T>
class CMyList;

template <typename T>
class CMyListIterator
{
	friend class CMyList<T>;

public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = T;
	using pointer = value_type*;
	using reference = value_type&;

	CMyListIterator(Node<T>* node)
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

	CMyListIterator& operator++()
	{
		m_node = m_node->next;
		return *this;
	}
	CMyListIterator operator++(int)
	{
		CMyListIterator tmpCopy(*this);
		++*this;
		return tmpCopy;
	}
	CMyListIterator& operator--()
	{
		m_node = m_node->prev;
		return *this;
	}
	CMyListIterator operator--(int)
	{
		CMyListIterator tmpCopy(*this);
		--*this;
		return tmpCopy;
	}

	bool operator==(CMyListIterator const& other) const
	{
		return (m_node == other.m_node);
	}
	bool operator!=(CMyListIterator const& other) const
	{
		return !(m_node == other.m_node);
	}

private:
	Node<T>* m_node;
};