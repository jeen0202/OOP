#include <iostream>
using std::cout;

class Age
{
    private:
        int *age;

    public:
        Age(int vAge); // parameter를 보유한 생성자
        Age(const Age &obj); //복사 생성자
        int getAge() const{return *age;} // inline function
        void setAge(int vAge) {*age = vAge;}
};

Age::Age(int vAge)
{
    age = new int; // 멤버변수 *age로 heap 주소를 지정
    *age = vAge; // *age가 지정한 공간에 vAge 대입
    cout << "생성자 호출 \n";
}
// 복사 생성자
Age::Age(const Age &obj)
{
    age =new int;
    *age = obj.getAge();
    cout << "\n복사 생성자 호출\n";
}
