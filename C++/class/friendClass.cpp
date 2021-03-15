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
        int getBudget() {return budget;};
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
    while(1){
    cout << "=========급여지급일=========" << endl;    
    cout << "Jieun's 급여 지급 : " ;
    cin >> salary;
    if(salary<=sejin.getBudget()){
    sejin.sendMoney(jieun,salary);
    }else{
        cout << "잔고가 부족합니다!! " << endl;
        break;
    }
    sejin.showBudget();
    jieun.showSalary();      
    }
}