#pragma once
#include <string>

//predefined implementations
template <typename T> class LinkListIterator;
template <typename T> class DoublyLinkList;

//LinkNode Class
template <typename T>
class LinkNode
{
	//define friend classes that can access the private data
	friend class LinkListIterator<T>;
	friend class DoublyLinkList<T>;

public:
	LinkNode(T data, int priority);
private:
	T m_data;
	int m_priority;
	LinkNode* m_pNext;
	LinkNode* m_pPrev;
};

//Template constructor
template<typename T>
LinkNode<T>::LinkNode(T data, int priority)
{
	m_data = data;
	m_priority = priority;
	m_pNext = nullptr;
	m_pPrev = nullptr;
}