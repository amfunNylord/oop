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
		if (m_node->next == nullptr)
		{
			return m_node->prev->data;
		}
		return m_node->data;
	}
	pointer operator->() const
	{
		return &m_node->data;
	}

	CMyListIterator& operator++()
	{
		try
		{
			if (m_node->next == nullptr)
			{
				throw std::runtime_error("Iterator is out of range");
			}
			m_node = m_node->next;
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
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
		try
		{
			if (m_node->prev == nullptr)
			{
				throw std::runtime_error("Iterator is out of range");
			}
			m_node = m_node->prev;
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
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