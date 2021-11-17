#pragma once
#include "LinkNode.h"

//Link List Iterator class
template <typename T>
class LinkListIterator
{
public:
	LinkListIterator() {}

	//overloaded operators
	void operator=(LinkNode<T>* node);
	T& operator*();
	void operator++();
	void operator++(int);
	bool operator!=(LinkNode<T>* node);
	bool operator==(LinkNode<T>* node);
private:
	LinkNode<T>* m_currentNode;
};

template<typename T>
void LinkListIterator<T>::operator=(LinkNode<T>* node)
{
	//ASSERT: Node is not Null
	m_currentNode = node;
}

template<typename T>
T& LinkListIterator<T>::operator*()
{
	//ASSERT: node is not NULL
	return m_currentNode->m_data;
}

template<typename T>
void LinkListIterator<T>::operator++()
{
	//Assert: node is not NULL
	m_currentNode = m_currentNode->m_pNext;
}

template<typename T>
void LinkListIterator<T>::operator++(int)
{
	//Assert: node is not NULL
	m_currentNode = m_currentNode->m_pNext;
}

template<typename T>
bool LinkListIterator<T>::operator!=(LinkNode<T>* node)
{
	return m_currentNode != node;
}

template<typename T>
bool LinkListIterator<T>::operator==(LinkNode<T>* node)
{
	return m_currentNode == node;
}
