#pragma once
#include "CMyListIterator.h"
#include "CMyListReverseIterator.h"

template <typename T>
class CMyList
{
public:
	CMyList() = default;
	CMyList(const CMyList& other)
	{
		for (T el : other)
		{
			try
			{
				InsertBack(el);
			}
			catch (const std::exception&)
			{
				Clear();
				throw std::bad_alloc("Not enough memory");
			}
		}
	}
	CMyList& operator=(const CMyList& other)
	{
		if (std::addressof(other) != this)
		{
			Clear();
			CMyList tmpCopy(other);
			std::swap(m_size, tmpCopy.m_size);
			std::swap(m_firstNode, tmpCopy.m_firstNode);
			std::swap(m_lastNode, tmpCopy.m_lastNode);
		}
		return *this;
	}

	~CMyList() noexcept
	{
		Clear();
	}

	CMyListIterator<T> begin() const
	{
		return CMyListIterator<T>(m_firstNode);
	}
	CMyListIterator<T> end() const
	{
		return CMyListIterator<T>(m_lastNode);
	}
	CMyListReverseIterator<T> rbegin() const
	{
		return CMyListReverseIterator<T>(m_lastNode);
	}
	CMyListReverseIterator<T> rend() const
	{
		return CMyListReverseIterator<T>(m_firstNode);
	}

	size_t GetSize() const 
	{
		return m_size;
	};
	bool IsEmpty() const
	{
		return (m_size == 0);
	}
	void InsertFront(const T& data)
	{
		Insert(begin(), data);
	}
	void InsertBack(const T& data)
	{
		Insert(end(), data);
	}
	void Clear()
	{
		if (!IsEmpty())
		{
			Node<T>* exLastNode = m_lastNode;
			m_lastNode = m_lastNode->prev;
			m_lastNode->next = nullptr;
			delete exLastNode;
			while (m_firstNode != nullptr)
			{	
				Node<T>* tempNode = m_firstNode->next;
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
	void Insert(CMyListIterator<T> iter, const T& data)
	{
		m_size++;
		if (iter.m_node != nullptr && iter.m_node->data != T() && iter.m_node->prev == nullptr)
		{
			Node<T>* newNode = new Node<T>(data, nullptr, m_firstNode);
			m_firstNode->prev = newNode;
			m_firstNode = newNode;
			return;
		}
		if (iter.m_node == nullptr || iter.m_node->prev == nullptr)
		{
			Node<T>* newNode = new Node<T>(data, nullptr, m_lastNode);
			m_firstNode = newNode;
			m_lastNode->prev = newNode;
			return;
		}
		Node<T>* leftNode = iter.m_node->prev;
		Node<T>* rightNode = iter.m_node;
		Node<T>* newNode = new Node<T>(data, leftNode, rightNode);
		leftNode->next = newNode;
		rightNode->prev = newNode;
	}
	void Erase(CMyListIterator<T> iter)
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
			Node<T>* erasingNode = m_lastNode->prev;
			m_lastNode->prev = erasingNode->prev;
			delete erasingNode;
			m_lastNode->prev->next = m_lastNode;
			return;
		}
		Node<T>* leftNode = iter.m_node->prev;
		Node<T>* rightNode = iter.m_node->next;
		delete iter.m_node;
		leftNode->next = rightNode;
		rightNode->prev = leftNode;
	}

private:
	size_t m_size = 0;
	Node<T> *m_firstNode = nullptr, *m_lastNode = new Node<T>(T(), nullptr, nullptr);
};
