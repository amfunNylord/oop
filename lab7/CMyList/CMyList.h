#pragma once
#include "CMyListIterator.h"
#include "CMyListReverseIterator.h"
#include <optional>
// написать noexcept gde eto vozmojno 
template <typename T>
class CMyList
{
public:
	CMyList() = default;
	CMyList(const CMyList& other)
	{
		// const &
		for (T el : other)
		{
			try
			{
				InsertBack(el);
			}
			// ловить любое исключение, отличное от std::exception
			catch (const std::exception&)
			{
				Clear();
				delete m_lastNode;
				m_lastNode = nullptr;
				throw;
			}
		}
	}
	CMyList& operator=(const CMyList& other)
	{
		if (std::addressof(other) != this)
		{
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
		delete m_lastNode;
	}
	// нужен move конструктор
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
		if (!IsEmpty()) // упростить код 
		{
			m_lastNode->prev->next = nullptr;
			while (m_firstNode != nullptr)
			{
				Node<T>* tempNode = m_firstNode->next;
				delete m_firstNode;
				m_firstNode = tempNode;
			}
			m_lastNode->prev = nullptr;
			m_size = 0;
		}
	}
	void Insert(CMyListIterator<T> iter, const T& data)
	{
		// упростить / через зацикливание
		Node<T>* newNode = new Node<T>(data);
		if (m_size != 0)
		{
			m_size++;
			if (iter.m_node->next == nullptr)
			{
				newNode->next = m_lastNode;
				m_lastNode->prev->next = newNode;
				newNode->prev = m_lastNode->prev;
				m_lastNode->prev = newNode;
				return;
			}
			if (iter.m_node->prev == nullptr)
			{
				newNode->next = m_firstNode;
				m_firstNode->prev = newNode;
				m_firstNode = newNode;
				return;
			}
			
			Node<T>* leftNode = iter.m_node->prev;
			Node<T>* rightNode = iter.m_node;
			newNode->prev = leftNode;
			newNode->next = rightNode;
			leftNode->next = newNode;
			rightNode->prev = newNode;
		}
		else
		{
			m_size++;
			m_firstNode = newNode;
			m_firstNode->next = m_lastNode;
			m_lastNode->prev = m_firstNode;
		}
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
	Node<T>*m_firstNode = nullptr, *m_lastNode = new Node<T>(std::nullopt);
};
