#include <iostream>
using namespace std;
class Developer
{    
    private:
        int salary;
        friend class Manager;   
    public :
    Developer() {salary = 0;};       
    void showSalary() { cout << "Developer's salary : " << salary << endl;};
};

class Manager{
    private:
        int budget;
    public:
        Manager() { budget = 1000;}
        void sendMoney(Developer &dev, int salary)
        {
            this->budget -= salary;
            dev.salary += salary;
        }
        void showBudget() {cout << "Manager's budget : " << budget << endl;}
};
int main()
{
    Manager sejin;
    Developer jieun;
    int salary;
    sejin.showBudget();
    jieun.showSalary();

    cout << "Jieun을 고용" << endl;
    cout << "월급 책정 : " ;
    cin >> salary;
    sejin.sendMoney(jieun,salary);

    sejin.showBudget();
    jieun.showSalary();
}