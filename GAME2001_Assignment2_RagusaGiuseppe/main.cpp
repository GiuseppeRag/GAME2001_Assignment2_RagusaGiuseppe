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

	//Push Initial Values
	queueAsc.Push("Buy Milk", 2);
	queueAsc.Push("Rake The Leaves", 3);
	queueAsc.Push("Walk the Dog", 1);

	//Veiw List
	cout << endl << "Ascending Queue in Order:" << endl;
	queueAsc.PrintList();
	cout << endl;

	//Push More Values
	queueAsc.Push("Wash Dishes", 2);
	queueAsc.Push("Make Dinner", 5);
	queueAsc.Push("Video Games", 7);

	//Pop the first 2
	queueAsc.Pop();
	queueAsc.Pop();

	cout << endl << "The Highest Task is " << queueAsc.Front()->GetData() << " with Priority " << queueAsc.Front()->GetPriority() << endl;

	//View List (IN REVERSE)
	cout << endl << "Ascending Queue in Reverse Order" << endl;
	queueAsc.PrintListReverse();

	//Queue 2: Descending Char Queue
	cout << endl;
	cout << "====================================" << endl
		 << "||            EXAMPLE 2           ||" << endl
		 << "====================================" << endl << endl;
	PriorityQueue<char> queueDes = PriorityQueue<char>(false);

	queueDes.Pop();
	queueDes.Push('A', 10);
	queueDes.Pop();
	queueDes.Push('Z', 10);
	queueDes.Push('E', 2);
	queueDes.Push('R', 8);
	queueDes.Push('O', 5);

	cout << endl << "The Lowest Task is " << queueDes.Back()->GetData() << " with Priority " << queueDes.Back()->GetPriority() << endl;

	//View List
	cout << endl << "Descending Queue in Order" << endl;
	queueDes.PrintList();

	cout << endl << "CLEAN UP QUEUE DATA:" << endl;
	return 0;
}