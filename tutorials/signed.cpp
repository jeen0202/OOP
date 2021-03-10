#include <iostream>
#include <vector>
/*
 * 아래와 같이 코딩할 경우 변수 i는 signed integer 
 * v는 unsigned integer이기 때문에 warning이 발생한다.
 * 이를 예방하는 두가지 방법은 size_type과 iterator 사용이 있다.
*/
int main()
{
    using namespace std;

    const int max =10;
    vector<int> v(max,77);
//  for(vector<int>::size_type i = 0 ; i< v.size(); ++i)
//  for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    for(int i = 0; i<v.size();++i)
        cout <<v[i]<<endl;
}
