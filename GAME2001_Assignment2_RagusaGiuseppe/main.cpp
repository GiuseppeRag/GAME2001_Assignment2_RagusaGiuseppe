#include <iostream>
#include <string>
#include "PriorityQueue.h"

using namespace std;

int main()
{
	PriorityQueue<string> queue = PriorityQueue<string>(false);

	queue.Push("Apples", 3);
	queue.Push("Bananas", 5);
	queue.Push("Cake", 7);
	queue.Push("Donut", 6);

	queue.Pop();

	queue.PrintListReverse();

	return 0;
}