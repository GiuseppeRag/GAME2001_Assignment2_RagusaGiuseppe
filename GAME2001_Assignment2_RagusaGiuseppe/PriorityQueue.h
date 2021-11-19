#pragma once
#include <iostream>
#include "DoublyLinkedLink.h"
#include "LinkListIterator.h"

template <typename T>
class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();

	LinkNode<T>* Front();
	LinkNode<T>* Back();
	void Push(T data);
	void Pop();
	void SwapMode();
	bool GetMode();
	LinkNode<T>* Search(T dataToFind);
	int Size();
	bool IsEmpty();
	void PrintList();

private:
	DoublyLinkList<T>* m_pList;
	LinkListIterator<T> m_pIterator;
	bool m_reverseMode;
};

template<typename T>
PriorityQueue<T>::PriorityQueue()
{
	m_pList = new DoublyLinkList<T>();
	m_pIterator = LinkListIterator<T>();

	//Indicates the mode of Searching and Inserting. When false, start traversing from the Root of the list. When true, start from the Tail
	m_reverseMode = false;
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
void PriorityQueue<T>::Push(T data)
{
	if (m_reverseMode)
		//PushBack
	else
		m_pList->Push(data);
}

template<typename T>
inline void PriorityQueue<T>::Pop()
{
	if (m_reverseMode)
		//PopBack
	else
		m_pList->Pop();
}

template<typename T>
inline void PriorityQueue<T>::SwapMode()
{
	m_reverseMode = !m_reverseMode;
	cout << "Reverse Mode has been set to " << (m_reverseMode ? "TRUE" : "FALSE") << endl;
}

template<typename T>
bool PriorityQueue<T>::GetMode()
{
	return m_reverseMode;
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
inline bool PriorityQueue<T>::IsEmpty()
{
	return m_pList->m_size == 0;
}

template<typename T>
inline void PriorityQueue<T>::PrintList()
{

}
