#pragma once
template <typename T>
class CMyList
{
public:
	CMyList();
	~CMyList();

private:
public:
	bool operator==(const CMyList& other) const
	{
		return false;
	}
};

template <typename T>
inline CMyList<T>::CMyList()
{
}

template <typename T>
inline CMyList<T>::~CMyList()
{
}
