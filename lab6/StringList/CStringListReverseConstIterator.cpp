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
	m_node = m_node->prev;
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
	m_node = m_node->next;
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
