#include <iostream>
using namespace std;

class Snack {
    private :
        int cookie =0;
        int nacho =0;
        int kancho =0;
        int chip =0;
        static int amount;
    public:
        Snack(int,int,int,int);
        static void sum(int a=0, int b=0, int c = 0, int d = 0); // private으로 선언된 static 멤버변수에 접근
        static void show_amount();
};

int Snack::amount = 0;

Snack::Snack(int a, int b, int c, int d) : cookie(a), nacho(b), kancho(c), chip(d) {}

void Snack :: sum(int a, int b, int c, int d)
{
    amount +=(a+b+c+d);
}

void Snack::show_amount()
{
    cout << "Amount of Snack : " << amount << endl;
}
