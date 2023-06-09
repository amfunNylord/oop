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
	m_node = m_node->next;
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
	m_node = m_node->prev;
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
