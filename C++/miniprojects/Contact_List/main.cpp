#include <iostream>
#include <termios.h>
#include "db_connect.h"
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


int main()
{
    db_connect db;
    int id;
    db.showList();
    db.addMember("test","test","test");
    cout << "\tAFTER ADD" << endl;
    db.showList();
    id = db.searchID("test");
    cout << "\tresult : " << id << endl;    
    db.updateAddress(id,"광주광역시");
    db.updatePhone(id,"01073775773");
    cout << "\tAFTER UPDATE\n";
    db.showList();
    db.deleteMember(id);
    cout << "\tAFTER DELETE\n";
    db.showList();
}