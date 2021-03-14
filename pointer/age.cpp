#include <iostream>
using namespace std;

int main()
{
    // Pointer를 사용하여 int의 크기만큼 동적할당
    int *age = new int;

    *age = 100;

    cout << "*age : " << *age << endl;

    delete age;  //동적할당 해제
    age = NULL; // 변수가 가르키는 주소 data를 NuLL로 지정
    int *rectangle = new int[3]; // int형 배열 데이터를 동적할당

    *rectangle=10;
    *(rectangle+1)=20;
    *(rectangle+2)=30;

    cout << "*rectangle : " << *rectangle << endl;
    cout << "*(rectangle+1) : " << *(rectangle+1) << endl;
    cout << "*(rectangle+2) : " << *(rectangle+2) << endl;
    
    delete[] rectangle;

    return 0;
}