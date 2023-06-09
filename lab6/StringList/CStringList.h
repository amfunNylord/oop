#pragma once
#include "CStringListNode.h"
#include "CStringListIterator.h"
#include "CStringListConstIterator.h"
#include "CStringListReverseIterator.h"
#include "CStringListReverseConstIterator.h"

//  итераторы консатантные + tests

class CStringList
{
public:
	size_t GetSize() const;
	bool IsEmpty() const;
	void InsertFront(const std::string& data);
	void InsertBack(const std::string& data);
	void Clear();
	void Insert(CStringListIterator iter, const std::string& data);
	void Erase(CStringListIterator iter);

	// default constructor
	CStringList() = default;
	// copy constructor
	CStringList(const CStringList& other);
	// move constructor
	CStringList(CStringList&& other) noexcept;
	// destructor
	~CStringList();

	// copy assignment 
	CStringList& operator=(const CStringList& other);
	// move assignment
	CStringList& operator=(CStringList&& other) noexcept;

	CStringListIterator begin() const;
	CStringListIterator end() const;

	CStringListConstIterator cbegin() const;
	CStringListConstIterator cend() const;

	CStringListReverseIterator rbegin() const;
	CStringListReverseIterator rend() const;

	CStringListReverseConstIterator crbegin() const;
	CStringListReverseConstIterator crend() const;

private:
	size_t m_size = 0;
	Node *m_firstNode = nullptr, *m_lastNode = new Node("", nullptr, nullptr);
};