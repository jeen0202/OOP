#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <termios.h>
using namespace std;
int getKey(int is_echo = 0)
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
class Menu
{
    public :
        void main_menu();
};
// db_connect db;
    // int id;
    // db.showList();
    // db.addMember("test","test","test");
    // cout << "\tAFTER ADD" << endl;
    // db.showList();
    // id = db.searchID("test");
    // cout << "\tresult : " << id << endl;    
    // db.updateAddress(id,"광주광역시");
    // db.updatePhone(id,"01073775773");
    // cout << "\tAFTER UPDATE\n";
    // db.showList();
    // db.deleteMember(id);
    // cout << "\tAFTER DELETE\n";
    // db.showList();
void Menu::main_menu()
{
    char ch;
    while(1)
    {
        clrscr();
        cout<<"***********************************"<<endl;
        cout<<"***********************************"<<endl;
        cout <<"사 내 비 상 연 락 망 " << endl;        
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;       
        cout <<"1: 전 체 보 기" << endl;        
        cout <<"2: 사 원 조 회" << endl;        
        cout <<"3: 정 보 수 정" << endl;        
        cout <<"4: 정 보 삭 제" << endl;       
        cout <<"0: 나가기" << endl;       
        cout <<"선택 : ";
        ch = getKey();
        if (ch == '1')
            {
               
            }
        else if (ch == '2')
            {
              
               
            }
        else if (ch == '3')
            {

            }
        else if (ch == '4')
            {
               
            }
        else if (ch == '0')            
            break ;
        }
        clrscr();
}

#endif