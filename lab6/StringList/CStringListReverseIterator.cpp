#include "CStringListReverseIterator.h"

CStringListReverseIterator::CStringListReverseIterator(Node* node)
	: m_node(node)
{
}

CStringListReverseIterator::CStringListReverseIterator(const CStringListReverseIterator& iter)
	: m_node(iter.m_node)
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
	m_node = m_node->prev;
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
	m_node = m_node->next;
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