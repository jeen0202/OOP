#include <iostream>
#include "stackT.h"
using namespace std;

int main()
{
	Stack<int> s1(20);
	s1.push(30);

	Stack<string> s2(20);
	s2.push("hello");
	cout << "int Stack : " << s1.pop() << endl;
	cout << "String Stack : " << s2.pop() << endl;
}
