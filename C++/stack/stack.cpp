#include "stack.h"

Stack::Stack(int size=10)
{
	buf = new int[size];
	idx=0;
}
Stack::~Stack()
{
	delete[] buf;
}
void Stack::push(int n)
{
	buf[idx++] = n;
}
int Stack::pop()
{
	return buf[--idx];
}
