#include <iostream>
#include "Age.h"
using std::cout;
using std::endl;

int main()
{
    Age girl(30);
    cout << "gitl의 나이 : " << girl.getAge() << endl;

    Age boy = girl; // Age객체 girl 복사하여 boy 객체 생성
    cout << "boy의 나비 : " << boy.getAge() << endl;

    boy.setAge(15); // boy의 나이 변경
    //복사 생성자를 만들지 않으면 기존객체인 girl의 멤버변수도 변경되어 버린다. (얕은 복사)
   cout << "girl의 나이 : " << girl.getAge() << endl;
   cout << "boy의 나비 : " << boy.getAge() << endl;
   //girl의 멤버변수인 age는 변화하지 않는다. (복사생성자를 통한 깊은 복사)

   

   return 0;
}