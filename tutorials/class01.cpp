#include <iostream>
class Stack
{
    int buff[10];
    int idx;
    public:
    void init() {idx =0;}
    void push(int n)
    {
        buff[idx++]= n;
    }
    int pop() 
    {
        return buff[--idx];
    }
};

int main()
{
    Stack s1;
    s1.init();
    s1.push(10);
    s1.push(20);
    s1.push(30);

    std::cout <<s1.pop() << std::endl;
}
 
