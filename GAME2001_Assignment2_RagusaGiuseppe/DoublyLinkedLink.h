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

	void Push(T newData, int priority, bool ascending);
	void Pop();
private:
	int m_size;
	LinkNode<T>* m_pFirst;
	LinkNode<T>* m_pLast;

	//Return a different condition depending on whether the list is ascending or descending
	bool FirstNodeCondition(bool ascending, LinkNode<T>* node);
	bool LastNodeCondition(bool ascending, LinkNode<T>* node);
	bool CompareNodeCondition(bool ascending, LinkNode<T>* currentNode, LinkNode<T>* newNode);
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
	if (AssertHelper::Assert(m_pFirst != nullptr, "List is Empty!"))
		return m_pFirst;
	return nullptr;
}

// Returns the node at the back of the queue
template<typename T>
LinkNode<T>* DoublyLinkList<T>::Last()
{
	if (AssertHelper::Assert(m_pLast != nullptr, "List is Empty!"))
		return m_pLast;
	return nullptr;
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

// Pushes a new node with the specified data into the queue. Sets the nodes position based on priority and mode
template<typename T>
void DoublyLinkList<T>::Push(T newData, int priority, bool ascending)
{
	LinkNode<T>* node = new LinkNode<T>(newData, priority);

	if (AssertHelper::Assert(node != nullptr, "Data failed to add")) {

		//CASE 1: Is the List Empty?
		if (m_pFirst == nullptr) {
			m_pFirst = node;
			m_pLast = m_pFirst;
		}
		//CASE 2: Does the new node need to replace the current root node?
		else if (FirstNodeCondition(ascending, node)) {
			node->m_pNext = m_pFirst;
			m_pFirst->m_pPrev = node;
			m_pFirst = node;
		}
		////CASE 3: Does the new node need to replace the current tail node?
		//else if (LastNodeCondition(ascending, node)) {
		//	m_pLast->m_pNext = node;
		//	node->m_pPrev = m_pLast;
		//	m_pLast = node;
		//}
		//CASE 4: Node belongs in the middle of the list, find out where
		else {
			LinkListIterator<T> IteratorNode = LinkListIterator<T>();
			IteratorNode = First();

			//Will hold the current node being pointed to, used to avoid accessing the Iterator every time
			LinkNode<T>* currentNode = First();

			while (currentNode->m_pNext != nullptr) {

				if (CompareNodeCondition(ascending, currentNode, node)) {
					// Connect the prev node and next node to the newly created node, then break the loop
					node->m_pPrev = currentNode;
					node->m_pNext = currentNode->m_pNext;
					currentNode->m_pNext->m_pPrev = node;
					currentNode->m_pNext = node;
					break;
				}
				else {
					IteratorNode++; //Go to the next node in the list
					currentNode = IteratorNode.CurrentNode();
				}
			}

			//If The loop was broken early, this condition would not activate because the new spot was already found
			if (currentNode->m_pNext == nullptr)
			{
				currentNode->m_pNext = node;
				node->m_pPrev = currentNode;
				m_pLast = node;
			}

			//Clean up
			IteratorNode = nullptr;
			currentNode = nullptr;
			node = nullptr;
		}

		//Increase the Size
		m_size++;

		//Display Success Message
		cout << "New Node '" << newData << "' with Priority " << priority << " successfully added" << endl;
	}

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
			m_pFirst = nullptr;
			m_pLast = nullptr;
		}
		//CASE 2: set the first node m_next pointer as the new node
		else
		{
			LinkNode<T>* newFirstNode = m_pFirst->m_pNext;

			delete m_pFirst;
			m_pFirst = newFirstNode;
			m_pFirst->m_pPrev = End();

			//cleanup
			newFirstNode = nullptr;
		}
		m_size--;

		cout << "Front node has been removed successfully" << endl;
	}
}

// Checks the first node if it needs to be replaced. Returns a different condition depending on ascending or descending mode
template<typename T>
bool DoublyLinkList<T>::FirstNodeCondition(bool ascending, LinkNode<T>* node)
{
	return ascending ? (m_pFirst->m_priority > node->m_priority) : (m_pFirst->m_priority < node->m_priority);
}

// Checks the last node if it needs to be replaced. Returns a different condition depending on ascending or descending mode
template<typename T>
bool DoublyLinkList<T>::LastNodeCondition(bool ascending, LinkNode<T>* node)
{
	return ascending ? (m_pLast->m_priority < node->m_priority) : (m_pLast->m_priority > node->m_priority);
}

// Checks for the spot where the new node will go. Returns a different condition depending on ascending or descending mode
template<typename T>
bool DoublyLinkList<T>::CompareNodeCondition(bool ascending, LinkNode<T>* currentNode, LinkNode<T>* newNode)
{
	return ascending ? (currentNode->m_pNext->m_priority > newNode->m_priority) : (currentNode->m_pNext->m_priority < newNode->m_priority);
}
