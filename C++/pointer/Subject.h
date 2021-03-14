#include <iostream>
using std::cout;
using std::endl;

class Subject
{
    private :
    int kor,eng,math;
    public :
     int sum,ave;
     
     void funSum();
     void funAve();
     void output();

     Subject(int a, int b, int c); //생성자

};
Subject::Subject(int a, int b, int c )
{
    kor = a, eng = b, math = c;
}
void Subject::funSum()
{
    sum = kor + eng + math;
}

void Subject::funAve()
{
    ave = sum/3;
}

void Subject::output()
{
    cout << "sum : " << sum << endl;
    cout << "ave : " << ave << endl;
}