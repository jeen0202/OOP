#include <termios.h>
#include <iostream>
#include <string>
#include <random>
#include <sstream>
#include <algorithm>

#include "Menu.h"
//#include "Servant.cpp"

#include <fstream>
using namespace std;

vector<string> split(string str, char delimeter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
    while(getline(ss,temp,delimeter)){
        internal.push_back(temp);
    }
    return internal;
}


int getKey(int is_echo =0)
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

void clrscr(){ system("clear"); }

void Menu::main_menu()
{
    
    char ch;
    while(1)
    {
        clrscr();
        cout<<"*************************************************************"<<endl;
        cout<<"*************************************************************"<<endl;
        cout <<"W E L C O M E T O S E R V A N T W O R L D" << endl;        
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;       
        cout <<"1: GET SERVANT" << endl;        
        cout <<"2: LIST OF SERVANT" << endl;        
        cout <<"3: GET INTO BATTLE" << endl;   
        cout <<"0: QUIT" << endl;       
        cout <<"Enter Your Choice : ";
        ch = getKey();
        if (ch == '1')
        {
            clrscr();
            serv_menu();

        }
        else if (ch == '2')
        {
            clrscr();
            list_of_servant();
               
        }
        else if (ch == '3')
        {
            clrscr();
        }
        else if (ch == '0')            
            break ;
        }
        clrscr();
    }
void Menu::serv_menu()
{
    char ch;
    vector<string> box;
    string line,name;
    int level;
    Servant newServ;
    ifstream file;
    file.open("Servant.txt", ios::in);
    do
    {
        getline(file,line);
        box.push_back(line);
    } while (file.peek()!=EOF);
    file.close();
    cout << "Exit(0)" << endl;
    while(1)
    {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> dis(0,box.size()-1);
    line = box.at(dis(gen));
    //cout << "Line => " << line << endl;
    name = split(line,' ')[0];
    level = stoi(split(line, ' ')[1]);
    newServ.setName(name);
    newServ.setLevel(level);
    cout << "Servant : " << newServ.getName() << " Level : " << newServ.getLevel() << endl;
    cout << "Do you want this Servant?(Y/N)" ;
    ch = getKey(0);
    ch = toupper(ch);
    cout << endl;
    if(ch == 'Y')
    {
        ofstream file;
        file.open("Player.txt", ios::out | ios::app);
        //writeFile.write((char*)&pizza,sizeof(Food));
        file.write((char*)&newServ,sizeof(Servant));
        file.close();

    }
    if(ch == '0')
        return;  
    }
    
    
}

void Menu::list_of_servant()
{
    char ch;
    ifstream readServant;
    vector<Servant> list;
    Servant temp;
    readServant.open("Player.txt", ios::in);
    if(!readServant.is_open()){
        cout << "You did't have Servant" << endl;
        cout << "Press any key to return..." << endl;
        getKey();
        return;
    }else{
    while (readServant.peek()!=EOF)
    {
        readServant.read((char*)&temp,sizeof(Servant));
        list.push_back(temp);
    } 
    readServant.close();
    }
    while(1)
    {
        clrscr();
        cout<<"*************************************************************"<<endl;
        cout<<"*************************************************************"<<endl;
        cout <<"\t M Y S E R V A N T" << endl;        
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        if(list.empty()){
            cout << "You did't have Servant" << endl;
            cout << "Press any key to return..." << endl;
            if(getKey())
            {
                return;
            }
        }else{
            for(int i = 0;i<list.size();i++)
            {
                cout << i+1 << ". " <<list.at(i).getName() << endl;
            }       
            // cout <<"1st Servant" << endl;        
            // cout <<"2nd Servant" << endl;        
            // cout <<"3rd Servant" << endl;
            // cout <<"4th Servant" << endl;   
            cout <<"0: QUIT" << endl;       
            cout <<"Enter Your Choice : ";
            ch = getKey();
            if (ch == '1')
            {
                clrscr();
                cout << "Select 1" << endl;
            }else if(ch == '0')
            {
                return;
            }
        }

    }
}