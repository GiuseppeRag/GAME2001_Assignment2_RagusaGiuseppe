#pragma once
#include <iostream>
#include "DoublyLinkedLink.h"
#include "LinkListIterator.h"

using namespace std;

template <typename T>
class PriorityQueue
{
public:
	PriorityQueue(bool mode);
	~PriorityQueue();

	LinkNode<T>* Front();
	LinkNode<T>* Back();
	void Push(T data, int priority);
	void Pop();
	bool GetMode();
	LinkNode<T>* Search(T dataToFind);
	int Size();
	bool IsEmpty();
	void PrintList();

private:
	DoublyLinkList<T>* m_pList;
	LinkListIterator<T> m_pIterator;
	bool m_ascendingMode;
};

template<typename T>
PriorityQueue<T>::PriorityQueue(bool mode)
{
	m_ascendingMode = mode;
	m_pList = new DoublyLinkList<T>();
	m_pIterator = LinkListIterator<T>();
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
	delete m_pList;
}

template<typename T>
LinkNode<T>* PriorityQueue<T>::Front()
{
	return m_pList->Root();
}

template<typename T>
LinkNode<T>* PriorityQueue<T>::Back()
{
	return m_pList->Tail();
}

template<typename T>
void PriorityQueue<T>::Push(T data, int priority)
{
	m_pList->Push(data, priority, m_ascendingMode);
}

template<typename T>
void PriorityQueue<T>::Pop()
{
	m_pList->Pop();
}

template<typename T>
bool PriorityQueue<T>::GetMode()
{
	return m_ascendingMode;
}

template<typename T>
LinkNode<T>* PriorityQueue<T>::Search(T dataToFind)
{
}

template<typename T>
int PriorityQueue<T>::Size()
{
	return m_pList->m_size;
}

template<typename T>
bool PriorityQueue<T>::IsEmpty()
{
	return m_pList->m_size == 0;
}

template<typename T>
void PriorityQueue<T>::PrintList()
{
	for (m_pIterator = m_pList->Last(); m_pIterator != nullptr; m_pIterator++)
	{
		cout << "Data: " << m_pIterator.CurrentNodeData() << "   Priority: " << m_pIterator.CurrentNodePriority() << endl;
	}
	m_pIterator = m_pList->Last();
}
