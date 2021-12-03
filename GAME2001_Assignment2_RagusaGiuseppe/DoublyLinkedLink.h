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

	LinkNode<T>* First();
	LinkNode<T>* Last();
	LinkNode<T>* End();
	int Size();

	void PushFront(LinkNode<T>* newNode);
	void PushAfter(LinkNode<T>* newNode, LinkNode<T>* nodeToFollow);
	void Pop();
private:
	int m_size;
	LinkNode<T>* m_pFirst;
	LinkNode<T>* m_pLast;
};

// Constructor
template<typename T>
DoublyLinkList<T>::DoublyLinkList() : m_size(0), m_pFirst(nullptr), m_pLast(nullptr) {}

// Destructor
template<typename T>
DoublyLinkList<T>::~DoublyLinkList()
{
	//Pops everything in the list as long as m_pLast has a value (stops when m_pLast is null aka the last element is gone)
	while (m_pLast)
		Pop();
}

// Returns the node at the front of the queue
template<typename T>
LinkNode<T>* DoublyLinkList<T>::First()
{
	return m_pFirst;
}

// Returns the node at the back of the queue
template<typename T>
LinkNode<T>* DoublyLinkList<T>::Last()
{
	return m_pLast;
}

// Returns nullptr (The m_prev pointer of the first node is NULL, and the m_next pointer of the last node is NULL)
template<typename T>
LinkNode<T>* DoublyLinkList<T>::End()
{
	return nullptr;
}

// Returns the size of the list
template<typename T>
int DoublyLinkList<T>::Size()
{
	return m_size;
}

template<typename T>
void DoublyLinkList<T>::PushFront(LinkNode<T>* newNode)
{
	newNode->m_pNext = m_pFirst;

	//If List is empty, dont adjust the m_pNext pointers. Instead, the first and last node will point to this new node
	if (m_pFirst != nullptr)
		m_pFirst->m_pPrev = newNode;
	else
		m_pLast = newNode;

	m_pFirst = newNode;
	m_size++;

	//Display Success Message
	cout << "New Node '" << newNode->m_data << "' with Priority " << newNode->m_priority << " successfully added" << endl;
}

template<typename T>
void DoublyLinkList<T>::PushAfter(LinkNode<T>* newNode, LinkNode<T>* nodeToFollow)
{
	//connect the new node to the list
	newNode->m_pPrev = nodeToFollow;
	newNode->m_pNext = nodeToFollow->m_pNext;

	//if the next node is null, its the end of the list, so replace the m_pLast pointer. Otherwise link the m_prev pointer to new node
	if (newNode->m_pNext != nullptr)
		newNode->m_pNext->m_pPrev = newNode;
	else
		m_pLast = newNode;

	//finish connection
	nodeToFollow->m_pNext = newNode;
	m_size++;

	//Display Success Message
	cout << "New Node '" << newNode->m_data << "' with Priority " << newNode->m_priority << " successfully added" << endl;
}


// Removes the node at the front of the queue
template<typename T>
void DoublyLinkList<T>::Pop()
{
	if (AssertHelper::Assert(m_pFirst != nullptr, "Nothing to Pop, the list is empty!")) {

		//CASE 1: Is there only 1 node left in the list?
		if (m_pFirst->m_pNext == nullptr)
		{
			//delete the node
			delete m_pFirst;
			m_pFirst = m_pLast = nullptr;
		}
		//CASE 2: set the first node m_next pointer as the new node
		else
		{
			//List is doubly linked, so m_pFirst pointer can be moved and still access the original first node
			m_pFirst = m_pFirst->m_pNext;
			delete m_pFirst->m_pPrev;
			m_pFirst->m_pPrev = End();
		}
		m_size--;

		cout << "Front node has been removed successfully" << endl;
	}
}
