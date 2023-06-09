#include "CStringListReverseIterator.h"

CStringListReverseIterator::CStringListReverseIterator(Node* node)
	: m_node(node)
{
}

CStringListReverseIterator::reference CStringListReverseIterator::operator*() const
{
	return m_node->data;
}

CStringListReverseIterator::pointer CStringListReverseIterator::operator->() const
{
	return &m_node->data;
}

CStringListReverseIterator& CStringListReverseIterator::operator++()
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

CStringListReverseIterator CStringListReverseIterator::operator++(int)
{
	CStringListReverseIterator tmpCopy(*this);
	++*this;
	return tmpCopy;
}

CStringListReverseIterator& CStringListReverseIterator::operator--()
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

CStringListReverseIterator CStringListReverseIterator::operator--(int)
{
	CStringListReverseIterator tmpCopy(*this);
	--*this;
	return tmpCopy;
}

bool CStringListReverseIterator::operator==(CStringListReverseIterator const& other) const
{
	return (m_node == other.m_node);
}

bool CStringListReverseIterator::operator!=(CStringListReverseIterator const& other) const
{
	return !(m_node == other.m_node);
}