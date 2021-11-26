#pragma once
#include <iostream>
#include "DoublyLinkedLink.h"
#include "LinkListIterator.h"

using namespace std;

//Priority Queue Wrapper Class
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

	int Size();
	bool IsEmpty();

	void PrintList();
	void PrintListReverse();

private:
	DoublyLinkList<T>* m_pList;
	LinkListIterator<T> m_pIterator;
	bool m_ascendingMode;
};

// Constructor
template<typename T>
PriorityQueue<T>::PriorityQueue(bool mode) : m_ascendingMode(mode)
{
	m_pList = new DoublyLinkList<T>();
	m_pIterator = LinkListIterator<T>();
}

// Destructor
template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
	// The list automatically deletes the nodes within it
	delete m_pList;
}

// Returns the node at the front of the queue
template<typename T>
LinkNode<T>* PriorityQueue<T>::Front()
{
	return m_pList->First();
}

// Returns the node at the back of the queue
template<typename T>
LinkNode<T>* PriorityQueue<T>::Back()
{
	return m_pList->Last();
}

// Pushes a new node into the list. List handles the actual logic
template<typename T>
void PriorityQueue<T>::Push(T data, int priority)
{
	m_pList->Push(data, priority, m_ascendingMode);
}

// Pops the front node out of the queue. List handles the actual logic
template<typename T>
void PriorityQueue<T>::Pop()
{
	m_pList->Pop();
}

// Returns the current mode the list is being sorted in (Ascending or Descending)
template<typename T>
bool PriorityQueue<T>::GetMode()
{
	return m_ascendingMode;
}

// Returns the size of the list
template<typename T>
int PriorityQueue<T>::Size()
{
	return m_pList->Size();
}

// Returns a boolean depending on whether the list is empty or not
template<typename T>
bool PriorityQueue<T>::IsEmpty()
{
	return m_pList->Size() == 0;
}

// Prints the Values and Priority of the nodes in the list from front to back
template<typename T>
void PriorityQueue<T>::PrintList()
{
	cout << "========== LIST FRONT ==========" << endl;

	for (m_pIterator = m_pList->First(); m_pIterator != m_pList->End(); m_pIterator++)
		cout << "Data: " << m_pIterator.CurrentNodeData() << "   Priority: " << m_pIterator.CurrentNodePriority() << endl;

	cout << "========== LIST BACK ==========" << endl;

	m_pIterator = m_pList->First();
}

// Prints the Values and Priority of the nodes in the list from back to front
template<typename T>
void PriorityQueue<T>::PrintListReverse()
{
	cout << "========== LIST BACK ==========" << endl;

	for (m_pIterator = m_pList->Last(); m_pIterator != m_pList->End(); m_pIterator--)
		cout << "Data: " << m_pIterator.CurrentNodeData() << "   Priority: " << m_pIterator.CurrentNodePriority() << endl;

	cout << "========== LIST FRONT ==========" << endl;

	m_pIterator = m_pList->First();
}
