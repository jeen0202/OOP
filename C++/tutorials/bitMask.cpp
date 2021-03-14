#include <iostream>
using namespace std;

//bit 형식의 데이터 Masking을 위한 Mask 선언
#define MASK (0xf5)

void printBinary(unsigned int n)
{
    int i = 7;
    while(i >=0) {
            cout << (n >> i & 1);
            i--;
            }
            cout << endl;
            }
int main()
{
    unsigned int a = 15;
    cout <<"MASK       : ";
    printBinary(MASK);

    cout << "a          : ";
    printBinary(a);
    //&연산을 통해 Masking
    a &=MASK;
    cout << "a & MASK   : ";
    printBinary(a);

    return 0;
    }
