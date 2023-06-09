#include "CStringList.h"
// excep?
CStringList::CStringList(const CStringList& other)
{
	for (std::string el : other)
	{
		try
		{
			InsertBack(el);
		}
		catch (...)
		{
			Clear();
			throw;
		}
	}
}

CStringList& CStringList::operator=(const CStringList& other)
{
	if (std::addressof(other) != this)
	{
		Clear();
		CStringList tmpCopy(other);
		std::swap(m_size, tmpCopy.m_size);
		std::swap(m_firstNode, tmpCopy.m_firstNode);
		std::swap(m_lastNode, tmpCopy.m_lastNode);
	}
	return *this;
}

CStringList::CStringList(CStringList&& other) noexcept
	: m_firstNode(other.m_firstNode)
	, m_lastNode(other.m_lastNode)
	, m_size(other.m_size)
{
	other.m_firstNode = other.m_lastNode = nullptr;
	other.m_size = 0;
}

CStringList& CStringList::operator=(CStringList&& other) noexcept
{
	if (&other != this)
	{
		Clear();
		m_firstNode = other.m_firstNode;
		m_lastNode = other.m_lastNode;
		m_size = other.m_size;
		other.m_firstNode = other.m_lastNode = nullptr;
		other.m_size = 0;
	}
	return *this;
}

size_t CStringList::GetSize() const
{
	return m_size;
}

bool CStringList::IsEmpty() const
{
	return (m_size == 0);
}

void CStringList::InsertFront(const std::string& data)
{
	Insert(begin(), data);
}

void CStringList::InsertBack(const std::string& data)
{
	Insert(end(), data);
}

void CStringList::Clear()
{
	if (!IsEmpty())
	{
		Node* exLastNode = m_lastNode;
		m_lastNode = m_lastNode->prev;
		m_lastNode->next = nullptr;
		delete exLastNode;
		while (m_firstNode != nullptr)
		{
			Node* tempNode = m_firstNode->next;
			delete m_firstNode;
			m_firstNode = tempNode;
		}
	}
	else
	{
		delete m_lastNode;
	}
	m_size = 0;
	m_firstNode = m_lastNode = nullptr;
}

void CStringList::Insert(CStringListIterator iter, const std::string& data)
{
	m_size++;
	if (iter.m_node != nullptr && iter.m_node->data != "" && iter.m_node->prev == nullptr)
	{
		Node* newNode = new Node(data, nullptr, m_firstNode);
		m_firstNode->prev = newNode;
		m_firstNode = newNode;
		return;
	}
	if (iter.m_node == nullptr || iter.m_node->prev == nullptr)
	{
		Node* newNode = new Node(data, nullptr, m_lastNode);
		m_firstNode = newNode;
		m_lastNode->prev = newNode;
		return;
	}
	Node* leftNode = iter.m_node->prev;
	Node* rightNode = iter.m_node;
	Node* newNode = new Node(data, leftNode, rightNode);
	leftNode->next = newNode;
	rightNode->prev = newNode;
}

void CStringList::Erase(CStringListIterator iter)
{
	if (IsEmpty())
	{
		throw std::logic_error("List is empty");
	}
	m_size--;
	if (iter.m_node->prev == nullptr)
	{
		m_firstNode = m_firstNode->next;
		delete m_firstNode->prev;
		return;
	}
	if (iter.m_node->next == nullptr)
	{
		Node* erasingNode = m_lastNode->prev;
		m_lastNode->prev = erasingNode->prev;
		delete erasingNode;
		m_lastNode->prev->next = m_lastNode; 
		return;
	}
	Node* leftNode = iter.m_node->prev;
	Node* rightNode = iter.m_node->next;
	delete iter.m_node;
	leftNode->next = rightNode;
	rightNode->prev = leftNode;

}

CStringList::~CStringList()
{
	Clear();
}

CStringListIterator CStringList::begin() const
{
	return CStringListIterator(m_firstNode);
}

CStringListIterator CStringList::end() const
{
	return CStringListIterator(m_lastNode);
}

CStringListConstIterator CStringList::cbegin() const
{
	return CStringListConstIterator(m_firstNode);
}

CStringListConstIterator CStringList::cend() const
{
	return CStringListConstIterator(m_lastNode);
}

CStringListReverseIterator CStringList::rbegin() const
{
	return CStringListReverseIterator(m_lastNode);
}

CStringListReverseIterator CStringList::rend() const
{
	return CStringListReverseIterator(m_firstNode);
}

CStringListReverseConstIterator CStringList::crbegin() const
{
	return CStringListReverseConstIterator(m_lastNode);
}

CStringListReverseConstIterator CStringList::crend() const
{
	return CStringListReverseConstIterator(m_firstNode);
}

