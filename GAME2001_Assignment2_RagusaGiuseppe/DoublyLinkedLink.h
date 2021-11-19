#pragma once
#include "LinkNode.h"
#include "LinkListIterator.h"

//Link List Class
template <typename T>
class DoublyLinkList
{
public:
	DoublyLinkList();
	~DoublyLinkList();

	LinkNode<T>* Root();
	LinkNode<T>* Tail();
	LinkNode<T>* End();

	void Push(T newData);
	void Pop();
private:
	int m_size;
	LinkNode<T>* m_pRoot;
	LinkNode<T>* m_pTail;
};

template<typename T>
DoublyLinkList<T>::DoublyLinkList()
{
	m_size = 0;
	m_pRoot = nullptr;
	m_pTail = nullptr;
}

template<typename T>
DoublyLinkList<T>::~DoublyLinkList()
{
	while (m_pRoot)
	{
		Pop();
	}
}

template<typename T>
LinkNode<T>* DoublyLinkList<T>::Root()
{
	//Assert: Root is not Null
	return m_pRoot;
}

template<typename T>
LinkNode<T>* DoublyLinkList<T>::Tail()
{
	//Assert: Tail is not NULL
	return m_pTail;
}

template<typename T>
LinkNode<T>* DoublyLinkList<T>::End()
{
	return nullptr;
}

template<typename T>
void DoublyLinkList<T>::Push(T newData)
{
	LinkNode<T>* node = new LinkNode<T>(newData);

	//Assert: Node is not Null

	if (m_pRoot == nullptr) {
		m_pRoot = node;
		m_pTail = m_pRoot;
	}
	else {
		LinkNode<T>* prev = m_pTail;
		m_pTail->m_pNext = node;
		m_pTail = node;
		m_pTail->m_pPrev = prev;

		prev = nullptr;
	}

	m_size++;

}

template<typename T>
void DoublyLinkList<T>::Pop()
{
	//Assert: root is not NULL

	if (m_pRoot->m_pNext == nullptr)
	{
		delete m_pRoot;
		m_pRoot = nullptr;
		m_pTail = nullptr;
	}
	else
	{
		LinkNode<T>* newLastNode = m_pTail->m_pPrev;
		//Assert: newLastNode is not NULL

		delete m_pTail;
		m_pTail = newLastNode;
		m_pTail->m_pNext = End();

		newLastNode = nullptr;
	}

	m_size = (m_size == 0 ? m_size : m_size - 1);
}
