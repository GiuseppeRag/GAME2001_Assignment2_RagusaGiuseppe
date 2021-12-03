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

	//Return a different condition depending on whether the list is ascending or descending
	bool FirstNodeCondition(int frontNodePriority, int newNodePriority);
	bool CompareNodeCondition(int currentNodePriority, int newNodePriority);
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
	LinkNode<T>* node = new LinkNode<T>(data, priority);

	//Set the iterator to the front
	m_pIterator = Front();

	if (AssertHelper::Assert(node != nullptr, "Data failed to add")) {

		//Check if the first node needs to be replace or if empty
		if (IsEmpty() || FirstNodeCondition(m_pIterator.CurrentNodePriority(), priority)) {
			m_pList->PushFront(node);

			//cleanup
			node = nullptr;
		}
		//Otherwise Iterate through the list
		else
		{
			//iterate through the list
			while (m_pIterator.CurrentNode() != nullptr)
			{
				//if the priority condition is met (changes depending on mode), we insert the new node
				if (CompareNodeCondition(m_pIterator.CurrentNodePriority(), priority)) {

					//The node in question has a lower priority than the new node. we want to add the new Node BEFORE this node,
					// so the iterator is moved back by 1 space
					m_pIterator--;
					m_pList->PushAfter(node, m_pIterator.CurrentNode());

					//cleanup
					node = nullptr;
					return;
				}
				else { //Skip to the next node
					m_pIterator++;
				}
			}
			//If no appropriate Spot found, place after the fast node
			m_pList->PushAfter(node, Back());

			//cleanup
			node = nullptr;
		}
	}
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
		cout << "Data: " << *m_pIterator << "   Priority: " << m_pIterator.CurrentNodePriority() << endl;

	cout << "========== LIST BACK ==========" << endl;

	m_pIterator = m_pList->First();
}

// Prints the Values and Priority of the nodes in the list from back to front
template<typename T>
void PriorityQueue<T>::PrintListReverse()
{
	cout << "========== LIST BACK ==========" << endl;

	for (m_pIterator = m_pList->Last(); m_pIterator != m_pList->End(); m_pIterator--)
		cout << "Data: " << *m_pIterator << "   Priority: " << m_pIterator.CurrentNodePriority() << endl;

	cout << "========== LIST FRONT ==========" << endl;

	m_pIterator = m_pList->First();
}


// Checks the first node if it needs to be replaced. Returns a different condition depending on ascending or descending mode
template<typename T>
bool PriorityQueue<T>::FirstNodeCondition(int frontNodePriority, int newNodePriority)
{
	return m_ascendingMode ? (frontNodePriority > newNodePriority) : (frontNodePriority < newNodePriority);
}

// Checks for the spot where the new node will go. Returns a different condition depending on ascending or descending mode
template<typename T>
bool PriorityQueue<T>::CompareNodeCondition(int currentNodePriority, int newNodePriority)
{
	return m_ascendingMode ? (currentNodePriority > newNodePriority) : (currentNodePriority < newNodePriority);
}
