#include "CStringListReverseConstIterator.h"

CStringListReverseConstIterator::CStringListReverseConstIterator(Node* node)
	: m_node(node)
{
}

CStringListReverseConstIterator::reference CStringListReverseConstIterator::operator*() const
{
	return m_node->data;
}

CStringListReverseConstIterator::pointer CStringListReverseConstIterator::operator->() const
{
	return &m_node->data;
}

CStringListReverseConstIterator& CStringListReverseConstIterator::operator++()
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

CStringListReverseConstIterator CStringListReverseConstIterator::operator++(int)
{
	CStringListReverseConstIterator tmpCopy(*this);
	++*this;
	return tmpCopy;
}

CStringListReverseConstIterator& CStringListReverseConstIterator::operator--()
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

CStringListReverseConstIterator CStringListReverseConstIterator::operator--(int)
{
	CStringListReverseConstIterator tmpCopy(*this);
	--*this;
	return tmpCopy;
}

bool CStringListReverseConstIterator::operator==(CStringListReverseConstIterator const& other) const
{
	return (m_node == other.m_node);
}

bool CStringListReverseConstIterator::operator!=(CStringListReverseConstIterator const& other) const
{
	return !(m_node == other.m_node);
}
