#include <iostream>
using namespace std;



class SoSimple
{
    private:
    static int simObjCnt; //같은 종류의 Class 끼리 공유하는 전역변수 취급
    public:
        SoSimple()
        {
            simObjCnt++;
            cout << simObjCnt << "번째 SoSimple 객체 " << endl;
        }
};

int SoSimple::simObjCnt = 0; // Class static 변수는 외부에서 초기화
class SoComplex
{
    private:
    static int cmxObjCnt;
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
int SoComplex::cmxObjCnt = 0;
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