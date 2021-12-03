#include <iostream>
#include <string>
#include "PriorityQueue.h"

using namespace std;

int main()
{
	//Queue 1: Ascending String Priority Queue
	cout << "====================================" << endl
		 << "||            EXAMPLE 1           ||" << endl
		 << "====================================" << endl;
	PriorityQueue<string> queueAsc = PriorityQueue<string>(true);
	LinkListIterator<string> itrAsc;

	//Push Initial Values
	queueAsc.Push("Buy Milk", 4);
	queueAsc.Push("Rake The Leaves", 2);
	queueAsc.Push("Walk the Dog", 9);

	//Veiw List
	cout << endl << "Ascending Queue in Order:" << endl;
	queueAsc.PrintList();
	cout << endl;

	//Push More Values
	queueAsc.Push("Wash Dishes", 1);
	queueAsc.Push("Video Games", 11);
	queueAsc.Push("Make Dinner", 3);

	//Pop the first 2
	queueAsc.Pop();
	queueAsc.Pop();

	itrAsc = queueAsc.Front();
	cout << endl << "The Highest Task is " << *itrAsc << " with Priority " << itrAsc.CurrentNodePriority() << endl;

	//View List (IN REVERSE)
	cout << endl << "Ascending Queue in Reverse Order" << endl;
	queueAsc.PrintListReverse();

	//Queue 2: Descending Char Queue
	cout << endl;
	cout << "====================================" << endl
		 << "||            EXAMPLE 2           ||" << endl
		 << "====================================" << endl << endl;
	PriorityQueue<char> queueDes = PriorityQueue<char>(false);
	LinkListIterator<char> itrDes;

	queueDes.Pop();
	queueDes.Push('A', 10);
	queueDes.Pop();
	queueDes.Push('Z', 15);
	queueDes.Push('E', 7);
	queueDes.Push('R', 1);
	queueDes.Push('O', 7);

	itrDes = queueDes.Back();
	cout << endl << "The Lowest Task is " << *itrDes << " with Priority " << itrDes.CurrentNodePriority() << endl;

	//View List
	cout << endl << "Descending Queue in Order" << endl;
	queueDes.PrintList();

	cout << endl << "CLEAN UP QUEUE DATA:" << endl;
	return 0;
}