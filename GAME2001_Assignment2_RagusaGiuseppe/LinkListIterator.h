#pragma once
#include "LinkNode.h"
#include "AssertHelper.h"

//Link List Iterator class
template <typename T>
class LinkListIterator
{
public:
	LinkListIterator() {}

	// Getter methods to prevent accidental overwrites 
	LinkNode<T>* CurrentNode();
	T CurrentNodeData();
	int CurrentNodePriority();

	//overloaded operators
	void operator=(LinkNode<T>* node);
	T& operator*();
	void operator++();
	void operator++(int);
	void operator--();
	void operator--(int);
	bool operator!=(LinkNode<T>* node);
	bool operator==(LinkNode<T>* node);
private:
	LinkNode<T>* m_currentNode;
};

// Returns an instance of the node the iterator is pointing to
template<typename T>
LinkNode<T>* LinkListIterator<T>::CurrentNode()
{
	return m_currentNode;
}

// Returns the data being held in the node the iterator is pointing to
template<typename T>
T LinkListIterator<T>::CurrentNodeData()
{
	return m_currentNode->m_data;
}

//  Returns the priority of the node the iterator is point ot
template<typename T>
int LinkListIterator<T>::CurrentNodePriority()
{
	return m_currentNode->m_priority;
}

// Assignment Operator (Is not used in most circumstances due to lack of random access)
template<typename T>
void LinkListIterator<T>::operator=(LinkNode<T>* node)
{
	m_currentNode = node;
}

// Deference Operator (An alternative to CurrentNodeData())
template<typename T>
T& LinkListIterator<T>::operator*()
{
	if (AssertHelper::Assert(m_currentNode != nullptr, "Selected Node is NULL"))
		return m_currentNode->m_data;
	return nullptr;
}

// Pre-Increment: Skips to the next node in the list
template<typename T>
void LinkListIterator<T>::operator++()
{
	if (AssertHelper::Assert(m_currentNode != nullptr, "Selected Node is NULL"))
		m_currentNode = m_currentNode->m_pNext;
}

// Post-Increment: Same as Pre-Increment
template<typename T>
void LinkListIterator<T>::operator++(int)
{
	if (AssertHelper::Assert(m_currentNode != nullptr, "Selected Node is NULL"))
		m_currentNode = m_currentNode->m_pNext;
}

// Pre-Decrement: returns the previous node in the list
template<typename T>
void LinkListIterator<T>::operator--()
{
	if (AssertHelper::Assert(m_currentNode != nullptr, "Selected Node is NULL"))
		m_currentNode = m_currentNode->m_pPrev;
}

// Post-Decrement: Same as Pre-Decrement
template<typename T>
void LinkListIterator<T>::operator--(int)
{
	if (AssertHelper::Assert(m_currentNode != nullptr, "Selected Node is NULL"))
		m_currentNode = m_currentNode->m_pPrev;
}

// Non-equality Operator: compares the address of the nodes to make sure they aren't the same
template<typename T>
bool LinkListIterator<T>::operator!=(LinkNode<T>* node)
{
	return m_currentNode != node;
}

// Equality Operator: compares the address of the nodes to make sure they are the same
template<typename T>
bool LinkListIterator<T>::operator==(LinkNode<T>* node)
{
	return m_currentNode == node;
}
