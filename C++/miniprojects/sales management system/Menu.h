#include <iostream>
using namespace std;

class Product;
class Account;
class Menu
{
    private :
    void edit_menu();
    static char ch;   

    public :
        void main_menu();
        static void setCh(char);

};

void Menu::setCh(char ch_)
{
    Menu::ch = ch_;
}
void Menu::main_menu()
{
    while(1)
    {
        cout<<"*************************************************************"<<endl;
        cout<<"*************************************************************"<<endl;
        cout <<"S A L E S M A N A G E M E N T" << endl;        
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;       
        cout <<"1: PURCHASE PRODUCTS" << endl;        
        cout <<"2: LIST OF PRODUCTS" << endl;        
        cout <<"3: EDIT PRODUCTS FILE" << endl;        
        cout <<"4: BILLS REPORT" << endl;       
        cout <<"0: QUIT" << endl;       
        cout <<"Enter Your Choice : ";
        cin >> ch;
        switch(ch){
            case '1' :
                Product p;
                p.purchase();
            case '2' :
                Product p;
                p.list_of_item() ;
            case '3' :
                edit_menu() ;
            case '4' :
                Account a;
                a.bill_list();
            case '0' :
                break;
        }
    }
}

void Menu:: edit_menu()
{
    while(1)
    {
        cout<<"*************************************************************"<<endl;
        cout<<"*************************************************************"<<endl;
        cout <<"E D I T M E N U" << endl;
        cout <<"~~~~~~~~~~~~~~~~" << endl;
        cout <<"1: ADD PRODUCTS" << endl;
        cout <<"2: MODIFY PRODUCTS" << endl;
        cout <<"3: DELETE PRODUCTS" << endl;
        cout <<"0: EXIT" << endl;
        cout <<"Enter Choice : ";
        cin >>ch;
        switch(ch)
        {
            case '1' :
                Product p ;
                p.add_item();
                break;
            case '2' :
                Product p;
                p.mofidy_item();
                break;
            case '3' :
                Product p;
                p.delete_item();
                break;
            case '0' :
                break;
        }               
    }
}