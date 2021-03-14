#include <iostream>
using namespace std;

class addition
{
	private :
		int result;
	public:
		void add(int value);
		void add(int startValue, int endValue);
		int getResult(){return result;}
};
//Class의 Member함수를 parameter에 따라 다른게 동작하게 만들 수 있다.
void addition::add(int value)
{
	result =0;

	for(int i=1;i<=value;++i)
	{
		result+=i;
	}
}

void addition::add(int startValue, int endValue)
{
	result =0;
	
	for(int i=startValue; i<=endValue; ++i)
	{
		result+=i;
	}
}

int main()
{
	addition add1;
	add1.add(10);
	cout << "1부터 10까지의 합 : " << add1.getResult() << endl;

	addition add2;
	add2.add(10,20);
	cout << "10부터 20까지의 합 : " << add2.getResult() << endl;

	return 0;
}
