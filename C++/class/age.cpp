#include <iostream>
using namespace std;
//파라미터에 따라 다르게 동작하는 생성자를 class 외부에서 선언할 수도 있다.
class Age
{
	private:
		int age;
	public:
		Age();
		Age(int valueofAge);
		int getAge(){return age;}
};

//매개변수가 없는 생성자
Age::Age()
{
	age = 10;
}
//매겨변수가 존재하는 생성자.
Age::Age(int valueofAge)
{
	age=valueofAge;
}

int main()
{
	Age boy;
	cout << "boy의 나이 : " << boy.getAge() << endl;

	Age girl(30);
	cout << "girl의 나이 : " << girl.getAge() << endl;

	return 0;
}
