#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//반복문과 동적할당을 통한 Array Data 입력
int main()
{
    int x,i;
    cout << "배열의 크기를 입력하세요 : ";
    cin >> x;
    int*p = new int[x];

    for(i =0; i <x; i ++)
    {
        cout << i+1 << "번째 숫자 입력 => " ;
        cin >> *(p+i);
    }
    for(i = 0; i <x; i ++)
    {
        cout << "*(p+" << i << ") : " <<*(p+i) << endl;
    }

    delete []p;
    p=NULL;
    return 0;
}
