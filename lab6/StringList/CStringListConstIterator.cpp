#include "CStringListConstIterator.h"

CStringListConstIterator::CStringListConstIterator(Node* node)
	: m_node(node)
{
}

CStringListConstIterator::reference CStringListConstIterator::operator*() const
{
	return m_node->data;
}

CStringListConstIterator::pointer CStringListConstIterator::operator->() const
{
	return &m_node->data;
}

CStringListConstIterator& CStringListConstIterator::operator++()
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

CStringListConstIterator CStringListConstIterator::operator++(int)
{
	CStringListConstIterator tmpCopy(*this);
	++*this;
	return tmpCopy;
}

CStringListConstIterator& CStringListConstIterator::operator--()
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

CStringListConstIterator CStringListConstIterator::operator--(int)
{
	CStringListConstIterator tmpCopy(*this);
	--*this;
	return tmpCopy;
}

bool CStringListConstIterator::operator==(CStringListConstIterator const& other) const
{
	return (m_node == other.m_node);
}

bool CStringListConstIterator::operator!=(CStringListConstIterator const& other) const
{
	return !(m_node == other.m_node);
}
