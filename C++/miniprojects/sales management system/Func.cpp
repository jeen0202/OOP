#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <algorithm> // upper
#include <termios.h>

using namespace std;
#include "Class.h";

int getKey(int is_echo)
{
    int ch;
    struct termios old;
    struct termios current;
    /* 현재 설정된 terminal i/o 값을 backup함 */ 
    tcgetattr(0, &old); 
    /* 현재의 설정된 terminal i/o에 일부 속성만 변경하기 위해 복사함 */ 
    current = old; 
    /* buffer i/o를 중단함 */ 
    current.c_lflag &= ~ICANON;
    if (is_echo) { 
        // 입력값을 화면에 표시할 경우 
        current.c_lflag |= ECHO; } 
    else { // 입력값을 화면에 표시하지 않을 경우
         current.c_lflag &= ~ECHO; } /* 변경된 설정값으로 설정합니다.*/ 
    tcsetattr(0, TCSANOW, &current); 
    ch = getchar(); 
    tcsetattr(0, TCSANOW, &old);
    return ch;

}
void clrscr(){ system("CLS"); }

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
                p.modify_item();
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

int Product::last_code()
{
    fstream file;
    file.open("PRODUCT.DAT". ios::in);
    file.seekg(0,ios::beg);
    int t=0;
    while(file.read((char*)this, sizeof(Product)))
        t = itemcode;
    file.close();
    return t;
}
void Product :: list_of_item()
{
    fstream file;
    file.open("PRODUCT.DAT" , ios::in);
    file.seekg(0);
    int row=6, found = 0;
    cout << "LIST OF ITEMS" << endl;
    cout << "ITEM CODE ITEM NAME ITEM COST ITEM PRICE" << endl;
    cout << "***********************************************************" << endl;
    while(file.read((char*) this, sizeof(Product)))
    {
        found=1;
        cout << itemcode << endl;
        cout << itemname << endl;
        cout << itemcost << endl;
        cout << itemprice << endl;
        
        if( row ==22)
        {
            row = 5;
            cout << "Press any key to continue...";
            getKey(0);
            clrscr();
            cout <<"LIST OF ITEMS" << endl;
            cout <<"ITEM CODE ITEM NAME ITEM COST ITEM PRICE" << endl;
            cout <<"***********************************************************" << endl;
        }
        else
            row++;
    }
    if (!found)
    {
        cout << "\7Records not found" <<endl;
    }
    cout <<"PRess any key to continue..." ;
    getKey(0);
    file.close();
}

void Product:: add_item()
{
    int tcode,valid;
    char ch;
    string t_itemcost, t_itemprice;
    tcode = last_code();
    tcode++;
    do
    {
        clrscr();
        cout << "<0>=Exit" << endl;        
        cout << "Item Code : " << endl;
        cout << "Item Name : " << endl;
        cout << "Item Cost : " << endl;
        cout << "Item Price : " << endl;
        do
        {
            valid =1;
            cout <<"ENTER ITEM NAME TO ADD IN THE MENU" << endl;
            cout <<"Item Name : " ; cin >> itemname;
            transform(itemname.begin(), itemname.end(), itemname.begin(), ::toupper); // 대문자로 변환
            if (itemname.at(0) == '0')
                return ;
            if ((itemname.size()<1) || (itemname.size()>20))
            {
                valid = 0;
                cout << "\7 Range = 1..20";
                getKey(0);
            }
        } while (!valid);
        do
        {
            clrscr();
            valid = 1;
            cout <<"ENTER ITEM COST TO ADD IN THE MENU" << endl; ;
            cout << "Item Cost : "; cin >> t_itemcost ;
            itemcost = stof(t_itemcost);
            if(t_itemcost.at(0) == '0')
                return;
            if(itemcost <1 || itemcost > 800)
            {
                valid = 0;
                cout << "\7 Range = 1..800" ;
                getKey(0);
            }
        } while (!valid);
        do
        {
            valid =1;
            clrscr();
            cout << "ENTER ITEM PRICE TO ADD IN THE MENU" << endl; ;
            cout << "Item Price : " ; cin >>t_itemprice;
            itemprice  = stof(t_itemprice);
            if(t_itemprice.at(0) =='0')
                return ;
            if(itemprice < itemcost || itemprice > 1000)
            {
                valid = 0;
                cout << "\7 Range = " << itemcost <<".. 1000" ;
                getKey(0);
            }    
        } while (!valid);
        do
        {
            clrscr();
            cout << "Do you want to save this record (y/n) : " ;
            cin >> ch;
            ch = toupper(ch);
            if(ch =='0')
            return;        
        } while (ch!='N' && ch!='Y');
        if(ch =='Y')
        {
            itemcode = tcode;
            fstream file;
            file.open("PRODUCT.DAT",ios::out | ios::app);
            file.write((char*) this, sizeof(Product)) ;
            file.close() ;
            tcode++ ;
        }
        do{
            clrscr();
            cout << "Do you wnat to add more records (y/n) :  ";
            cin >> ch;
            ch = toupper(ch);
            if(ch=='0')
            return ;
        }
        while( ch!='N' && ch!='Y');    
    } 
    while (ch == 'Y');
    
}
void Product :: display_record(int tcode)
{
    fstream file;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg);
    while( file.read((char *) this, sizeof(Product)))
    {
        if (itemcode == tcode)
        {
            cout << "Item Code : " << itemcode << endl;
            cout << "Item Name : " << itemname << endl;
            cout << "Item Cost : " << itemcost << endl;
            cout << "Item Price " << itemprice ;
            break;
        }
    }
    file.close();
}

int Product :: item_found(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg);
    int found=0;
    while (file.read((char *) this, sizeof(Product)))
    {
        if (itemcode == tcode)
        {
            found ++;
            break;
        }
    }
    file.close();
    return found;
}

int Product::recordno(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", iso::in);
    file.seekg(0,ios::beg);
    int found=0;
    while(file.read((char *) this, sizeof(Product)))
    {
        found++;
        if (itemcode == tcode)
            break;
    }
    file.close() ;
    return found;
}

void Product :: delete_record(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    fstream temp ;
    temp.open("temp.dat", ios::out) ;
    file.seekg(0,ios::beg) ;
    while ( !file.eof() )
    {
        file.read((char *) this, sizeof(Product)) ;
        if ( file.eof() )
            break ;
        if ( itemcode != tcode )
            temp.write((char *) this, sizeof(Product)) ;
    }
    file.close() ;
    temp.close() ;
    file.open("PRODUCT.DAT", ios::out) ;
    temp.open("temp.dat", ios::in) ;
    temp.seekg(0,ios::beg) ;
    while ( !temp.eof() )
    {
        temp.read((char *) this, sizeof(Product)) ;
        if ( temp.eof() )
            break ;
        file.write((char *) this, sizeof(Product)) ;
    }
    file.close() ;
    temp.close() ;
}

void Product:: delete_item()
{
    clrscr();
    char ch;
    string t_code;
    int t, tcode;
    cout <<"Press <Enter> to see the list" << endl;
    cout <<"Enter Item Code of the item to be deleted : " ; cin >> t_code;
    t =stoi(t_code);
    tcode = t;
    if (t_code.at(0) == '0' )
        return;
    if(tcode == 0)
    {
        list_of_item();
        cout <<"Press <ENTER> to Exit"  << endl;
        cout << "Enter Item Code of the item to be deleted : " ;
        cin >> t_code;
        t = stoi(t_code);
        tcode = t;
        if(tcode == 0)
        return ;
    }
    clrscr();
    if(!item_found(tcode))
    {
        cout << "\7Record not found" :
        getKey(0);
        return;
    }
    display_record(tcode);
    do
    {
        cout <<"Do you want to delete this record (y/n) : " ; cin>>ch;
        ch = toupper(ch);
    } while (ch!='N' && ch!='Y');
    if(ch=='N')
        return;
    delete_record(tcode);
    cout << "\7Record Deleted" ;
    getKey(0);    
}

void Product :: modify_record(int tcode)
{
    int recno;
    recno = recordno(tcode);
    int valid, t_code;
    char ch;
    string t_itemcost, t_itemprice, t_itemcode;
    cout << "<0>=Exit" << endl;
    cout << "Item Code : " << endl;
    cout << "Item Name : " << endl;
    cout << "Item Cost : " << endl;
    cout << "Item Price : " << endl;
    do
    {
        
    }
}