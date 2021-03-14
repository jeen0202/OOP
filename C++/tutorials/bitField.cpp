#include<iostream>
using namespace std;
//구조체를 사용함으로써 각각의 변수를 사용하였을때보다 크기를 줄일 수 있다.
struct bitfienld {
    unsigned int b1 : 1;
    unsigned int b2 : 1;
    unsigned int nibble : 4;
    unsigned int byte : 8;
}bf;

int main()
{
    cout << sizeof(bf) << endl;
    return 0;
}
