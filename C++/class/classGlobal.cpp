#include <iostream>
using namespace std;

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
    public:
        SoSimple()
        {
            simObjCnt++;
            cout << simObjCnt << "번째 SoSimple 객체 " << endl;
        }
};

class SoComplex
{
    public:
    SoComplex()
    {
        cmxObjCnt++;
        cout << cmxObjCnt << "번째 SoComplex 객체 " << endl;
    }
    SoComplex(SoComplex & copy)
    {
        cmxObjCnt++;
        cout << cmxObjCnt << "번째 SoComplex 객체 " << endl;
    }
};

int main()
{
    SoSimple sim1;
    SoSimple sim2;
    SoSimple();

    SoComplex com1;
    SoComplex com2;
    SoComplex com3 = com2;

    return 0;
}