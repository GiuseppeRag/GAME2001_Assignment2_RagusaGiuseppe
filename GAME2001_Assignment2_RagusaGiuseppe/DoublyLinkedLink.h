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

	LinkNode<T>* Last();
	LinkNode<T>* First();
	LinkNode<T>* End();

	void Push(T newData, int priority, bool ascending);
	void Pop();
private:
	int m_size;
	//The "root" of the list is actually the last element in the list, since it was the first item inserted 
	LinkNode<T>* m_pLast;

	//The "tail" of the list is the first element, since it was the last item inserted
	LinkNode<T>* m_pFirst;
};

template<typename T>
DoublyLinkList<T>::DoublyLinkList()
{
	m_size = 0;
	m_pLast = nullptr;
	m_pFirst = nullptr;
}

template<typename T>
DoublyLinkList<T>::~DoublyLinkList()
{
	while (m_pLast)
	{
		Pop();
	}
}

template<typename T>
LinkNode<T>* DoublyLinkList<T>::Last()
{
	//Assert: Last is not Null
	return m_pLast;
}

template<typename T>
LinkNode<T>* DoublyLinkList<T>::First()
{
	//Assert: First is not NULL
	return m_pFirst;
}

template<typename T>
LinkNode<T>* DoublyLinkList<T>::End()
{
	return nullptr;
}

template<typename T>
void DoublyLinkList<T>::Push(T newData, int priority, bool ascending)
{
	LinkNode<T>* node = new LinkNode<T>(newData, priority);

	//Assert: Node is not Null

	//Is the list empty?
	if (m_pLast == nullptr) {
		m_pLast = node;
		m_pFirst = m_pLast;
	}
	else if ((m_pLast->m_priority < node->m_priority && ascending) || (m_pLast->m_priority > node->m_priority && !ascending)) {
		m_pLast->m_pPrev = node;
		node->m_pNext = m_pLast;
		m_pLast = node;
	}
	else if ((m_pFirst->m_priority > node->m_priority && ascending) || (m_pFirst->m_priority < node->m_priority && !ascending))
	{
		m_pFirst->m_pNext = node;
		node->m_pPrev = m_pFirst;
		m_pFirst = node;
	}
	//loop through the linked list and see if it belongs in the middle of the list
	else {
		LinkNode<T>* IteratorNode = m_pLast;

		while (IteratorNode->m_pNext != nullptr) {
			//perform this check if ascending
			if (ascending) {
				if (IteratorNode->m_pNext->m_priority < node->m_priority) {
					node->m_pPrev = IteratorNode;
					node->m_pNext = IteratorNode->m_pNext;
					IteratorNode->m_pNext->m_pPrev = node;
					IteratorNode->m_pNext = node;
					break;
				}
				else
					IteratorNode = IteratorNode->m_pNext;
			}
			//perform this check if descending
			else
			{
				if (IteratorNode->m_pNext->m_priority > node->m_priority)
				{
					node->m_pPrev = IteratorNode;
					node->m_pNext = IteratorNode->m_pNext;
					IteratorNode->m_pNext->m_pPrev = node;
					IteratorNode->m_pNext = node;
					break;
				}
				else
					IteratorNode = IteratorNode->m_pNext;
			}
		}

		//If The loop was broken early, this condition would not activate because the new spot was already found
		if (IteratorNode->m_pNext == nullptr)
		{
			IteratorNode->m_pNext = node;
			node->m_pPrev = IteratorNode;
			m_pFirst = node;
		}

		IteratorNode = nullptr;
		node = nullptr;
	}

	m_size++;

}

template<typename T>
void DoublyLinkList<T>::Pop()
{
	//Assert: Last is not NULL

	if (m_pLast->m_pNext == nullptr)
	{
		delete m_pLast;
		m_pLast = nullptr;
		m_pFirst = nullptr;
	}
	else
	{
		LinkNode<T>* newLastNode = m_pLast->m_pNext;
		//Assert: newLastNode is not NULL

		delete m_pLast;
		m_pLast = newLastNode;
		m_pLast->m_pPrev = End();

		newLastNode = nullptr;
	}

	m_size = (m_size == 0 ? m_size : m_size - 1);
}
