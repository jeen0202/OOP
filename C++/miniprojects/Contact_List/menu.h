#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <stdlib.h>
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

class Menu
{
    public :
        void main_menu();
};

void Menu::main_menu()
{
    char ch;
    db_connect db;
    int seletedId;
    string selectedName, selectedAddress, selectedPhone;
    while(1)
    {        
        if (ch == '1')
            {
                clrscr();
                db.showList();
                cout<<"\n*******************************************************"<<endl;                
                cout<<"메인 메뉴로 나가려면 아무키나 입력해주세요. ";
                getKey();
            }
        else if (ch == '2')
            {
                do
                {
                    clrscr();
                    cout << "조회 할 사원의 이름을 입력해 주세요 >> ";
                    cin >> selectedName;
                    clrscr();
                    seletedId = db.searchID(selectedName);
                    cout<<"\n*******************************************************"<<endl;
                    cout << "계속 검색하시겠습니까?? (Y/N) : ";                                      
                    while(ch !='Y' || ch!='N'){                    
                        ch = getKey();
                        ch = toupper(ch);
                        if(ch == 'Y')
                            break;                    
                        else if(ch == 'N')
                            break;
                        else if(ch =='0')
                            return ;    
                    }
                }while(ch =='Y');                
            }
        else if (ch == '3')
            {
                while(1){
                    clrscr();
                    string newAddress;
                    string newPhone;
                    cout << "변경할 사원의 이름을 입력해 주세요 >> ";
                    cin >> selectedName;
                    clrscr();
                    seletedId = db.searchID(selectedName);
                   if(seletedId>0)
                   {
                        cout << "변경할 내용을 선택해 주세요 (1.주소/2.번호/3.모두변경/0.취소)";
                        while(ch!='1'||ch!='2'||ch!='3'||ch!='0') 
                        {
                            ch = getKey();
                            if(ch=='1')
                                break;
                            else if(ch=='2')
                                break;
                            else if(ch=='3')
                                break;
                            else if(ch=='0')
                                break;        
                        }
                        switch(ch)
                        {
                            case '0':
                                clrscr();                                                            
                                break;
                            case '1':
                                clrscr();
                                cout << "변경할 주소를 입력해 주세요 >> ";
                                getline(cin,newAddress);
                                db.updateAddress(seletedId,newAddress);
                                break;
                            case '2':
                                clrscr();
                                cout << "변경할 전화번호를 입력해 주세요 >> ";
                                cin >> newPhone;
                                db.updatePhone(seletedId,newPhone);
                                break;
                            case '3':
                                clrscr();
                                cout << "변경할 주소를 입력해 주세요 >> ";
                                getline(cin,newAddress);
                                cout << "변경할 전화번호를 입력해 주세요 >> ";
                                getline(cin,newPhone);
                                db.updateAddress(seletedId,newAddress);
                                db.updatePhone(seletedId,newPhone);
                                break;
                        }  
                    }
                        cout << "정보변경을 재실행 하시겠습니까?(Y/N) " ;
                        while(ch!='Y'||ch!='N')
                        {
                            ch = getKey();
                            ch = toupper(ch);
                            if(ch =='Y')
                                break;
                            else if(ch=='N'){                                
                                main_menu();
                            }
                            else if(ch=='0'){
                                clrscr();
                                return;
                            }
                                
                        }                       
                }
                
            }
        else if (ch == '4')
            {
               //삭제               
               clrscr();
               cout << "삭제할 사원의 이름을 입력해 주세요 >> ";
               cin >> selectedName;
               seletedId = db.searchID(selectedName);
               cout << "사원번호 "<< seletedId <<". " <<selectedName << "을 삭제하시겠습니까?(Y/N) ";
               while(ch!='Y'||ch!='N')
               {
                    ch=getKey();
                    ch=toupper(ch);
                    if(ch=='Y')
                    {
                        db.deleteMember(seletedId);
                        break;
                    }
                    else if(ch=='N')
                    {
                        ch = '4';
                        break;  
                    }
                
                }             
            }
        else if(ch=='5')
        {            
            clrscr();
            cout << "새로운 등록할 사원의 이름을 입력해 주세요 >> ";
            getline(cin,selectedName);
            cout << "해당 사원의 주소를 입력해 주세요 >> ";
            getline(cin,selectedAddress);
            cout << "해당 사원의 연락처를 입력해 주세요 >> ";
            getline(cin,selectedPhone);
            clrscr();
            cout << "이름\t주소\t전화번호" << std::endl;
            cout << selectedName << "\t" << selectedAddress << " " << selectedPhone << endl;
            cout << "사원을 추가하시겠습니까? (Y/N) ";            
            while(ch!='Y'||ch!='N')
            {
                ch = toupper(getKey());
                if(ch=='Y'){
                    db.addMember(selectedName,selectedAddress,selectedPhone);                    
                    break;
                }else if(ch=='N'){                    
                    break;
                }
            }
            
        }    
        else if (ch == '0')            
            break ;
        clrscr();
        cout<<"***********************************"<<endl;
        cout<<"***********************************"<<endl;
        cout <<"사 내 비 상 연 락 망 " << endl;        
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;       
        cout <<"1: 전 체 보 기" << endl;        
        cout <<"2: 사 원 조 회" << endl;        
        cout <<"3: 정 보 수 정" << endl;        
        cout <<"4: 정 보 삭 제" << endl;
        cout <<"5: 사 원 추 가" << endl;       
        cout <<"0: 나가기" << endl;       
        cout <<"선택 : ";
        ch = getKey();    
        }
        clrscr();
}

#endif