#include <iostream>
#include <string>

using namespace std;

//Exists so the function does not have to be redeclared in each class
static class AssertHelper
{

public:
	static bool Assert(bool condition, string message)
	{
		//Returns false if the condition passed is not valid and displays and error message. Otherwise, return true 
		if (!condition) {
			cout << "ERROR: " << message << endl;
			return false;
		}
		return true;
	}
};