#include <iostream>
#include "stack.cpp"
using namespace std;
int main()
{
	Stack s1(20);
	s1.push(30);
	cout << s1.pop() << endl;
}
