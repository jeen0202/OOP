#include <iostream>
using namespace std;
class Stack
{
    //기본적으로 private
    //Pointer를 사용하여 동적할당
    int* buff;
    int idx;

    public:
    //생성자
    Stack(int size = 10) {
        buff = new int[size];
        idx=0;
    };
    ~Stack()
    {
        delete[] buff;
    }
    void push(int n)
    {
        buff[idx++]= n;
    }
    int pop() 
    {
        return buff[--idx];
    }
    int getIdx(){
        return (idx);
    }
};

int main()
{
    int size = 5;
    Stack s1(size);
    int i;
    while(cin >> i){
        if(s1.getIdx() >size){
        cout << "Stack FULL!" << endl;
            for(int j=0;j<=size;j++){
                cout << "POP! : "<< s1.pop() << endl;;
            }
        break;
        }
        s1.push(i);
        
    }
    return 0;
}
