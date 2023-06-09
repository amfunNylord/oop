#include "CStringListIterator.h"

CStringListIterator::CStringListIterator(Node* node)
	: m_node(node)
{
}

CStringListIterator::reference CStringListIterator::operator*() const
{
	return m_node->data;
}

CStringListIterator::pointer CStringListIterator::operator->() const
{
	return &m_node->data;
}

CStringListIterator& CStringListIterator::operator++()
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

CStringListIterator CStringListIterator::operator++(int)
{
	CStringListIterator tmpCopy(*this);
	++*this;
	return tmpCopy;
}

CStringListIterator& CStringListIterator::operator--()
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

CStringListIterator CStringListIterator::operator--(int)
{
	CStringListIterator tmpCopy(*this);
	--*this;
	return tmpCopy;
}

bool CStringListIterator::operator==(CStringListIterator const& other) const
{
	return (m_node == other.m_node);
}

bool CStringListIterator::operator!=(CStringListIterator const& other) const
{
	return !(m_node == other.m_node);
}