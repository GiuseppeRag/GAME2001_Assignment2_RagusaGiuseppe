#include <iostream>
#include <string>
#include "DoublyLinkedLink.h"
#include "LinkListIterator.h"

using namespace std;

int main()
{
	DoublyLinkList<int>* list = new DoublyLinkList<int>();

	list->Push(6);
	list->Push(3);
	list->Push(1);
	list->Push(10);
	list->Pop();
	list->Push(11);
	list->Push(17);
	list->Pop();
	list->Pop();
	list->Push(4);

	LinkListIterator<int> iterator;

	for (iterator = list->Root(); iterator != list->End(); iterator++)
	{
		cout << *iterator << " ";
	}
	return 0;
}