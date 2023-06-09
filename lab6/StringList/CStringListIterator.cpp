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
	m_node = m_node->next;
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
	m_node = m_node->prev;
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